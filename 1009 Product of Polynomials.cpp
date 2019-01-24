#include <cstdio>
#include <map>

using namespace std;

const int maxn = 1010;

map<int, double> poly, polyResult;

int main(int argc, char** argv) {
	int K1, K2, expo;
	double coef;
	scanf("%d", &K1);
	while(K1--){
		scanf("%d %lf", &expo, &coef);
		poly[expo] = coef;
	}
	scanf("%d", &K2);
	while(K2--){
		scanf("%d %lf", &expo, &coef);
		for(map<int, double>::iterator it = poly.begin(); it != poly.end(); it++){
			polyResult[expo + it->first] += coef * it->second; 
		}
	}
	int cnt = 0;
	for(map<int, double>::iterator it = polyResult.begin(); it != polyResult.end(); it++){
		if(it->second != 0.0) cnt++;
	}
	printf("%d", cnt);
	for(map<int, double>::reverse_iterator it = polyResult.rbegin(); it != polyResult.rend(); it++){
		if(it->second != 0.0) printf(" %d %.1f", it->first, it->second);
	}
	return 0;
}
