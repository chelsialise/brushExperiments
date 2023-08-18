#include "colorLerpScene.h"

//---------------------------------------------------------------
void colorLerpScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Color Lerp"));
    
    for (int i = 0; i < 200; i++) {
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        meshes.push_back(mesh);
    }
    
}


//---------------------------------------------------------------
void colorLerpScene::update(){
    
    mousePos = mousePos * 0.5 + mouseFbo() * 0.5;
   
    //ofPoint pos = ofPoint(ofGetMouseX(), ofGetMouseY());
    line.addVertex(mousePos);
    
    ofPolyline smooothedLine = line.getSmoothed(7);
    
    for (int i = 0; i < smooothedLine.size(); i++) {
        int i_m_1 = i-1;
        int i_p_1 = i+1;
        if (i_m_1 < 0) {
            i_m_1 = 0;
        }
        if (i_p_1 == smooothedLine.size()) {
            i_p_1 = smooothedLine.size()-1;
        }
        ofPoint prev = smooothedLine[i_m_1];
        ofPoint curr = smooothedLine[i];
        ofPoint next = smooothedLine[i_p_1];
        
        int radius = 200;
        int resolution = 100;
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
       
        ofColor c1 = ofColor(45, 0, 247);
        ofColor c2 = ofColor(242, 0, 137);
        float lerpAmount = sin(0.01 * i);
        ofColor inBetween = c2.lerp(c1, ofMap(lerpAmount, -1, 1, 0, 1));
        
        for (int j = 0; j < resolution; j++) {
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            mesh.addVertex(curr);
            mesh.addVertex(curr + radius * ofPoint(cos(angle), sin(angle)));
            mesh.addColor(inBetween);
            mesh.addColor(inBetween);
//            mesh.addColor(ofColor(7,7,7));
//            mesh.addColor(ofColor(7,7,7));
        }
        meshes[i] = mesh;
        
    }

    if (line.size() > 200) {
        line.getVertices().erase(line.getVertices().begin());
    }
    
}


//---------------------------------------------------------------
void colorLerpScene::draw(){
    
    ofBackground(245, 245, 245);
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
        //meshes[i].drawWireframe();
    }
    
}
