#pragma once

#include "ofMain.h"
#include "FboSource.h"

class BinaryShapes1 : public ofx::piMapper::FboSource {
public:
public:
	void setup();
	void update();
	void draw();
	void reset();
	void setName(string _name);
	int startTime;
	void setColor(ofColor);
	ofColor rectColor;
	float t;
	float theta;
	float numb;
	int maxFrameCount;
	float space;

	int a, b;
	/*
	std::vector<ofRectangle> rects;
	std::vector<float> rectSpeeds;
	*/
	void drawWall(int x, int y, int w, int h);
	void drawTile(int x, int y, int size, float p);

	void shape(float xPos, float yPos, float pOne, float pTwo);
	void drawGeoShape(int a, int b, int maxFrameCount, int space);

};