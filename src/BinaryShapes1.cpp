#include "BinaryShapes1.h"

void BinaryShapes1::setup()
{
	name = "Binary Shape FBO Source";

	// Allocate our FBO source, decide how big it should be
	allocate(600, 600);
	a = 24;
	b = 11;
	maxFrameCount = 130;
	ofNoFill();
	space = 25;


}

void BinaryShapes1::update()
{

}

void BinaryShapes1::draw()
{
	//ofClear(0);

	//drawWall(0, 0, fbo->getWidth(), fbo->getHeight());
	drawGeoShape(a, b, maxFrameCount, space);
}

void BinaryShapes1::reset()
{
	startTime = ofGetElapsedTimeMillis();
	//ofClear(0);

}

void BinaryShapes1::setName(string _name)
{
	name = _name;
}

void BinaryShapes1::setColor(ofColor c)
{
	rectColor = c;

}

void BinaryShapes1::drawWall(int x, int y, int w, int h)
{
	ofPushMatrix();
	ofTranslate(x, y);
	int numX = 20;
	int numY = 20;
	int sizeX = w / numX;
	int sizeY = h / numY;
	int startX = sizeX / 2;
	int startY = sizeY / 2;

	for (int x = 0; x < numX; x++) {
		for (int y = 0; y < numY; y++) {
			float phase = ofGetFrameNum();
			float locX = startX + x * sizeX;
			float locY = startY + y * sizeY;
			float phaseDiff = ofMap(ofDist(locX, locY, w / 2, h / 2), 0, w / 2, 0, 180);
			drawTile(locX, locY, sizeX, phase + phaseDiff);
		}
	}
	ofPopMatrix();
}

void BinaryShapes1::drawTile(int x, int y, int size, float p)
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	float height = ofMap(abs(sin(ofDegToRad(p))), 0, 1, 5, size - 5);
	float width = height;
	ofColor c = ofColor(0);
	c.setHsb(int(p) % 255, 255, 255);
	ofSetColor(c);
	ofDrawRectangle(x, y, width, height);
}

void BinaryShapes1::drawGeoShape(int a, int b, int maxFrameCount, int space)
{
	ofClear(0);
	ofBackground(0);
	ofPushMatrix();
	ofTranslate(fbo->getWidth() / 2, fbo->getHeight() / 2);

	t = (float)ofGetFrameNum() / maxFrameCount;
	theta = TWO_PI * t;

	for (float x = -250; x <= 250; x += 100) {
		for (float y = -250; y <= 250; y += 100) {

			float offSet = (x * a) + (y * b);
			float sz1 = ofMap(sin(-theta + offSet), 0, 1, space, 0);
			float sz2 = ofMap(cos(-theta + offSet), 0, 1, 0, -space);

			ofColor initialwhite = ofRandom(230, 255);
			ofColor purple = ofColor::peachPuff;
			ofColor blue = ofColor::lightSkyBlue;
			ofColor green = ofColor::lightSeaGreen;

			if (ofGetElapsedTimeMillis() - startTime < 30000) {
				//ofColor c = initialwhite.getLerped(blue, offSet);
				ofSetColor(purple);
			}
			else if (ofGetElapsedTimeMillis() - startTime < 45000) {
				ofSetColor(blue);
			}
			else if (ofGetElapsedTimeMillis() - startTime < 60000) {
				ofSetColor(green);
			}
			else if (ofGetElapsedTimeMillis() - startTime < 90000) {
				ofSetColor(blue);
			}
			else if (ofGetElapsedTimeMillis() - startTime < 110000) {
				ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
			}
			else if (ofGetElapsedTimeMillis() - startTime < 150000) {
				ofSetColor(initialwhite);
			}
			else if (ofGetElapsedTimeMillis() - startTime < 2000000) {
				ofSetColor(initialwhite);
			}



			//ofSetColor(50, 30, 90);
			ofSetLineWidth(3);
			shape(x, y, sz1, sz2);
		}
	}

	ofPopMatrix();
}

void BinaryShapes1::shape(float xPos, float yPos, float pOne, float pTwo)
{
	ofPushMatrix();
	ofTranslate(xPos, yPos);

	ofBeginShape();
	ofVertex(-pOne, -pOne);
	ofVertex(-pOne, -pTwo);
	ofVertex(pOne, -pTwo);
	ofVertex(pOne, -pOne);
	ofVertex(pTwo, -pOne);
	ofVertex(pTwo, pOne);
	ofVertex(pOne, pOne);
	ofVertex(pOne, pTwo);
	ofVertex(-pOne, pTwo);
	ofVertex(-pOne, pOne);
	ofVertex(-pTwo, pOne);
	ofVertex(-pTwo, -pOne);
	ofEndShape(true);


	ofPopMatrix();
}