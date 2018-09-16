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
			// a[] b[] �̿��� ��� ���� ��츦 x�� ����
			// c[] d[] �̿��� ��� ���� ��츦 y�� ����
			x.push_back(a[i] + b[j]);
			y.push_back(c[i] + d[j]);
		}
	}

	//sort(x.begin(), x.end()); // �ð��ʰ��ֹ�;;;
	sort(y.begin(), y.end());

	for (int i = 0; i < x.size(); i++) {

		int m, s = 0, _low=0, _up=0;
		int e = y.size();
		
		//------------------
		// x[i] �� -30�̸�
		// y[?] ���� 30�ξָ� ã�ƾ��ϴµ�. 30�� �ְ� �������� �� �ִ�.
		// ���� binary search�� lower bound / upper bound�� ����
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