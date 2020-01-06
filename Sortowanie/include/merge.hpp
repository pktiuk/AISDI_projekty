#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


template<typename IteratorType>
void merge(IteratorType first,IteratorType mid, IteratorType last)
{
    IteratorType f1 = first;
    IteratorType f2 = mid;

    vector<typename IteratorType::value_type>tmp;

    while( f1 != mid || f2 != last )
    {
        if( f1 == mid )
        {
            tmp.push_back(*f2);
            f2++;
        }
        else
        if(f2 == last)
        {
            tmp.push_back(*f1);
            f1++;
        }
        else
        {
            if(*f1<*f2)
            {
                tmp.push_back(*f1);
                f1++;
            }
            else
            {
                tmp.push_back(*f2);
                f2++;
            }
        }
    }
    /*
    for(int i = 0; i < tmp.size(); ++i)
        cout<<tmp[i]  << " ";
    cout <<"\n";
    */
    int j =0;
    for(auto i = next(first, 0); i != last; ++i )
    {
        *i = tmp[j]; 
        j++;
    }

}

template<typename IteratorType>
void mergeSort(IteratorType first, IteratorType last)
{
    if( last <= first + 1)
    {
        return;
    }
    IteratorType mid = first + (last-first)/2;
    mergeSort(first, mid);
    mergeSort(mid, last);

    //cout << *first << " " << *mid << " " << *last << "\n";

    merge(first, mid, last);

    /*
    for(auto i = next(first, 0); i != last; ++i )
    {
        cout << *i <<"i ";
    }
    cout << "\n";
    */
}