#include <iostream>
#include <algorithm>
#include <vector>
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
		vector<ll> a;

		for (int i = 0; i < n; i++) {
			int y;
			cin >> y;
			a.push_back(y);
		}

		if (n < 3) {
			cout << "-1" << endl;
		} else {
			ll x = 0;
			vector<ll> aN; 

			for (int i = 0; i < n; i++) {
				x += a[i];
				aN.push_back(a[i]*n*2);
			}

			ll sum = x*n*2;
			sort(aN.begin(), aN.end());
            
			if (x <= aN[n/2]) {
				cout << aN[n/2] - x + 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
    }
    return 0;
}