//#include <bits/stdc++.h>//c++17万能头，包含<iostream>等必要头文件
//using namespace std;
//#define ll long long
//int n;
//string s;
//int main(void) {
//	//快速读写数据
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> s;
//	for (int i = 0; i < n/2; i++) {
//		if (s[i] != s[n - i - 1]) {
//			cout << "NO" << endl;
//			return 0;
//		}
//	}
//	cout << "YES" << endl;
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
char a[100000000];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &a[i]);
	}

	for (int i = 0; i < n/2; i++) {
		if (a[i] != a[n - i - 1]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;

}



