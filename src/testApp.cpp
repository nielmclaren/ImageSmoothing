#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofEnableAlphaBlending();
	
	input.loadImage("input.png");
	input.setImageType(OF_IMAGE_GRAYSCALE);
	imageWidth = input.width;
	imageHeight = input.height;
	
	ofPixels p;
	p.setFromPixels(input.getPixels(), imageWidth, imageHeight, OF_IMAGE_GRAYSCALE);
	blur(p, 100);
	output.setFromPixels(p);
	
	mouseY = 0;
}

void testApp::update() {
}

void testApp::draw() {
	ofBackground(0);
	ofSetColor(255, 255, 255);
	input.draw(0, 0);
	output.draw(imageWidth, 0);
	
	// Horizontal selection line.
	ofSetColor(255, 0, 0);
	ofLine(0, mouseY, imageWidth, mouseY);
	ofSetColor(255);
	ofLine(imageWidth, mouseY, imageWidth, mouseY);
	
	// Draw bar chart.
	unsigned char p;
	
	// Draw white bars from output image.
	ofSetColor(255, 200);
	pixels = output.getPixels();
	for (int x = 0; x < imageWidth; x++) {
		p = pixels[mouseY * imageWidth + x];
		ofLine(x, imageHeight, x, imageHeight - p);
	}
	
	// Draw red bars from input image.
	ofSetColor(255, 0, 0, 200);
	pixels = input.getPixels();
	for (int x = 0; x < imageWidth; x++) {
		p = pixels[mouseY * imageWidth + x];
		ofLine(x, imageHeight, x, imageHeight - p);
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