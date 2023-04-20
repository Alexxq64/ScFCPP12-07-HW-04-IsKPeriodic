#include <iostream>
#include <string>
using namespace std;

bool isKPeriodic(const string& str, int k) {
	if (k <= 0) {
		cout << "k must be more than zero!" << endl;
		return false;
	}
	if (str.length() % k != 0) return false;
	string pattern = str.substr(0, k);
	for (size_t i = 0; i < str.length() / k; i++) {
		if (str.substr(i * k, k) != pattern) return false;
	}
	return true;
}

void test(const string& str, int k) {
	cout << str << " k = " << k << "   " << (isKPeriodic(str, k) ? "True" : "False") << endl;

}

int main() {
	string sample1 = "abcabcabcabc";
	string sample2 = "abcabcabcab";
	string sample3 = "abcabcabcabca";
	string sample4 = "abcabcabcabd";

	test(sample1, 3);
	test(sample2, 3);
	test(sample3, 3);
	test(sample4, 3);
	test(sample1, 4);
	isKPeriodic(sample1, 0);
}
