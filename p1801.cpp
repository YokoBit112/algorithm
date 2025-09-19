#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n[200010], m[200010];
priority_queue<ll, vector<ll>, greater<ll>> e;
priority_queue<ll, vector<ll>, less<ll>> r;
int main(void)
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++){cin >> m[i];}
	for (int i = 0; i < b; i++){cin >> n[i];}
	sort(n, n + b);
	int p = 0;
	for (int i = 0; i < b; i++)
	{
		while (p < n[i])
		{
			r.push(m[p]);
			e.push(r.top());
			r.pop();
			p++;
		}
		cout << e.top() << endl;
		r.push(e.top());
		e.pop();
	}


	return 0;

}