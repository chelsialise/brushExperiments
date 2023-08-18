#include "starScene.h"

//---------------------------------------------------------------
void starScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Star Brush"));
    
}



//---------------------------------------------------------------
void starScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    path.addVertex(mousePos);
    
    if (meshes.size() > 250) {
        meshes.erase(meshes.begin());
    }
    
    int resolution = 25;
    float radius = 200;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    ofPoint center = ofPoint(mousePos.x, mousePos.y);
    mesh.addVertex(center);
    mesh.addColor(ofColor(166, 196, 211));
    //mesh.addColor(ofColor::black);
    
//    float pct = ofMap(i, 0, line.size(), 0, 1);
//    ofColor c1 = ofColor(3, 166, 60); /// green
//    ofColor c2 = ofColor(242, 53, 53); /// red
//    ofColor c3 = ofColor(217, 142, 4); /// orange
//    ofColor c4 = ofColor(166, 196, 211); /// light blue
//    ofColor lerp1 = c1.lerp(c2, pct);
//    ofColor lerp2 = c3.lerp(c4, pct);
//
//    ofColor c = lerp1;
//
//    if (j % 2 == 0){
//        radius = 300;
//        c = lerp2;
//    }
    
    ofColor c1 = ofColor(3, 166, 60); /// green
    ofColor c2 = ofColor(242, 53, 53); /// red
    ofColor c3 = ofColor(217, 142, 4); /// orange
    ofColor c4 = ofColor(166, 196, 211); /// light blue
    float lerpAmount = sin(good_i * 0.02);
    float pct = ofMap(lerpAmount, -1, 1, 0, 1);
    ofColor lerp1 = c1.lerp(c2, pct);
    ofColor lerp2 = c3.lerp(c4, pct);
    
    for (int i = 0; i < resolution; i++) {
        float angle = ofMap(i, 0, resolution-1, 0, TWO_PI);
        if (i % 2 == 0) {
            ofPoint pos1 = center + radius * ofPoint(cos(angle), sin(angle));
            mesh.addVertex(pos1);
            mesh.addColor(lerp1);
            //mesh.addColor(ofColor::black);
        } else {
            ofPoint pos2 = center + (radius-50) * ofPoint(cos(angle), sin(angle));
            mesh.addVertex(pos2);
            mesh.addColor(lerp2);
            //mesh.addColor(ofColor::gray);
        }
    }
    
    meshes.push_back(mesh);
    good_i++;
    
}


//---------------------------------------------------------------
void starScene::draw(){
    
    ofBackground(245, 245, 245);
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
        //meshes[i].drawWireframe();
    }
    
}
