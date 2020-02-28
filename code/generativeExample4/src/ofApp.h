#pragma once

#include "ofMain.h"

// declaration of class line
// line has two elements: ofPoint a, and ofPoint b
class line {
    public:
        ofPoint a;
        ofPoint b;
};


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
		
        
        // mylines is the name of a vector of type line
        // syntax: vector <type> name;
        vector < line > myLines;
};
