#include "Cycles.h"

void Cycles::setup()
{
	name = "Cycles FBO Source";

	// Allocate our FBO source, decide how big it should be
	allocate(250, 250);

	this->beginFbo();
	//ofSetFrameRate(60);
	//col1 = ofColor(0);
	phase = 0;
	this->endFbo();

	//ofSetFrameRate(60);

	//ofSetLineWidth(3);



}

void Cycles::update()
{
	phase += 1;
}

void Cycles::draw()
{
	ofClear(0);
	int numOfLines = 32;
	float spacing = 14; // spacing between arcs

	for (int i = 0; i < numOfLines; i++)
	{
		int position = phase + spacing * i;
		float phaseDiff = 360 / numOfLines;
		arc(phase + phaseDiff * i, spacing + spacing * i);
	}
}

void Cycles::reset()
{
	//ofClear(0);
	startTime = ofGetElapsedTimeMillis();

}

void Cycles::setName(string _name)
{
	name = _name;
}


void Cycles::arc(float phase, float radius)
{
	//ofClear(0);
	ofPushMatrix();
	ofTranslate(fbo->getWidth() / 2, fbo->getHeight() / 2);

	ofPath path;
	float startAngle = ofMap(sin(ofDegToRad(phase / 2)), -1, 1, 179, 0);
	float endAngle = ofMap(sin(ofDegToRad(phase / 2)), -1, 1, -179, 0);
	path.arc(0, 0, radius, radius, phase + startAngle, phase + endAngle);
	path.setCircleResolution(100);
	path.setStrokeWidth(4);
	path.setFilled(false);

	ofColor initialwhite = ofRandom(230, 255);
	ofColor purple = ofColor::peachPuff;
	ofColor blue = ofColor::lightSkyBlue;
	ofColor green = ofColor::lightSeaGreen;
	ofColor chaos;
	chaos.r = ofRandom(0, 255);
	chaos.g = ofRandom(0, 255);
	chaos.b = ofRandom(0, 255);
	//ofSetColor(chaos);
	if (ofGetElapsedTimeMillis() - startTime < 30000) {
		float percent = ofMap(endAngle, startAngle, 160, 0, 1, true);
		ofColor c = purple.getLerped(blue, percent);
		path.setColor(c);
	}
	else if (ofGetElapsedTimeMillis() - startTime < 45000) {
		float percent = ofMap(endAngle, startAngle, 80, 0, 1, true);
		ofColor c = green.getLerped(blue, percent);
		path.setColor(c);
	}
	else if (ofGetElapsedTimeMillis() - startTime < 60000) {
		float percent = ofMap(endAngle, startAngle, 80, 1, 0, true);
		ofColor c = green.getLerped(blue, percent);
		path.setColor(c);
	}
	else if (ofGetElapsedTimeMillis() - startTime < 90000) {
		float percent = ofMap(endAngle, startAngle, 60, 0, 1, true);
		ofColor c = chaos.getLerped(green, percent);
		path.setColor(c);
	}
	else if (ofGetElapsedTimeMillis() - startTime < 110000) {
		float percent = ofMap(endAngle, startAngle, 40, 1, 0, true);
		ofColor c = chaos.getLerped(blue, percent);
		path.setColor(c);
	}




	path.draw();
	ofPopMatrix();
}