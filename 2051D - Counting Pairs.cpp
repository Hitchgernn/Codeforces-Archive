#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int MAX_N = 2e5 + 5;
typedef long long ll;
typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector <ll> a;
        ordered_set s;

        for (int i = 0; i < n; i++){
            ll num;
            cin >> num;
            a.push_back(num);
        }

        sort(a.begin(), a.end());
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        ll left = sum - y;
        ll right = sum - x;
        ll count = 0;

        for (int i = 0; i < n; i++) {
            // idk why the output is incorrect when i'm using ordered set as a pointer
            // ll l = left - a[i];
            // ll r = right - a[i];
            // count += (s.order_of_key(r + 1) - s.order_of_key(l));
            // s.insert(a[i]);
            auto l = lower_bound(a.begin() + i + 1, a.end(), left - a[i]);
            auto r = upper_bound(a.begin() + i + 1, a.end(), right - a[i]);
            count += max(r - l, 0LL);
        }
        cout << count << endl;

    }
    return 0;
}
