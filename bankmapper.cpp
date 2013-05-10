/* 
 * File:   bankmapper.cpp
 * Author: damien
 * 
 * 
 */

#include "bankmapper.h"

bankmapper::bankmapper() {
}

bankmapper::bankmapper(const bankmapper& orig) {
}

bankmapper::~bankmapper() {
}

void bankmapper::init(char* address, char* name, int bidentry){
    this->address = address;
    this->name = name;
    this->bid = bidentry;
}