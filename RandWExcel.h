#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;
class CSVWriter
{
public:
    CSVWriter();
	~CSVWriter();
	void writeEx(string a, string * path);
    void writeText(string fileName, string* path, string Note);
    void writeAllDays(string* fileDir);

};
//********************ReadEx*********************//
/*
 * A class to read data from a csv file.
 */
class CSVReader
{
    std::string fileName;
    std::string delimeter;
    std::string* fileDir;

public:
    CSVReader();
        
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > readEx(string filename, string* filePath);
    std::vector<std::string> readText(string fileName, string* fileDir);
    std::vector<std::string> readAllDays(string* fileDir);
    string Time();
};