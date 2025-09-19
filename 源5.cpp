#include <bits/stdc++.h>
using namespace std;
#define ll long long
string distr = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
int n, m, k;

struct hak {
    int ac = 0;
    int fa[24] = { 0 };  // ��ʼ������
    int oj = 0;
    int timee = 0;
    bool bj[24];

    // ���캯����ʼ��bj����
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
        // ȷ��map�е�Ԫ������ȷ��ʼ��
        if (str.find(lab) == str.end()) {
            str[lab] = hak();  // ʹ�ù��캯����ʼ��
        }

        if (pair.state == "OJ") {
            str[lab].oj++;
        }
        else if (pair.state == "AC") {
            int problem = pair.th - 'A';
            if (problem >= 0 && problem < 24) {  // ���������ʱ߽�
                if (!str[lab].bj[problem]) {
                    str[lab].ac++;
                    str[lab].timee += pair.timee + str[lab].fa[problem];
                    str[lab].bj[problem] = true;
                }
            }
        }
        else {
            int problem = pair.th - 'A';
            if (problem >= 0 && problem < 24) {  // ���������ʱ߽�
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
            // ��������Ƿ�����Ч��Χ��
            if (ran >= 1 && ran <= reslis.size()) {
                cout << reslis[ran - 1].name << endl;
            }
        }
        else {
            if (!reslis.empty()) {  // ��������Ƿ�Ϊ��
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