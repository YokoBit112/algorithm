#include <bits/stdc++.h>
using namespace std;
#define ll long long
string distr = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
int n, m, k;

struct hak {
    int ac = 0;
    int fa[24] = { 0 };  // 初始化数组
    int oj = 0;
    int timee = 0;
    bool bj[24];

    // 构造函数初始化bj数组
    hak() {
        memset(bj, 0, sizeof(bj));
    }
};

struct he {
    string name;
    char th = 'A';
    int timee = 0;
    string state;
};

struct hek {
    string name;
    int ac = 0;
    int oj = 0;
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

void solveH() {
    cin >> n >> m;
    string temp;
    char th;
    int timee;
    string state;
    he temm;
    for (int i = 0; i < m; i++) {
        cin >> temp >> th >> timee >> state;
        temm.name = temp;
        temm.th = th;
        temm.timee = timee;
        temm.state = state;
        listt.push_back(temm);
    }
    sort(listt.begin(), listt.end(), cmp);

    for (auto& pair : listt) {
        string lab = pair.name;
        // 确保map中的元素已正确初始化
        if (str.find(lab) == str.end()) {
            str[lab] = hak();  // 使用构造函数初始化
        }

        if (pair.state == "OJ") {
            str[lab].oj++;
        }
        else if (pair.state == "AC") {
            int problem = pair.th - 'A';
            if (problem >= 0 && problem < 24) {  // 检查数组访问边界
                if (!str[lab].bj[problem]) {
                    str[lab].ac++;
                    str[lab].timee += pair.timee + str[lab].fa[problem];
                    str[lab].bj[problem] = true;
                }
            }
        }
        else {
            int problem = pair.th - 'A';
            if (problem >= 0 && problem < 24) {  // 检查数组访问边界
                str[lab].fa[problem] += 20;
            }
        }
    }

    for (auto& pair : str) {
        hek temphek;
        temphek.name = pair.first;
        temphek.ac = pair.second.ac;
        temphek.oj = pair.second.oj;
        temphek.timee = pair.second.timee;
        reslis.push_back(temphek);
    }

    sort(reslis.begin(), reslis.end(), cmpe);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int sat;
        cin >> sat;
        if (sat == 1) {
            int ran;
            cin >> ran;
            // 检查排名是否在有效范围内
            if (ran >= 1 && ran <= reslis.size()) {
                cout << reslis[ran - 1].name << endl;
            }
        }
        else {
            if (!reslis.empty()) {  // 检查容器是否为空
                cout << reslis[0].name << " " << reslis[0].ac << " " << reslis[0].oj << endl;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solveH();
    return 0;
}