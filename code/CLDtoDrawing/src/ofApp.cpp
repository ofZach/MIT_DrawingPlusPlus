#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void removeIslands(ofPixels& img) {
    int w = img.getWidth(), h = img.getHeight();
    int ia1=-w-1,ia2=-w-0,ia3=-w+1,ib1=-0-1,ib3=-0+1,ic1=+w-1,ic2=+w-0,ic3=+w+1;
    unsigned char* p = img.getPixels();
    for(int y = 1; y + 1 < h; y++) {
        for(int x = 1; x + 1 < w; x++) {
            int i = y * w + x;
            if(p[i]) {
                if(!p[i+ia1]&&!p[i+ia2]&&!p[i+ia3]&&!p[i+ib1]&&!p[i+ib3]&&!p[i+ic1]&&!p[i+ic2]&&!p[i+ic3]) {
                    p[i] = 0;
                }
            }
        }
    }
}


typedef std::pair<int, int> intPair;
vector<ofPolyline> getPaths(ofPixels& img, float minGapLength = 2, int minPathLength = 0) {
    
    
    float minGapSquared = minGapLength * minGapLength;
    
    list<intPair> remaining;
    int w = img.getWidth(), h = img.getHeight();
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            if(img.getColor(x, y).getBrightness() > 128) {
                remaining.push_back(intPair(x, y));
            }
        }
    }
    
    vector<ofPolyline> paths;
    if(!remaining.empty()) {
        int x = remaining.back().first, y = remaining.back().second;
        while(!remaining.empty()) {
            int nearDistance = 0;
            list<intPair>::iterator nearIt, it;
            for(it = remaining.begin(); it != remaining.end(); it++) {
                intPair& cur = *it;
                int xd = x - cur.first, yd = y - cur.second;
                int distance = xd * xd + yd * yd;
                if(it == remaining.begin() || distance < nearDistance) {
                    nearIt = it, nearDistance = distance;
                    // break for immediate neighbors
                    if(nearDistance < 4) {
                        break;
                    }
                }
            }
            intPair& next = *nearIt;
            x = next.first, y = next.second;
            if(paths.empty()) {
                paths.push_back(ofPolyline());
            } else if(nearDistance >= minGapSquared) {
                if(paths.back().size() < minPathLength) {
                    paths.back().clear();
                } else {
                    paths.push_back(ofPolyline());
                }
            }
            paths.back().addVertex(ofPoint(x, y));
            remaining.erase(nearIt);
        }
    }
    
    return paths;
}




void ofApp::setup() {
    ofBackground(255);

	
	gui.setup();
    gui.add(doFDoG.set("doFDoG", true));
    gui.add(halfw.set("halfw", 4, 1, 8));
    gui.add(smoothPasses.set("smoothPasses", 2, 1, 4));
    gui.add(sigma1.set("sigma1", 0.68, 0.01, 2.0));
    gui.add(sigma2.set("sigma2", 6.0, 0.01, 10.0));
    gui.add(tau.set("tau", 0.974, 0.8, 1.0));
    gui.add(black.set("black", -8, -255, 255));
    gui.add(doThresh.set("doThresh", true));
    gui.add(thresh.set("thresh", 150, 0, 255));
    gui.add(doThin.set("doThin", true));
    gui.add(doCanny.set("doCanny", true));
    gui.add(cannyParam1.set("cannyParam1", 400, 0, 1024));
    gui.add(cannyParam2.set("cannyParam2", 600, 0, 1024));
    
    grabber.setup(640,480);
    
}

void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew() == true){
        input.setFromPixels(grabber.getPixels());
        input.resize(320,240);
        input.setImageType(OF_IMAGE_GRAYSCALE);
        input.update();
        
        if (output.getWidth() != input.getWidth()){
            output.setFromPixels(input.getPixels());
        }
        if (canny.getWidth() != input.getWidth()){
            canny.setFromPixels(input.getPixels());
        }
        
        if(doFDoG) {
            CLD(input, output, halfw, smoothPasses, sigma1, sigma2, tau, black);
            invert(output);
            if(doThresh) {
                threshold(output, thresh);
            }
            if(doThin) {
                thin(output);
            }
            output.update();
        }
        if(doCanny) {
            Canny(input, canny, cannyParam1 * 2, cannyParam2 * 2, 5);
            canny.update();
        }
    }
	
}

void ofApp::draw(){
    
    ofBackground(0);
    
    grabber.draw(0,0);
    
    gui.draw();
    
    
    if (input.getWidth() > 0){
        ofSetColor(80);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        input.draw(640, 0);
        ofSetColor(255);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        output.draw(640, 0);

        ofSetColor(80);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        input.draw(640, 256);
         ofSetColor(255);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        canny.draw(640, 256);
        
        ofEnableAlphaBlending();
        
        
        ofSetLineWidth(2);
        
        
         if (doFDoG){
            vector < ofPolyline > paths = getPaths(output);
            ofPushMatrix();
            ofTranslate(640+320,0);
                for (int j = 0; j < paths.size(); j++){
                    
                    
                    if (paths[j].size() > 3){
                            ofSetColor(ofRandom(255),
                                       ofRandom(255),
                                       ofRandom(255));
                        
                        paths[j] =  paths[j].getResampledBySpacing(1);
                        paths[j] =  paths[j].getSmoothed(9);
                        paths[j].draw();
                    }

                }
            ofPopMatrix();
         }
        
        if (doCanny){
            vector < ofPolyline > paths  = getPaths(canny);
            ofPushMatrix();
            ofTranslate(640+320,240);
                for (int j = 0; j < paths.size(); j++){
                    
                    
                    if (paths[j].size() > 3){
                            ofSetColor(ofRandom(255),
                                       ofRandom(255),
                                       ofRandom(255));
                        
                        paths[j] =  paths[j].getResampledBySpacing(1);
                        paths[j] =  paths[j].getSmoothed(9);
                        paths[j].draw();
                    }

                }
            ofPopMatrix();
        }
        

    }
    ofSetColor(255);
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofDrawBitmapStringHighlight("Coherent line drawing", 640, 20);
	ofDrawBitmapStringHighlight("Canny edge detection", 640, 256 + 20);
}
