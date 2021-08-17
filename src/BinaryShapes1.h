#pragma once

#include "ofMain.h"
#include "FboSource.h"

class BinaryShapes1 : public ofx::piMapper::FboSource {
public:
	void setup();
	void update();
	void draw();
	void reset();
	void setName(string _name);

};