
#include "ofApp.h"

// function for updating new speeds
// use booleans to update speedA and/or speedB
void ofApp::updateSpeeds(bool updateA, bool updateB) {
    // set minimum and maximum speed
   int minSpeed = 2;
   int maxSpeed = 4;
   
   // set the threshold for deciding if direction is -1 or 1
   float directionThreshold = 0.5;
   
   // (a ? b : c) means if a then b, otherwise c
   // these directions are either -1 or 1, randomly
   // since the threshold is 0.5, both are equally probable
   int directionA = ofRandom(0, 1) > directionThreshold ? -1 : 1;
   int directionB = ofRandom(0, 1) > directionThreshold ? -1 : 1;
   
   // calculate random speeds and multiply them by their direction
    // only update them if the corresponding booleans are true
    if (updateA) {
        speedA = ofRandom(minSpeed, maxSpeed) * (directionA);
    }
    if (updateB) {
        speedB = ofRandom(minSpeed, maxSpeed) * (directionB);
    }
   
}

//--------------------------------------------------------------
void ofApp::setup(){

    // set the position of nodeA in the middle of the screen
    nodeA.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    // make nodeA be the parent of nodeB
    nodeB.setParent(nodeA);
    
    // set the position of nodeB
    nodeB.setPosition(200, 0, 0);
    
    // make nodeB be the parent of node C
    nodeC.setParent(nodeB);
    
    // set the position of nodeC
    nodeC.setPosition(100, 0, 0);
    
    // update speeds of nodes A and B
    updateSpeeds(true, true);
    
    // initialize to 0 the variables for smoothing
    speedASmooth = 0;
    speedBSmooth = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // variable to control probability of calling updateSpeeds()
    // a bigger value makes it less probable, and viceversa
    float updateThreshold = 0.95;
    
    // if a random number is bigger than threshold, update speedA
    if (ofRandom(0,1) > updateThreshold){
        updateSpeeds(true, false);
    }
    
    // if a random number is bigger than threshold, update speedB
    if (ofRandom(0,1) > updateThreshold){
        updateSpeeds(false, true);
    }

    // percentage to control smoothing of speedA and speedB
    // bigger values make make the speeds jump faster
    float percentageSmooth = 0.03;

    // update speedASmooth and speedBSmooth
    // speedASmooth is made up of a mix of its past value and its new target value
    speedASmooth = (1 - percentageSmooth) * speedASmooth + percentageSmooth * speedA;
    speedBSmooth = (1 - percentageSmooth) * speedBSmooth + percentageSmooth * speedB;
    
    // rotate nodeA and nodeB around the Z axis
    nodeA.rotateDeg(speedASmooth, ofPoint(0,0,1));
    nodeB.rotateDeg(speedBSmooth, ofPoint(0,0,1));
    
    // draw nodes A, B, C
    nodeA.draw();
    nodeB.draw();
    nodeC.draw();
    
    // draw line between node A and node B
    ofLine(nodeA.getGlobalPosition(),
           nodeB.getGlobalPosition());
    
    // draw line between node B and node C
    ofLine(nodeB.getGlobalPosition(),
           nodeC.getGlobalPosition());
    
    // if there are more than a 1000 vertices in myLine
    if (myLine.size() > 1000){
        // delete the first one
        myLine.getVertices().erase(myLine.getVertices().begin());
    }
    
    // go through every element in myLine
    for (int i = 0; i < myLine.size(); i++){
        // move it one pixel to the left
        myLine[i].x -= 1;
    }
    
    // add the position of nodeC as a vertex to myLine
    myLine.addVertex(nodeC.getGlobalPosition());
    
    // draw the ofPolyline myLine
    myLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // if space bar is pressed, update the speeds
    if (key == ' '){
        updateSpeeds(true, true);
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
