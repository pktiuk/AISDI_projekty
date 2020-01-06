#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sys/times.h>
#include <bubblesort.hpp>
#include <loadWords.hpp>
#include <merge.hpp>

using namespace std;

using namespace std;

int main() {
    
    vector<string>v;
    v = read("pan-tadeusz.txt");

    int n = 1000;
    struct tms t1, t2;
    times(&t1);
    sort(v.begin(), next(v.begin(), n));
    times(&t2);
    auto dt = t2.tms_utime -t1.tms_utime;
    cout << "sort, n = " << n << " time : " << dt << endl;

    times(&t1);
    mergeSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "merge sort, n = " << n << " time : " << dt << endl;

    times(&t1);
    bubbleSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "bubble, n = " << n << " time : " << dt << endl;

    n = 10000;
    times(&t1);
    sort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "sort, n = " << n << " time : " << dt << endl;

    times(&t1);
    mergeSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "merge sort, n = " << n << " time : " << dt << endl;

    times(&t1);
    bubbleSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "bubble, n = " << n << " time : " << dt << endl;

    n = 50000;
    times(&t1);
    sort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "sort, n = " << n << " time : " << dt << endl;
    
    times(&t1);
    mergeSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "merge sort, n = " << n << " time : " << dt << endl;
    
    times(&t1);
    bubbleSort(v.begin(), next(v.begin(), n));
    times(&t2);
    dt = t2.tms_utime -t1.tms_utime;
    cout << "bubble, n = " << n << " time : " << dt << endl;
}
