#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int arr[10000], n, z, k, countBinary = 0, t;

void genFind(int i);
int UCV(int i);

int UCV(int i) {
	int countZero = 0;
	for (int h = 1; h <= i; h++) {
		countZero = 0;
		if (arr[h] == 0) {
			int index = h;
			while (arr[index] == 0 && index <= i) {
				countZero++; // lap den khi gap so 1 dau tien
				index++;
			}
			if (countZero >= z) return 0;
		}
	}
	return 1;
}
void genFind(int i) {
if (countBinary == k) return;
      if (UCV(i) == 1) t = 0;
      else t = 1; 
		for (int j = t; j <= 1; j++) {
			arr[i] = j;
			if (i == n) {
				countBinary++;
				if (countBinary == k) {
				for (int i = 1; i <= n; i++) printf("%d ", arr[i]); printf("\n");
					return;
				}
			}
			else genFind(i + 1);
			for (int cur = i; cur <= n; cur++) arr[cur] = 0; // sau khi backtracking lên thì phải trả lại trạng thái của dãy arr //
		}
	
	/*
		arr[i] = 1;
		if (i == n) {
			countBinary++;
			if (countBinary == k) {
				for (int i = 1; i <= n; i++) printf("%d ", arr[i]); printf("\n");
				return;
			}
		}
		else genFind(i + 1);
		for (int cur = i; cur <= n; cur++) arr[cur] = 0; // sau khi backtracking lên thì phải trả lại trạng thái của dãy arr // */
}
int main() {
	scanf("%d%d%d", &n, &k, &z);
	genFind(1);
	if (countBinary < k) printf("-1"); 0;
}