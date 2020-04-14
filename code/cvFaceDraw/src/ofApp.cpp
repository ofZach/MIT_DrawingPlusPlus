#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup the size of grabber
    grabber.setup(640,480);
    
    // setup the face tracker
    tracker.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update the grabber image
    grabber.update();
    
    // if the frame is a new one
    if (grabber.isFrameNew()){
        // pass the new image on grabber to the face tracker
        tracker.update(grabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the image on grabber on the upper left corner
    grabber.draw(0,0);
    
    // drawDebug() performs a detailed drawing of the faces
    // uncomment the next line to try it
    // tracker.drawDebug();
    
    // check if the face tracker detects any faces
    if(tracker.size() > 0){
        
        // leftEye is an instance of ofPolyline
        // leftEye stores the left eye landmark of the 0th face
        ofPolyline leftEye =  tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
        
        // draw the ofPolyline leftEye
        leftEye.draw();
        
        // retrieve the center of the bounding box of leftEye
        // and append this vertex to the ofPolyline leftTrail
        // in order to story its history over time
        leftTrail.addVertex(leftEye.getBoundingBox().getCenter());
        
        // execute the same behavior for ofPolyline rightEye and rightTrail
        ofPolyline rightEye =  tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        
        rightEye.draw();
        
        rightTrail.addVertex(rightEye.getBoundingBox().getCenter());
    }
    
    // set green drawing color
    ofSetColor(0,255,0);
    // draw the green left trail
    leftTrail.draw();
    
    // set red drawing color
    ofSetColor(255,0,0);
    // draw the red right trail
    rightTrail.draw();
    
    // set white drawing color at the end of the draw() function
    // openFrameworks remembers only the latest drawing color
    // next time draw() is executed, drawing will be white
    // in this app in particular, this is used for drawing both eyes
    ofSetColor(255);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // if any key is pressed, clear trails of both eyes
    leftTrail.clear();
    rightTrail.clear();
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
