#include "sceneManager.h"

//---------------------------------------------------------------
void sceneManager::setup(){
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->gui.setPosition(ofPoint(20,20));
        scenes[i]->gui.setDefaultWidth(225);
        scenes[i]->gui.loadFont("InterTight-VariableFont_wght.ttf", 12);
        scenes[i]->gui.setDefaultTextPadding(8);
        scenes[i]->gui.setDefaultTextColor(ofColor(245,245,245));
        scenes[i]->gui.setDefaultFillColor(ofColor(13,13,13));
        scenes[i]->gui.setHeaderBackgroundColor(ofColor(26,26,75));
    }
     
    currentScene = 0;
    
}

void sceneManager::nextScene(){
    currentScene++;
    currentScene %= scenes.size();
}

void sceneManager::prevScene(){
    currentScene--;
    if (currentScene < 0){
        currentScene += scenes.size();
    }
}



//---------------------------------------------------------------
void sceneManager::update(){
    scenes[currentScene]->update();
}


//---------------------------------------------------------------
void sceneManager::drawGUI(){
    scenes[currentScene]->gui.draw();
}


//---------------------------------------------------------------
void sceneManager::draw(){
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
}




