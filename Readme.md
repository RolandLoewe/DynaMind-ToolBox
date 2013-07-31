DynaMind-BasicModules provides a set of basic module for DynaMind:

## Overview Basic Modules
|Name|Short description|
|----|-----------------|
|[ImportwithGDAL](ImportwithGDAL.md)|loads shapefiles, geoTIFFs, or load data from a WFS server
|[AddDataToNewView](AddDataToNewView.md)|adds components to another view
|[AppendAttributes](AppendAttributes.md)|intersects faces with rasterdata and add sum or median as attribute to face
|[AppendViewFromSystem](AppendViewFromSystem.md)|copies several userdefined datastreams in a new one (try to use [JoinDatastreams](JoinDatastreams.md) instead)
|[AttributeCalculator](AttributeCalculator.md)|calculates attributes based on other attributes, one of the most used modules for vector data.
|[CalculateCentroid](CalculateCentroid.md)|calculates centroids and area of faces
|[CalculateBoundingBox](CalculateBoundingBox.md)|creates bounding boxes for components
|[CellularAutomata](CellularAutomata.md)|the attribute calculator for raster data
|[SpatialLinking](SpatialLinking.md)|spatially links nodes with faces and faces with faces
|[JoinDatastreams](JoinDatastreams.md)|joins user defined data streams to a leading data stream
|[ExportToShapeFile](ExportToShapeFile.md)|exports data to shape file
|[ImportRasterData](ImportRasterData.md)|imports a ascii raster data file
|[ExportRasterData](ExportRasterData.md)|exports raster data set
|[RemoveComponent](RemoveComponent.md)|removes selected components
|[SinglePoint](SinglePoint.md)|adds a single point
|[ClearView](ClearView.md)|removes objects from a view (deprecated use [RemoveComponent](RemoveComponent.md))
|[FaceToEdge](FaceToEdge.md)|converts faces to edges
|[ExportNodesToFile](ExportNodesToFile.md)|exports nodes and their attributes into a text file
