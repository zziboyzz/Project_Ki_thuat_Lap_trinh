#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <wx/wx.h>
class CSVReaders
{
    std::string fileName;
    std::string delimeter;
public:
    CSVReaders(std::string filename, std::string delm = ",") :
        fileName(filename), delimeter(delm)
    { }
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > readEx();
};

