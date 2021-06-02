#include "RandWExcel.h"
CSVWriter::CSVWriter() {
}
CSVWriter::~CSVWriter() {
}
void CSVWriter::writeEx(string a) {
    // current date/time based on current system
    time_t now = time(0);
    tm* ltm = gmtime(&now);
    // convert now to string form
    std::stringstream ss1;
    ss1 << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year;
    std::string ts1 = ss1.str();
    //
	ofstream MyExcelFile2;
	MyExcelFile2.open("C:\\Users\\Quan\\Documents\\C++\\WXform\\lttcdt\\Excels\\" + ts1 + ".csv", ios::app);
    std::stringstream ss2;
    ss2 << "sec: " << ltm->tm_sec << " min: " << ltm->tm_min << " hour: " << ltm->tm_hour + 7 ;
    std::string ts2 = ss2.str();
	MyExcelFile2 << ts2 << "," << a << endl;
	MyExcelFile2.close();
}
/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
string CSVReader::Time() {
    // current date/time based on current system
    time_t now = time(0);
    tm* ltm = gmtime(&now);
    // convert now to string form
    std::stringstream ss;
    ss << ltm->tm_mday << "-" << 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year;
    std::string ts = ss.str();
    return ts;
}
std::vector<std::vector<std::string> > CSVReader::readEx()
{
    std::ifstream file("C:\\Users\\Quan\\Documents\\C++\\WXform\\lttcdt\\Excels\\" + fileName + ".csv", ios::in);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        //boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        std::string word = "";
        stringstream s(line);
        while (getline(s, word, ',')){
            // add all the column data
            // of a row to a vector
            vec.push_back(word);
        }
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}