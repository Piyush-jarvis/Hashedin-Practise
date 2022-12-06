#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
    
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";   
    }
    cout << endl;
}


int main(){
    int arr[10] = {10,25,322,0,-45,-31,0,65,-789,999};
    swapAlternate(arr,10);
    cout <<"The array after alternate swapping is: "<< endl;
    printArray(arr,10);
    return 0;
}