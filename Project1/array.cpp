#include<stdio.h>
using namespace std;

int n; // ������������N
bool opr[10]; // ������һ��bool���鱣������n-1�����ţ�������true��ʾ�Ӻ�"+"����false��ʾ����"-"��
bool found = false; // ��ʾ�Ƿ��ҵ�һ��⣬���û�ҵ��Ļ���Ҫ��������"None"
					// dfs��������������״̬��deep��ʾ�ݹ���ȣ�����ö�ٵ��ڼ���������ߵķ��ţ�sum��ʾ֮ǰ���ֱ��ʽ��ֵ��
					// ���ö����ɺ�sum��ֵ�պ�Ϊ0����������鷽����������Ҫ�������Ĺ�������opr���鱣��״̬��
void dfs(int deep, int sum) {
	// ����������������ʽ�����϶�Ӧ��ֵ��
	if (deep == n) {
		if (sum == 0) {
			found = true;
			// �������潫���շ��������������ʽ������Ŀ������
			// ���ǵû���Ŷ��
			for (int i = 1; i<n; i++)
			{
				printf("%d", i);
				if (opr[i])
				{
					printf("+");

				}
				else
				{
					printf("-");
				}

			}
			printf("%d=0\n", n);

		}
		return;
	}
	// �������������������ȷ���߼���
	opr[deep] = true;
	dfs(deep + 1, sum + deep + 1);
	opr[deep] = false;
	dfs(deep + 1, sum - deep - 1);
}

// main�������Լ����Ŷ������~
int main_1() {
	scanf("%d", &n);
	dfs(1, 1);
	if (!found)
		printf("None\n");
	return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;
void quick_sort(int dat[], int l, int r) {
	// ��������д�������������ĳ�ֵ
	int i = l, j = r, mid = dat[r];
	do {
		while (dat[i] < mid) ++i;
		while (dat[j] > mid) --j;
		if (i <= j) {
			swap(dat[i], dat[j]);
			++i; --j;
		}
	} while (i < j);
	// ����������д��һ���ݹ���õĲ�������ϸ�ع�һ�¸ոս��Ŀ��������㷨��˼�����
	if (l < j) quick_sort(dat, l, j);
	// ����������д�ڶ����ݹ���õĲ�����
	if (i < r) quick_sort(dat, i, r);
}
int main() {
	int dat[10] = { 1, 4, 3, 2, 5, 3, 2, 5, 10, 9 };
	quick_sort(dat, 0, 9);
	for (int i = 0; i < 10; ++i)
		printf("%d ", dat[i]);
	return 0;
}