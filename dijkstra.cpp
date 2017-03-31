#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Graph{
	int V;
	int E;
	int** Adj;
};

struct Edge{
	int to;
	int weight;
};

struct Comp{
	bool operator() (struct Edge E1, struct Edge E2){
		return E1.weight > E2.weight;
	}
};

struct Graph* newAdjMatrixOfGraph();
void DijkstraAlg();
void Dijkstra(struct Graph* G, int start, int end);
void BacktrackPath(int* Path, int start, int end);

int main(void){
	DijkstraAlg();
	return 0;
}

void DijkstraAlg(){
	struct Graph* G = newAdjMatrixOfGrapth();
	int start , end;
	cout << "시작점을 입력하세요" ; cin >> start;
	cout << "끝점을 입력하세요"; cin >> end;
	Dijkstra(G, start, end);
}

void Dijkstra(struct Graph* G, int start, int end)
{
	priority_queue<Edge, vector<Edge>, Comp> PQ;
	struct Edge E;
	E.to = start;
	E.weight = 0;
	PQ.push(E);
}
