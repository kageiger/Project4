/**
 * Personality.cpp
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 4
 *
 * <#description#>
 */


#include <iostream>

#include "Personality.h"

void Personality::reset(){
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++){
        points[i] = DEFAULT_POINTS;
    }
}

Personality::Personality(){
    
    reset();
}

//Changes the value of the personality based on user's answers

void Personality::adjustPersonality(Attribute& inAttribute){
    
    Attribute getIndex;
    
    // add inAttribute to points
    //inAttribute = MAX_NUM_ATTRIBUTES
    // if negative points cause < Min_Points set = to Min_Points
    //if > MAX_POINTS set = to MAX_POINTs
    
    points[inAttribute.getIndex()] += inAttribute.getPoints();
    
    if(points[inAttribute.getIndex()] < MIN_POINTS){
        
        points[inAttribute.getIndex()] = MIN_POINTS;
    }
    if(points[inAttribute.getIndex()] > MAX_POINTS){
        
        points[inAttribute.getIndex()] = MAX_POINTS;
    }
   
    
}
// TODO: implement reset, constructor, adjustPersonality

//personality.p;
//p.write(cout):

void Personality::write(ostream &outs) {
    
    cout << "Your EECS Harmony Personality Profile" << endl;
    for(int i = 0; i < MAX_NUM_ATTRIBUTES; i++){
        outs << ATTRIBUTE_NAMES[i]<< ": "<< points[i] << endl;
    }
}
