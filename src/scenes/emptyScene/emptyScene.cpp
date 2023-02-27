#include "emptyScene.h"

//---------------------------------------------------------------
void emptyScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "[insert name]"));
    
}



//---------------------------------------------------------------
void emptyScene::update(){
   
//    mousePos = mousePos * 0.8 + mouseFbo() * 0.2;
//    line.addVertex(mousePos);
//
//    if (line.size() > 100) {
//        line.getVertices().erase(line.begin());
//    }
    
}


//---------------------------------------------------------------
void emptyScene::draw(){
    
    //ofSetColor(255, 255, 255);
    //ofSetLineWidth(10);
    //line.draw();
    
    
}
