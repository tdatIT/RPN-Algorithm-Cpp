#include <fstream>
#include <iostream>
#include <string>


const std::string FILE_IN = "input.txt";

std::string readLine()
{
    // create instance file stream
    std::fstream fs;
    fs.open(FILE_IN, std::ios::in);
 
    // Readline
    std::string _data;
    std::getline(fs, _data);
    fs.close();
    return _data;
}
