#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int final = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        ans = ans - a + b;
        final = max(final, ans);
    }
    cout << final << endl;
    return 0;
}