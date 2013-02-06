#include "ramGlobal.h"
#include "ramBaseApp.h"
#include "ramControlPanel.h"

#include <numeric>

string ramToResourcePath(string path)
{
	return ofFilePath::join(ofToDataPath("../../../../resources"), path);
}

void ramInit()
{
	static bool inited = false;
	if (inited) return;
	inited = true;
	
	// !!!:
	ofLogWarning("ramInit() in ramGlobal.cpp: ofSetLogLevel(OF_LOG_SILENT) will be deleted when Fonts probrem in ofxUI is fixed.");
	ofSetLogLevel(OF_LOG_SILENT);
	
	ramSharedData::instance().setup();
	
	ramGetGUI().setup();
//	ramGetGUI().loadFont(ramToResourcePath("Fonts/din-webfont.ttf"), 10);
}

ramSharedData* ramSharedData::_instance = NULL;

ramSharedData& ramSharedData::instance()
{
	if (_instance == NULL)
		_instance = new ramSharedData;
	return *_instance;
}

void ramSharedData::setup()
{
	shadow.setup();
}