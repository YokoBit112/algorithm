#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

//void solveB()
//{
//	for (int i = 0; i < 100; i++) {
//		cout << "I really want to join AutoGo" << endl;
//	}
//}
//
int radem(int l, int r) {
	double sl = (double)rand()/32767;
	return sl * (l + r);
}
//int n;
//string s;
//string sta = "asdfghjklqwertyuiopzxcvbnm1234567890";
//void solveA() {
//
//
//	//cin >> n >> s;
//	bool se = false;
//	for (int i = 0; i < n / 2; i++) {
//		if (s[i] != s[n - i - 1]) {
//			se = 1;
//			break;
//		}
//	}
//	if (se)cout << "NO" << endl;
//	else cout << "YES" << endl;
//}

//string craftH(string se) {
//	string temp;
//	for (int i = 0; i < se.size() / 2 + 1; i++) {
//		temp.push_back(se[i]);
//	}
//	for (int i = temp.size() - 2; i >= 0; i--) {
//		temp.push_back(temp[i]);
//	}
//	return temp;
//}
bool writeStringToFile(const std::string& filename, const std::string& content, bool append = false) {
	// 根据append参数决定打开模式
	std::ofstream outFile;
	if (append) {
		// 追加模式：在文件末尾添加内容
		outFile.open(filename, std::ios::app);
	}
	else {
		// 默认模式：创建新文件或覆盖已有文件
		outFile.open(filename);
	}

	// 检查文件是否成功打开
	if (!outFile.is_open()) {
		std::cerr << "无法打开文件: " << filename << std::endl;
		return false;
	}

	// 写入内容
	outFile << content;

	// 关闭文件（超出作用域时也会自动关闭，这里显式关闭更清晰）
	outFile.close();

	return true;
}
//
//int m, k,t;
//void solveC(int ie) {
//	{
//		//cout << (ll)n * m - k + 1 << endl;
//		writeStringToFile(to_string(ie) + ".out", to_string((ll)n * m - k + 1) + "\n",true);
//	}
//}
//

//int n, k; vector<int> a;
//
//void solveF(int ie) {
//	sort(a.begin(), a.end());
//	int ke = 0, res = 0;
//	while (n > 0) {
//		n -= a[ke++];
//		res++;
//	}
//	cout << res << endl;
//	writeStringToFile(to_string(ie) + ".out", to_string(res) +"\n");
//}
//int t, n, k, b;
//
//vector<int> a;
//void solveG(int ie) {
//	int Lin = a[0], rank = 1, firste = 0;;
//	for (int i = 1; i < k; i++) {
//		if (Lin < a[i]) {
//			if (firste < a[i])firste = a[i];
//			rank++;
//		}
//	}
//	if (rank == 1) {
//		writeStringToFile(to_string(ie) + ".out", "1 -1\n", true);
//		cout << "1 -1" << endl;
//	}
//	else {
//		writeStringToFile(to_string(ie) + ".out", to_string(rank) + " "+to_string(firste-Lin)+"\n", true);
//		cout << rank << " " << firste - Lin << endl;
//	}
//}

string distr = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
string thdir = "ASDFGHJKLQWERTYUIOPZXCVBNM";
string stadir[3] = { "AC","WA","OJ" };
int n, m, k;
struct hak {
	int ac = 0;
	int fa[24];
	int oj = 0;
	int timee = 0;
	bool bj[24];
};

struct he {
	string name;
	char th;
	int timee;
	string state;
};

struct hek {
	string name;
	int ac;
	int oj;
	int timee = 0;
};

map<string, hak> str;
vector<he> listt;
vector<hek> reslis;

bool cmp(he a, he b) {
	return a.timee < b.timee;
}

bool cmpe(hek a, hek b) {
	if (a.ac != b.ac) {
		return a.ac > b.ac;
	}
	if (a.timee != b.timee) {
		return a.timee < b.timee;
	}
	return a.name < b.name;
}

void solveH(int ie) {
	sort(listt.begin(), listt.end(), cmp);
	for (auto& pair : listt)
	{
		string lab = pair.name;
		if (pair.state == "OJ")str[lab].oj++;
		else if (pair.state == "AC") {
			if (!str[lab].bj[pair.th - 'A'])
			{
				str[lab].ac++;
				str[lab].timee += pair.timee + str[lab].fa[pair.th - 'A'];
				str[lab].bj[pair.th - 'A'] = 1;
			}
		}
		else {
			str[lab].fa[pair.th - 'A'] += 20;
		}
	}
	for (auto& pair : str) {
		string tempe = pair.first;
		int ac = pair.second.ac, oj = pair.second.oj, timee = pair.second.timee;
		hek temphek;
		temphek.name = tempe, temphek.ac = ac, temphek.oj = oj, temphek.timee = timee;
		reslis.push_back(temphek);
	}
	sort(reslis.begin(), reslis.end(), cmpe);
	
	do { k = radem(1, 10000); } while (!k || k > 10000);
	cout << k << endl;
	writeStringToFile(to_string(ie) + ".in", to_string(k) + "\n", true);
	for (int i = 0; i < k; i++) {
		//查询
		int sat;
		do { sat = radem(1, 2); } while (sat < 1 || sat>2);
		if (sat == 1) {
			int ran;
			do { ran = radem(1, n); } while (ran<1 || ran>n);
			writeStringToFile(to_string(ie) + ".in", to_string(sat)+" "+to_string(ran) + "\n", true);
			cout << sat << " " << ran << endl;
			cout << reslis[ran - 1].name<<endl;
			writeStringToFile(to_string(ie)+".out", reslis[ran - 1].name + "\n", true);
		}
		else {
			writeStringToFile(to_string(ie) + ".in", to_string(sat) + "\n", true);
			cout << sat << endl;
			cout << reslis[0].name << " " << reslis[0].ac << " " << reslis[0].oj << endl;
			writeStringToFile(to_string(ie) + ".out", reslis[0].name + " " + to_string(reslis[0].ac)+ " "+ to_string(reslis[0].oj) + "\n", true);
		}
	}
	str.clear();
	reslis.clear();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand((unsigned)time(NULL));
	for (int i = 1; i < 11; i++) {
		do { n = radem(1, 63); } while (!n || n > 63);

		do{m = radem(1, 1000);} while (m<n);
		cout << n << " " << m << endl;
		writeStringToFile(to_string(i) + ".in", to_string(n) + " " + to_string(m) + "\n", true);
		for (int p = 0; p < n; p++) {
			string namee;
			namee.push_back(distr[p]);
			cout << namee << endl << endl;
			int dirs;
			
			do { dirs = radem(0, 23); } while (dirs > 23);
			char th = thdir[dirs];
			
			int timee;
			do {timee = radem(0, 300); } while (timee>300);
			
			string state;
			if (timee <= 240) {
				do { dirs = radem(0, 1); } while(dirs < 0 || dirs>1);
				state = stadir[dirs];
			}
			else state = stadir[2];

			he temm;
			temm.name = namee, temm.th = th, temm.timee = timee, temm.state = state;
			writeStringToFile(to_string(i) + ".in", namee+" "+th+" "+to_string(timee) + " " + state + "\n", true);
			cout << namee << " " << th << " " << timee << " " << state << endl;
			namee.clear();
			listt.push_back(temm);
		}
		for (int p = 0; p < m - n; p++) {
			int dirs;
			do { dirs = radem(1, n); } while (!dirs || dirs > n);
			string namee;
			namee.push_back(distr[dirs]);

			do { dirs = radem(0, 23); } while (dirs > 23);
			char th = thdir[dirs];

			int timee;
			do { timee = radem(0, 300); } while (timee>300);

			string state;
			if (timee <= 240) {
				do { dirs = radem(0, 1); } while (dirs<0||dirs>1);
				state = stadir[dirs];
			}
			else state = stadir[2];

			he temm;
			temm.name = namee, temm.th = th, temm.timee = timee, temm.state = state;
			cout << namee << " " << th << " " << timee << " " << state << endl;
			writeStringToFile(to_string(i) + ".in", namee + " " + th + " " + to_string(timee) + " " + state + "\n", true);
			listt.push_back(temm);
			namee.clear();
		}
		
		solveH(i);

		listt.clear();
	}
	return 0;
}