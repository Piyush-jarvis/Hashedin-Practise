#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapAlternate(int arr[], int size)
{
    int c ;
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size)
        {
           c = arr[1];
           arr[1] = arr[0];
           arr[0] = c;
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
    int arr[7] = {10,25,322,0,-45,-31,0};
    swapAlternate(arr,10);
    cout <<"The array after alternate swapping is: "<< endl;
    printArray(arr,7);
    return 0;
}