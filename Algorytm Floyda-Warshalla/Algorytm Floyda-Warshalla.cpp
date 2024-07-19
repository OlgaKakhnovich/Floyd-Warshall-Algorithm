#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

const int INF = 99999;

vector<vector<int>> graph = { {0,   5,   4,   8,   INF },
							  {-4,  0,  -2,  INF,  5   },
							  {INF, INF, 0,   5,   2   },
							  {-1,   2, INF,  0,  -1  },
							  {INF, INF, 4,   2 ,   0  } };

int N = graph.size();


vector<vector<int>> Dist(N, vector<int>(N));
vector<vector<int>> Next(N, vector<int>(N));

void inicjalizacja(vector<vector<int>>& graph)
{
	int n = graph.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Dist[i][j] = graph[i][j];
			if (graph[i][j] == INF)
				Next[i][j] = -1;
			else
				Next[i][j] = j;
		}
	}
}

void FloydWarshall(int N)
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j<N; j++)
			{
				if (Dist[i][k] != INF && Dist[k][j] != INF && Dist[i][j] > Dist[i][k] + Dist[k][j])
				{
					Dist[i][j] = Dist[i][k] + Dist[k][j];
					Next[i][j] = Next[i][k];
				}
			}
		}
	}

}

vector<int> Path(int u, int v)
{
	if (Next[u][v] == -1)
		return {};
	vector<int> path = { u };
	while (u != v) {
		u = Next[u][v];
		path.push_back(u);
	}
	return path;
}

void printPath(vector<int>& path)
{
	int n = path.size();
	for (int i = 0; i < n - 1; i++)
	{
		cout << path[i] << "->";
	}
	cout << path[n - 1] << endl;
}

void printDist()
{
	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{
			if (Dist[i][j] == INF)
				cout << "INF"
				<< " ";
			else
				cout << Dist[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() {

	inicjalizacja(graph);
	FloydWarshall(N);
	cout << "PRINT: \n____________\n";
	printDist();
	cout << "_____________\n";
	vector<int> path;
	cout << "From 0 to 2\n ";
	path = Path(0, 2);
	printPath(path);
	cout << "From 0 to 3\n ";
	path = Path(0, 3);
	printPath(path);
	cout << "From 1 to 4\n ";
	path = Path(1, 4);
	printPath(path);
	return 0;
}

