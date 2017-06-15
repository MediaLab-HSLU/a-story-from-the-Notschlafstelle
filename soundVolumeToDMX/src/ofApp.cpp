#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    audioTrack.load("burhan-teil1.wav");
    audioTrack.setVolume(1.);
    audioTrack.setLoop(true);
    audioTrack.play();
    fftSmoothed = ofSoundGetSpectrum(128);
    
    // the fft needs to be smoothed out, so we create an array of floats
    // for that purpose:
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    nBandsToGet = 128;
    
    
    //DMX
    //open the device
    dmx.connect(0);
    
    ////////////////
    chan1 = 0;
    chan2 = 0;
    chan3 = 0;
    chan4 = 0;
    ////////////////
    
    fftSmoothed[0] =0;
}

//--------------------------------------------------------------
void ofApp::update(){
    // update the sound playing system:
    ofSoundUpdate();
    
    // (5) grab the fft, and put in into a "smoothed" array,
    //		by taking maximums, as peaks and then smoothing downward
    float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed calue sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw the fft resutls:
    ofSetColor(255,255,255,255);
    
    float width = (float)(5*128) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
        ofDrawRectangle(100+i*width,ofGetHeight()-100,width,-(fftSmoothed[i] * 200));
    }
    cout<<fftSmoothed[0]<<endl;
    //DMX
    ////////////////
    chan1 = 0;
    chan2 = 0;
    chan3 = 0;
    chan4 = 0;
    ////////////////
    
    
    float audioLight = ofMap(fftSmoothed[0], 0.0, 0.5, 0.0, 255.0, true);
   
    
    if(audioLight<=255){
        //asign our colors to the right dmx channels
        chan1 = int(audioLight);
        chan2 = int(audioLight);
        chan3 = int(audioLight);
        chan4 = int(audioLight);
    }
    
    dmx.setLevel(1, chan1);
    dmx.setLevel(2, chan2);
    dmx.setLevel(3, chan3);
    dmx.setLevel(4, chan4);
    dmx.update();
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
