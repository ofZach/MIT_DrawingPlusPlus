#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // iterate 100 times
    for (int z = 0; z < 100; z++){
        
        // execute if the myLines vector is empty
        if (myLines.size() == 0){
            
            // declare a new line called tempLine
            line tempLine;
            
            // declare a new ofPoint in the middle of the canvas
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            
            // declare a variable called distance
            float distance = 100;
            
            // declare a random variable called angle
            float angle = ofRandom(0, TWO_PI);
            
            // set "a" and "b" points of the line
            // "a" is the ofPoint start
            // "b" is the result of using distance, angle from start
            tempLine.a = start;
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // add the tempLine to the end of the myLines vector
            myLines.push_back(tempLine);
        }
        // execute if the myLines vector is not empty
        else {
            
            // select a random line in the myLines vector
            int whichLine = ofRandom(0, myLines.size());
            
            // select a random percentage between 0.0 and 1.0
            float randomPct = ofRandom(0,1);
            
            // with randomPct, select a random ofPoint in whichLine
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            // calculate the vector between "b" and "a" of whichLine
            ofPoint diff = myLines[whichLine].b - myLines[whichLine].a;
            
            // retrieve the angle between "a" and "b"
            float startAngle = atan2(diff.y, diff.x);
            
            // declare a variable called distance
            float distance = 20;
            
            // declare a variable called angle, equal to startAngle
            float angle = startAngle;
            
            // add a random value to startAngle
            angle += ofRandom(-.3, .3);
            
            // declare a new line called tempLine
            line tempLine;
            
            // in tempLine "a" is the ofPoint start
            // "b" is result of using distance, angle from start
            tempLine.a = start;
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            // declare a boolean called bOk, default true
            bool bOk = true;
            
            // declare an ofPoint called inter
            ofPoint inter;
            
            // iterate through every line in the myLines vector
            for (int i = 0; i < myLines.size(); i++){
                
                // check if tempLine and the current line intersect
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    
                    // if they intersect, make bOk false and break
                    bOk = false;
                    break;
                }
            }
            // only if bOk boolean is true,
            // append tempLine to end of myLines vector
            if (  bOk ){
                myLines.push_back(tempLine);
            }
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // paint the background black
    ofBackground(0);
    
    // declare a new ofMesh
    ofMesh m;
    // set the mode of the mesh to be primitive lines
    m.setMode(OF_PRIMITIVE_LINES);
    
    // go through every element in the myLines vector
    for (int i = 0; i < myLines.size(); i++){
        
        // add the points "a" and "b" of each line as vertices
        m.addVertex(myLines[i].a);
        m.addVertex(myLines[i].b);
        
        // add white color with full opacity
        m.addColor(ofColor(255,255,255,255));
        
        // add white color with full transparency
        m.addColor(ofColor(255,255,255,0));
        
    }
    
    // draw the mesh
    m.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // check if spacebar key is pressed
    if (key == ' '){
        // clear all the elements in the myLines vector
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
