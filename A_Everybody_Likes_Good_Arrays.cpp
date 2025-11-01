#include <iostream>
using namespace std;

bool is_same_parity(int a, int b)
{
    return (a % 2) == (b % 2);
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int m;

        int count = 0;
        int final_answer = 0;
        int prev;
        cin >> m;
        cin>>prev;
        for (int i = 1; i < m; i++)
        {
            int x;
            cin >> x;
            if (i == 0 || is_same_parity(x, prev))
            {
                count++;
            }
            else
            {
                final_answer = final_answer + count;
                count = 0;
            }

            prev = x;
        }
        final_answer = final_answer + count;
        cout << final_answer << endl;
    }
}