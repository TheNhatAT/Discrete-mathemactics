#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int arr[10000], n , m;


void print() {
	for (int i = 1; i <= m; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

void set(int i) {
	int j;
	for (j = arr[i - 1] + 2; j <= n - 2 * (m - i); j++) {
		arr[i] = j;
		if (i == m) print();
		else set(i + 1);
	}
}
int main() {
	arr[0] = -1;
	scanf("%d%d", &n, &m);
	set(1);
	return 0;
}