#include <bits/stdc++.h>
using namespace std;

int Largest_Element(int arr[], int n)
{
    int maxi = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    return maxi;
}

int main()
{
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        int value;
        cin>>value;
        array[i]=value;
    }
    cout<<Largest_Element(array,size)<<endl;
}