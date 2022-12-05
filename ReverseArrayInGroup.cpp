#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        for(int i = 0; i <n ; i+=k)
        {
            reverse(arr.begin()+i,arr.begin()+min(n,k+i));
        }
    //     for( int i=0;i<n;i=i+k)

    //     {

    //       int first = i;

    //       int last = i + k - 1; 

    //       if(last > n - 1) 

    //       last = n - 1;

    //       while( first < last)

    //          {

    //             swap( arr[first] , arr[last] );

    //             first ++;

    //             last --;

    //          }

    //     }

    // }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}
