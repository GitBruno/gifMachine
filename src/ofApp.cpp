#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gifEncoder.setup(gifW, gifH, 0.033f, 8); // frameduration, colors = 8
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// 1. Draw everything from center
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );

        // Technique to make a perfect loop: normalize the time, then use sin()

        // normalized time (between 0.0 and 1.0)
        float t = (framesCurr % framesTotal) / static_cast<float>(framesTotal);
        // an oscillating size
        float sz = 60 + 50 * sinf(t * TWO_PI);

        ofDrawCircle(0, 0, sz);
    
    ofPopMatrix();

    // MAKE GIF
    if (isRecording) {
        // Save frame if not done yet
        if(framesCurr < framesTotal) {
            img.grabScreen(0, 0, gifW, gifH);
            gifEncoder.addFrame(img, 0.033f); // pixels + duration
        }

        // When done, save gif to disk
        if(framesCurr == framesTotal) {
            gifEncoder.save("test.gif");
            isRecording = false;
            framesCurr = -1;
        }
    } // End isRecording

    framesCurr++;

}

//--------------------------------------------------------------
void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "Keycode key pressed: " << key << endl;
    if(key == 114){
        isRecording = true;
        framesCurr = -1;
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

//--------------------------------------------------------------
void ofApp::exit() {
    gifEncoder.exit();
}
