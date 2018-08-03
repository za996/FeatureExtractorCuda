//
// Created by simo on 11/07/18.
//

#include <iostream>
#include "AggregatedGrayPair.h"

AggregatedGrayPair::AggregatedGrayPair(unsigned int i){
    grayLevel = i;
}

void AggregatedGrayPair::printPair() const {
    std::cout << "k: "<< grayLevel;
}

/* Extracting pairs */
int AggregatedGrayPair::getAggregatedGrayLevel() const{
    return grayLevel;
}

