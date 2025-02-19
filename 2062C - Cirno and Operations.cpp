#include <iostream>
#include <vector>
#include <algorithm>
#define I                   ios_base::sync_with_stdio(0);
#define Luv                 cin.tie(0);
#define Hanni_and_Minji     cout.tie(0);
typedef long long ll;
using namespace std;
const int MAX_N = 2e5 + 5;

ll getSum(vector<ll> &b) {
    ll total = 0;
    vector <ll> a_new;
    
    for (int i = 0; i < b.size() - 1; i++) {
        ll x = b[i + 1] - b[i];
        total += x;
        a_new.push_back(x);
    }

    b = a_new;
    if (total < 0) {
        total *= -1;
    }
    return total;
}

int main () {
    I Luv Hanni_and_Minji
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll mx = 0;
        vector<ll> a;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            mx += x;
        }
        
        if (a.size() == 1) {
            cout << a[0] << endl;
        } else {
            while (a.size() > 1) {
                ll x = getSum(a);
                mx = max(mx, x);
            }
            cout << mx << endl;
        }

    }
    return 0;
}