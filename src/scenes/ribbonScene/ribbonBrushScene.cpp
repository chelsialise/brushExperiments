#include "ribbonBrushScene.h"

//---------------------------------------------------------------
void ribbonBrushScene::setup(){
    
    gui.setup();
    gui.add(sceneTitle.setup("Scene", "Ribbon"));
    
    numDeleted = 0;
    
}



//---------------------------------------------------------------
void ribbonBrushScene::update(){
   
    mousePos = mousePos * 0.5 + mouseFbo() * 0.5;

    if (path.size() > 100) {
        path.getVertices().erase(path.begin());
        numDeleted++;
    }
    
}


//---------------------------------------------------------------
void ribbonBrushScene::draw(){
    
    path.addVertex(mousePos);
    ofPolyline smoothedPath = path.getSmoothed(5);
    
    vector<ofMesh> meshes;
    for (int i = 0; i < 10; i++) {
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        meshes.push_back(mesh);
    }
    
    for (int i = 0; i < smoothedPath.size(); i++) {
        
        int goodi = i + numDeleted;
        int i_minus_1 = i-1;
        int i_plus_1 = i+1;
        if (i_minus_1 < 0) {
            i_minus_1 = 0;
        }
        if (i_plus_1 == smoothedPath.size()) {
            i_plus_1 = smoothedPath.size()-1;
        }
        
        ofPoint prev = smoothedPath[i_minus_1];
        ofPoint curr = smoothedPath[i];
        ofPoint next = smoothedPath[i_plus_1];
        
        ///calculate velocity
        float vel = (next-prev).length();
        
        /// make normals
        ofPoint diff = next - prev;
        ofPoint normal = diff.getNormalized();
        ofPoint topEnd =  curr + normal.getRotated(90, ofPoint(0, 0, 1)) * 100 * (ofMap(vel, 0, 600, 1, 100) * 0.008);
        ofPoint bottomEnd = curr + normal.getRotated(-90, ofPoint(0, 0, 1)) * 100 * (ofMap(vel, 0, 600, 1, 100) * 0.008);
        
        for (int j = 0; j < meshes.size(); j++) {
            
            float pctA = ofMap(j, 0, 10, 0, 1);
            float pctB = ofMap(j+1, 0, 10, 0, 1);
            
            ofPoint pointA = topEnd + pctA*(bottomEnd - topEnd);
            ofPoint pointB = topEnd + pctB*(bottomEnd - topEnd);
            
            meshes[j].addVertex(pointA);
            meshes[j].addVertex(pointB);
            
            float dotA = normal.dot(ofPoint(0,1).getRotated(pctA*90, ofPoint(0,0,1)));
            ofColor colorA = ofColor(127,0,0) + ofColor::white.getLerped(ofColor::black, ofMap(dotA, -1, 1, 0, 1));
            float dotB = normal.dot(ofPoint(0,1).getRotated(pctB*90, ofPoint(0,0,1)));
            ofColor colorB = ofColor(127,0,0) + ofColor::white.getLerped(ofColor::black, ofMap(dotB, -1, 1, 0, 1));
            
            meshes[j].addColor(colorA);
            meshes[j].addColor(colorB);
        }
        
        /// draw normals
        //ofSetColor(0, 0, 0);
        //ofDrawLine(curr, topEnd);
        //ofDrawLine(curr, bottomEnd);
        
    }
    
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
    }
    
    
}
