#include <iostream> 
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

long long toDecimal(string N, int radix);
long long getLow(string N);

int main(int argc, char** argv) {
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	if(tag == 2) swap(N1, N2); //当tag为2时，交换N1, N2,方便对数据进行统一处理 
	long long decimalN1 = toDecimal(N1, radix);
	long long low = getLow(N2), high = max(low, decimalN1); //分别计算出需要测定进制的上下限，计算上限时，上限一定≥下限，同时题目说明了，当进制不唯一时，输出最小的进制，所以还要加入N1的十进制数作为第二限定条件（此处是难点，多琢磨琢磨） 
	while(low <= high){ //数据量比较大，采用二分法来压缩时间 
		long long mid = (low + high) / 2; //mid即测试的进制 
		long long decimalN2 = toDecimal(N2, mid);
		if(decimalN2 < 0 || decimalN2 > decimalN1){ //难点：如果radix太大超出long long型的范围，会使decimalN2变为负数，此时也代表了进制过大 
			high = mid - 1;
		}else if(decimalN2 < decimalN1){ //进制选取的太小 
			low = mid + 1;
		}else{ //找到正确的进制，输出答案 
			cout << mid;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}

long long toDecimal(string N, int radix){
	long long sum = 0;
	for(int i = 0; i < N.length(); i++){ //注意数字和字母转换成十进制时公式不一样 
		if(isdigit(N[i])) sum = sum * radix + N[i] - '0';
		else sum = sum * radix + N[i] - 'a' + 10;
	}
	return sum;
}

long long getLow(string N){ //获得进制的下限 
	char maxElement = '0';
	for(int i = 0; i < N.length(); i++){
		if(N[i] > maxElement) maxElement = N[i];
	}
	return (isdigit(maxElement) ? maxElement - '0' : maxElement - 'a' + 10) + 1; //最小进制一定比最大的元素大1 
}
