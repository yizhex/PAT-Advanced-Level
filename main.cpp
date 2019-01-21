#include <cstdio>

const int maxn = 1010;

double poly[maxn];

int main(int argc, char** argv) {
	int K, expo;
	double coef;
	for(int i = 0; i < 2; i++){
		scanf("%d", &K);
		for(int j = 0; j < K; j++){
			scanf("%d %lf", &expo, &coef);
			poly[expo] += coef;
		}
	}
	int cnt = 0;
	for(int i = maxn; i >= 0; i--){
		if(poly[i] != 0){
			cnt++;
		}
	}
	printf("%d", cnt);
	for(int i = maxn; i >= 0; i--){
		if(poly[i] != 0){
			printf(" %d %.1f", i, poly[i]);
		}
	}
	return 0;
}
