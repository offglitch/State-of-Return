#include "HeartMagic.h"

void HeartMagic::setup() {
	//ofSetFrameRate(60);
	//startTime = ofGetElapsedTimeMillis();
	//ofBackground(0);
	name = "Magic Heart FBO Source";
	allocate(720, 720);
	this->beginFbo();
	//ofClear(255, 0, 0);
	ofSetLineWidth(2);
	ofSetColor(255);
	ofSetFrameRate(60);
	this->endFbo();

	//ofSetColor(255);

	//ofSetLineWidth(2);
}

void HeartMagic::setName(string _name)
{
	name = _name;
}

void HeartMagic::reset()
{
	startTime = ofGetElapsedTimeMillis();
}



//--------------------------------------------------------------
void HeartMagic::update() {
	//ofSeedRandom(39);

}

//--------------------------------------------------------------
void HeartMagic::draw() {

	ofClear(0);
	ofPushMatrix();
	ofPushStyle();

	ofTranslate(fbo->getWidth() / 2, fbo->getHeight() / 2);


	if (ofGetElapsedTimeMillis() - startTime < 30000) {
		for (auto scale = 1; scale < 2; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {

				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}

				if (deg == param % 360) {

					ofFill();
					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

			//ofNoFill();
			//ofBeginShape();
			//ofVertices(vertices);
			//ofEndShape();
		}
	}
	else if (ofGetElapsedTimeMillis() - startTime < 60000) {
		for (auto scale = 1; scale < 3; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {
				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				if (deg == param % 360) {

					ofFill();
					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

			//ofNoFill();
			//ofBeginShape();
			//ofVertices(vertices);
			//ofEndShape();
		}
	}


	else if (ofGetElapsedTimeMillis() - startTime < 90000) {
		for (auto scale = 1; scale < 16; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {
				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				if (deg == param % 360) {

					ofFill();
					ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));

					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

			//ofNoFill();
			//ofBeginShape();
			//ofVertices(vertices);
			//ofEndShape();
		}
	}
	else if (ofGetElapsedTimeMillis() - startTime < 100000) {
		for (auto scale = 1; scale < 20; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {
				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				if (deg == param % 360) {

					ofFill();
					ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));

					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

			//ofNoFill();
			//ofBeginShape();
			//ofVertices(vertices);
			//ofEndShape();
		}

	}

	else if (ofGetElapsedTimeMillis() - startTime < 110000) {
		for (auto scale = 1; scale < 20; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {
				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				if (deg == param % 360) {

					ofFill();
					ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

			ofNoFill();

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();
		}

	}

	else if (ofGetElapsedTimeMillis() - startTime < 170000) {
		for (auto scale = 1; scale < 2; scale += 1) {

			vector<glm::vec2> vertices;
			auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
			for (auto deg = 0; deg < 360; deg += 1) {
				if (param < 360) {

					if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				else {

					if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
				}
				if (deg == param % 360) {

					ofFill();
					ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
					ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 4);
				}
			}

		}

	}
	ofPopStyle();
	ofPopMatrix();

}


glm::vec2 HeartMagic::make_point(float theta) {

	float x = 16 * (pow(sin(theta), 3));
	float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
	return glm::vec2(x, -y);
}
