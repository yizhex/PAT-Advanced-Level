#include <string>
#include <iostream>

using namespace std;

string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(int argc, char** argv) {
	string input;
	cin >> input;
	int sum = 0;
	for(int i = 0; i < input.length(); i++){
		sum += input[i] - '0';
	}
	string output = to_string(sum);
	for(int i = 0; i < output.length(); i++){
		if(i != 0) cout << " ";
		cout << word[output[i] - '0'];
	}
	return 0;
}
