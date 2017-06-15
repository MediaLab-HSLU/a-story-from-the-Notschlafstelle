#pragma once

#include "ofMain.h"
#include "ofxDmx.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofSoundPlayer audioTrack;
    float * fftSmoothed;
    int nBandsToGet;
    
    //DMX::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ofxDmx dmx;
    int level;
    
    ofParameter<int> chan1;
    ofParameter<int> chan2;
    ofParameter<int> chan3;
    ofParameter<int> chan4;
    ofParameter<bool> autoCycle;
};
