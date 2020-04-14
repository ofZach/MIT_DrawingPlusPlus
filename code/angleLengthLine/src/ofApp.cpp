#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // paint the background black
    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the ofPolyline line
    line.draw();
    
    // go through every angleLengthline in the alines vector
    for (int i = 0; i < alines.size(); i++){
        // draw the corresponding instance of angleLengthline
        alines[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // when any key is pressed
    
    // clear all the angleLengthLine elements in the alines vector
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
    
    // every time the mouse is dragged
    
    // add vertex to ofPolyline line with the mouse position
    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // every time the mouse is pressed
    
    // delete all vertices in ofPolyline line
    line.clear();
    // add new vertex to ofPolyline with current mouse position
    line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // every time the mouse is released
    
    // declare new instance of angleLengthLine
    angleLengthLine angleLine;
    
    // calculate from line, the vectors inside of angleLine
    angleLine.convertFrom(line);
    
    // add the angleLengthLine angleLine to the alines vector
    alines.push_back(angleLine);
    
    // clear all vertices in ofPolyline line
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
