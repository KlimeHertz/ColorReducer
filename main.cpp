#include <iostream>
#include "Color.h"
#include "FileManager.h"
#include "ColorReductor.h"

int main() {
/*
    Color c = Color(255,255,255);
    std::cout << c.GetColorRGB() << std::endl;
    Color nC = Color::CreateColor("120,52,30");
    std::cout << nC.GetColorRGB();

    std::string c1 = "255,255,255";
    std::string c2 = "249,249,249";
    if (Color::CompareColorsRadius(c1,c2,20)) {
        std::cout << "the color is inside "<< std::endl;
    } else {
        std::cout << "the color is not inside "<< std::endl;
    }
    return 0;*/
    std::vector<std::string> color;
    FileManager fm = FileManager("C:/Users/Hertz/CLionProjects/ColorReducer/colors.txt","C:/Users/Hertz/CLionProjects/ColorReducer/imageout.txt");
    ColorReductor cr = ColorReductor();
    while (fm.NextLineColors(color)){
        cr.ProcessForDomColor(color);
        color.clear();
    }
    auto mDomColors = cr.GetDomColors();

    fm.ResetLineCount();
    color.clear();

    fm.NextLineColorsReduction(cr);
/*
    while (fm.NextLineColors(color)){
        cr.ReduceColorInLine(color,fm);
        color.clear();
    }*/

}
