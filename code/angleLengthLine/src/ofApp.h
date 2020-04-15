#pragma once

#include "ofMain.h"
//add .h file with class angleLengthLine
#include "angleLengthLine.h"

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
		
    // declare ofPolyline line
    ofPolyline line;
    
    // declare vector alines of type angleLengthLine
    vector < angleLengthLine > alines;
    
};
