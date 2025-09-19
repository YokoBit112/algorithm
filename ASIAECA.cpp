#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;




bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

map<string, int> t1,t2;
set<string> sch;
string tem;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tem;
		sch.insert(tem);
		if(!t1[tem])t1[tem] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tem;
		sch.insert(tem);
		if (!t2[tem])t2[tem] = i + 1;
	}
	vector<pair<string,int>> v1(t1.begin(), t1.end()),v2(t2.begin(),t2.end());
	
	sort(v1.begin(), v1.end(), cmp); sort(v2.begin(), v2.end(), cmp);
	int m = max(v1.size(), v2.size()),m1 = v1.size(),m2 = v2.size();
	string a;
	vector<string> ans;
	for (int i = 0; i < m; i++) {
		if (i >= m1) {
			a = (v2.end()-1)->first;
			if (find(ans.begin(), ans.end(), a) == ans.end()) {
				ans.push_back(a);
			}
			v2.pop_back();
			continue;
		}
		if (i >= m2) {
			a = (v1.end() - 1)->first;
			if (find(ans.begin(), ans.end(), a) == ans.end()) {
				ans.push_back(a);
			}
			v1.pop_back();
			continue;
		}
		a = (v1.end() - 1)->first;
		if (find(ans.begin(), ans.end(), a) == ans.end()) {
			ans.push_back(a);
		}
		v1.pop_back();
		a = (v2.end() - 1)->first;
		if (find(ans.begin(), ans.end(), a) == ans.end()) {
			ans.push_back(a);
		}
		v2.pop_back();
	}
	for (auto& pair : ans)cout << pair << endl;
	return 0;
}