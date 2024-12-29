#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	thread.setup();
	thread.startThread(true);

	thread1.startThread(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	thread.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	thread.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case 'f':
			ofToggleFullscreen();
		break;
	}
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
