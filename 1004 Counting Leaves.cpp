#include <cstdio>
#include <queue>
#include <vector> 

using namespace std;

const int maxn = 110;

typedef struct {
	int layer;
	vector<int> child;
}Node;

int leaves[maxn], maxLayer = -1;
Node node[maxn];

void levelOrder(int st);

int main(int argc, char** argv) {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int father, K, tempChild;
		scanf("%d %d", &father, &K);
		for(int j = 0; j < K; j++){
			scanf("%d", &tempChild);
			node[father].child.push_back(tempChild);
		}
	}
	levelOrder(1);
	for(int i = 1; i <= maxLayer; i++){
		if(i != 1) printf(" ");
		printf("%d", leaves[i]);
	}
	return 0;
}

void levelOrder(int st){
	queue<int> q;
	q.push(st);
	node[st].layer = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(node[now].child.empty()){
			leaves[node[now].layer]++; //这一层的叶结点数目+1 
			if(node[now].layer > maxLayer){ //最大层的节点一定为叶结点 
				maxLayer = node[now].layer;
			}
		}
		for(int i = 0; i < node[now].child.size(); i++){
			q.push(node[now].child[i]);
			node[node[now].child[i]].layer = node[now].layer + 1; //孩子结点的层数+1 
		}
	}
}
