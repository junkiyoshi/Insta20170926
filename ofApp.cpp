#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofNoFill();
	ofSetLineWidth(3);

	this->noise_source = ofRandom(10);

}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source += 0.05;
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float radius = 150;
	float lap = 10;
	float x, y, z;
	float noise_value;
	float noise_span = ofMap(ofNoise(this->noise_source), 0, 1, 0.0001, 0.025);
	ofColor c;
	for (int i = 0; i < lap; i++) {
		c.setHsb(255 / lap * i, 255, 255);
		ofSetColor(c);

		ofBeginShape();
		for (float deg = 0; deg <= 360; deg += 0.1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);

			noise_value = ofNoise(i, x * noise_span, y * noise_span, ofGetFrameNum() * 0.005);

			if (noise_value > 0.4) {
				z = radius * noise_value;
			}
			else {
				z = radius * 0.4;
			}

			ofVertex(ofVec3f(x, y, z));
		}

		ofEndShape(true);
	}

	this->cam.end();
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
