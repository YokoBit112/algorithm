#include<iostream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

string zwm[8] = { "","BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong" };

struct node {
	string name;	//���� 
	string zw;		//ְ�� 
	int bg, lv, tk;	//�ﹱ �ȼ� ���ֱ�� 
} ex[120];

int n;

//�ﹱ��ͬ ������˳������ 
bool cmp1(node ta, node tb) {
	if (ta.bg == tb.bg) return ta.tk < tb.tk;
	return ta.bg > tb.bg;
}
//�ȼ���ͬ ������˳������ 
bool cmp2(node ta, node tb) {
	if (ta.lv == tb.lv) return ta.tk < tb.tk;
	return ta.lv > tb.lv;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ex[i].name >> ex[i].zw >> ex[i].bg >> ex[i].lv;
		ex[i].tk = i;
	}
	int rec = 1;
	//����ж��ٸ������͸����� ��rec��¼ 
	while (true) {
		if (ex[rec].zw != zwm[1] && ex[rec].zw != zwm[2]) break;
		rec++;
	}
	int tmp = rec;
	sort(ex + rec, ex + n + 1, cmp1);				//��ͷ��β���ﹱ���� 
	sort(ex + rec, ex + min(rec + 2, n + 1), cmp2);	//�Ի������� 
	rec = min(rec + 2, n + 1);
	sort(ex + rec, ex + min(rec + 4, n + 1), cmp2);	//�Գ������� 
	rec = min(rec + 4, n + 1);
	sort(ex + rec, ex + min(rec + 7, n + 1), cmp2);	//���������� 
	rec = min(rec + 7, n + 1);
	sort(ex + rec, ex + min(rec + 25, n + 1), cmp2);	//�Ծ�Ӣ���� 
	rec = min(rec + 25, n + 1);
	sort(ex + rec, ex + n + 1, cmp2);				//�԰������� 
	for (int i = tmp; i <= n; i++) {				//Ϊ���˰����͸��������������������±�ǩ 
		ex[i].zw = zwm[7];
		if (i < tmp + 38) ex[i].zw = zwm[6];
		if (i < tmp + 13) ex[i].zw = zwm[5];
		if (i < tmp + 6) ex[i].zw = zwm[4];
		if (i < tmp + 2) ex[i].zw = zwm[3];
	}
	for (int i = 1; i <= n; i++) {
		cout << ex[i].name << " " << ex[i].zw << " " << ex[i].lv << endl;
	}
	return 0;
}