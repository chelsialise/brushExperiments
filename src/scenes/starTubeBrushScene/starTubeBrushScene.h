#pragma once

#include "ofMain.h"
#include "baseScene.h"

class starTubeBrushScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
//    ofPolyline line;
//    ofPoint mousePos;
    
};
