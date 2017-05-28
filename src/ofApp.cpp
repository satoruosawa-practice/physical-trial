#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetFrameRate(60);
  ofBackground(0);
  
  box2d_.init();
  
  gravity_ = 10;
  box2d_.setGravity(0, gravity_);
  box2d_.createBounds();
  box2d_.setFPS(30.0);
  box2d_.registerGrabbing();
  
}

//--------------------------------------------------------------
void ofApp::update(){
  float r = 1;
  circles_.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
  circles_.back().get()->setPhysics(3.0, 0.53, 0.1);
  circles_.back().get()->setup(box2d_.getWorld(),
                               ofGetWidth() / 2,
                               ofGetHeight() / 2,
                               r);
  if (circles_.size() > 500) {
    circles_.erase(circles_.begin());
  }
  box2d_.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i = 0; i < circles_.size(); i++) {
    ofFill();
    ofSetHexColor(0x55c738);
    circles_[i].get()->draw();
  }
  ofDrawBitmapString(circles_.size(), 10, ofGetHeight() - 20);
  ofDrawBitmapString(ofGetFrameRate(), 10, ofGetHeight() - 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  
}//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  ofPoint pt = ofPoint(mouseX - ofGetWidth() / 2,
                       mouseY - ofGetHeight() / 2).getNormalized() * gravity_;
  box2d_.setGravity(pt);
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
