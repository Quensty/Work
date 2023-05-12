#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#include<Windows.h>
using namespace std;

int topics_num;//�û��ƶ�������Ŀ����
bool operation[5] = { 0 };//�û�ѡ�������
string operate[5] = { "+","-","*","/" };
int magnitude = 0;//�û�ѡ������������10��100��
bool bracket = 0, decimal = 0;//�Ƿ������š�С��
int out_way = 0;//�û�ѡ�������ʽ����ʾ1�������ļ�2��
int level = 0;//�û�ѡ����Ŀ�ȼ���1��2��3��

void select_amount()//�û��ƶ�������Ŀ����
{
	topics_num = 0;
	cout << "��        ���������붨�Ƶ���Ŀ����        ��" << endl;
	cout << "��";
	cin >> topics_num;
	cout << "                                         ��" << endl;
	return;
}

void select_operation()//�û�ѡ�������
{
	memset(operation, 5, 0);
	string in;
	cout << "��         ����������ѡ��������         ��" << endl;
	cout << "��";
	cin >> in;
	cout << "                                         ��" << endl;
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i] == '+')
			operation[0] = 1;
		if (in[i] == '-')
			operation[1] = 1;
		if (in[i] == '*')
			operation[2] = 1;
		if (in[i] == '/')
			operation[3] = 1;
		if (in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
			cout << "��        !!!��������ȷ�������!!!        ��" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			select_operation();
		}
	}
	return;
}

void select_data_magnitude()//�û�ѡ������������10��100��
{
	magnitude = 0;
	cout << "��  ����������ѡ�������������10��100��   ��" << endl;
	cout << "��";
	cin >> magnitude;
	cout << "                                         ��" << endl;
	return;
}

void select_bracket()//�û�ѡ���Ƿ���Ҫ����
{
	bracket = 0;
	string in;
	cout << "�����������Ƿ���Ҫ���ţ��ǡ�1��  ��0������" << endl;
	cout << "��";
	cin >> in;
	cout << "                                         ��" << endl;
	if (in == "1")
		bracket = 1;
	else if (in == "0")
		bracket = 0;
	else
	{
		cout << "��          !!!��������ȷ��ѡ��!!!        ��" << endl;
		select_bracket();
	}
	return;
}

void select_decimal()//�û�ѡ�������ʽ
{
	decimal = 0;
	string in;
	cout << "�����������Ƿ���ҪС�����ǡ�1��  ��0������" << endl;
	cout << "��";
	cin >> in;
	cout << "                                         ��" << endl;
	if (in == "1")
		decimal = 1;
	else if (in == "0")
		decimal = 0;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "��          !!!��������ȷ��ѡ��!!!        ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_decimal();
	}
	return;
}

void output();

void select_level()//�û�ѡ����Ŀ�ȼ���1��2��3��
{
	level = 0;
	string in;
	cout << "����������Ŀ�ȼ�(LV1��1��LV2��2��LV3��3��)��" << endl;
	cout << "��";
	cin >> in;
	cout << "                                         ��" << endl;
	if (in == "1")
		output();
	else if (in == "2")
		level = 0;
	else if (in == "3")
		level = 0;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "��          !!!��������ȷ��ѡ��!!!        ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_decimal();
	}
	return;
}

void select_output()//�û�ѡ�������ʽ
{
	out_way = 0;
	string in;
	cout << "����ѡ�������ʽ����ʾ��1�������ļ���2������" << endl;
	cout << "��";
	cin >> in;
	cout << "                                         ��" << endl;
	if (in == "1")
		out_way = 1;
	else if (in == "2")
		out_way = 2;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "��          !!!��������ȷ��ѡ��!!!        ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_decimal();
	}
	return;
}

void screen()//����̨��ʾ
{
	int sum = 0, num = 0;
	int a[5] = { 0,1,2,3,4 };
	int a1[100][5] = { 0 };
	string sequence[5];
	for (int i = 0; i < 4; i++)
	{
		if (operation[i] == 1)
		{
			sequence[sum++] = operate[i];
		}
	}
	do
	{
		for (int i = 0; i < sum; i++)
		{
			a1[num][i] = a[i];
		}
		num++;
	} while (next_permutation(a, a + sum));
	if (decimal == 1)
	{
		for (int i = 0; i < topics_num; i++)
		{
			int t = rand();
			for (int j = 0; j < sum; j++)
			{
				cout << double(rand() % (magnitude * 100) / 100.0);
				cout << sequence[a1[t % int(pow(2, sum))][j]];
			}
			cout << double(rand() % (magnitude * 100) / 100.0) << "=" << endl;
		}

	}
	else
	{
		for (int i = 0; i < topics_num; i++)
		{
			int t = rand();
			for (int j = 0; j < sum; j++)
			{
				cout << rand() % magnitude;
				cout << sequence[a1[t % int(pow(2, sum))][j]];
			}
			cout << rand() % magnitude << "=" << endl;
		}

	}
	return;
}

void file()//����ļ�
{
	ofstream fout("output.txt");
	queue<char>b;
	int sum = 0, num = 0;
	int a[5] = { 0,1,2,3,4 };
	int a1[100][5] = { 0 };
	string sequence[5];
	for (int i = 0; i < 4; i++)
	{
		if (operation[i] == 1)
		{
			sequence[sum++] = operate[i];
		}
	}
	do
	{
		for (int i = 0; i < sum; i++)
		{
			a1[num][i] = a[i];
		}
		num++;
	} while (next_permutation(a, a + sum));
	if (decimal == 1)
	{
		for (int i = 0; i < topics_num; i++)
		{
			int t = rand();
			for (int j = 0; j < sum; j++)
			{
				fout << double(rand() % (magnitude * 100) / 100.0);
				fout << sequence[a1[t % int(pow(2, sum))][j]];
			}
			fout << double(rand() % (magnitude * 100) / 100.0) << "=" << endl;
		}

	}
	else
	{
		for (int i = 0; i < topics_num; i++)
		{
			int t = rand();
			for (int j = 0; j < sum; j++)
			{
				fout << rand() % magnitude;
				fout << sequence[a1[t % int(pow(2, sum))][j]];
			}
			fout << rand() % magnitude << "=" << endl;
		}

	}
	return;
}

void output()//������ʽ
{
	if (out_way == 1)
		screen();
	if (out_way == 2)
		file();
	return;
}



void welcome()
{
	int next = 0;
	while (1)
	{
		system("cls");
		cout << "������������������������������������������������������������������������������������" << endl;
		cout << "��        ��ӭ������������������          ��" << endl;
		cout << "��                                        ��" << endl;
		cout << "����һ�����룿                            ��" << endl;
		cout << "����1�� ��������                          ��" << endl;
		cout << "����2�� ��Ҫ�˳�                          ��" << endl;
		cout << "��";
		cin >> next;
		cout << "                                         ��" << endl;

		if (next == 2)//�˳�
		{
			cout << "��                  bye~                  ��" << endl;
			cout << "������������������������������������������������������������������������������������" << endl;
			return;
		}

		select_amount();
		select_operation();
		select_data_magnitude();
		select_bracket();
		select_decimal();
		select_output();
		output();
		Sleep(5000);
	}
}

int main()
{
	welcome();
	return 0;
}