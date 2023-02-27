#pragma once

#include "ofMain.h"
#include "baseScene.h"

class starBrushScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPolyline path;
    ofPoint mousePos;
    vector<ofMesh> meshes;
    ofMesh background;
    int good_i;
};
