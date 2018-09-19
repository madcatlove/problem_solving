#include <iostream>
using namespace std;

#define OFFSET (10000000)
int m[20000022];
int _MIN = 987654321;
int _MAX = -_MIN;

#define SMIN(a,b) ((a)>(b) ? (b) : (a))
#define SMAX(a,b) ((a)>(b) ? (a) : (b))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		m[d+OFFSET]++;

		_MIN = SMIN(_MIN, (d + OFFSET));
		_MAX = SMAX(_MAX, (d + OFFSET));
	}

	for (int i = _MIN; i <= _MAX; i++) {
		if (m[i]) {
			for (int j = 0; j < m[i]; j++) {
				cout << (i - OFFSET) << "\n";
			}
		}
	}




	return 0;
}