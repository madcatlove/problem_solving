#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[4011], b[4011], c[4011], d[4011];
vector<int> x, y;
long long cnt = 0;

int main() {
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// a[] b[] 이용한 모든 합의 경우를 x에 저장
			// c[] d[] 이용한 모든 합의 경우를 y에 저장
			x.push_back(a[i] + b[j]);
			y.push_back(c[i] + d[j]);
		}
	}

	//sort(x.begin(), x.end()); // 시간초과주범;;;
	sort(y.begin(), y.end());

	for (int i = 0; i < x.size(); i++) {

		int m, s = 0, _low=0, _up=0;
		int e = y.size();
		
		//------------------
		// x[i] 가 -30이면
		// y[?] 에서 30인애를 찾아야하는데. 30인 애가 여러개일 수 있다.
		// 따라서 binary search로 lower bound / upper bound를 구현
		//-------------------

		s = 0, e = y.size()-1;
		while (s < e) {
			m = (s + e) / 2;
			if (x[i] + y[m] < 0) s = m + 1;
			else e = m;
		}
		_low = e;

		s = 0, e = y.size()-1;
		while (s < e) {
			m = (s + e) / 2;
			if (x[i] + y[m] <= 0) s = m + 1;
			else e = m;
		}
		_up = e;

		cnt = cnt + (_up - _low);
	}


	printf("%lld\n", cnt);

	return 0;
}