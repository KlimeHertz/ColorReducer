//
// Created by Hertz on 11/04/2023.
//

#ifndef COLORREDUCER_COLORREDUCTOR_H
#define COLORREDUCER_COLORREDUCTOR_H
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include "Color.h"
#include "FileManager.h"

class ColorReductor {
public:
    ColorReductor();
    void ReduceColors();
    void ProcessForDomColor (std::vector<std::string> &LineColors);
    void PrintColorsArray (std::vector<std::string> &ColorArr);
    std::vector<std::string> GetDomColors ();
    std::vector<std::string> ReduceColorInLine(std::vector<std::string> &LineColors);
private:
     void ReduceDomColors();
     bool vectorContainColor(std::vector<std::string> &line , std::string &color);
     int ColorsSum();
     std::vector<std::string> mDomColors;
     std::map<std::string,int> mColorsCount;
};


#endif //COLORREDUCER_COLORREDUCTOR_H
