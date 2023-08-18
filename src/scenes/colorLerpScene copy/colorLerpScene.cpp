#include "colorLerpScene.h"

//---------------------------------------------------------------
void colorLerpScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Color Lerp"));
    
}


//---------------------------------------------------------------
void colorLerpScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    
    int radius = 500;
    int resolution = 100;
    ofPoint pos = ofPoint(mousePos.x, mousePos.y);
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    ofColor c1 = ofColor(45, 0, 247);
    ofColor c2 = ofColor(242, 0, 137);
    float lerpAmount = sin(0.01 * good_i);
    ofColor inBetween = c2.lerp(c1, ofMap(lerpAmount, -1, 1, 0, 1));
    
    for (int i = 0; i < resolution; i++) {
        float angle = ofMap(i, 0, resolution-1, 0, TWO_PI);
        mesh.addVertex(pos);
        mesh.addVertex(pos + radius * ofPoint(cos(angle), sin(angle)));
        mesh.addColor(inBetween);
        mesh.addColor(inBetween);
    }
    
    shapes.push_back(mesh);
    good_i++;

    
    if (shapes.size() > 200) {
        shapes.erase(shapes.begin());
    }
    
}


//---------------------------------------------------------------
void colorLerpScene::draw(){
    
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i].draw();
    }
    
}
