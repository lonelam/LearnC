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
const double k = 155.5;
int main()
{
	int t;
	double a, m;
	cin.sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(2);
	while (cin >> t)
	{
		while (t--)
		{
			
			cin >> a >> m;
			cout << (k * m / a) << endl;
		}
	}
}