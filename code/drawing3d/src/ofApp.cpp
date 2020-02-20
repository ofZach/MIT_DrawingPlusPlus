#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // set thickness of ofPolyline
    ofSetLineWidth(3);
    
    // only add a new element to ofPolyline if mouse is pressed
    if (bMousePressed == true){
        line.addVertex( mouseX, mouseY);
    }
    
    // go through every element in ofPolyline line
    for (int i = 0; i < line.size(); i++){
        // each point is translated by (-width/2, -height/2)
         line[i] -= ofPoint( ofGetWidth()/2, ofGetHeight()/2);
    }
    
    // declare ofMatrix4x4 mat, an instance of a matrix
    ofMatrix4x4 mat;
    
    // populate ofMatrix4x4 with a rotational matrix
    // 4 arguments: angle, x, y, z
    // (1, 0, 1, 0) means rotate in 1 degree along the y axis
    // x axis is the horizontal one of the screen plane, direction: right
    // y axis is the vertical one of the screen plane, direction: downwards
    // z axis is perpendicular to screen, direction: inside of screen
    mat.makeRotationMatrix(1, 0, 1, 0);
    
    // go through every element in ofPolyline line
    for (int i = 0; i < line.size(); i++){
        // create copy of current element in ofPolyline line
        ofPoint pt = line[i];
        // use rotation matrix to rotate this point
        pt = mat * pt;
        // replace old value of element with the new rotated one
         line[i] = pt;
    }
    
    // go through every element in ofPolyline line
    for (int i = 0; i < line.size(); i++){
        // undo original translation
        // move each point by (width/2, height/2)
         line[i] += ofPoint( ofGetWidth()/2, ofGetHeight()/2);
    }
    
    // draw ofPolyline line
    line.draw();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // when mousePressed, set boolean to true
    bMousePressed = true;
    
    // delete all elements in ofPolyline line
    line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // when mouseReleased, set boolean to false
    bMousePressed = false;
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
