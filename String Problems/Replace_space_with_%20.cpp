#include <iostream>
using namespace std;

void space20(string &str) {
	int count = 0;
	int size = str.size();

	int index = size - 1;
	while (index-- >= 0) {
		if (str[index] == ' ')
			continue;
		else
			break;
	}
	for (int it = 0; it <= index; it++) {
		if (str[it] == ' ')
			count++;
	}

	str.resize(index + 1 + count*2);
	int new_index = str.size() - 1;
	for (int it = index; it >= 0; it--) {
		if (str[it] == ' ') {
			str[new_index] = '0';
			str[new_index-1] = '2';
			str[new_index-2] = '%';
			new_index -= 3;
		}
		else {
			str[new_index] = str[it];
			new_index--;
		}
	}
}

int main()
{
	string str = "Mr John Smith  ";

	space20(str);
	cout << str << endl;
	return 0;
}
