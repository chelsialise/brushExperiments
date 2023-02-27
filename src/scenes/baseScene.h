#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class baseScene {
    
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    ofPoint mouseFbo();
    
    /// gui panel
    ofxPanel gui;
    
    /// fbo
    ofFbo * fbo;
    float * w;
    float * h;
    
    
};
