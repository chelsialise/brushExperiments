#include "dotProductTubeBrushScene.h"

//---------------------------------------------------------------
void dotProductTubeBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Dot Product Tube"));
    
}



//---------------------------------------------------------------
void dotProductTubeBrushScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    line.addVertex(mousePos);

    if (line.size() > 200) {
        line.getVertices().erase(line.begin());
    }
    
}


//---------------------------------------------------------------
void dotProductTubeBrushScene::draw(){
    
//    ofSetColor(255, 255, 255);
//    ofSetLineWidth(10);
//    line.draw();
    
    ofEnableDepthTest();
    for (int i = 0; i < line.size(); i++) {
        resolution = 50;
        radius = 500;
        
        int i_minus_1 = i-1;
        int i_plus_1 = i+1;
        if (i_minus_1 < 0) {
            i_minus_1 = 0;
        }
        if (i_plus_1 == line.size()) {
            i_plus_1 = line.size()-1;
        }
        
        ofPoint prev = line[i_minus_1];
        ofPoint curr = line[i];
        ofPoint next = line[i_plus_1];
        
        ofPoint diff = next-prev;
        ofPoint normal = diff.getNormalized();
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        for (int j = 0; j < resolution; j++) {
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            
            ofPoint pos1 = curr + radius * ofPoint(cos(angle), sin(angle));
            ofPoint pos2  = next + radius * ofPoint(cos(angle), sin(angle));
            
            pos1.z = ofMap(i, 0, line.size(), -1, 0);
            pos2.z = ofMap(i+1, 0, line.size(), -1, 0);
            
            mesh.addVertex(pos1);
            mesh.addVertex(pos2);
            
            float pct = ofMap(j, 0, resolution-1, 0, 1);
            ofColor c1 = ofColor(12, 15, 64);
            float dot = normal.dot(ofPoint(0,1).getRotated(angle*110, ofPoint(0,0,1)));
            ofColor color = c1 + ofColor::white.getLerped(ofColor::black, ofMap(dot, -1, 1, 0, 1));
            
            mesh.addColor(color);
            mesh.addColor(color);
        }
        mesh.draw();
    }
    ofDisableDepthTest();
    
    
}
