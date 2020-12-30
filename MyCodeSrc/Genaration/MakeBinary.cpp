#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void makeBinary(int arr[], int n);
int checkEnd(int arr[], int n);

int main() {
	int arr[10000], i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%1d", &arr[i]);
	}
	makeBinary(arr, n);
	return 0;
}

void  makeBinary(int arr[], int n) {
	{
		//while(true) {
			int i = n;
			if (checkEnd(arr, n) == 1) printf("-1");
			else {
				while (arr[i] == 1) { // khi gặp 1 thì lặp từ phải qua trái khi gặp chữ số 0 thì dừng
					arr[i] = 0; // gặp chữ số 1 thì gán thành 0
					i = i - 1; // giảm biến index
				}
				arr[i] = 1; // gán chữ số 0 đầu tiên thấy từ phải qua trái thành 1

				for (int k = 1; k <= n; k++) {
					printf("%d", arr[k]);
				}
			}
		//}
	 }
}

int checkEnd(int arr[], int n)
{
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) return 0;
	}
	return 1;
}
