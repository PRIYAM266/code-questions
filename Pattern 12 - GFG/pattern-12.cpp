//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for (int i = 0; i < n; i++) {
            //num
            for (int j = 0; j < i+1; j++) {
                cout << j+1 << " ";
            }
            //space
            for (int j = 0; j < 2*(n-1-i); j++) {
                cout << "  ";
            }
            //num
            for (int j = i + 1; j > 0; j--) {
                cout << j << " ";
            }
            cout << endl;
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