#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string &input, string output, int itr) {
	if(itr == input.size()) {
		cout << output << endl;
		return;
	}
	
	//include
	printSubsequence(input, output + input[itr], itr + 1);
	
	//exclude
	printSubsequence(input, output, itr + 1);
}

int main() {
	string output = "";
	string input = "abc";
	printSubsequence(input, output, 0);
	return 0;
}
