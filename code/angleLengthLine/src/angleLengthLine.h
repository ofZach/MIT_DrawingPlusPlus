#pragma once

#include "ofMain.h"

// class definition of angleLengthLine
class angleLengthLine {

public:
    
    // startPoint is an attribute (variable) of the class
    // startPoint stores the starting point of the line
    ofPoint startPoint;
    
    // angles, angleDiffs, and distances are attributes (variables)
    // they are vectors of type float
    // we consider an ofPolyline to be made out of many consecutive straight lines
    // angles stores the absolute value of the angle of each line
    // angleDiffs stores the difference of angles between consecutive lines
    // distances stores the length of each line
    vector < float > angles;
    vector < float > angleDiffs;
    vector < float > distances;
    
    // startTime is an attribute (variable) of the class
    // startTime stores the moment in time when the line was created
    float startTime;
    
    // convertFrom is a method (function) of the class
    // its input is a ofPolyline
    // it calculates the values of the angles, angleDiffs, distances vectors
    void convertFrom(ofPolyline & line){
        
        // check if the line can be drawn
        // a line can be drawn if it has more than two vertices
        if (line.getVertices().size() > 2){
            
            // store current time in startTime
            startTime = ofGetElapsedTimef();
            
            // clear the three vectors
            angles.clear();
            angleDiffs.clear();
            distances.clear();
            
            // reset startPoint to be the 0th vertex of line
            startPoint = line.getVertices()[0];
            
            // go through all vertices of the line, except the last one
            for (int i = 0; i < line.getVertices().size()-1; i++){
                
                // store on ofPoint diff thhe result of next - current vertex
                ofPoint diff = line.getVertices()[i+1] - line.getVertices()[i];
                
                // store on float angle the arctan of ofPoint diff
                // atan2(y, x) returns the angle between (x, y) and positive x axis
                // atan2() returns a value between -PI and PI
                float angle = atan2(diff.y, diff.x);
                
                // store on float dist the distance between diff and (0, 0)
                float dist = diff.length();
                
                // append float angle to the end of the vector angles
                angles.push_back(angle);
                
                // append float dist to the end of the vector distances
                distances.push_back(dist);
                
                // for the 0th vertex, append 0 to the end of angleDiffs vector
                if (i == 0){
                    angleDiffs.push_back(0);
                }
                // for all other vertices
                else {
                    // calculate the difference between current and previous angle
                    float diffAngle = angles[i] - angles[i-1];
                    
                    // if diffAngle is not on the range -PI, PI, wrap around
                    if (diffAngle < -PI) {
                        diffAngle += TWO_PI;
                    }
                    else if (diffAngle > PI) {
                        diffAngle -= TWO_PI;
                    }
                    
                    // add diffAngle to the end of vector angleDiffs
                    angleDiffs.push_back(diffAngle);
                }
            }
        }
    }
    
    // draw() is a method (function) of the class
    void draw(){
        
        // do not draw the fill of figures, only stroke
        ofNoFill();
        
        // begin a new shape specified by veritces
        ofBeginShape();
        
        // declare ofPoint pt and copy its value from startPoint
        ofPoint pt = startPoint;
        
        // add pt as the 0th vertex of the shaoe
        ofVertex(pt.x, pt.y);
        
        // declare initial angle, default value is 0
        float angle = 0;
        
        // iterate through all elements in the angles vector
        for (int i = 0; i < angles.size(); i++){
            
            // for the 0th vertex, retrieve the 0th value in angles
            if (i == 0){
                angle = angles[0];
            }
            // for all other vertices after the 0th
            else {
                // update angle by adding to itself the value angleDiffs[i]  * cos(x)
                // where x is 0.5 * the time elapsed since startTime
                // we cos(x) because when the line begins to be drawn, x=0 => cos(x)=1
                // so at the beginning of times, the line is drawn as is
                // the line oscillates between original state and straight when cos(x)=0
                angle += angleDiffs[i] * cos( 0.5* (ofGetElapsedTimef() - startTime));
            }
            
            // update pt by adding distances[i] at the angle
            pt.x += cos(angle) * distances[i];
            pt.y += sin(angle) * distances[i];
            
            // add the vertex to the shape
            ofVertex(pt.x, pt.y);
        }
        
        // after all vertices are added, end the shape
        ofEndShape();
    }
    
};
