#include <bits/stdc++.h>

using namespace std;

const string TASKNAME = "SORT";  //ten bai`

typedef long long ll;
typedef pair<int, int> ptq;

const int iFirst = 1;
const int iLast = 10;

template<typename Numeric, typename Generator = std::mt19937>
Numeric random(Numeric from, Numeric to)
{
    thread_local static Generator gen(std::random_device{}());

    using dist_type = typename std::conditional
    <
        std::is_integral<Numeric>::value
        , std::uniform_int_distribution<Numeric>
        , std::uniform_real_distribution<Numeric>
    >::type;

    thread_local static dist_type dist;

    return dist(gen, typename dist_type::param_type{from, to});
}

string intToString(int x)
{
    stringstream ss;
    ss << x;
    string st; ss >> st;
    if (x < 10) st = "0" + st;
    if (x == 0) st = "00";
    return st;
}


void MakeTest(ofstream& cout, int iTest)  // ham sinh test
{
    vector<double> a;
    const int N = 1000000;
    const long long maxN = 1000000000;
    cout << N << "\n";
    for (int i = 0; i <= N; ++i)
        a.push_back(random<double>(-maxN,maxN));
    if (iTest == 1)
        sort(a.begin(), a.end());
    if (iTest == 2)
        sort(a.rbegin(), a.rend());
    for (auto value:a)
        cout << setprecision(9) << fixed << value << " ";
}

int main()
{
    srand(time(NULL));

    system(((string)"mkdir INPUT").c_str()); // create INP forder 
    system(((string)"mkdir OUTPUT").c_str()); // creata OUT forder

    string inputForder = "INPUT";
    string outputForder = "OUTPUT";
    for(int iTest = iFirst; iTest <= iLast; iTest++)
    {
        //string testForder = TASKNAME + "\\Test" + intToString(iTest); //ten folder SUM\\Test
    
        string inputFile = TASKNAME + ".INP";
        string outputFile = TASKNAME + ".OUT";
        //system(("mkdir " + testForder).c_str());
        ofstream inp (inputFile.c_str());

        MakeTest(inp, iTest);
        inp.close();
        
        system(((string)"sorting.exe").c_str());  // bat buoc phai co file (TASKNAME + ".exe") thi chuong trinh moi chay duoc
        
        string newinputFile = intToString(iTest) + ".INP";
        string newoutputFile = intToString(iTest) + ".OUT";
        system(("rename " + inputFile + " " + newinputFile).c_str());
        system(("rename " + outputFile + " " + newoutputFile).c_str());

        system(("move /y " + newinputFile + " " + inputForder).c_str());
        system(("move /y " + newoutputFile + " " + outputForder).c_str());
    }
}