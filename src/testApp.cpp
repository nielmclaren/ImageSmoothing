#include "testApp.h"

void testApp::setup() {
	image.loadImage("input.png");
	image.setImageType(OF_IMAGE_GRAYSCALE);
	
	mouseY = 0;
}

void testApp::update() {
}

void testApp::draw() {
	ofBackground(0);
	ofSetColor(255, 255, 255);
	image.draw(0, 0);
	
	ofSetColor(255, 0, 0);
	ofLine(0, mouseY, image.width, mouseY);
	
	unsigned char p;
	pixels = image.getPixels();
	for (int x = 0; x < image.width; x++) {
		p = pixels[mouseY * image.width + x];
		ofLine(x, image.height, x, image.height - p);
	}
}

void testApp::keyPressed(int key) {
}

void testApp::keyReleased(int key) {
}

void testApp::mouseMoved(int x, int y) {
	mouseY = y;
}

void testApp::mouseDragged(int x, int y, int button) {
}

void testApp::mousePressed(int x, int y, int button) {
}

void testApp::mouseReleased(int x, int y, int button) {
}

void testApp::windowResized(int w, int h) {
}

void testApp::gotMessage(ofMessage msg) {
}

void testApp::dragEvent(ofDragInfo dragInfo) {
}