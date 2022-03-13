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

void writeAnswer(ofstream& cout, vector<string> vecString, string Head) {
    cout << Head;
    for (auto value: vecString)  
        cout << ", " << value.substr(value.rfind(":") + 1, value.size() - value.rfind(":") + 1);
    cout << "\n";
    return;
}

int main() {
    string fileCppName = "gentest";
    system((fileCppName + ".exe").c_str());
    ofstream out (((string)"answer.csv").c_str());
    vector<string> qsC, msC, hsC, inT, qsT, msT, hsT;
    for (int iTest = iFirst; iTest <= iLast; iTest++) {
        string inputFile = "./OUTPUT/" + intToString(iTest) + ".OUT";
        //cout << "/OUTPUT/" + intToString(iTest) + ".OUT\n";
        ifstream inp (inputFile.c_str());
        string quickSortCheck; getline(inp, quickSortCheck);
        string mergeSortCheck; getline(inp, mergeSortCheck);
        string heapSortCheck; getline(inp, heapSortCheck);

        string inputTime; getline(inp, inputTime);

        string quickSortTime; getline(inp, quickSortTime);
        string mergeSortTime; getline(inp, mergeSortTime);
        string heapSortTime; getline(inp, heapSortTime);

        qsC.push_back(quickSortCheck);
        msC.push_back(mergeSortCheck);
        hsC.push_back(heapSortCheck);

        inT.push_back(inputTime);

        qsT.push_back(quickSortTime);
        msT.push_back(mergeSortTime);
        hsT.push_back(heapSortTime);

        inp.close();
    }
    for (int i = iFirst; i <= iLast; i++)
        out << ", Test " << intToString(i);
    out << "\n";

    writeAnswer(out, inT, "Read Input");
    writeAnswer(out, qsC, "Quick Sort Check");
    writeAnswer(out, qsT, "Quick Sort Time");
    writeAnswer(out, msC, "Merge Sort Check");
    writeAnswer(out, msT, "Merge Sort Time");
    writeAnswer(out, hsC, "Heap Sort Check");
    writeAnswer(out, hsT, "Heap Sort Time");

    out.close();
}