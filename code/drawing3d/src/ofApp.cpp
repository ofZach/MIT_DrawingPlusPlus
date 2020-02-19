#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetLineWidth(3);
    
    if (bMousePressed == true){
        line.addVertex( mouseX, mouseY);
    }
    
    
    for (int i = 0; i < line.size(); i++){
        line[i] -= ofPoint( ofGetWidth()/2, ofGetHeight()/2);
    }
    
    ofMatrix4x4 mat;
    mat.makeRotationMatrix(1, 0, 1, 0);
    for (int i = 0; i < line.size(); i++){
        ofPoint pt = line[i];
        pt = mat * pt;
        line[i] = pt;
    }
    
    
    for (int i = 0; i < line.size(); i++){
        line[i] += ofPoint( ofGetWidth()/2, ofGetHeight()/2);
    }
    
    line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    //line.addVertex(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    bMousePressed = true;
    line.clear();
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
 bMousePressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
