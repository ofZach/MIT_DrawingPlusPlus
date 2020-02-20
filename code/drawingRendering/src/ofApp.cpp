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
    ofSetLineWidth(10);
    
    // if there is more than one element in ofPolyline line
    if (line.size() > 1){
        
        // retrieve time since app was executed
        float time = ofGetElapsedTimef();
        
        // declare mesh and set its mode to triangle strip
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        // go through every element in line
        for (int i = 0; i < line.size(); i++){
            // retrieve index of previous element (i-1)
            int i_m_1 = i - 1;
            // retrieve index of next element (i + 1)
            int i_p_1 = i + 1;
            
            // border condition
            // 0th element does not have previous element
            if (i_m_1 < 0) {
                i_m_1 = 0;
            }
            
            // border condition
            // last element does not have next element
            if (i_p_1 == line.size()) {
                i_p_1 = line.size() - 1;
            }
                
            // retrieve previous and next points
            ofPoint prev = line[i_m_1];
            ofPoint next = line[i_p_1];
            
            // calculate difference between next and previous points
            ofPoint diff = next - prev;
            
            // calculate normal to diff
            // first normalize magnitude of diff with getNormalized()
            // then rotate this vector 90 degrees in z axis
            ofPoint normal = diff.getNormalized().rotate(90, ofPoint(0,0,1));
            
            // add new vertices to mesh by using the normal
            mesh.addVertex(line[i] - normal * 10);
            mesh.addVertex(line[i] + normal * 10);
            
            // create percentages that are dependend on time and element i
            float pct1 = sin(i*0.1 + time);
            float pct2 = sin(i*0.14 + time*0.3);
            
            // add two new colors to mesh
            mesh.addColor(ofColor(127 + 127 * pct1));
            mesh.addColor(ofColor(127 + 127 * pct2));
        }
        // draw the mesh
        mesh.draw();
    }
    
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
    
    // when mouseDragged, add new element to ofPolyline line
    line.addVertex(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // when mousePressed, clear all elements in ofPolyline line
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
