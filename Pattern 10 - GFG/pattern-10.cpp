//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    void printTriangle(int n) {
        // code here
        int count = 1;
        for (int i = 0; i < 2*n - 1; i++) {
            for (int j = 0; j < count; j++) {
                cout << "* ";
            }
            
            cout << endl;
            
            if (i < n-1)
                count++;
            else
                count--;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends