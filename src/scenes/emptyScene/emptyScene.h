#pragma once

#include "ofMain.h"
#include "baseScene.h"

class emptyScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
//    ofPolyline line;
//    ofPoint mousePos;
    
};
