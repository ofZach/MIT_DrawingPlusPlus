#pragma once

#include "ofMain.h"
// add ofxFaceTracker2.h
#include "ofxFaceTracker2.h"

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
    
    // grabber is an instance of ofVideoGrabber
    ofVideoGrabber grabber;
    
    // tracker is an instance of ofxFaceTracker2
    ofxFaceTracker2 tracker;
    
    // leftTrail is an instance of ofPolyline
    ofPolyline leftTrail;
    
    // rightTrail is an instance of ofPolyline
    ofPolyline rightTrail;
		
};
