/**
 * Answer.cpp
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 4
 *
 * <#description#>
 */

#include "Answer.h"

Answer::Answer() {
    
    attribute = Attribute();
    text = "";
}

Attribute Answer::getAttribute() {
    
    return attribute;
}

void Answer::setAttribute(Attribute &inAttribute){
    
    attribute = inAttribute;
    
}

string Answer::getText(){
    
    return text;
}

void Answer::setText(string inText){
    
    text = inText;
}
// TODO: getAttribute, setAttribute, getText, setText


void Answer::read(istream &ins) {
    
    attribute.read(ins);
    getline(ins, text);
}


void Answer::write(ostream &outs) {
    
    outs << text;
}
