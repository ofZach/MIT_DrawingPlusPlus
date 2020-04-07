#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // iterate a hundred times
    for (int z = 0; z < 100; z++){
        
        // execute if the myLines vector is empty
        if (myLines.size() == 0){
            
            // declare new line called tempLine
            line tempLine;
            
            // declare new ofPoint called start, in middle of canvas
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            
            // declare variable called distance
            float distance = 100;
            
            // declare variable called angle, random value
            float angle = ofRandom(0, TWO_PI);
            
            // use ofPoint start to define "a" in tempLine
            tempLine.a = start;
            
            // use distance and angle to define "b" in tempLine
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // add tempLine to the end of the myLines vector
            myLines.push_back(tempLine);
        }
        // executy is the myLines vector is not empty
        else {
            
            // select a random line in the myLines vector
            int whichLine = ofRandom(0, myLines.size());
            
            // select a random percentage, between 0.0 and 1.0
            float randomPct = ofRandom(0,1);
            
            // according to the random percentage, calculate a point  in the line
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            // calculate the vecor between "b" and "a" of the line
            ofPoint diff = myLines[whichLine].b - myLines[whichLine].a;
            
            // calculate the starting angle from the diff vector
            float startAngle = atan2(diff.y, diff.x);
            
            // select a random distance
            float distance = ofRandom(10,300);
            
            // select a random angle, either +90 or -90 degrees from startAngle
            float angle = startAngle + (ofRandom(0, 1) > 0.5 ? PI/2.0 :  -PI/2.0);
            // add a random value between 0.0 and 0.1 to the randomAngle
            angle += ofRandom(0, .1);
            
            // declare a new line called tempLine
            line tempLine;
            
            // set the "a" and "b" points of tempLine
            // "a" is the ofPoint start
            // "b" is calculated by going from start,
            // advancing the distance in the angle
            tempLine.a = start;
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // declare ofPoint called inter
            ofPoint inter;
            
            // iterate through every line in the myLines vector
            for (int i = 0; i < myLines.size(); i++){
                
                // check if the tempLine intersects with the current line
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    
                    // if they intersect, make "b" of tempLine the intersection
                    tempLine.b = inter;
                }
            }
            
            // check if the tempLine is bigger than a threshold
            if ((tempLine.a - tempLine.b).length() > 5 ){
                // add the tempLine to the end of the myLines vector
                myLines.push_back(tempLine);
            }
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw black background
    ofBackground(0);
    
    // iterate through every line in myLines vector
    for (int i = 0; i < myLines.size(); i++){
        
        // draw the current line
        ofDrawLine(myLines[i].a,
                   myLines[i].b);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // check if space bar key is pressed
    if (key == ' '){
        // clear all the elements in vector myLines
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
