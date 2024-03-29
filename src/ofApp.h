#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

#include <vector>
#include <cmath>
#include <chrono>

class Circle {
public:
    Circle(float x_, float y_, float radius_, ofColor color_, int expectedAmount_) : x(x_), y(y_), radius(radius_), color(color_), expectedAmount(expectedAmount_) {}

    float x;
    float y;
    float radius;
    ofColor color;
    int expectedAmount;
    int currentAmount = 0;

    void drawCircle(int amountOfPeople);
};

class ofApp : public ofBaseApp {
public:

    void setup();
    void update();
    void draw();
    void exit();

    void drawPointCloud();

    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void writeToFile(int score);
    int ofApp::getHighScoreFromFile();

    void drawKinectImages();
    void updateCircles();
    void updateKinect();
    void updateContours();
    void drawCircles();
    std::vector<float> findBlobs(int i);
    bool isPointInCircle(double x, double y, double x_center, double y_center, double radius);
    void setupNewRound();

    //fonts
    ofTrueTypeFont font;
    ofTrueTypeFont headerFont;

    //sounds
    ofSoundPlayer correct;
    ofSoundPlayer incorrect;
    ofSoundPlayer background;
    ofSoundPlayer outro;


    //circles
    vector<Circle> circles;


    ofxKinect kinect;


    ofxCvColorImage colorImg;

    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image

    ofxCvContourFinder contourFinder;

    bool bThreshWithOpenCV;
    bool bDrawPointCloud;

    int nearThreshold;
    int farThreshold;

    int angle;

    // used for viewing the point cloud
    ofEasyCam easyCam;

};
