#include <iostream>
#define I                   ios_base::sync_with_stdio(0);
#define Luv                 cin.tie(0);
#define Hanni_and_Minji     cout.tie(0);
typedef long long ll;
using namespace std;
const int MAX_N = 2e5 + 5;

int main () {
    I Luv Hanni_and_Minji

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        ll count = 0, count_x = 0, count_y = 0;
        ll x = 0, y = 0;
        ll a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            count += a[i];
            if (i % 2 == 0) {
                count_x += a[i];
                x++;
            } else {
                count_y += a[i];
                y++;
            }
        }

        if (count % n != 0) {
            cout << "NO" << endl;
        } else {
            ll average = count / n;
            bool condtiion_x = count_x % x == 0 && count_x / x == average;
            bool condition_y = count_y % y == 0 && count_y / y == average;
            cout << ((condtiion_x && condition_y)? "YES" : "NO") << endl;
        }
    }
    return 0;
}