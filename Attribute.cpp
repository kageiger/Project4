/**
 * Attribute.cpp
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 4
 *
 * <#description#>
 */

#include "Attribute.h"

//Sets index and points to 0
Attribute::Attribute() {
    
    index = 0;
    points = 0;
    
}

// gets the value(index) into range so it doesnt go out of bound
int Attribute::getValueWithinRange(int value) {
    
    
    if(value >= 0 && value < MAX_NUM_ATTRIBUTES){
        
        return value;
    }
    
    if(value > (MAX_NUM_ATTRIBUTES - 1)) {
        return (MAX_NUM_ATTRIBUTES - 1);
    }else{
        
        value = 0;
    
    }
    return value;
}


// After checking validity, sets Index and Points
Attribute::Attribute(int inIndex, int inPoints) {
    
    inIndex = getValueWithinRange(inIndex);
    index =  inIndex;
    points = inPoints;
}


// returns the index
int Attribute::getIndex()  {
    
    return index;
}


// returns the amount of points
int Attribute::getPoints()  {
  
    return points;
}


// gets inIndex within range and then sets index equal to inIndex
void Attribute::setIndex(int inIndex) {
    inIndex = getValueWithinRange(inIndex);
    index = inIndex;
}

//sets points equal to inPoints
void Attribute::setPoints(int inPoints) {
    
    points = inPoints;
}


// reads in index and points and then checks the validity of index
void Attribute::read(istream &ins) {
    
    
    ins >> index;
    ins >> points;
    setIndex(index);
}

//writes out the index and points
void Attribute::write(ostream &outs)  {
    
    outs << index;
    outs << points;
    
}
