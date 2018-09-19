#include <cstdio>
#include <queue>
using namespace std;

int n, k;

int visited[200022]; // visited[m] m지점까지오는데 최소비용

int validRange(int x) {
	if (!(0 <= x && x <= 200000)) {
		return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &k);

	queue<int> x, step;

	for (int i = 0; i < 200022; i++) {
		visited[i] = 987654321;
	}

	x.push(n); step.push(0);
	visited[n] = 0;

	while (!x.empty()) {
		int curX = x.front(); x.pop();
		int curStep = step.front(); step.pop();

		if (curX == k) {
			printf("%d\n", curStep);
			break;
		}

		if (validRange(curX - 1) && curStep + 1 < visited[curX - 1]) {
			x.push(curX - 1);
			step.push(curStep + 1);
			visited[curX - 1] = curStep + 1;
		}

		if (validRange(curX + 1) && curStep + 1 < visited[curX + 1]) {
			x.push(curX + 1);
			step.push(curStep + 1);
			visited[curX + 1] = curStep + 1;
		}

		if (validRange(curX * 2) && curStep + 1 < visited[curX * 2]) {
			x.push(curX * 2);
			step.push(curStep + 1);
			visited[curX * 2] = curStep + 1;
		}

	}

	return 0;
}