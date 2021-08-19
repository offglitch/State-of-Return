#pragma once

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "VideoSource.h"
#include "ScanlineSource.h"
#include "SceneManager.h"
#include "BouncingBallsSource.h"
#include "MovingRectSource.h"
#include "HeartMagic.h"
#include "Cycles.h"
#include "BinaryShapes1.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);

    ofxPiMapper piMapper;

    // By using a custom source that is derived from FboSource
    // you will be able to see the source listed in sources editor
    ScanlineSource customSource;
    BouncingBallsSource bouncingBallsSource;
    MovingRectSource movingRectSource;
    HeartMagic heartMagicSource;
    Cycles cyclesSource;
    BinaryShapes1 binarySource;
    ofImage dummyObjects;
    
    SceneManager sceneManager;
};
