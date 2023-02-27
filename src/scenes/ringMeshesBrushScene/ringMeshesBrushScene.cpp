#include "ringMeshesBrushScene.h"

//---------------------------------------------------------------
void ringMeshesBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Ring of Meshes"));
    
}



//---------------------------------------------------------------
void ringMeshesBrushScene::update(){
   
    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
    
    int radius = 600;
    int resolution = 100;
    ofPoint pos = ofPoint(mousePos.x, mousePos.y);
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    vector<ofMesh> meshes;

    for (int i = 0; i < 4; i++) {
        float pct = ofMap(i, 0, 4, 0, 1);
        for (int j = 0; j < resolution; j++) {
            float angle = ofMap(j, 0, resolution-1, 0, TWO_PI);
            mesh.addVertex(pos + (((radius/4)*i) * ofPoint(cos(angle), sin(angle))));
            mesh.addVertex(pos + (radius/4 + ((radius/4)*i)) * ofPoint(cos(angle), sin(angle)));
            ofColor c1 = ofColor(0, 127, 95) * sin(angle);
            ofColor c2 = ofColor(255, 255, 63) * cos(angle);
            ofColor inBetween = c2.lerp(c1, pct);
            mesh.addColor(inBetween);
            mesh.addColor(inBetween);
        }
        meshes.push_back(mesh);
    }

    shapes.push_back(meshes);
    good_i++;
    
    
    if (shapes.size() > 200) {
        shapes.erase(shapes.begin());
    }
    
}


//---------------------------------------------------------------
void ringMeshesBrushScene::draw(){

    for (int i = 0; i < shapes.size(); i++) {
        for (int j = 0; j < shapes[i].size(); j++) {
            shapes[i][j].draw();
        }
    }
    
}
