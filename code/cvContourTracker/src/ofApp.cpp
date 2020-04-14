#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup dimensions of camera input
    cam.setup(640, 480);
    
    // imitate(ofImage x, ofImage y) is part of ofxCv
    // it makes x have the same size and type as y
    // we use it to make background have same properties as cam
    ofxCv::imitate(background, cam);
    // and then to make diff have same properties as cam
    ofxCv::imitate(diff, cam);
    
    // setup the contour finder
    // make the finder sort the blobs by size
    finder.setSortBySize(true);
    // set the minimum threshold for the finder
    finder.setThreshold(10);
    
    // setup the width of the line stroke
    ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // we update the camera feed
    cam.update();
    
    // we check if there is a new frame
    if(cam.isFrameNew()) {
        
        // absdiff(ofImage x, ofImage y, ofImagez)
        // calculate the absolute difference between x and y
        // and assigns it to z
        ofxCv::absdiff(cam, background, diff);
        
        // when we do an ofxCv operation on an image,
        // we have to update it
        // this operation happens on the graphics card
        diff.update();
        
        // find the contours on the ofImage diff
        finder.findContours(diff);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw cam on the upper left corner
    cam.draw(0, 0);
    
    // draw background on the upper right corner
    background.draw(640,0);
    
    // draw diff on the lower left corner
    diff.draw(0,480);
    
    // check if there are any contours detected
    if (finder.size() > 0){
        
        // retrieve the first polyLine in the contour finder
        // since they are sorted by size, it its the largest
        finder.getPolyline(0).draw();
        
        // copy the largest line on another auxiliary one
        ofPolyline line = finder.getPolyline(0);
        
        // declare an ofPoint called top
        // initial position is lower left corner of cam image
        ofPoint top(0,cam.getHeight());
        
        // go through every point in the largest line
        for (int i = 0; i < line.size(); i++){
            // if any of these points has a smaller y
            // than top.y, update top.y to this value
            // with this, we find the upper point in the line
            if (line[i].y < top.y){
                top = line[i];
            }
        }
        
        // set drawing color to red
        ofSetColor(255,0,0);
        
        // draw a red circle on the position of ofPoint top
        ofDrawCircle(top, 10);
        
        // add the position of top to the ofPolyline myLine
        myLine.addVertex(top);
        
        // draw the ofPolyline myLine
        myLine.draw();
        
        // set the drawing color to white
        ofSetColor(255);
    }
    
    // save the current drawing matrix to memory
    ofPushMatrix();
    
    // translate the origin of the coordinate system
    ofTranslate(640, 480);
    
    // draw the contourFinder on the lower left corner
    finder.draw();
    
    // restore the previous drawing matrix from memory
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // check if the key pressed is space
    if (key == ' '){
        // copy the content from cam to background
        ofxCv::copy(cam, background);
        // update the ofImage we did an ofxCv operation on
        background.update();
    }
    
    // check if the key pressed is the letter l
    if (key == 'l'){
        // clear the ofPolyline myLine
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
