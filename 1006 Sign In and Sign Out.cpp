#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;

int main(int argc, char** argv) {
	char earliestID[16], latestID[16], ID[16];
	int earliestTime = INF, latestTime = -INF, M, inTime, outTime;
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		int hh, mm, ss;
		scanf("%s %d:%d:%d", ID, &hh, &mm, &ss);
		inTime = hh * 10000 + mm * 100 + ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		outTime = hh * 10000 + mm * 100 + ss;
		if(inTime < earliestTime){
			earliestTime = inTime;
			strcpy(earliestID, ID);
		}
		if(outTime > latestTime){
			latestTime = outTime;
			strcpy(latestID, ID);
		}
	}
	printf("%s %s", earliestID, latestID);
	return 0;
}
