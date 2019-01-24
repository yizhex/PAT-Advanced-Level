#include <cstdio>

const int maxn = 10010;

int dp[maxn], pre[maxn], seq[maxn];

int main(int argc, char** argv) {
	int K;
	scanf("%d", &K);
	bool flag = false;
	for(int i = 0; i < K; i++){
		scanf("%d", &seq[i]);
		if(seq[i] >= 0) flag = true; //判断是否全为负数 
	}
	if(flag == false){ //全为负数输出0
		printf("0 %d %d", seq[0], seq[K - 1]); 
		return 0;
	}
	dp[0] = seq[0];
	pre[0] = 0; //pre数组用来存储当前子列和的开始位置，也就是i的位置 
	int indexI = 0, indexJ = 0, maxSum = dp[0];
	for(int i = 1; i < K; i++){
		if(dp[i - 1] >= 0){ //dp存储的是以当前下标为最后一位的最长子列和 
			dp[i] = dp[i - 1] + seq[i];
			pre[i] = pre[i - 1]; //更新子列和时，开始位置不变 
		}
		else{ //若dp[i - 1]小于等于0的话，那么此时的子列和就为seq[i] 
			dp[i] = seq[i];
			pre[i] = i; 
		}
		if(dp[i] > maxSum){
			maxSum = dp[i];
			indexI = pre[i];
			indexJ = i;
		}
	}
	printf("%d %d %d", maxSum, seq[indexI], seq[indexJ]);
	
	return 0;
}
