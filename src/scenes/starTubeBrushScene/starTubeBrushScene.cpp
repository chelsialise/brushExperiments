#include "starTubeBrushScene.h"

//---------------------------------------------------------------
void starTubeBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Star Tube"));
    
}



//---------------------------------------------------------------
void starTubeBrushScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    line.addVertex(mousePos);

    if (line.size() > 100) {
        line.getVertices().erase(line.begin());
    }

}


//---------------------------------------------------------------
void starTubeBrushScene::draw(){
    
//    ofSetColor(255, 255, 255);
//    ofSetLineWidth(10);
//    line.draw();
    
    ofColor c1 = ofColor(3, 166, 60); ///green
    ofColor c2 = ofColor(242, 53, 53); ///red
    ofColor c3 = ofColor(217, 142, 4); ///orange
    ofColor c4 = ofColor(166, 196, 211); ///light blue
    
    ofEnableDepthTest();
    for (int i = 0; i < line.size()-1; i++){
        resolution = 25;
        ofPoint center1 = line[i];
        ofPoint center2 = line[i+1];
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        for (int j = 0; j < resolution; j++){
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            float pct = ofMap(i, 0, line.size(), 0, 1);
            ofColor lerp1 = c1.lerp(c2, pct);
            ofColor lerp2 = c3.lerp(c4, pct);
            ofColor c = lerp1;
            radius = 500;
            if (j % 2 == 0){
                radius = 300;
                c = lerp2;
            }
            ofPoint pos1 = center1 + radius * ofPoint(cos(angle), sin(angle));
            ofPoint pos2 = center2 + radius * ofPoint(cos(angle), sin(angle));
                
            pos1.z = ofMap(i, 0, line.size(), -1, 0);
            pos2.z = ofMap(i+1, 0, line.size(), -1, 0);
                
            mesh.addVertex(pos1);
            mesh.addVertex(pos2);
            mesh.addColor(c);
            mesh.addColor(c);
        }
        //meshes.push_back(mesh);
        mesh.draw();
    }
    
    ofDisableDepthTest();
    
//    for (int i = 0; i < meshes.size()-1; i++){
//        meshes[i].draw();
//    }
    
}
