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
	void writeEx(string a);

};
//********************ReadEx*********************//
/*
 * A class to read data from a csv file.
 */
class CSVReader
{
    std::string fileName;
    std::string delimeter;
public:
    CSVReader(std::string filename, std::string delm = ",") :
        fileName(filename), delimeter(delm)
    { }
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > readEx();
    string Time();
};