#pragma once

#include "ofMain.h"
#include "ofUtils.h"
#include "ofxCv.h"
#include "vector.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	/** Custom blur method that ignores values below the given threshold. */
	void threshBlur(unsigned char* src, unsigned char* dst, int w, int h, int radius, int threshold);
	
	ofImage input;
	ofImage output;
	int imageWidth, imageHeight;
	unsigned char* pixels;
	int mouseY;
};
