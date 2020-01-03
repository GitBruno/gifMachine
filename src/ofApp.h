#pragma once

#include "ofMain.h"
#include "ofxGifEncoder.h"

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
        void onGifSaved(string & fileName);
        void exit();

        ofxGifEncoder gifEncoder;
        ofImage img;

        int gifW {ofGetWidth()};
        int gifH {ofGetHeight()};
        int framesTotal {30};
        int framesCurr {0};

        bool isRecording {true};
};
