#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofEnableAlphaBlending();
	
	input.loadImage("input.png");
	input.setImageType(OF_IMAGE_GRAYSCALE);
	imageWidth = input.width;
	imageHeight = input.height;
	
	unsigned char* tmp = new unsigned char[imageWidth * imageHeight];
	unsigned char* tmp2 = new unsigned char[imageWidth * imageHeight];
	
	output.allocate(imageWidth, imageHeight, OF_IMAGE_GRAYSCALE);
	
	unsigned char* inPixels = input.getPixels();
	unsigned char* outPixels = output.getPixels();
	threshBlur(inPixels, tmp, imageWidth, imageHeight, 30, 1);
	threshBlur(tmp, outPixels, imageWidth, imageHeight, 30, -1);
	
	ofPixels tmpOfp, outOfp;
	tmpOfp.setFromPixels(outPixels, imageWidth, imageHeight, OF_IMAGE_GRAYSCALE);
	outOfp.allocate(imageWidth, imageHeight, OF_IMAGE_GRAYSCALE);
	normalize(tmpOfp, outOfp);
	
	output.setFromPixels(outOfp);
	
	mouseY = 0;
	
	delete[] tmp;
	delete[] tmp2;
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
	ofLine(imageWidth, mouseY, 2 * imageWidth, mouseY);
	
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
	mouseY = MAX(0, MIN(imageHeight - 1, y));
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

void testApp::threshBlur(unsigned char* src, unsigned char* dst, int w, int h, int r, int t) {
	int x, y, kx, ky, p, f, sum, count;
	unsigned char* tmp = new unsigned char[w * h];
	
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			
			sum = 0;
			count = 0;
			for (kx = -r; kx <= r; kx++) {
				p = src[y * w + max(0, min(w - 1, x + kx))];
				f = r + 1 - abs(kx);
				sum += p * f;
				if (p > t) count += f;
			}
			
			tmp[y * w + x] = count > 0 ? sum / count : 0;
		}
	}
	
	
	for (x = 0; x < w; x++) {
		for (y = 0; y < h; y++) {
			
			sum = 0;
			count = 0;
			for (ky = -r; ky <= r; ky++) {
				p = tmp[max(0, min(h - 1, y + ky)) * w + x];
				f = r + 1 - abs(ky);
				sum += p * f;
				if (p > t) count += f;
			}
			
			dst[y * w + x] = count > 0 ? sum / count : 0;
		}
	}
	
	delete[] tmp;
}











