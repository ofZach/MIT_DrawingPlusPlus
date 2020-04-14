#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bDrawingA = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    lineA.draw();
    lineB.draw();
    mixPct = sin(ofGetElapsedTimef()) * 0.5 + 0.5;
    
    if (lineA.size() > 2 &&
        lineB.size() > 2 ){
        
        
        ofPolyline resampleA = lineA.getResampledByCount(100);
        
        
        while (resampleA.size() < 100){ resampleA.addVertex(resampleA.getVertices()[ resampleA.size()-1]);
        }
        
        ofPolyline resampleB = lineB.getResampledByCount(100);
        
        while (resampleB.size() < 100){ resampleB.addVertex(resampleB.getVertices()[ resampleB.size()-1]);
        }
        
        mix.clear();
        for (int i = 0; i < 100; i++){
            mix.addVertex(  (1-mixPct) * resampleA[i] +
                          (mixPct) * resampleB[i] );
            
        }
        
        mix.draw();
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

    if (bDrawingA){
        lineA.addVertex(ofPoint(x,y));
    } else {
        lineB.addVertex(ofPoint(x,y));
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if (bDrawingA){
        lineA.clear();
        lineA.addVertex(ofPoint(x,y));
    } else {
        lineB.clear();
        lineB.addVertex(ofPoint(x,y));
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    bDrawingA = !bDrawingA;
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
