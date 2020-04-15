#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // boolean bDrawingA defaults to true
    // the next line drawn by the user will be stored in lineA
    bDrawingA = true;
    
    // int sampleCount is 100 vertices per line
    sampleCount = 100;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // render both lines drawn by the user
    lineA.draw();
    lineB.draw();
    
    // update the interpolation percentage
    // the percentage varies sinusoidally over time
    // its range is 0.0 to 1.0
    mixPct = sin(ofGetElapsedTimef()) * 0.5 + 0.5;
    
    // check if both lines by the user have more than two vertices
    if (lineA.size() > 2 &&
        lineB.size() > 2 ){
        
        // resample lineA and store it in ofPolyline resampleA
        ofPolyline resampleA = lineA.getResampledByCount(sampleCount);
        
        
        // sometimes the resampled ofPolyline has less vertices
        // maybe it is a bug on the implementation of getResampledByCount()
        // if this happens, copy the last vertex and add it to the end
        // in this example we want 100 points in resampledA
        // if we get less, we copy the last one, and paste at the end
        while (resampleA.size() < sampleCount){ resampleA.addVertex(resampleA.getVertices()[ resampleA.size()-1]);
        }
        
        // repeat the same operations for corresponding lineB and resampleB
        ofPolyline resampleB = lineB.getResampledByCount(sampleCount);
        
        while (resampleB.size() < sampleCount){ resampleB.addVertex(resampleB.getVertices()[ resampleB.size()-1]);
        }
        
        // clear all the vertices in ofPolyline mix
        mix.clear();
        
        // iterate as many points as sampleCount
        for (int i = 0; i < sampleCount; i++){
            // with mixPct, go through vertices in resampleA and resampleB
            // interpolate between them, and add vertex to ofPolyline mnix
            mix.addVertex(  (1-mixPct) * resampleA[i] +
                          (mixPct) * resampleB[i] );
            
        }
        
        // render on screen the mix ofPolyline
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
    
    // check if bDrawingA is true
    if (bDrawingA){
        // add the current mouse position as a vertex to lineA
        lineA.addVertex(ofPoint(x,y));
    }
    // in other case, bDrawingA is false
    else {
        // add the current mouse position as a vertex to lineB
        lineB.addVertex(ofPoint(x,y));
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // check if bDrawingA is true
    if (bDrawingA){
        // clear all the vertices in ofPolyline lineA
        lineA.clear();
        // add the current mouse position as a vertex to lineA
        lineA.addVertex(ofPoint(x,y));
        
    }
    // in other case, bDrawingA is false
    else {
        // clear all the vertices in ofPolyline lineB
        lineB.clear();
        // add the current mouse position as a vertex to lineB
        lineB.addVertex(ofPoint(x,y));
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // every time the mouse is released, toggle bDrawingA
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
