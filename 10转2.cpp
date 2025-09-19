#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

void  dectobin(ll a)
{
        vector<int> c;
        while (1)
        {
            int d = a % 2;
            a -= d;
            a /= 2;
            c.push_back(d);
            if (a == 0) { break; }

        }
        for (auto i = c.end() - 1; i != c.begin(); i--)
        {
            cout << *i;
        }
        cout << *c.begin();
}

int main(void)
{
	ll a;
	scanf("%lld", &a);
	dectobin(a);
}