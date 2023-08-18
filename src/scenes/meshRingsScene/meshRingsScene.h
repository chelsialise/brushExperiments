#pragma once

#include "ofMain.h"
#include "baseScene.h"

class meshRingsScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPoint mousePos;
    vector<vector<ofMesh>> shapes;
    int good_i = 0;
    
};
