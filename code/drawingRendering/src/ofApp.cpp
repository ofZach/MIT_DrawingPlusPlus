#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // bOOo opengl line is wack
    //ofSetLineWidth(10);
    
    if (line.size() > 1){
        
        float time = ofGetElapsedTimef();
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        for (int i = 0; i < line.size(); i++){
            int i_m_1 = i-1;
            int i_p_1 = i+1;
            if (i_m_1 < 0) i_m_1 = 0;
            if (i_p_1 == line.size()) i_p_1 = line.size()-1;
            
            ofPoint prev = line[i_m_1];
            ofPoint next = line[i_p_1];
            ofPoint diff = next - prev;
            ofPoint normal = diff.getNormalized().rotate(90, ofPoint(0,0,1));
//            ofLine(line[i] - normal * 10,
//                   line[i] + normal * 10);
            mesh.addVertex(line[i] - normal * 10);
            mesh.addVertex(line[i] + normal * 10);
            float pct = sin(i*0.1 + time);
            float pct2 = sin(i*0.14 + time*0.3);
            mesh.addColor(ofColor(127 + 127 * pct));
            mesh.addColor(ofColor(127 + 127 * pct2));
            
            //ofDrawCircle(line[i], 2);
        }
        mesh.draw();
    }
    
    //line.draw();
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

    line.addVertex(x,y);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
    
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
