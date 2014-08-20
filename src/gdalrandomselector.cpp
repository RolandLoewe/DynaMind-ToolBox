#include "gdalrandomselector.h"

DM_DECLARE_NODE_NAME(GDALRandomSelector, GDALModules)

GDALRandomSelector::GDALRandomSelector()
{
	GDALModule = true;

	srand (time(NULL));

	this->viewName = "";
	this->addParameter("view_name", DM::STRING, &this->viewName);

	this->attribute = "";
	this->addParameter("attribute", DM::STRING, &this->attribute);

	this->elements = 0;
	this->addParameter("elements", DM::INT, &this->elements);

	this->units = "";
	this->addParameter("units", DM::STRING, &this->units);


	//dummy to get the ports
	std::vector<DM::ViewContainer> data;
	data.push_back(  DM::ViewContainer ("dummy", DM::SUBSYSTEM, DM::MODIFY) );
	this->addGDALData("city", data);

}

void GDALRandomSelector::init()
{

	if (viewName.empty() || attribute.empty())
		return;
	this->vc = DM::ViewContainer(viewName, DM::FACE, DM::READ);
	this->vc.addAttribute(attribute, DM::Attribute::INT, DM::WRITE);
	if (!this->units.empty())
		vc.addAttribute(units, DM::Attribute::INT, DM::READ);

	std::vector<DM::ViewContainer*> data_stream;
	data_stream.push_back(&vc);
	this->registerViewContainers(data_stream);

}

void GDALRandomSelector::run()
{

	vc.resetReading();
	int total_number_of_featurers = vc.getFeatureCount();
	if (total_number_of_featurers == -1) {
		DM::Logger(DM::Error) << "Error feature counter";
		return;
	}
	std::vector<int> rand_elements;
	std::vector<int> ids;
	int elements_max = elements;

	OGRFeature * f;

	int counter = 0;
	while(f = vc.getNextFeature()) {
		rand_elements.push_back(counter++);
		ids.push_back(f->GetFID());
	}
	vc.syncAlteredFeatures();
	vc.syncReadFeatures();

	vc.resetReading();

	for (int i = 0; i < elements_max; i++) {
		int r = rand() %total_number_of_featurers;
		rand_elements[i] = rand_elements[r];
	}

	counter = 0;
	bool has_unit = true;
	if (this->units.empty())
		has_unit = false;
	while (elements_max > 0) {
		if (counter > rand_elements.size()-1) {
			break;
		}
		f = vc.getFeature(ids[rand_elements[counter++]]);
		if (!f) {
			DM::Logger(DM::Warning) << "Feature not falied";
			continue;
		}
		if (!has_unit) {
			elements_max--;
			f->SetField(attribute.c_str(), 1);
			continue;
		}

		int e = f->GetFieldAsInteger(units.c_str());
		if (e == 0) {
			continue;
		}

		f->SetField(attribute.c_str(), 1);
		elements_max-=e;
	}
}


