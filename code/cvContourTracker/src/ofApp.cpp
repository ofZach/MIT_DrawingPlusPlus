#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(640, 480);
    
    // imitate() will set up bg and diff
    // so they have the same size and type as cam
    ofxCv::imitate(background, cam);
    ofxCv::imitate(diff, cam);
}

//--------------------------------------------------------------
void ofApp::update(){

    cam.update();
    if(cam.isFrameNew()) {
       ofxCv::absdiff(cam, background, diff);
       diff.update();
        finder.setSortBySize(true);
       finder.setThreshold(10 );
       finder.findContours(diff);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.draw(0, 0);
    background.draw(640,0);
    diff.draw(0,480);
    
    ofSetLineWidth(3);
    if (finder.size() > 0){
        finder.getPolyline(0).draw();
        
        ofPolyline line = finder.getPolyline(0);
        ofPoint top(0,cam.getHeight());
        for (int i = 0; i < line.size(); i++){
            if (line[i].y < top.y){
                top = line[i];
            }
        }
        ofSetColor(255,0,0);
        ofDrawCircle(top, 10);
        myLine.addVertex(top);
        myLine.draw();
        ofSetColor(255);
        
        
    }
    
    
    
    
    
    ofPushMatrix();
    ofTranslate(640, 480);
    finder.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        ofxCv::copy(cam, background);
        background.update();
    }
    
    if (key == 'l'){
        myLine.clear();
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
