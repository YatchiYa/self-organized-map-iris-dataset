#include "../../includes/som.h"

/**
 * function to draw the data and the normalized data on file
 * using an extern library : pbplot 
 * pbplot : available online
 * we just need to download the .h and .c files to use it
 * 
 * */

void        draw_data_simple(t_iris_database *iris_data, char* path)
{
	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	double      xs[150];
	double      ys[150];
	double      xs2[150];
	double      ys2[150];
	double      xs3[150];
	double      ys3[150];
    int         i;

    i = 0;
	// set our iris-setosa data with x an y 
    while (i < 150)
    {
        if (i < 50)
        {
            xs[i] = iris_data->data[i].spal_petal_data[2];
            ys[i] = iris_data->data[i].spal_petal_data[3];
        }
        else
        {
            xs[i] = 0;
            ys[i] = 0;
        }
        i++;
    }
    i = 0;
	// set our iris-verginica data with x an y 
    while (i < 150)
    {
        if (i > 50 && i < 100)
        {
            xs2[i] = iris_data->data[i].spal_petal_data[2];
            ys2[i] = iris_data->data[i].spal_petal_data[3];
        }
        else
        {
            xs2[i] = 0;
            ys2[i] = 0;
        }
        i++;
    }
    i = 0;
	// set our iris-versicolore data with x an y 
    while (i < 150)
    {
        if (i > 100 && i < 150)
        {
            xs3[i] = iris_data->data[i].spal_petal_data[2];
            ys3[i] = iris_data->data[i].spal_petal_data[3];
        }
        else
        {
            xs3[i] = 0;
            ys3[i] = 0;
        }
        i++;
    }

	// define the configuration of each graph - setosa - verginica - versicolor
	// define dots  graph setting and color, and x and y 
	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = sizeof(xs)/sizeof(double);
	series->ys = ys;
	series->ysLength = sizeof(ys)/sizeof(double);
	series->linearInterpolation = false;
	series->pointType = L"dots";
	series->pointTypeLength = wcslen(series->pointType);
	series->color = CreateRGBColor(0, 1, 0);

	// define the configuration of each graph - setosa - verginica - versicolor
	// define dots  graph setting and color, and x and y 
	ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
	series2->xs = xs2;
	series2->xsLength = sizeof(xs2)/sizeof(double);
	series2->ys = ys2;
	series2->ysLength = sizeof(ys2)/sizeof(double);
	series2->linearInterpolation = false;
	series2->pointType = L"dots";
	series2->pointTypeLength = wcslen(series2->pointType);
	series2->color = CreateRGBColor(1, 0, 0);

	// define the configuration of each graph - setosa - verginica - versicolor
	// define dots  graph setting and color, and x and y 
	ScatterPlotSeries *series3 = GetDefaultScatterPlotSeriesSettings();
	series3->xs = xs3;
	series3->xsLength = sizeof(xs3)/sizeof(double);
	series3->ys = ys3;
	series3->ysLength = sizeof(ys3)/sizeof(double);
	series3->linearInterpolation = false;
	series3->pointType = L"dots";
	series3->pointTypeLength = wcslen(series3->pointType);
	series3->color = CreateRGBColor(0, 0, 1);


	// define the setting of our display
	// define the resolution of our img
	// define the padding from border of our display
	// define the differents labels and the length of our display
	// set the series
	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1200;
	settings->height = 1050;
	settings->autoBoundaries = true;
	settings->autoPadding = false;
	settings->xPadding = (double)200;
	settings->yPadding = (double)200;
	settings->title = L"iris-data";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"petal-length -- red:Versicolor - green:Setosa - blue:virginica --";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"petal-width ";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series, series2, series3};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 3;

	// draw the img with settings
	DrawScatterPlotFromSettings(imageReference, settings);

	// remove the existing file already
	size_t length;
	char *tmp_path = ft_strjoin("rm ", path);
	system(tmp_path);

	
	// draw the image
	double *pngdata = ConvertToPNG(&length, imageReference->image);
	WriteToFile(pngdata, length, path);
	DeleteImage(imageReference->image);
}