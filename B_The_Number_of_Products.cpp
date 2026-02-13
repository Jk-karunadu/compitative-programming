#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long pos_prefixes = 1; 
    long long neg_prefixes = 0;
    
    long long ans_pos = 0;
    long long ans_neg = 0;
    
    int current_sign = 1; 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x < 0) {
            current_sign *= -1;
        }

        if (current_sign == 1) {
            ans_pos += pos_prefixes;
            ans_neg += neg_prefixes;
            pos_prefixes++;
        } else {
            ans_pos += neg_prefixes;
            ans_neg += pos_prefixes;
            neg_prefixes++;
        }
    }

    cout << ans_neg << " " << ans_pos << endl;

    return 0;
}