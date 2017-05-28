#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  // 画面の基本設定
  ofSetFrameRate(60);
  ofBackground(0);
  
  // Box2Dの世界の設定
  box2d_.init();               // 初期化
  box2d_.setGravity(0, 10);    // 重力
  box2d_.createBounds();       // 画面の周囲に壁を作成
  box2d_.setFPS(30.0);         // box2Dの世界でのFPS
  box2d_.registerGrabbing();   // 物体をつかめるようにする
}

//--------------------------------------------------------------
void ofApp::update(){
  box2d_.update();             // box2Dの更新
}

//--------------------------------------------------------------
void ofApp::draw(){
  // 円を描画
  for (int i = 0; i < circles_.size(); i++) {
    ofFill();
    ofSetHexColor(0xf6c738);
    circles_[i].get()->draw();
  }
  // 四角を描画
  for (int i = 0; i < boxes_.size(); i++) {
    ofFill();
    ofSetHexColor(0xBF2545);
    boxes_[i].get()->draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // cキーで円を追加
  if(key == 'c') {
    float r = ofRandom(4, 20);
    circles_.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
    circles_.back().get()->setPhysics(3.0, 0.53, 0.1);
    circles_.back().get()->setup(box2d_.getWorld(), mouseX, mouseY, r);
    
  }
  // bキーで四角を追加
  if(key == 'b') {
    float w = ofRandom(4, 20);
    float h = ofRandom(4, 20);
    boxes_.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
    boxes_.back().get()->setPhysics(3.0, 0.53, 0.1);
    boxes_.back().get()->setup(box2d_.getWorld(), mouseX, mouseY, w, h);
  }
}//--------------------------------------------------------------
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
