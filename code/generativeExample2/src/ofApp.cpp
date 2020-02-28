#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //
    for (int z = 0; z < 100; z++){
        
        // check if the myLines vector is empty
        if (myLines.size() == 0){
            
            // declare a new line called tempLine
            line tempLine;
            
            // create an ofPoint in the middle of the screen
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            
            // declare a distance of 100 px
            float distance = 100;
            
            // calculate a random angle between 0 and 2*PI
            float angle = ofRandom(0, TWO_PI);
            
            // starting point a of tempLine is ofPoint start
            tempLine.a = start;
            
            // ending point b of tempLine is calculated
            // b is 100 px from a, at the random angle
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // add the tempLine to the end of the vector myLines
            myLines.push_back(tempLine);
        
        
        }
        // if there are lines in the myLines vector
        else {
            
            // pick a random line in the vector myLines
            int randomLineIndex = ofRandom(0, myLines.size());
            
            // pick a random percentage, between 0.0 and 1.0
            float randomPct = ofRandom(0,1);
            
            // declare an ofPoint called start
            // which lies inside of the random line
            // random percentage scales between a (0.0) and b (1.0)
            ofPoint start = myLines[randomLineIndex].a * (1-randomPct) +
                            myLines[randomLineIndex].b * randomPct;
            
            // declare a distance of 100 px
            float distance = 100;
            
            // calculate a random angle between 0 and 2*PI
            float angle = ofRandom(0, TWO_PI);
            
            // declare a new line called tempLine
            line tempLine;
            
            // starting point a of tempLine is ofPoint start
            tempLine.a = start;
            
            // ending point b of tempLine is calculated
            // b is 100 px from a, at the random angle
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // declare addTempline bOK, default value is true
            // we check if tempLine intersects with any line in myLines
            // if tempLine intersects no line, addTempline is true
            // if tempLine interesects any line, addTempline is false
            bool addTempline = true;
            
            // declare a new ofPoint called inter
            ofPoint inter;
            // go through every ofLine in the vector myLines
            for (int i = 0; i < myLines.size(); i++){
                // if the tempLine intersects with the current ofLine of the vector myLines
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    // make addTempline false
                    addTempline = false;  // :(
                    // end the iteration
                    break;
                }
            }
            
            // if the addTempline boolean is true
            // add the tempLine to the last position of the myLines vector
            if (addTempline) {
                myLines.push_back(tempLine);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // paint the background, color black
    ofBackground(0);
    
    // set the line width to 2 px
    ofSetLineWidth(2);
    
    // go through every line in myLines
    for (int i = 0; i < myLines.size(); i++){
        // draw each line
        ofDrawLine(myLines[i].a, myLines[i].b);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // when spacebar is pressed, clear the myLines vector
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
