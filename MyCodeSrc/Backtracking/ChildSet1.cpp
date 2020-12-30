#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int arr[11000], n, m, k, count = 0;


void set(int i) {
	int j;
	if (k == count) return;
	for (j = arr[i - 1] + 1; j <= n - (m - i); j++) {
		arr[i] = j;
		if (i == m) {
			count++;
			if (k == count) {
				for (int i = 1; i <= m; i++) {
					printf("%d ", arr[i]);
				}
				return;
			}
		}
		else set(i + 1);
	}
}
int main() {
	arr[0] = 0;
	scanf("%d%d%d", &n, &m, &k);
	set(1);
	printf("%d", count);
	if (k > count) printf("-1");
	return 0;
}