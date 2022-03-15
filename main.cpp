#include <bits/stdc++.h>
using namespace std;

const int iFirst = 1;
const int iLast = 10;

string intToString(int x)
{
    stringstream ss;
    ss << x;
    string st; ss >> st;
    if (x < 10) st = "0" + st;
    if (x == 0) st = "00";
    return st;
}

int main() { 
    string fileCppName = "gentest";
    system((fileCppName + ".exe").c_str());
    ofstream cout (((string)"answer.csv").c_str());

    cout << ", Read Input Time";
    cout << ", Quick Sort Ckeck, Quick Sort Time, Merge Sort Check, Merge Sort Time";
    cout << ", Heap Sort Check, Heap Sort Time, C++ Sort Check, C++ Sort Time\n";
    // Column of CSV File

    for (int iTest = iFirst; iTest <= iLast; iTest++) {
        string inputFile = "./OUTPUT/" + intToString(iTest) + ".OUT";
        //cout << "/OUTPUT/" + intToString(iTest) + ".OUT\n";
        cout << "Test " << intToString(iTest);  
        ifstream inp (inputFile.c_str());
        string quickSortCheck; getline(inp, quickSortCheck);
        string mergeSortCheck; getline(inp, mergeSortCheck);
        string heapSortCheck; getline(inp, heapSortCheck);
        string cplusplusSortCheck; getline(inp, cplusplusSortCheck);

        string inputTime; getline(inp, inputTime);

        string quickSortTime; getline(inp, quickSortTime);
        string mergeSortTime; getline(inp, mergeSortTime);
        string heapSortTime; getline(inp, heapSortTime);
        string cplusplusSortTime; getline(inp, cplusplusSortTime);

        string a[9] = {inputTime, quickSortCheck, quickSortTime, mergeSortCheck, mergeSortTime
                        , heapSortCheck, heapSortTime, cplusplusSortCheck, cplusplusSortTime};
        for (auto value:a)
            cout << ", " << value.substr(value.rfind(":") + 1, value.size() - value.rfind(":") + 1);
        cout << "\n";
        inp.close();
    }
    cout.close();
}