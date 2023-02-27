#include "dotProductBrushScene.h"

//---------------------------------------------------------------
void dotProductBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Dot Product"));
    
}


//---------------------------------------------------------------
void dotProductBrushScene::update(){
   
    mousePos = mousePos * 0.2 + mouseFbo() * 0.8;
    line.addVertex(mousePos);
    
    resolution = 50;
    radius = 500;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    ofPoint center = mousePos;
    mesh.addVertex(center);
    mesh.addColor(ofColor(12, 15, 64));
    
    for (int i = 0; i < resolution; i++) {
        int prev_i = line.size()-3;
        int curr_i = line.size()-2;
        int next_i = line.size()-1;
        if (prev_i < 0) {
            prev_i = 0;
        }
        
        ofPoint prev = line[prev_i];
        ofPoint curr = line[curr_i];
        ofPoint next = line[next_i];
        ofPoint diff = next - prev;
        ofPoint normal = diff.getNormalized();
        
        float angle = ofMap(i, 0, resolution-1, 0, TWO_PI);
        ofPoint pos = mousePos + radius * ofPoint(cos(angle), sin(angle));
        mesh.addVertex(pos);
        
        float pct = ofMap(i, 0, resolution-1, 0, 1);
        float dot = normal.dot(ofPoint(0,1).getRotated(angle*110, ofPoint(0,0,1)));
        ofColor color = ofColor(12, 15, 64) + ofColor::white.getLerped(ofColor::black, ofMap(dot, -1, 1, 0, 1));
        mesh.addColor(color);
    }
    meshes.push_back(mesh);
        
    
    if (meshes.size() > 200) {
        meshes.erase(meshes.begin());
    }
    
}


//---------------------------------------------------------------
void dotProductBrushScene::draw(){
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
    }
    
    //    ofSetColor(255, 255, 255);
    //    ofSetLineWidth(10);
    //    line.draw();
    
}
