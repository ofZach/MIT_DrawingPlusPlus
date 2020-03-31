#pragma once

#include "ofMain.h"
#include "ofxCv.h"


//#define USE_LIVE


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
        
#ifdef USE_LIVE
        ofVideoGrabber grabber;
#else
        ofVideoPlayer player;
#endif
        ofxCv::ContourFinder finder;
        ofColor targetColor;
    
        ofPolyline myLine;
    
};
