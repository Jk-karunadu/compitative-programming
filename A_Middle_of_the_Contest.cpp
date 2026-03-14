#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int h1, m1, h2, m2;
    char colon;

    cin >> h1 >> colon >> m1;
    cin >> h2 >> colon >> m2;

    int total_min1 = h1 * 60 + m1;
    int total_min2 = h2 * 60 + m2;

    int mid_total = (total_min1 + total_min2) / 2;

    int midh = mid_total / 60;
    int midm = mid_total % 60;

    if (midh < 10) cout << "0";
    cout << midh << ":";
    if (midm < 10) cout << "0";
    cout << midm << endl;

    return 0;
}