#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Cycles : public ofx::piMapper::FboSource {
public:
	void setup();
	void update();
	void draw();
	void reset();
	void setName(string _name);
	void setColor(ofColor);
	ofColor col1;
	float phase;
	void arc(float phase, float radius);
	int startTime;

};