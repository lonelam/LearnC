#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
/*
-----------Answered by Lonelam---------
*
*          ������       ������
*       �������� �ة��������������� �ة�����
*       ��                 ��
*       ��       ������       ��
*       ��  ���Щ�       ���Щ�  ��
*       ��                 ��
*       ��       ���ة�       ��
*       ��                 ��
*       ����������         ����������
*           ��         ��
*           ��         ��
*           ��         ��
*           ��         ��������������������������������
*           ��                        ��
*           ��                        ������
*           ��                        ������
*           ��                        ��
*           ������  ��  �����������������Щ�����  ��������
*             �� ���� ����       �� ���� ����
*             �������ة�����       �������ة�����
*                 ���ޱ���
*                 ������BUG!
*/
using namespace std;

int main()
{
	int t,n,m,a,b;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> a >> b;
			cout << 5 * (n - 1 + abs(n - a)) <<' '<< 5 * (n - 1 + abs(n - b)) << endl;
		}
	}
}