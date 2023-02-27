#include "baseScene.h"

//--------------------------------------------------------------
ofPoint baseScene::mouseFbo() {
    
    /// map mouse to fbo
    ofRectangle window(0, 0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0, 0, *w, *h);
    target.scaleTo(window);
    float mouseXFbo = ofMap(ofGetMouseX(), target.getLeft(), target.getRight(), 0, *w);
    float mouseYFbo = ofMap(ofGetMouseY(), target.getTop(), target.getBottom(), 0, *h);
    return ofPoint(mouseXFbo, mouseYFbo);
    
}

