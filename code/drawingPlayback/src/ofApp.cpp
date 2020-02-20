#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // load sound from folder bin/data/
    player.load("drawbar_c4_a.aif");
    
    // make the sound playback in looping mode
    player.setLoop(true);
    
    // start playback of the sound
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    // set the width of the stroke of ofPolyline
    ofSetLineWidth(2);
    
    // draw the ofPolyline line
    line.draw();
    
    // if the ofPolyline has elements
    if (line.size() > 0){
        
        // measure time since app was executed
        float time = ofGetElapsedTimef();
        
        // fmod(numer, denom) returns a floating point
        // which is the remainder when dividing numer/denom
        // so in this case position is a sawtooth wave between 0.0 and 1.0
        float position = fmod(time*0.2, 1.0);
        
        // getPointAtPercent(percentage) is a method of ofPolyline
        // returns the ofPoint corresponding to the percentage
        // where the first element in ofPolyline is 0.0
        // and the last element is 1.0
        ofPoint pt = line.getPointAtPercent(position);
        
        // ofMap(number, input start, input end, output start, output end)
        // the number is scaled from the input range to the output range
        float height = ofMap(pt.y, 0, ofGetHeight(), 10.0, 0.2);
        
        // set the playback speed of the sound according to y position
        // speed 1.0 is normal playback
        // 0.0 is pause, 0.5 is half speed, 2.0 is double speed
        // lower speed decreases pitch, higher speed increases pitch
        player.setSpeed(height);
        
        // draw a circle in the corresponding percentage
        ofDrawCircle(pt.x, pt.y, 10);
    }
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
    
    // when mouseDragged, add element to ofPolyline line
    line.addVertex(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // when mousePressed, clear all elements in ofPolyline line
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
