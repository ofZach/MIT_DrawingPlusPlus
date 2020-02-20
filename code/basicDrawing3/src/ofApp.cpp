#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // uncomment to smooth ofPolyline line
    // line = line.getSmoothed(3);
    
    // declare ofPolyline resampled
    // it is obtained from resampling ofPolyline line
    ofPolyline resampled = line.getResampledBySpacing(20);
    
    // iterate through every element in resampled
    for (int i = 0; i < resampled.size(); i++){
        // for each element, draw a red circle
        ofSetColor(255, 0, 0);
        ofDrawCircle(resampled[i], 10);
    }
    
    // uncomment to draw ofPolyline resampled in green
    // ofSetColor(0,255,0);
    // resampled.draw();
    
    // uncomment to draw ofPolyline line in blue
    // ofSetColor(0, 0, 255);
    // line.draw();
    
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
    
    // when mouseDragged, add new element to ofPolyline line
    line.addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // when mousePressed, delete all elements in ofPolyline line
    line.clear();
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
