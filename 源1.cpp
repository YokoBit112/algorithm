#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first)return a.first > b.first;
        else return a.second > b.second;
    }
};
bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
int solution(int distance, int n, std::vector<std::vector<int>> gas_stations) {
    // Please write your code here
    sort(gas_stations.begin(), gas_stations.end(), cmp);

    if (n > 0) { if (distance - gas_stations[n - 1][0] > 200)return -1; }
    else if (n == 0)return -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> a;
    int now = 200, dis = 0, sum = 0;
    for (int i = 0; i < gas_stations.size(); i++)
    {
        if (gas_stations[i][0] > distance) { n = i; break; }
        int neDIs = gas_stations[i][0], nePri = gas_stations[i][1], d2n = neDIs - dis;
        while (now < d2n) {
            if (a.empty())return -1;
            while (a.top().second <= dis && !a.empty()) { a.pop(); }
            if (a.empty())return -1;
            now += min(a.top().second, neDIs) - dis;
            sum += (min(a.top().second, neDIs) - dis) * a.top().first;
            if (neDIs > a.top().second) { dis = a.top().second; a.pop(); }
        }
        now -= d2n; dis = neDIs;
        a.push({ gas_stations[i][1],gas_stations[i][0] + 400 });//value,dis
    }
    distance += 200;
    int d2n = distance - gas_stations[n - 1][0];
    while (a.top().second <= gas_stations[n - 1][0] && !a.empty()) { a.pop(); }
    if (a.empty())return -1;
    while (now < d2n) {
        while (a.top().second <= dis && !a.empty()) { a.pop(); }
        if (a.empty())return -1;
        now += min(a.top().second, distance) - dis;
        sum += (min(a.top().second, distance) - dis) * a.top().first;
        if (distance > a.top().second) { dis = a.top().second; a.pop(); }
    }
    return sum;
}

int main() {
    std::vector<std::vector<int>> gasStations1 = {
        {300,25},{600,35},{900,5} };
    std::vector<std::vector<int>> gasStations2 = {
        {100, 999},  {150, 888},  {200, 777}, {300, 999},
        {400, 1009}, {450, 1019}, {500, 1399} };
    std::vector<std::vector<int>> gasStations3 = { {101}, {100, 100}, {102, 1} };
    std::vector<std::vector<int>> gasStations4 = {
        {34, 1},     {105, 9},  {9, 10},    {134, 66}, {215, 90},
        {999, 1999}, {49, 0},   {10, 1999}, {200, 2},  {300, 500},
        {12, 34},    {1, 23},   {46, 20},   {80, 12},  {1, 1999},
        {90, 33},    {101, 23}, {34, 88},   {103, 0},  {1, 1} };

    std::cout << (solution(1000, 3, gasStations1) == -1) << std::endl;
    std::cout << (solution(500, 7, gasStations2) == 410700) << std::endl;
    std::cout << (solution(500, 3, gasStations3) == -1) << std::endl;
    std::cout << (solution(100, 20, gasStations4) == 0) << std::endl;
    std::cout << (solution(100, 0, std::vector<std::vector<int>>{}) == -1)
        << std::endl;

    return 0;
}