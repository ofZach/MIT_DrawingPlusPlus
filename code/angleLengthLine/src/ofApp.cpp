#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

     ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    line.draw();
    
    
    for (int i = 0; i < alines.size(); i++){
        
        alines[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    alines.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    line.clear();
    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    angleLengthLine angleLine;
    angleLine.convertFrom(line);
    alines.push_back(angleLine);
    line.clear();
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
