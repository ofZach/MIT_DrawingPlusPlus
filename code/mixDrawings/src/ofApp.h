#pragma once

#include "ofMain.h"

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
    
    // lineA, lineB, and mix are instances of ofPolyine
    // lineA and lineB store the two most recent lines drawn
    // mix stores the interpolation between lineA and lineB
    ofPolyline lineA;
    ofPolyline lineB;
    ofPolyline mix;
    
    // mixPct is a float that stores the interpolation percentage
    float mixPct;
    
    // sampleCount is an integer that stores the sampling count
    int sampleCount;
    
    // bDrawingA is a boolean for toggling for every new drawing
    // this allows the app to always store the latest two drawings
    bool bDrawingA;
    
};
