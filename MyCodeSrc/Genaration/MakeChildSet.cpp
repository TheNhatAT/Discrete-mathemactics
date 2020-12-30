#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int checkEnd(int arr[], int m, int n);
void makeChildSet(int arr[], int n, int m);

void makeChildSet(int arr[], int n, int m) {
	if (checkEnd(arr, m, n) == 1) printf("-1");
	else {
		int i = m;
		while (arr[i] == n - m + i) { // n - m + i là các số ở cấu hình cuối cùng
			i = i - 1;
		}
		arr[i] = arr[i] + 1; //thêm 1 cho chữ số khác n - m + i
		for (int j = i + 1; j <= m; j++) {
			arr[j] = arr[i] + j - i; // tăng các số sau arr[i + 1] lên 1, 2, 3,...
		}
		for (int k = 1; k <= m; k++)
		{
			printf("%d ", arr[k]);
		}
	}
}
int checkEnd(int arr[], int m, int n) {
	int i;
	for (i = 1; i <= m; i++) {
		if (arr[i] != n - m + i) {
			return 0; // nếu khác cấu hình cuối, trả về 0.
		}
	}
	return 1;
}
int main() {
	int i, n, m;
	scanf("%d%d", &n, &m);
	int arr[10000]; // max la 100
	for (i = 1; i <= m; i++) { // tập hợp 1->n có chỉ số 1->n
		scanf("%d", &arr[i]);
	}
	makeChildSet(arr, n, m);
	return 0;
}