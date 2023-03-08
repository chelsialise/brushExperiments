#include "dotProductTubeFasterScene.h"

//---------------------------------------------------------------
void dotProductTubeFasterScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "DP Tube - Faster"));
    
}


//---------------------------------------------------------------
void dotProductTubeFasterScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    line.addVertex(mousePos);
    
    if (line.size() > 1) {
        ofPoint prev = line[line.size()-2];
        ofPoint curr = line[line.size()-1];
        
        ofPoint diff = curr-prev;
        ofPoint normal = diff.getNormalized();
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        resolution = 50;
        radius = 500;
        
        for (int j = 0; j < resolution; j++) {
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            
            ofPoint pos1 = prev + radius * ofPoint(cos(angle), sin(angle));
            ofPoint pos2  = curr + radius * ofPoint(cos(angle), sin(angle));
            
            pos1.z = ofMap(line.size()-2, 0, line.size(), -10, 0); /// not sure if this makes sense?
            pos2.z = ofMap(line.size()-1, 0, line.size(), -10, 0); /// not sure if this makes sense?
            
            mesh.addVertex(pos1);
            mesh.addVertex(pos2);
            
            float pct = ofMap(j, 0, resolution-1, 0, 1); /// we're not using this...
            ofColor c1 = ofColor(12, 15, 64);
            float dot = normal.dot(ofPoint(0,1).getRotated(sin(angle)*110, ofPoint(0,0,1)));
            ofColor color = c1 + ofColor::white.getLerped(ofColor::black, ofMap(dot, -1, 1, 0, 1));
            
            mesh.addColor(color);
            mesh.addColor(color);
        }
        meshes.push_back(mesh);
    }
    
    if (line.size() > 100) {
        line.getVertices().erase(line.begin());
    }
    
    if (meshes.size() > 99) {
        meshes.erase(meshes.begin());
    }
    
}


//---------------------------------------------------------------
void dotProductTubeFasterScene::draw(){
    
    //ofSetColor(255, 255, 255);
    //ofSetLineWidth(10);
    //line.draw();
    
    //ofEnableDepthTest();
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
    }
    //ofDisableDepthTest();
    
    
}
