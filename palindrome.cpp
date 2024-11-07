#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longest_palindromic_subsequence(const string& S) {
    int n = S.size();
    vector<vector<string>> dp(n, vector<string>(n, ""));
    
    // Base case
    for (int i=0; i<n; i++) {
        dp[i][i] = S[i];
    }
    

    for (int L=2; L<=n; L++) {
        for (int i = 0; i <= n-L; i++) {
            int j = i+L-1;
            if (S[i] == S[j]) {
                dp[i][j] = S[i] + dp[i+1][j-1] + S[j];
            } else {
                if(dp[i+1][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i][j-1];
                }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    string S;
    cout<<"Enter your String....\n";
    cin>>S;
    cout << "Longest palindromic subsequence: "<<longest_palindromic_subsequence(S)<<endl;
    return 0;
}
