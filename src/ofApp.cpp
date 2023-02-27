#include "ofApp.h"
#include "emptyScene.h"
#include "colorLerpBrushScene.h"
#include "ringMeshesBrushScene.h"
#include "ribbonBrushScene.h"
#include "starBrushScene.h"
#include "dotProductBrushScene.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    /// fbo setup
    int value;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);
    float total = 8.5 + 8.5;
    w = (8.5 / total) * (value-1);
    h = (8.5 / total) * (value-1);
    fbo.allocate(w, h, GL_RGBA, 4);
    
    /// syphon setup
    server.setName("brushExperimentsServer");
    
    /// add scenes
    SM.scenes.push_back(new emptyScene());
    SM.scenes.push_back(new colorLerpBrushScene());
    SM.scenes.push_back(new ringMeshesBrushScene());
    SM.scenes.push_back(new ribbonBrushScene());
    SM.scenes.push_back(new starBrushScene());
    SM.scenes.push_back(new dotProductBrushScene());

    for (int i = 0; i < SM.scenes.size(); i++){
        
        SM.scenes[i]->setup();
        SM.scenes[i]->fbo = &fbo;
        SM.scenes[i]->w = &w;
        SM.scenes[i]->h = &h;
        
    }
    
    SM.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    /// update scences
    SM.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ofRectangle bounds(0, 0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0, 0, w, h);
    target.scaleTo(bounds);
    
    SM.draw();
    
    ofClearAlpha();
    fbo.end();
    fbo.draw(target);
    
    SM.drawGUI();
    
    /// syphon
    server.publishScreen();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT){
        SM.nextScene();
    } else if (key == OF_KEY_LEFT){
        SM.prevScene();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


