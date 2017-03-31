#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

// adj list
vector<vector<int> > adj;
vector<bool> visited;
vector<int> order;
int N;

void dfs(int here)
{
	cout << " visit: " << here << endl;
	visited[here] = true;

	for(int i=0 ; i<adj[here].size() ; i++)
	{
		if(adj[here][i] && !visited[i])
		{
			dfs(i);
		}
	}

	order.push_back(here);
}

void dfsAll()
{
	visited = vector<bool>(adj.size(), false);
	int nComponent = 0;
	for(int i=0 ; i<adj.size() ; i++){
		if(!visited[i]){
			dfs(i);
			nComponent++;
			cout << "# Component: " << nComponent << endl;
		}
	}
	cout << "Total of Components = " << nComponent << endl;

	reverse(order.begin(), order.end());

	vector<int>::iterator it;
	cout << "topological order = " ;
	for(it=order.begin() ; it!=order.end() ; it++){
		cout << *it << " " ; 
	}
	cout << endl;
}

int main()
{
	freopen("sample.txt", "r", stdin);
	cin >> N;

	cout << "N: " << N << endl;
	char a, b;
	adj = vector<vector<int> > (8, vector<int>(8, 0));
	for(int i = 0 ; i<N ; i++){
		cin >> a >> b;
		int _a, _b;
		_a = a -'a';
		_b = b - 'a';
		adj[_a][_b] = 1;
		cout << a << "," << b << ":" << adj[_a][_b] << endl;
	}
	
	dfsAll();

	return 1;
}
