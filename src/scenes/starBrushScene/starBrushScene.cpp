#include "starBrushScene.h"

//---------------------------------------------------------------
void starBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Star Brush"));
    
}



//---------------------------------------------------------------
void starBrushScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    path.addVertex(mousePos);
    
    if (meshes.size() > 250) {
        meshes.erase(meshes.begin());
    }
    
    int resolution = 25;
    float radius = 500;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    ofPoint center = ofPoint(mousePos.x, mousePos.y);
    mesh.addVertex(center);
    mesh.addColor(ofColor(214,217,191));
    
    ofColor c1 = ofColor(171,191,21);
    ofColor c2 = ofColor(214,217,191);
    float lerpAmount1 = sin(good_i * 0.02);
    float pct1 = ofMap(lerpAmount1, -1, 1, 0, 1);
    ofColor inBetween1 = c2.lerp(c1, pct1);
    
    for (int i = 0; i < resolution; i++) {
        float angle = ofMap(i, 0, resolution-1, 0, TWO_PI);
        if (i % 2 == 0) {
            ofPoint pos1 = center + radius * ofPoint(cos(angle), sin(angle));
            mesh.addVertex(pos1);
            mesh.addColor(inBetween1);
        } else {
            ofPoint pos2 = center + (radius-150) * ofPoint(cos(angle), sin(angle));
            mesh.addVertex(pos2);
            mesh.addColor(inBetween1);
        }
    }
    
    meshes.push_back(mesh);
    good_i++;
    
}


//---------------------------------------------------------------
void starBrushScene::draw(){
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
    }
    
}
