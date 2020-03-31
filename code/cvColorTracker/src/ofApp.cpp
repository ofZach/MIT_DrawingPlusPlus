#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    
    
#ifdef USE_LIVE
    grabber.setup(1280,720);
#else
    player.load("Movie on 3-31-20 at 11.00 AM.mov");
    player.play();
#endif
    
    
}

//--------------------------------------------------------------
void ofApp::update(){


#ifdef USE_LIVE
    grabber.update();
       
           if(grabber.isFrameNew()) {
               finder.setTargetColor(targetColor, ofxCv::TRACK_COLOR_HS);
               finder.setThreshold(100);
               finder.setSortBySize(true);
               finder.findContours(grabber);
           }
#else
        player.update();
    
        if(player.isFrameNew()) {
            finder.setTargetColor(targetColor, ofxCv::TRACK_COLOR_HS);
            finder.setThreshold(100);
            finder.setSortBySize(true);
            finder.findContours(player);
        }
#endif
    

    
   
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(255);
    
#ifdef USE_LIVE
    grabber.draw(0,0);
#else
    player.draw(0,0);
#endif
    
    ofSetLineWidth(2);
    
    //finder.draw();
    if (finder.size() > 0){
        finder.getPolyline(0).draw();
        
        myLine.addVertex(finder.getPolyline(0).getBoundingBox().getCenter());
        
    }
    myLine = myLine.getSmoothed(3);
    myLine.draw();
    
    ofSetColor(targetColor);
    ofDrawRectangle(0, 0, 64, 64);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    myLine.clear();
    
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
    
    #ifdef USE_LIVE
        targetColor = grabber.getPixels().getColor(x, y);
    #else
        targetColor = player.getPixels().getColor(x, y);
    #endif
    
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
