#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("drawbar_c4_a.aif");
    player.setLoop(true);
    player.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetLineWidth(2);
    line.draw();
    
    if (line.size() > 0){
        float time = ofGetElapsedTimef();
        float position = fmod(time*0.2, 1.0);
        ofPoint pt = line.getPointAtPercent(position);
        
        float height = ofMap(pt.y, 0, ofGetHeight(), 10.0, 0.2);
        player.setSpeed(height);
        
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

    line.addVertex(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
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
