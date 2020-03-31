#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    tracker.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    if (grabber.isFrameNew()){
        tracker.update(grabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    grabber.draw(0,0);
    //tracker.drawDebug();
    if(tracker.size() > 0){
       ofPolyline leftEye =  tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
        leftEye.draw();
        
        leftTrail.addVertex(leftEye.getBoundingBox().getCenter());
        
        
        ofPolyline rightEye =  tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        rightEye.draw();
        
        rightTrail.addVertex(rightEye.getBoundingBox().getCenter());
        
       
    }
    
    
    ofSetColor(0,255,0);
    leftTrail.draw();
    ofSetColor(255,0,0);
    rightTrail.draw();
    ofSetColor(255);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
