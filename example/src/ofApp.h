#pragma once

#include "ofMain.h"
#include "ofxNVDA.h"

struct Button {
	ofRectangle rect;
	ofColor color, hoverColor;
	bool bHover = false;
	std::string name;
	std::string text;
};

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed( int key );
	void keyReleased( int key );
	void mouseMoved( int x, int y );
	void mouseDragged( int x, int y, int button );
	void mousePressed( int x, int y, int button );
	void mouseReleased( int x, int y, int button );
	void mouseEntered( int x, int y );
	void mouseExited( int x, int y );
	void windowResized( int w, int h );
	void dragEvent( ofDragInfo dragInfo );
	void gotMessage( ofMessage msg );

	Button button1, button2;
};
