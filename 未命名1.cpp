#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <algorithm>
#define INT_MAX 100000000
using namespace std;

// �ߵĽṹ�壬����Kruskal�㷨
struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V; // ������
    vector<vector<int>> adjMatrix; // �ڽӾ���
    vector<vector<pair<int, int>>> adjList; // �ڽӱ��洢(����, Ȩֵ)

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    // ���ļ���ȡͼ����Ϣ
    bool readGraphFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "�޷����ļ�" << endl;
            return 0;
        }

        int u, v, weight;
        while (file >> u >> v >> weight) {
            addEdge(u-1, v-1, weight);
        }
        file.close();
        return 1;
    }

    // ��ӱ�
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // ����ڽӾ���
    void printAdjMatrix() {
        cout << "�ڽӾ���:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // ����ڽӱ�
    void printAdjList() {
        cout << "�ڽӱ�:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "���� " << char(i+65) << ": ";
            for (const auto& edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }

    // ������ȱ���
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;

        cout << "DFS��������: ";
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            cout << u << " ";

            // ��������ڽӶ��㣬ȷ����������Ŵ�С�������
            for (auto it = adjList[u].rbegin(); it != adjList[u].rend(); ++it) {
                int v = it->first;
                if (!visited[v]) {
                    visited[v] = true;
                    s.push(v);
                }
            }
        }
        cout << endl;
    }

    // ������ȱ���
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS��������: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // ���������Ķȣ�����ͼ����Ⱥͳ�����ͬ��
    void printVertexDegrees() {
        cout << "������Ķ�:" << endl;
        for (int i = 0; i < V; ++i) {
            int degree = 0;
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    degree++;
                }
            }
            cout << "���� " << char(i+65) << " �Ķ�: " << degree << endl;
        }
    }

    // Prim�㷨����С������
    void primMST(int start) {
        vector<int> key(V, 1000000000); // �����㵽MST����СȨֵ
        vector<bool> inMST(V, false); // �Ƿ���MST��
        vector<int> parent(V, -1); // ���ڵ�

        key[start] = 0;

        for (int count = 0; count < V - 1; ++count) {
            // �ҵ�����MST����keyֵ��С�Ķ���
            int minKey = INT_MAX, u;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            // ���ö������MST
            inMST[u] = true;

            // ���������ڽӶ����keyֵ��parent
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // �����С�������ı�
        cout << "��С�������ı�:" << endl;
        for (int i = 0; i < V; ++i) {
            if (i != start && parent[i] != -1) {
                cout << parent[i] << "-" << i << "-" << adjMatrix[i][parent[i]] << endl;
            }
        }
    }
};

int main() {
    // ����һ������10�������ͼ
    Graph g(10);
	int states = 0;
    // ���ļ���ȡͼ����Ϣ
    if(g.readGraphFromFile("graph.txt"))
    {
		cout<<"�Ѵ��ļ�Graph.txt�ж�ȡͼ"<<endl;
	}
	while(1)
	{
		cout<<"����1�����Ӿ���\n����2����ڽ�����\n����3���������ȱ�������\n����4���������ȱ�������\n����5���ͼ�ĸ�������ĳ��Ⱥ����\n����6�����ĳ�������������С������\n����0�˳�����\n";
		cin>>states;
		switch (states) {
			case 0:
			    return 0;
			case 1:
				g.printAdjMatrix();// ����ڽӾ���
				break;
			case 2:
				g.printAdjList();// ����ڽӱ�
				break;
			case 3:
				// ������ȱ���
				g.DFS(0);
				break;
			case 4:
				// ������ȱ���
				g.BFS(0);
				break;
			case 5:
				 // ���������Ķ�
				g.printVertexDegrees();
				break;
			case 6:
				// Prim�㷨����С������
				g.primMST(0);
			
		}
	}
    return 0;
}    
