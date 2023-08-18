#include "flatRibbonScene.h"

//---------------------------------------------------------------
void flatRibbonScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Flat Ribbon/Ribbon Tube"));
    
}



//---------------------------------------------------------------
void flatRibbonScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    line.addVertex(mousePos);
    
    if (line.size() > 1) {
        ofPoint prev = line[line.size()-2];
        ofPoint curr = line[line.size()-1];
        
        ofPoint diff = curr-prev;
        ofPoint normal = diff.getNormalized();
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        resolution = 3;
        radius = 225;
        
        for (int j = 0; j < resolution; j++) {
            //float angle = ofMap(j, 0, resolution-1, 0, TWO_PI); /// horizontal ribbon
            float angle = ofMap(j, 0, resolution-1, HALF_PI, TWO_PI+HALF_PI); /// vertical ribbon
            
            ofPoint pos1 = prev + radius * ofPoint(cos(angle), sin(angle));
            ofPoint pos2  = curr + radius * ofPoint(cos(angle), sin(angle));
            
            pos1.z = 0.0;
            pos2.z = 0.1;
            
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
void flatRibbonScene::draw(){
    
    ofBackground(245, 245, 245);
    
    //ofSetColor(255, 255, 255);
    //ofSetLineWidth(10);
    //line.draw();
    
    ofEnableDepthTest();
    for (int i = 0; i < meshes.size(); i++) {
        ofPushMatrix();
        ofTranslate(0, 0, i*0.1);
        meshes[i].draw();
        ofPopMatrix();
    }
    ofDisableDepthTest();
    
}
