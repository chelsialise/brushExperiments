#pragma once

#include "ofMain.h"
#include "baseScene.h"

class dotProductBrushScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPolyline line;
    ofPoint mousePos;
    vector<ofMesh> meshes;
    int resolution;
    int radius;
    
};
