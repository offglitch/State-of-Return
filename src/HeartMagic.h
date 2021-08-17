#pragma once

#include "ofMain.h"
#include "FboSource.h"

class HeartMagic : public ofx::piMapper::FboSource {

public:
	void setup();
	void update();
	void draw();
	void reset();
	void setName(string _name);

	glm::vec2 make_point(float theta);
	int startTime;
	vector<ofColor> color_list;
	ofColor color;
};
