#pragma once

#include "ofMain.h"
#include "baseScene.h"

class squareTubeScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxLabel sceneTitle;
    
    ofPolyline line;
    vector<ofMesh> meshes;
    ofPoint mousePos;
    int resolution;
    float radius;
    
};
