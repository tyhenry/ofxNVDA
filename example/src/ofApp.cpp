#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground( 0 );

	button1.name       = "button 1";
	button1.color      = ofColor::blue;
	button1.hoverColor = ofColor::darkBlue;
	button1.text       = "I am the\nfirst button";
	button1.rect       = ofRectangle( 200, 200, 200, 100 );

	button2.name       = "button 2";
	button2.color      = ofColor::red;
	button2.hoverColor = ofColor::darkRed;
	button2.text       = "I am the\nsecond button";
	button2.rect       = ofRectangle( ofGetWidth() - 400, 200, 200, 100 );
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{

	if ( ofxNVDA::isNVDARunning() ) {
		ofDrawBitmapStringHighlight( "NVDA is running", { 20, 20 } );

	} else {
		ofDrawBitmapStringHighlight( "NVDA is not running!", { 20, 20 } );
	}

	ofPushStyle();
	ofSetColor( button1.bHover ? button1.color : button1.hoverColor );
	ofDrawRectangle( button1.rect );
	ofDrawBitmapStringHighlight( button1.text, button1.rect.position + glm::vec2( 20, 20 ) );
	ofPopStyle();

	ofPushStyle();
	ofSetColor( button2.bHover ? button2.color : button2.hoverColor );
	ofDrawRectangle( button2.rect );
	ofDrawBitmapStringHighlight( button2.text, button2.rect.position + glm::vec2( 20, 20 ) );
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed( int key )
{
}

//--------------------------------------------------------------
void ofApp::keyReleased( int key )
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved( int x, int y )
{

	if ( button1.rect.inside( x, y ) ) {
		if ( !button1.bHover ) {
			ofxNVDA::cancelSpeech();
			ofxNVDA::speakText( "hovered button 1" );
			button1.bHover = true;
		}
	} else {
		button1.bHover = false;
	}

	if ( button2.rect.inside( x, y ) ) {
		if ( !button2.bHover ) {
			ofxNVDA::cancelSpeech();
			ofxNVDA::speakText( "hovered button 1" );
			button2.bHover = true;
		}
	} else {
		button2.bHover = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged( int x, int y, int button )
{
}

//--------------------------------------------------------------
void ofApp::mousePressed( int x, int y, int button )
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased( int x, int y, int button )
{
	if ( button1.rect.inside( x, y ) ) {
		ofxNVDA::cancelSpeech();
		ofxNVDA::speakText( button1.text );
	}

	if ( button2.rect.inside( x, y ) ) {
		ofxNVDA::cancelSpeech();
		ofxNVDA::speakText( button2.text );
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered( int x, int y )
{
}

//--------------------------------------------------------------
void ofApp::mouseExited( int x, int y )
{
}

//--------------------------------------------------------------
void ofApp::windowResized( int w, int h )
{
}

//--------------------------------------------------------------
void ofApp::gotMessage( ofMessage msg )
{
}

//--------------------------------------------------------------
void ofApp::dragEvent( ofDragInfo dragInfo )
{
}
