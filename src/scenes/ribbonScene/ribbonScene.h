#pragma once

#include "ofMain.h"
#include "baseScene.h"

class ribbonScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPoint mousePos;
    ofPolyline path;
    ofPoint pos;
    int numDeleted;
    
    
};
