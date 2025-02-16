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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        map <ll, int> freq;
        vector <ll> stick, stored_stick_2, stored_stick_4;
        ll a;

        for (int i = 0; i < n; i++) {
            cin >> a;
            freq[a]++;
            stick.push_back(a);
        }

        bool square = false, rectangle = false;
        
        for (auto f : freq) {
            if (f.second >= 4) {
                stored_stick_4.push_back(f.first);
                square = true;
            } else if (f.second >= 2) {
                stored_stick_2.push_back(f.first);
                rectangle = true;
            }
        }

        sort(stick.begin(), stick.end());
        sort(stored_stick_2.begin(), stored_stick_2.end());

        vector <ll> remaining_value;

        if (square) {
            cout << stored_stick_4[0] << " " << stored_stick_4[0] << " " << stored_stick_4[0] << " " << stored_stick_4[0] << endl;
        } else if (rectangle && stored_stick_2.size() > 1) {
            cout << stored_stick_2[0] << " " << stored_stick_2[0] << " " << stored_stick_2[1] << " " << stored_stick_2[1] << endl; 
        } else if (rectangle) {
            int duplicate_count = 2;
            for (ll s : stick) {
                if (s == stored_stick_2[0] && duplicate_count > 0) {
                    duplicate_count--;
                    continue;
                }
                remaining_value.push_back(s);
            }
            bool found = false;
            ll legs = stored_stick_2[0]*2;
            for (int i = 0; i < remaining_value.size(); i++) {
                if (i != remaining_value.size() - 1 && remaining_value[i+1] - remaining_value[i] < legs) {
                    cout << stored_stick_2[0] << " " << stored_stick_2[0] << " " << remaining_value[i] << " " << remaining_value[i+1];
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}