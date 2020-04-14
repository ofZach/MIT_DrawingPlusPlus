#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    particleA.bFixed = true;
    
    particleA.pos.set(100,100);
    particleB.pos.set(200,100);
    particleC.pos.set(300,100);
    
    
    connector.springiness = 0.15;
    connector.distance = 0;
    connector.particleA = &particleA;
    connector.particleB = &particleB;
    
    connector2.springiness = 0.05;
    connector2.distance = 0;
    connector2.particleA = &particleB;
    connector2.particleB = &particleC;
}

//--------------------------------------------------------------
void ofApp::update(){

    particleA.pos.set(mouseX, mouseY);
    
    
    particleB.resetForce();
    connector.update();
    particleB.addDampingForce();
    particleB.update();
    
    particleC.resetForce();
    connector2.update();
    particleC.addDampingForce();
    particleC.update();
    
    
    
    if (ofGetMousePressed())
    temp.addVertex( (ofPoint)particleC.pos);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor(10,10,10), ofColor(0,0,0) );
    
    particleA.draw();
    particleB.draw();
    particleC.draw();
    
    ofDrawLine(particleA.pos,
               particleB.pos);
    
    ofDrawLine(particleB.pos,
               particleC.pos);
    
    if (temp.getVertices().size() > 500){
        temp.getVertices().erase(temp.getVertices().begin());
    }
    
    ofEnableAlphaBlending();
    //temp.draw();
    
    ofMesh m;
    m.setMode(OF_PRIMITIVE_LINE_STRIP);
    for (int i = 0; i < temp.getVertices().size(); i++){
        float pct = ofMap(i, 0, temp.getVertices().size()-1, 0,1);
        m.addColor(ofColor(pct*255));
        m.addVertex( ofPoint(temp.getVertices()[i].x, temp.getVertices()[i].y));
    }
    m.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    temp.clear();
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
