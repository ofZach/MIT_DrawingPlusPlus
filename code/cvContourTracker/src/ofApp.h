#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // ofVideograbber for the camera input
    ofVideoGrabber cam;
    
    // ofImage for storing the background image
    ofImage background;
    
    // ofImage for storing the difference between background and image
    ofImage diff;
    
    // ContourFinder from the ofxCv addon
    ofxCv::ContourFinder finder;
    
    // ofPolyline for drawing
    ofPolyline myLine;
		
};
