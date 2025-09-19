//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//
//ll a[200005], n, k,t;
//
//map<int, int> ha,ha1;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		ha.clear(), ha1.clear();
//		int cnt = -2, bcnt = -1;
//		for (int i = 0;i < n;i++) {
//			cin >> a[i];
//			ha[a[i]]++;
//		}
//		for (int i = 0;i <= n;i++) {
//			if (!ha[i]) {
//				cnt = i;
//				break;
//			}
//		}
//		ll sum = 0;
//		if (cnt == 0)cout << 0 << endl;
//		else {
//			for (int i = 0;i <= n;i++) {//k1
//				if ((i >= cnt && ha[i]) || (i < cnt && ha[i]>1)) {
//					sum += (ll)ha[i] * cnt;
//					ha1[cnt] += ha[i];
//				}
//				else if (i < cnt) {
//					sum += i;
//					ha1[i] += ha[i];
//				}
//			}
//			if (k == 1) {
//				cout << sum << endl;
//				continue;
//			}
//			for (int i = 0;i <= n;i++) {
//				if (!ha1[i]) {
//					cnt = i;
//					break;
//				}
//			}
//			if (cnt == 0) {
//				cout << 0 << endl;
//				continue;
//			}
//			if (k % 2) {
//				cout << sum << endl;
//				continue;
//			}
//			sum = 0;
//			for (int i = 0;i < n;i++) {
//				if ((i >= cnt && ha1[i]) || (i < cnt && ha1[i]>1)) {
//					sum += (ll)ha1[i] * cnt;
//				}
//				else if (i < cnt) {
//					sum += i;
//				}
//			}
//			cout << sum << endl;
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> l;
        vector<int> sl;
        int sl_size = -1;
        while (k > 0 && l != a) {
            k--;
            sl = l;
            l = a;
            int max_a = *max_element(a.begin(), a.end());
            vector<int> F(max(max_a + 1, n + 1), 0);
            for (int num : a) {
                F[num]++;
            }
            int mex = 0;
            while (mex < F.size() && F[mex] > 0) {
                mex++;
            }
            vector<int> B;
            int mm = 0;
            for (int num : a) {
                if (F[num] > 1) {
                    B.push_back(mex);
                }
                else {
                    B.push_back(mm);
                }
                if (num == mm) {
                    mm++;
                }
            }
            sort(B.begin(), B.end());
            a = B;
            if (a == sl) {
                k &= 1; 
            }
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        cout << sum << '\n';
    }

    return 0;
}
