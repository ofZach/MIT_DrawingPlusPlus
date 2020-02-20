#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // iterate with index z, 100 times
    for (int z = 0; z < 100; z++){
        
        // if myLines is empty
        if (myLines.size() == 0){
            
            // create a new line
            line tempLine;
            
            // create a new starting point in middle of screen
            ofPoint start = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
            
            // create a new (distance, angle) pair, with random angle
            float distance = 100;
            float angle = ofRandom(0, TWO_PI);
            
            // a is the ofPoint start
            tempLine.a = start;
            
            // b is the ofPoint resulting from
            // b = a + distance * (cos(angle), sin(angle))
            tempLine.b = start + distance * ofPoint(cos(angle), sin(angle));
            
            // add tempLine to the end of the vector
            myLines.push_back(tempLine);
            
        }
        // if there are elements in myLines
        else {
            
            // select a random line
            int whichLine = ofRandom(0, myLines.size());
            
            // create a random percentage
            float randomPct = ofRandom(0,1);
            
            // start is a point in whichLine
            // start is the corresponding point to the random percentage
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            // create a random distance
            float distance = ofRandom(10,100);
            
            // create a random angle
            float angle = ofRandom(0, TWO_PI);
            
            // create a new line
            line tempLine;
            // its start is the random point "a" along the random whichLine
            tempLine.a = start;
            // its end is the ofPoint resulting from
            // b = a + distance * (cos(angle), sin(angle))
            tempLine.b = start + distance * ofPoint(cos(angle), sin(angle));
            
            // create a true boolean
            bool bOk = true;
            
            // create a new point
            ofPoint inter;
            
            // iterate through every line in myLines
            for (int i = 0; i < myLines.size(); i++) {
                // if the calculated tempLine intersects with the current element in myLines
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    // make the boolean false and exit the loop :(
                    bOk = false;
                    break;
                }
            }
            // if bOK is still true after iterating through all the lines in vector myLines
            if (bOk) {
                // append the random tempLine to the end of the vector myLines
                myLines.push_back(tempLine);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // iterate over every line
    for (int i = 0; i < myLines.size(); i++){
        // draw each line from its start in "a" and end in "b"
        ofDrawLine(myLines[i].a, myLines[i].b);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // when any key is pressed, clear myLines
    myLines.clear();
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
