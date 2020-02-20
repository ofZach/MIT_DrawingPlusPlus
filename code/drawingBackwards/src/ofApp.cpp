#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // set line width
    ofSetLineWidth(3);
    
    // draw ofPolyline line
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
    
    // ofPoint diff is the mouse movement between frames
    ofPoint diff = ofPoint(x,y) - prevMouse;
    
    // ofPoint lastLinePt is the last point in ofPolyline line
    ofPoint lastLinePt = line[line.size()-1];
    
    // add new element to ofPolyline line
    // the new element is in opposite direction of diff
    line.addVertex(lastLinePt - diff);
    
    // let's move the drawing so that it always starts from mouse
    
    // this is the distance between mouse and last element in line
    ofPoint diffToMouse = ofPoint(x,y) - line[line.size()-1];
    
    // go through every element in ofPolyline line
    // move it by diffToMouse, distance of last point to mouse
    for (int i = 0; i < line.size(); i++){
        line[i] += diffToMouse;
    }
    
    // when mouseDragged, update prevMouse
    prevMouse.set(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // when mousePressed, reset line and prevMouse
    line.clear();
    line.addVertex(x,y);
    prevMouse.set(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
