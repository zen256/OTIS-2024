#pragma once
using namespace std;
#pragma once
void dfs(int**, int, int, vector<bool>&);
void bfs(int**, int, int, vector<bool>&);
void Fill_Matrix(int**&, int, int, string);
void Paint_Matrix(int**&, int);
bool Gamilton(int**&, int*&, int*&, int, int, int);
void Print_Path(int*&, int);
void Euler(int**&, vector<int>&, int);
void Dijkstra(int**&, int);
void Floyd(int**&, int);
void Prim(int**&, int);
int parent(int*, int);
void union_find(int*, int, int);
void Kruskal(pair<int, pair <int, int>>*, int*, int**&, int, int);
void main_kruskal(int**&, int, int, string);
void Kali();
void Permutation(string);
void StrongConnectedComponents(int**&, int);
//void findBiconnectedComponents(int**&, int);
void FindArtPointsAndBridges(int**&, int);