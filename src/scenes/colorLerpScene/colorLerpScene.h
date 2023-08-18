#pragma once

#include "ofMain.h"
#include "baseScene.h"

class colorLerpScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPoint mousePos;
    ofPolyline line;
    vector<ofMesh> meshes;


    
};
