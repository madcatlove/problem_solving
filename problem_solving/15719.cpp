#include <cstdio>
#include <iostream>
using namespace std;

int m[333333];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int d; 
		cin >> d;
		

		// check
		if (m[d/32] & (1<<(d%32)))  {
			cout << d << endl;
			break;
		}

		// set
		m[d / 32] = m[d / 32] | (1 << (d % 32));
	}

	return 0;
}