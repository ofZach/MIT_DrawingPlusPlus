#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // use z temporal variable to iterate 100 times
    for (int z = 0; z < 100; z++){
        
        // if myLines is an empty vector
        if (myLines.size() == 0){
            
            // declare a temporary line
            line tempLine;
            
            // ofPoint start is in the middle of the screen
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            
            // declare distance, 100 px
            float distance = 100;
            
            // declare angle, random number between 0 and 2*PI
            float angle = ofRandom(0, TWO_PI);
            
            // ofPoint a in tempLine is ofPoint start
            tempLine.a = start;
            
            // ofPoint b in temPline is calculated from start
            // b is a + distance * (cos(angle), sin(angle))
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // add tempLine as the last element of myLines
            myLines.push_back(tempLine);
        }
        // if myLines is not an empty vector
        else {
            
            //
            int whichLine = ofRandom(0, myLines.size());
            
            // pick a random percentage, between 0.0 and 1.0
            float randomPct = ofRandom(0,1);
            
            //
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            // pick a random distance between 10 and 300
            float randomDistance = ofRandom(10,300);
            
            // we will pick a random angle between 0 and 2*PI
            // not all angles are possible
            // we choose one of equally spaced angles between 0, 2*PI
            
            // set how many different angles we have
            int angleDivisions = 8;
            
            // calculate the space between two consecutive angles
            float angleDivisionSize = TWO_PI / angleDivisions;
            
            // pick one of the possible random angles
            float randomAngle = (int) ofRandom(0, angleDivisions) * angleDivisionSize;
            
            // create a new line called templine
            line tempLine;
            
            // its ofPoint a is start
            tempLine.a = start;
            
            // its ofPoint b is calculated from start
            // distance between a and b is randomDistance
            // the angle is determined by randomAngle
            tempLine.b = start + randomDistance * ofPoint(cos(randomAngle),
                                                    sin(randomAngle));
            
            // declare addTempline bOK, default value is true
            // we check if tempLine intersects with any line in myLines
            // if tempLine intersects no line, addTempline is true
            // if tempLine interesects any line, addTempline is false
            bool addTempline = true;
            
            // declare a new ofPoint called inter
            ofPoint inter;
            
            // go through every line in the vector myLines
            for (int i = 0; i < myLines.size(); i++){
                // if the tempLine intersects with the current line of the vector myLines
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b,
                                               myLines[i].a, myLines[i].b,
                                               inter)){
                    // make addTempline false :(
                    addTempline = false;
                    
                    // end the iteration
                    break;
                }
            }
            
            // if the addTempline boolean is true
            if (addTempline) {
                // add the tempLine to the last position of the myLines vector
                myLines.push_back(tempLine);
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // paint background with color black
    ofBackground(0);
    
    // set the width of the lines to 2px
    ofSetLineWidth(2);
    
    // go through every line in myLines
    for (int i = 0; i < myLines.size(); i++){
        // draw each line, from their point a to b
        ofDrawLine(myLines[i].a,
                   myLines[i].b);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // when spacebar is pressed
    if (key == ' '){
        // delete all elements in vector myLines
        myLines.clear();
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
