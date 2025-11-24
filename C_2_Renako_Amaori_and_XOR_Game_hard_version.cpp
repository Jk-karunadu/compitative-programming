#include <iostream>
#include <vector>

using namespace std;
void resolve_game() {
    int len;
    cin >> len;
    vector<int> seq1(len), seq2(len);
    int total_xor1 = 0; 
    int total_xor2 = 0;
    for (int i = 0; i < len; ++i) {
        cin >> seq1[i];
        total_xor1 ^= seq1[i];
    }
    for (int i = 0; i < len; ++i) {
        cin >> seq2[i];
        total_xor2 ^= seq2[i];
    }
    int xor_delta = total_xor1 ^ total_xor2;
    if (xor_delta == 0) {
        cout << "Tie\n";
        return;
    }
    int msb_pos = 0;
    for (int bit = 30; bit >= 0; --bit) {
        if ((xor_delta >> bit) & 1) {
            msb_pos = bit;
            break;
        }
    }

    int decisive_index = -1;
    for (int i = len - 1; i >= 0; --i) {
        int bit_val1 = (seq1[i] >> msb_pos) & 1;
        int bit_val2 = (seq2[i] >> msb_pos) & 1;

        if (bit_val1 != bit_val2) {
            decisive_index = i;
            break;
        }
    }
    if (decisive_index % 2 == 0) {
        cout << "Ajisai\n";
    } else {
        cout << "Mai\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_cases;
    cin >> num_cases;
    while (num_cases--) {
        resolve_game();
    }

    return 0;
}