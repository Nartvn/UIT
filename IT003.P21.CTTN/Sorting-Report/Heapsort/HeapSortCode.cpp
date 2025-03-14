#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector < int > endtime;
vector < int > vi;

int SNC(string x)
{
    bool ok = 0;
    if (x[0] == '-') ok = 1;
    else x = ' ' + x;
    int num = 0;
    for (int i = 1 ; i < (int)x.size() ; ++i)
        num = num * 10 + (int)(x[i] - '0');
    if (ok) num = -num;
    return num;
}

void heapify(int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && vi[l] > vi[largest])
        largest = l;
    if (r < n && vi[r] > vi[largest])
        largest = r;
    if (largest != i) {
        swap(vi[i], vi[largest]);
        heapify(n, largest);
    }
}

void heapSort(){
    int n = vi.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(vi[0], vi[i]);
        heapify(i, 0);
    }
}

void Get(int number)
{
    string name = "test";
    name = name + (char)(number + '0');
    name = name + ".inp";

    vi.clear();

    ifstream nowfile(name);

    string num;
    while (getline(nowfile, num))
    {
        vi.push_back(SNC(num));
    }

    nowfile.close();

    auto start = high_resolution_clock::now(); /// get starting timepoint
    ///----sorting here-----
    heapSort();
    //----------------------
    auto stop = high_resolution_clock::now(); /// end timepoint

    auto duration = duration_cast<milliseconds>(stop - start);
    int end = duration.count();

    endtime.push_back(end);
    return;
}

void GetTime()
{
    for (int i = 0 ; i <= 9 ; ++i)
        Get(i);
    return;
}

void PrintfTime()
{
    ofstream myfile;
    myfile.open ("Report.txt");
    for (int i = 0 ; i <= 9 ; ++i)
        myfile << "Time to run test " << i << " is: " << endtime[i] << '\n';

    int average = 0;
    for (int i = 0 ; i <= 9 ; ++i)
        average +=  endtime[i];
    average /= 9;
    myfile << "average is: " << average;

    myfile.close();
    return;

}
int main()
{
    GetTime();
    PrintfTime();
    return 0;
}
