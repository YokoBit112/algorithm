#include <bits/stdc++.h>
#include <cmath>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, less<ll>> q1;
priority_queue<ll, vector<ll>, greater<ll>> q2;

int main(void)
{
	int n,se;
	cin >> n;
	cin >> se;
	q1.push(se);
	cout << se << endl;
	for (int i = 2; i <= n; i++)
	{
		cin >> se;
		if (q1.top() > se)q1.push(se);
		else q2.push(se);

		while (abs((int)q1.size()-(int)q2.size())>1)
		{
			if (q1.size() > q2.size()){q2.push(q1.top());q1.pop();}
			else {q1.push(q2.top());q2.pop();}
		}
		if (i % 2)
		{
			if (q1.size() > q2.size()) { cout << q1.top(); }
			else { cout << q2.top(); }
			cout<<endl;
		}
	}
}