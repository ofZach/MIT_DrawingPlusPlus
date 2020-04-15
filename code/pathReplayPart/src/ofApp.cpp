#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bDoneDrawing = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(1);
    ofSetColor(255);
    line.draw();
    
    if (bDoneDrawing == true){
        
        float pctMe =  ofMap(fmod(ofGetElapsedTimef(), 5), 0, 5, 0, 1.2); // go from 0 to 1.2 (we will show 20%) every 5 seconds
        float pctToShow = 0.2; // show 20 pct of the lines
        
        ofPolyline newLine;
        for (int i = 0; i < 100; i++){
            float pct = ofMap(i, 0, 100, pctMe - pctToShow, pctMe);
            if (pct > 0 && pct < 1){
                newLine.addVertex(line.getPointAtPercent(pct));
            }
        }
        ofSetColor(255,0,0);
        ofSetLineWidth(3);
        newLine.draw();
        
    }
    
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

    line.addVertex(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    line.clear();
    bDoneDrawing = false;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

     bDoneDrawing = true;
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
