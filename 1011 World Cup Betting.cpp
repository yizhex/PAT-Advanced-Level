#include <cstdio>

char bet[3] = {'W', 'T', 'L'};

int main(int argc, char** argv) {
	double allOdds = 1;
	int ans[3];
	for(int i = 0; i < 3; i++){
		double odds, maxOdds = -1;
		for(int j = 0; j < 3; j++){
			scanf("%lf", &odds);
			if(odds > maxOdds){
				maxOdds = odds;
				ans[i] = j;
			}
		}
		allOdds *= maxOdds;
	}
	allOdds = (allOdds * 0.65 - 1) * 2;
	for(int i = 0; i < 3; i++){
		printf("%c ", bet[ans[i]]);
	}
	printf("%.2f", allOdds);
	return 0;
}
