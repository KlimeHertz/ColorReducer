//
// Created by Hertz on 11/04/2023.
//

#include "Color.h"



Color::Color(int Red, int Green, int Blue) : m_red(Red), m_green(Green), m_blue(Blue) {

}


Color Color::CreateColor(std::string colorString) {
    /* color format like 255,255,255 */
    char delim = ',';
    std::string color;
    std::vector<std::string> res;
    std::stringstream ss(colorString);
    Color nColor = Color(0,0,0);

    while (std::getline (ss, color, delim)) {
        res.push_back (color);
    }


    if (res.size() != 3) {
        //std::cout << "string is not RGB";
        return nColor;
    }

    nColor = Color(atoi(res.at(0).c_str()),atoi(res.at(1).c_str()),atoi(res.at(2).c_str()));
    return nColor;
}

void Color::PrintColorVector(std::vector<Color> colorsVector) {
    unsigned int i = 0;
    std::string colorsString;
    for (i = 0; i<= colorsVector.size() ; i ++) {
        if (colorsString.empty()){
            colorsString = colorsVector.at(i).GetColorRGB();
        }
        else {
            colorsString += ";" + colorsVector.at(i).GetColorRGB();
        }
    }

}

std::string Color::GetColorRGB() {
    return "("+std::to_string(m_red)+","+std::to_string(m_green)+","+std::to_string(m_blue)+")";
}

bool Color::IsColorInsideRadius(std::string const &center, std::string const &point , int radius) {
    Color CenterColor = Color::CreateColor(center);
    Color PointColor = Color::CreateColor(point);

    if (CenterColor == PointColor){
        return false;
    }

    int val = pow((CenterColor.m_red - PointColor.m_red),2) + pow((CenterColor.m_green - PointColor.m_green),2) + pow((CenterColor.m_blue - PointColor.m_blue),2);

    return val < pow(radius, 2);
}

bool Color::operator==(const Color &c) const {
    return this->m_red == c.m_red && this->m_green == c.m_green && this->m_blue == c.m_blue;
}
