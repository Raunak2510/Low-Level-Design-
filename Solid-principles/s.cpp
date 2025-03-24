#include <bits/stdc++.h>
//#include<fstram>

using namespace std;

// S- single responsibilty principles
// you have only one reason to change code in the class 

// in report class I have 2 reason to change code 
// 1. generate report , 2. save file  it mean it violate single responsibilty principles
class Report1{
    public: 
    void generateReport(){
        cout<<"report generate"<<endl;
    }

    void saveFile(const std:: string& fileName){
        std:: ofstream file(fileName);
        file<<"resport data"<<endl;
        file.close();
    }
};

// good code :- 

class Report {
public:
    void generateReport() {
        std::cout << "Generating Report..." << std::endl;
    }
};

class ReportSaver {
public:
    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        file << "Report data...";
        file.close();
    }
};


int main(){
    Report report;
    report.generateReport();
}