
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    nodeA.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    nodeB.setParent(nodeA);
    nodeB.setPosition(200,0,0);
    nodeC.setParent(nodeB);
    nodeC.setPosition(100,0,0);
    
   
    speedA = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    speedB = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    
    
    speedASmooth = 0;
    speedBSmooth = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if (ofRandom(0,1) > 0.95){
        speedA = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    }
    if (ofRandom(0,1) > 0.95){
        speedB = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
    }
    
    speedASmooth = 0.97 * speedASmooth + 0.03 * speedA;
    speedBSmooth = 0.97 * speedBSmooth + 0.03 * speedB;
    
    
  
    nodeA.rotateDeg(speedASmooth, ofPoint(0,0,1));
    nodeB.rotateDeg(speedBSmooth, ofPoint(0,0,1));
    
    
    nodeA.draw();
    nodeB.draw();
    nodeC.draw();
    ofLine(nodeA.getGlobalPosition(),
           nodeB.getGlobalPosition());
    
    ofLine(nodeB.getGlobalPosition(),
           nodeC.getGlobalPosition());
    
    if (myLine.size() > 1000){
        myLine.getVertices().erase(myLine.getVertices().begin());
    }
    
    for (int i = 0; i < myLine.size(); i++){
        myLine[i].x -= 1;
    }
    
    myLine.addVertex(nodeC.getGlobalPosition());
    myLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        speedA = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
        speedB = ofRandom(2,4) * (ofRandom(0,1) > 0.5 ? -1 : 1);
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
