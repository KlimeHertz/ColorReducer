//
// Created by Hertz on 11/04/2023.
//

#include "FileManager.h"

FileManager::FileManager(std::string fileInputPath, std::string fileOutputPath): mFileInPath(fileInputPath) , mFileOutPath(fileOutputPath) {
    mCurrentLineNb = 0;
    mFileInput.open(fileInputPath);
    mFileOutput.open(fileOutputPath);
    std::string tempLine;
    mRestart = false;

    if (!mFileInput.is_open()) std::cout << "File input is not Open" << std::endl;
    if (!mFileOutput.is_open()) std::cout << "File output is not Open" << std::endl;

    while (std::getline(mFileInput,tempLine)){
        boost::algorithm::trim(tempLine);
        if ( tempLine != ""){
            mFileInLines.push_back(tempLine);
        }
    }

}

bool FileManager::NextLineColors(std::vector<std::string> &LineColors) {
    if (!mFileInput.is_open()) return false;
    if (mCurrentLineNb > mFileInLines.size() - 1) return false;
    else {
        std::string currentLine = mFileInLines.at(mCurrentLineNb);
        char delim = ';';
        std::stringstream ss(currentLine);
        std::string color;

        while (std::getline (ss, color, delim)) {
            LineColors.push_back (color);
        }

        mCurrentLineNb++;
        return true;
    }
}

void FileManager::NextLineColorsReduction(ColorReductor ObjColorRed) {
    std::vector<std::string> LineColors;
    if (!mFileInput.is_open()) return;
    mCurrentLineNb = 0;

    while (mCurrentLineNb <= mFileInLines.size() - 1){
        LineColors.clear();
        std::string currentLine = mFileInLines.at(mCurrentLineNb);
        char delim = ';';
        std::stringstream ss(currentLine);
        std::string color;

        while (std::getline (ss, color, delim)) {
            LineColors.push_back (color);
        }

        auto ReducedColorsVector = ObjColorRed.ReduceColorInLine(LineColors);
        //ObjColorRed.PrintColorsArray(ReducedColorsVector);
        std::cout << "input vect size : " << LineColors.size() << " output vector size : " << ReducedColorsVector.size() << std::endl;
        WriteLineTofile(ReducedColorsVector);
        mCurrentLineNb++;
    }
}

std::string FileManager::SerializeColorsLine(std::vector<std::string> &colors) {
    std::string str;
    for (auto c : colors) str = str + c + ";";

    return str;
}

void FileManager::WriteLineTofile(std::vector<std::string> &colors) {
    std::string newline = SerializeColorsLine(colors);
    mFileOutput << newline << std::endl;
}

void FileManager::ResetLineCount() {
    mCurrentLineNb = 0;
    mRestart = true;
}
