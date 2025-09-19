#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <algorithm>
#define INT_MAX 100000000
using namespace std;

// 边的结构体，用于Kruskal算法
struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adjMatrix; // 邻接矩阵
    vector<vector<pair<int, int>>> adjList; // 邻接表，存储(顶点, 权值)

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    // 从文件读取图的信息
    bool readGraphFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "无法打开文件" << endl;
            return 0;
        }

        int u, v, weight;
        while (file >> u >> v >> weight) {
            addEdge(u-1, v-1, weight);
        }
        file.close();
        return 1;
    }

    // 添加边
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // 输出邻接矩阵
    void printAdjMatrix() {
        cout << "邻接矩阵:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // 输出邻接表
    void printAdjList() {
        cout << "邻接表:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "顶点 " << char(i+65) << ": ";
            for (const auto& edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }

    // 深度优先遍历
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        visited[start] = true;

        cout << "DFS遍历序列: ";
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            cout << u << " ";

            // 逆序遍历邻接顶点，确保按顶点序号从小到大访问
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

    // 广度优先遍历
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS遍历序列: ";
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

    // 计算各顶点的度（无向图的入度和出度相同）
    void printVertexDegrees() {
        cout << "各顶点的度:" << endl;
        for (int i = 0; i < V; ++i) {
            int degree = 0;
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    degree++;
                }
            }
            cout << "顶点 " << char(i+65) << " 的度: " << degree << endl;
        }
    }

    // Prim算法求最小生成树
    void primMST(int start) {
        vector<int> key(V, 1000000000); // 各顶点到MST的最小权值
        vector<bool> inMST(V, false); // 是否在MST中
        vector<int> parent(V, -1); // 父节点

        key[start] = 0;

        for (int count = 0; count < V - 1; ++count) {
            // 找到不在MST中且key值最小的顶点
            int minKey = INT_MAX, u;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            // 将该顶点加入MST
            inMST[u] = true;

            // 更新所有邻接顶点的key值和parent
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // 输出最小生成树的边
        cout << "最小生成树的边:" << endl;
        for (int i = 0; i < V; ++i) {
            if (i != start && parent[i] != -1) {
                cout << parent[i] << "-" << i << "-" << adjMatrix[i][parent[i]] << endl;
            }
        }
    }
};

int main() {
    // 创建一个包含10个顶点的图
    Graph g(10);
	int states = 0;
    // 从文件读取图的信息
    if(g.readGraphFromFile("graph.txt"))
    {
		cout<<"已从文件Graph.txt中读取图"<<endl;
	}
	while(1)
	{
		cout<<"输入1输出领接矩阵\n输入2输出邻接链表\n输入3输出深度优先遍历序列\n输入4输出广度优先遍历序列\n输入5输出图的各个定点的出度和入度\n输入6输出从某个顶点出发的最小生成树\n输入0退出程序\n";
		cin>>states;
		switch (states) {
			case 0:
			    return 0;
			case 1:
				g.printAdjMatrix();// 输出邻接矩阵
				break;
			case 2:
				g.printAdjList();// 输出邻接表
				break;
			case 3:
				// 深度优先遍历
				g.DFS(0);
				break;
			case 4:
				// 广度优先遍历
				g.BFS(0);
				break;
			case 5:
				 // 计算各顶点的度
				g.printVertexDegrees();
				break;
			case 6:
				// Prim算法求最小生成树
				g.primMST(0);
			
		}
	}
    return 0;
}    
