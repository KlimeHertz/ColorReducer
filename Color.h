//
// Created by Hertz on 11/04/2023.
//

#ifndef COLORREDUCER_COLOR_H
#define COLORREDUCER_COLOR_H
#include "stdio.h"
#include <string>
#include <vector>
#include <iostream>
#include "sstream"
#include <cmath>


class Color {

public:
    Color(int Red , int Green , int Blue);
    static Color CreateColor(std::string colorString);
    static void PrintColorVector(std::vector<Color> colorsVector);
    std::string GetColorRGB ();
    static bool IsColorInsideRadius (std::string const &center , std::string const &point, int radius);
    bool operator== (const Color&) const;

private:
    int m_red;
    int m_green;
    int m_blue;
};


#endif //COLORREDUCER_COLOR_H
