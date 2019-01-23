#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 510;
const int INF = 0x3f3f3f3f;

int G[maxn][maxn];
int d[maxn], c[maxn], weight[maxn], num[maxn];
bool visited[maxn];
int N, M, st, ed;

void Dijkstra(int s);

int main(int argc, char** argv) {
	scanf("%d %d %d %d", &N, &M, &st, &ed);
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int i = 0; i < N; i++){
		scanf("%d", &weight[i]);
	}
	for(int i = 0; i < M; i++){
		int c1, c2, tempW;
		scanf("%d %d %d", &c1, &c2, &tempW);
		G[c1][c2] = G[c2][c1] = tempW;
	}	
	Dijkstra(st);
	printf("%d %d", num[ed], c[ed]);
	return 0;
}

void Dijkstra(int s){
	fill(d, d + maxn, INF);
	d[s] = 0;
	c[s] = weight[s];
	num[s] = 1;
	for(int i = 0; i < N; i++){
		int u = -1, min = INF;
		for(int j = 0; j < N; j++){
			if(d[j] < min && visited[j] == false){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;
		for(int v = 0; v < N; v++){
			if(visited[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + weight[v];
					num[v] = num[u];
				}
				else if(d[u] + G[u][v] == d[v]){
					num[v] += num[u];
					if(c[u] + weight[v] > c[v]){
						c[v] = c[u] + weight[v];
					}
				}
			}
		}
	}
}
