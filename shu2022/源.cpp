#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
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
	int n, m, t;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m;
			if (n & 1 && m & 1)
			{
				cout << "YY\n";
			}
			else
			{
				cout << "XX\n";
			}
		}
	}
}