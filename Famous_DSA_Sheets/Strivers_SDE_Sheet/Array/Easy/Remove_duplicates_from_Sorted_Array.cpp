// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
        int n= arr.size();
        int i=0, j=1;
        while(j<n)
        {
            if(arr[i]==arr[j])
            {
                j++;
            }
            else if(arr[i]!=arr[j])
            {
                i++;
                arr[i]=arr[j];
                j++;
            }
        }
        return i+1;
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
    cout<<removeDuplicates(array)<<endl;
}