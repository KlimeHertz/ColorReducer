//
// Created by Hertz on 11/04/2023.
//

#include "ColorReductor.h"


ColorReductor::ColorReductor() {

}

void ColorReductor::ProcessForDomColor(std::vector<std::string> &LineColors) {
    for (int i = 0 ; i<LineColors.size() ; i++){
        if (auto search = mColorsCount.find(LineColors.at(i)); search != mColorsCount.end()){
            mColorsCount[LineColors.at(i)] += 1;
        } else {
            mColorsCount.insert({LineColors.at(i), 0});
        }
    }
}

std::vector<std::string> ColorReductor::ReduceColorInLine(std::vector<std::string> &LineColors ) {
    for (int i(0); i< mDomColors.size(); i++){
        for(int j(0); j< LineColors.size(); j++){
            if (mDomColors.at(i) != LineColors.at(j)){
                if (Color::IsColorInsideRadius(mDomColors.at(i),LineColors.at(j),20)){
                    LineColors.at(j) = mDomColors.at(i);
                }
            }
        }
    }

    return LineColors;
}

std::vector<std::string> ColorReductor::GetDomColors() {
    int total = ColorsSum();
    float trh = 0.5;

    for (const auto& [key, value] : mColorsCount) {
        if ((value / static_cast<float >(total)) * 100 >= trh) {
            //std::cout << (value / static_cast<float >(total)) * 100 << std::endl;
            mDomColors.push_back(key);
        }
    }

    this->ReduceDomColors();

    return mDomColors;
}

void ColorReductor::ReduceDomColors() {
    for (int i(0); i<mDomColors.size(); i++){
        for(int j(0); j <mDomColors.size(); j++){
            if (mDomColors.at(i) != mDomColors.at(j)){
                if (Color::IsColorInsideRadius(mDomColors.at(i),mDomColors.at(j),20)){
                    mDomColors.at(j) = mDomColors.at(i);
                }
            }
        }
    }
}

int ColorReductor::ColorsSum() {
    int count = 0;
    for (const auto& [key, value] : mColorsCount)
        count += value;
    return count;
}

void ColorReductor::PrintColorsArray(std::vector<std::string> &ColorArr) {
    for (const auto& color : ColorArr)
        std::cout << '[' << color << "]" << "; ";
}

bool ColorReductor::vectorContainColor(std::vector<std::string> &line , std::string &color) {

    if (std::binary_search(line.begin(),line.end(),color)){
        return true;
    } else {
        return false;
    }
}