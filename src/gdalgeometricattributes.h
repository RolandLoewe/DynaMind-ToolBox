#ifndef GDALGEOMETRICATTRIBUTES_H
#define GDALGEOMETRICATTRIBUTES_H

#include <dmmodule.h>
#include <dm.h>

class DM_HELPER_DLL_EXPORT OGRPolygon;

class DM_HELPER_DLL_EXPORT GDALGeometricAttributes : public DM::Module
{
	DM_DECLARE_NODE(GDALGeometricAttributes)
private:
	std::string leadingViewName;
	bool isCalculateArea;
	bool isAspectRationBB;
	bool isPercentageFilled;

	DM::ViewContainer vc;
	double calculateArea(OGRPolygon *poly);
	double aspectRationBB(OGRPolygon *poly);
	double percentageFilled(OGRPolygon *ogr_poly);
public:
	GDALGeometricAttributes();
	void run();
	void init();
};

#endif // GDALGEOMETRICATTRIBUTES_H
