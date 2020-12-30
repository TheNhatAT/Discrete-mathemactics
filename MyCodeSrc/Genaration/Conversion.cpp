#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int checkEnd(int* arr, int n) {
	int m = n;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != m) {
			return 0;
		}
		m = m - 1;
	}
	return 1;
}
void swap(int* arr, int x, int y);
void makeConversion(int *arr, int n) {
	if (checkEnd(arr, n) == 1) printf("-1");
	else {
		int i, j, k, r, s;
		  j = n - 1;
		while (arr[j] > arr[j + 1]) j = j - 1; // tim j la chi so lon nhat thoa man aj < aj+1
		  k = n;
		while (arr[j] > arr[k]) k = k - 1; // tim ak(min) > aj ben phai aj
		swap(arr, j, k);
		r = n; s = j + 1;
		while (r > s) {
			swap(arr, r, s);
			r = r - 1; s = s + 1;
		}
		for (int k = 1; k <= n; k++)
		{
			printf("%d ", arr[k]);
		}
	}
}
void swap(int* arr, int x, int y) {
	int cur;
	cur = arr[x];
	arr[x] = arr[y];
	arr[y] = cur;
}
int main() {
	int i, n;
	scanf("%d", &n);
	int arr[10000]; // max la 100
	for (i = 1; i <= n; i++) { // tập hợp 1->n có chỉ số 1->n
		scanf("%d", &arr[i]);
	}
	makeConversion(arr, n);
	return 0;
}