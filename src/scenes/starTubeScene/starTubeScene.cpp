#include "starTubeScene.h"

//---------------------------------------------------------------
void starTubeScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Star Tube"));
    
}


//---------------------------------------------------------------
void starTubeScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    line.addVertex(mousePos);

    if (line.size() > 100) {
        line.getVertices().erase(line.begin());
    }

}


//---------------------------------------------------------------
void starTubeScene::draw(){
    
//    ofSetColor(255, 255, 255);
//    ofSetLineWidth(10);
//    line.draw();
    ofBackground(245, 245, 245);
    
    ofEnableDepthTest();
    for (int i = 0; i < line.size()-1; i++){
        resolution = 25;
        ofPoint center1 = line[i];
        ofPoint center2 = line[i+1];
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        float pct = ofMap(i, 0, line.size(), 0, 1);
        
        for (int j = 0; j < resolution; j++){
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            radius = 250;
            
            ofColor c1 = ofColor(3, 166, 60); /// green
            ofColor c2 = ofColor(242, 53, 53); /// red
            ofColor c3 = ofColor(217, 142, 4); /// orange
            ofColor c4 = ofColor(166, 196, 211); /// light blue
            ofColor lerp1 = c1.lerp(c2, pct);
            ofColor lerp2 = c3.lerp(c4, pct);
            
            ofColor c = lerp1;
            
            if (j % 2 == 0){
                radius = 175;
                c = lerp2;
            }
            
            ofPoint pos1 = center1 + radius * ofPoint(cos(angle), sin(angle));
            ofPoint pos2 = center2 + radius * ofPoint(cos(angle), sin(angle));
                
            pos1.z = ofMap(i, 0, line.size(), -10, 0);
            pos2.z = ofMap(i+1, 0, line.size(), -10, 0);
                
            mesh.addVertex(pos1);
            mesh.addVertex(pos2);
            mesh.addColor(c);
            mesh.addColor(c);
        }
        mesh.draw();
    }
    ofDisableDepthTest();
    
}
