#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pa {
    string id;
    string name;
    double ComputerArchitecture, LinearAlgebra, OperatingSystem, average;
    bool operator == (const string& uid) {
        return (this->id == uid);
    }
};

int main(void)
{
    string uid, data;
    vector<pa> a;
    while (cin >> uid)
    {
        pa e;
        int p = 0;
        e.id = uid;
        string ae;
        getline(cin, data);
        for (int i = 1; i != data.size(); i++)
        {
            if (data[i] != ',')ae.push_back(data[i]);
            else break;
        }
        if (ae.size() + 2 <= data.size())
        {
            string be = data.substr(ae.size() + 3, data.size() - ae.size() + 2);
            double se = stod(be);
            if (ae == "Computer Architecture") {
                e.ComputerArchitecture = se;
                p = 1;
            }
            else if (ae == "Linear Algebra")
            {
                e.LinearAlgebra = se;
                p = 2;
            }
            else if (ae == "Operating System")
            {
                e.OperatingSystem = se;
                p = 3;
            }
        }
        else {
            p = 4;
            e.name = ae;
        }
        uid.erase(uid.end() - 1);
        auto b = find(a.begin(), a.end(), uid);
        if (b == a.end())a.push_back(e);
        else {
            if (p == 1)b->ComputerArchitecture = e.ComputerArchitecture;
            else if (p == 2)b->LinearAlgebra = e.LinearAlgebra;
            else if (p == 3)b->OperatingSystem = e.OperatingSystem;
            else if (p == 4)b->name = e.name;
        }
    }
    cout << "student id, name, Computer Architecture, Linear Algebra, Operating System, average";
    for (int i = 0; i != a.size(); i++)
    {
        cout << a[i].id << a[i].name << a[i].ComputerArchitecture << a[i].LinearAlgebra << a[i].OperatingSystem << endl;
    }
}