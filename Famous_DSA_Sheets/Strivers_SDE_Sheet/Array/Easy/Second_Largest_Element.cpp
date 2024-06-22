// Given an array Arr of size N, print the second largest distinct element from an array. If the second largest element doesn't exist then return -1.

#include <bits/stdc++.h>
using namespace std;

int Second_Largest_Element(vector<int> &arr)
{
    int max = INT_MIN, second_max = INT_MIN;
    for(auto i : arr)
    {
        if(i>max)
        {
            second_max = max;
            max = i;
        }
        else if (i> second_max && i != max)
        {
            second_max = i;
        }
    }
    return second_max;
}

int main()
{
    int size;
    cin>>size;
    vector<int> array(size);
    for(int i=0;i<size;i++)
    {
        int value;
        cin>>value;
        array[i]=value;
    }
    cout<<Second_Largest_Element(array)<<endl;
}