#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<ll, int> is_equal;
	ll odd_sum = 0, even_sum = 0;
	bool ans = false;
	is_equal[0] = -1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			even_sum += a[i];
		} else {
			odd_sum += a[i];
		}
		ll balance = even_sum - odd_sum;
		if (is_equal.find(balance) != is_equal.end()) {
			ans = true;
			break;
		} else {
			is_equal[balance] = i;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}
 
int main() {
	ios_base::sync_with_wtdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
