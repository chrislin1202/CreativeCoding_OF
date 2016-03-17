//
//  Tree.cpp
//  recursiveTreeObject
//
//  Created by  Christine on 2/24/16.
//
//

#include "Tree.hpp"


void Tree::seed1(float dotSize, float angle, float x, float y){
    ofSetColor(255, 0, 0);
    ofFill();
    //nested if statement
    if(dotSize >1.0f){
        float r = ofRandomuf();
        
        //first if statement will happen 98% of time
        if(r > 0.02f){
            ofDrawCircle(x,y,dotSize);
            float newX = x + cos(angle) * dotSize;
            float newY = y + sin(angle) * dotSize;
            seed1(dotSize * 0.99f, angle + angleOffSetA, newX, newY);
        } else {
            ofDrawCircle(x, y, dotSize);
            float newX = x + cos(angle);
            float newY = y + sin(angle);
            seed1(dotSize* 0.99f, angle + angleOffSetA, newX, newY);
            seed2(dotSize* 0.6f, angle + angleOffSetB, newX, newY);
            seed1(dotSize* 0.5f, angle - angleOffSetB, newX, newY);
        }
    }
}


void Tree::seed2(float dotSize, float angle, float x, float y){
    ofSetColor(0, 0, 255);
    ofFill();
    if(dotSize >1.0f){
        float r = ofRandomuf();
        if(r > 0.05f){
            ofDrawCircle(x,y,dotSize);
            float newX = x + cos(angle) * dotSize;
            float newY = y + sin(angle) * dotSize;
            seed2(dotSize*0.99f, angle + angleOffSetA, newX, newY);
        } else {
            ofDrawCircle(x, y, dotSize);
            float newX = x + cos(angle);
            float newY = y + sin(angle);
            seed2(dotSize*0.99f, angle - angleOffSetA, newX, newY);
            seed1(dotSize*0.6f, angle + angleOffSetB, newX, newY);
            seed2(dotSize*0.5f, angle - angleOffSetB, newX, newY);
        }
    }
}