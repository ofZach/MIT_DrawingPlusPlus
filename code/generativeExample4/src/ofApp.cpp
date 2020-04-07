#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

    // create variable z to iterate 100 times
    for (int z = 0; z < 100; z++){
        
        // if the myLines vector is empty
        if (myLines.size() == 0){
        
            // declare a line called tempLine
            line tempLine;
            
            // create an ofPoint at the middle of the canvas
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            
            // declare a distance with a fixed value
            float distance = 100;
            
            // declare a random angle
            float angle = ofRandom(0, TWO_PI);
            
            // set start as the "a" point of tempLine
            tempLine.a = start;
            
            // go from start with the distance and angle, set as the "b" point of tempLine
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // add tempLine to the myLines vector
            myLines.push_back(tempLine);
        }
        // if the myLines vector is not empty
        else {
            
            // pick a random line of the myLines vector
            int whichLine = ofRandom(0, myLines.size());
            
            // pick a random percentage between 0.0 and 1.0
            float randomPct = ofRandom(0,1);
            
            // find
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            // pick a random distance
            float distance = ofRandom(10,300);
            
            // pick a random angle
            float angle = ofRandom(0,TWO_PI);
            
            // declare a new line called tempLine
            line tempLine;
            
            // set start as the "a" point of tempLine
            tempLine.a = start;
            
            // go from start with the distance and angle, set as the "b" point of tempLine
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // set a boolean, default true
            bool bOk = true;
            
            // declare ofPoint named inter
            ofPoint inter;
            
            // iterate through every line in the myLines vector
            for (int i = 0; i < myLines.size(); i++){
                // check if each line intersects with tempLine
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    // if they interesect, shorten tempLine and make it end at the intersection
                    tempLine.b = inter;
                }
            }
            // check if the length of tempLine is bigger than a threshold
            if (  (tempLine.a - tempLine.b).length() > 5 ){
                // append tempLine to the end of the myLines vector
                myLines.push_back(tempLine);
            }
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw black background
    ofBackground(0);
    // set line width
    ofSetLineWidth(2);
    // go through every line in the myLines vector
    for (int i = 0; i < myLines.size(); i++){
        // draw each line from its start point "a" to end point "b"
        ofDrawLine(myLines[i].a,
                   myLines[i].b);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // clear the myLines vector when spacebar is pressed
    if (key == ' '){
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
