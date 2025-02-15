#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <deque>
#define I                   ios_base::sync_with_stdio(0);
#define Luv                 cin.tie(0);
#define Hanni_and_Minji     cout.tie(0);
typedef long long ll;
using namespace std;
const int MAX_N = 2e5 + 5;

int main () {
    I Luv Hanni_and_Minji

    int n, t;
    cin >> t;

    while (t--) {
        vector <ll> a, b;
        cin >> n;

        if (n/2 % 2 != 0) {
            cout << "NO" << endl;
        } else {
            ll count_a = 0, count_b = 0;
            for (int i = 1; i <= n/2; i++) {
                a.emplace_back(2*i);
                count_a += 2*i;
            } 
            for (int i = 1; i <= n/2; i++) {
                if (i < n/2) {
                    b.emplace_back(2*i - 1);
                    count_b += 2*i - 1;
                } else {
                    ll x = 2*i - 1;
                    while (count_b + x < count_a) {
                        x += 2;
                    }
                    b.emplace_back(x);
                    count_b += x;
                }
            }
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                if (i <= n/2) {
                    cout << a[i - 1] << " ";
                } else {
                    cout << b[i - n/2 - 1] << " ";
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}