#pragma once

#include "ofMain.h"


class timePoint {
  
    public:
        float x;
        float y;
        float t;
};

//--------------------------------------------------
class timePointRecorder {

	public: 
	
		void setup();
		void clear();
		void draw();
	
		void		startDrawing(float x, float y);
		void		addPoint (float x, float y);
		void		endDrawing();
		
		ofPoint		getPositionForTime( float time);
		ofPoint		getVelocityForTime( float time);
		
		bool		bHaveADrawing();
		float		getDuration();
	
		vector < timePoint >	pts;
		float					startTime;
		bool					bRecording;
	
	
};

