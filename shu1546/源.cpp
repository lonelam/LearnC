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
*           ��                        ��20��2�֣�50��50��2��20��4�֣���1��10����5��
*           ������  ��  �����������������Щ�����  ��������
*             �� ���� ����       �� ���� ����100�Ļ�����100��2*50��11��
*             �������ة�����       �������ة�����
*                 ���ޱ���
*                 ������BUG!
*/
using namespace std;
int dp[1001];//
int main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				for (int l = 0; l < 11; l++)
				{
					
					if ((n=i + j * 2 + k * 5 + l * 10 )< 101)
					{
						dp[n] ++;
					}
				}
			}
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n / 10]);
	}
}