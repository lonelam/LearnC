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
	cin.sync_with_stdio(false);
	int t,n;
	while (cin >> t)
	{
		while (t--)

		{
			cin >> n;
			if (n == 1 || n == 2)
			{
				cout << 5 << endl;
			}
			else
			{
				cout << 6 << endl;
			}
		}
	}
}