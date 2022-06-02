#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main(void){
    ifstream fin("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/c++/input.txt");
    ofstream fout("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/c++/output.txt");
    string buf;

    while (fin >> buf){
        fout << buf << endl;
    }

    fout.close();
    fin.close();
    
}