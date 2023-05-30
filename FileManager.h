//
// Created by Hertz on 11/04/2023.
//

#ifndef COLORREDUCER_FILEMANAGER_H
#define COLORREDUCER_FILEMANAGER_H
#include <string>
#include "ColorReductor.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "sstream"
#include <boost/algorithm/string/trim.hpp>

class ColorReductor;

class FileManager {

public:
    FileManager(std::string fileInputPath , std::string fileOutputPath);
    bool NextLineColors(std::vector<std::string> &LineColors );
    void ResetLineCount();
    void NextLineColorsReduction(ColorReductor ObjColorRed);
private:
    std::string SerializeColorsLine(std::vector<std::string> &colors);
    std::string mFileInPath;
    std::string mFileOutPath;
    int mCurrentLineNb;
    std::ifstream mFileInput;
    std::ofstream mFileOutput;
    std::vector<std::string> mFileInLines;
    bool mRestart;
    void WriteLineTofile(std::vector<std::string> &colors);
};


#endif //COLORREDUCER_FILEMANAGER_H
