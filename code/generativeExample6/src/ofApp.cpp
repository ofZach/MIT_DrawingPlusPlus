#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int z = 0; z < 100; z++){
    
        if (myLines.size() == 0){
        
            line tempLine;
            ofPoint start = ofPoint(ofGetWidth()/2,
                                    ofGetHeight()/2);
            float distance = 100;
            float angle = ofRandom(0, TWO_PI);
            
            tempLine.a = start;
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            myLines.push_back(tempLine);
        } else {
            
            //
            int whichLine = ofRandom(0, myLines.size());
            //float randomPct = 0.9; //ofRandom(0,1);
            float randomPct = ofRandom(0,1);
            ofPoint start = myLines[whichLine].a * (1-randomPct) +
                            myLines[whichLine].b * randomPct;
            
            ofPoint diff = myLines[whichLine].b - myLines[whichLine].a;
            float startAngle = atan2(diff.y, diff.x);
            
            float distance = 20;
            float angle = startAngle;
            angle += ofRandom(-.3, .3);
            
            line tempLine;
            tempLine.a = start;
            tempLine.b = start + distance * ofPoint(cos(angle),
                                                    sin(angle));
            
            bool bOk = true;
            ofPoint inter;
            for (int i = 0; i < myLines.size(); i++){
                if ( ofLineSegmentIntersection(tempLine.a, tempLine.b, myLines[i].a, myLines[i].b, inter)){
                    //tempLine.b = inter;
                    bOk = false;  // :(
                    break;
                }
            }
            if (  bOk ){
                myLines.push_back(tempLine);
            }
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    //ofSetLineWidth(2);
    
    ofMesh m;
    m.setMode(OF_PRIMITIVE_LINES);
    for (int i = 0; i < myLines.size(); i++){
//        ofDrawLine(myLines[i].a,
//                   myLines[i].b);
        m.addVertex(myLines[i].a);
        m.addVertex(myLines[i].b);
        m.addColor(ofColor(255,255,255,255));

        m.addColor(ofColor(255,255,255,0));
        
    }
    m.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
