#include <iostream>
#include <string>
using namespace std;

bool isKPeriodic(const string& str, int k) {
	if (k <= 0) {
		//if there need to explain this case to the user, uncomment next line
		//cout << "k must be more than zero!" << endl;
		return false;
	}
	if (str.length() % k != 0) return false;
	// the homework condition doesn't indicate whether the case of a single repetition is actually is a k-periodical; if not, uncomment next line
	//if (str.length() == k) return false;
	string pattern = str.substr(0, k);
	for (size_t i = 1; i < str.length() / k; i++) {
		if (str.substr(i * k, k) != pattern) return false;
	}
	return true;
}

void test(const string& str, int k) {
	cout << str << "            length is " << str.length() << "  k = " << k << "   " << (isKPeriodic(str, k) ? "True" : "False") << endl;

}

int main() {
	string sample1 = "abcabcabcabc";
	string sample2 = "abcabcabcab";
	string sample3 = "abcabcabcabca";
	string sample4 = "abcabcabcabd";
	string sample5 = "abc";


	test(sample1, 6);
	test(sample2, 3);
	test(sample3, 3);
	test(sample4, 3);
	test(sample1, 4);
	test(sample1, 0);
	test(sample5, 3);
}
