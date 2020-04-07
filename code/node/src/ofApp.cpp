
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // set position of node A to be at center of (x,y) plane
    nodeA.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    // set nodeA as parent of nodeB
    nodeB.setParent(nodeA);
    // move 200px in x axis for nodeB
    nodeB.setPosition(200,0,0);
    
    //set nodeB as parent of nodeC
    nodeC.setParent(nodeB);
    // move 100px in x axis for nodeC
    nodeC.setPosition(100,0,0);
    
    // reset speeds
    resetSpeeds(true, true);
    
    // reset smoothing for speedA and speedB
    speedASmooth = 0;
    speedBSmooth = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

// function for resetting either speedA, speedB, or both
void ofApp::resetSpeeds(bool resetA, bool resetB) {
    
    // random values between 2.0 and 4.0
    // random direction either -1 or 1
    
    if (resetA) {
        speedA = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    }
    
    if (resetB) {
        speedB = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // declare variable for setting a threshold for resetting speeds
    
    float randomThreshold = 0.95;
    
    // declare booleans for resetting speeds, default false
    bool resetSpeedA = false;
    bool resetSpeedB = false;
    
    // if randomVariable is larger than thresold, reset speedA
    if (ofRandom(0,1) > randomThreshold){
        resetSpeedA = true;
    }
    
    // if randomVariable is larger than thresold, reset speedB
    if (ofRandom(0,1) > randomThreshold){
        resetSpeedB = true;
    }
    
    // reset speeds according to booleans
    resetSpeeds(resetSpeedA, resetSpeedB);
    
    // declare value for smoothing percentage
    float smoothPercent = 0.97;
    
    // smoothing of speedA and speedB
    speedASmooth = smoothPercent * speedASmooth + (1 - smoothPercent) * speedA;
    speedBSmooth = smoothPercent * speedBSmooth + (1 - smoothPercent) * speedB;
    
    // rotate nodeA and nodeB according to speeds
    nodeA.rotateDeg(speedASmooth, ofPoint(0,0,1));
    nodeB.rotateDeg(speedBSmooth, ofPoint(0,0,1));
    
    // draw nodes
    nodeA.draw();
    nodeB.draw();
    nodeC.draw();
    
    // draw line between nodeA and nodeB
    ofLine(nodeA.getGlobalPosition(),
           nodeB.getGlobalPosition());
    
    // draw line between nodeB and nodeC
    ofLine(nodeB.getGlobalPosition(),
           nodeC.getGlobalPosition());
    
    // if ofPolyline myLine has more than 1000 vertices
    if (myLine.size() > 1000){
        // delete the first/oldest vertex
        myLine.getVertices().erase(myLine.getVertices().begin());
    }
    
    // go through every vertex in the ofPolyline myLine
    for (int i = 0; i < myLine.size(); i++){
        // substract 1 from the x value of each vertex
        // this makes every vertex move one pixel to the left
        myLine[i].x -= 1;
    }
    
    // add the position of nodeC to the ofPolyline myLine
    myLine.addVertex(nodeC.getGlobalPosition());
    
    // draw the ofPolyline myLine
    myLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        resetSpeeds(true, true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
