#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<Windows.h>
using namespace std;

int topics_num;//用户制定生成题目数量
bool operation[5] = { 0 };//用户选择运算符
string operate[5] = { "+","-","*","/" };
int magnitude = 0;//用户选择数据量级（10，100）
bool bracket = 0, decimal = 0;//是否有括号、小数
int out_way = 0;//用户选择输出方式（显示1、导出文件2）
int level = 0;//用户选择题目等级（1、2、3）

void select_amount()//用户制定生成题目数量
{
	topics_num = 0;
	cout << "│        请输入您想定制的题目数量        │" << endl;
	cout << "│";
	cin >> topics_num;
	cout << "                                         │" << endl;
	return;
}

void select_operation()//用户选择运算符
{
	memset(operation, 5, 0);
	string in;
	cout << "│         请输入您想选择的运算符         │" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
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
			cout << "│        !!!请输入正确的运算符!!!        │" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			select_operation();
		}
	}
	return;
}

void select_data_magnitude()//用户选择数据量级（10，100）
{
	magnitude = 0;
	string in;
	cout << "│  请输入您想选择的数据量级（10，100）   │" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
	if (in == "10")
		magnitude = 10;
	else if (in == "100")
		magnitude = 100;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "│          !!!请输入正确的选项!!!        │" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_data_magnitude();
	}
	return;

}

void select_bracket()//用户选择是否需要括号
{
	bracket = 0;
	string in;
	cout << "│请输入您是否需要括号（是·1·  否·0·）│" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
	if (in == "1")
		bracket = 1;
	else if (in == "0")
		bracket = 0;
	else
	{
		cout << "│          !!!请输入正确的选项!!!        │" << endl;
		select_bracket();
	}
	return;
}

void select_decimal()//用户选择输出方式
{
	decimal = 0;
	string in;
	cout << "│请输入您是否需要小数（是·1·  否·0·）│" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
	if (in == "1")
		decimal = 1;
	else if (in == "0")
		decimal = 0;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "│          !!!请输入正确的选项!!!        │" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_decimal();
	}
	return;
}

void output();

void select_level()//用户选择题目等级（1、2、3）
{
	level = 0;
	string in;
	cout << "│请输入题目等级(LV1·1·LV2·2·LV3·3·)│" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
	if (in == "1")
		level = 1;
	else if (in == "2")
		level = 2;
	else if (in == "3")
		level = 3;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "│          !!!请输入正确的选项!!!        │" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_level();
	}
	return;
}

void select_output()//用户选择输出方式
{
	out_way = 0;
	string in;
	cout << "│请选择输出方式（显示·1·导出文件·2·）│" << endl;
	cout << "│";
	cin >> in;
	cout << "                                         │" << endl;
	if (in == "1")
		out_way = 1;
	else if (in == "2")
		out_way = 2;
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		cout << "│          !!!请输入正确的选项!!!        │" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		select_decimal();
	}
	return;
}

void screen()//控制台显示
{
	int sum = 0, num = 0;
	int a[5] = { 0,1,2,3,4 }, b[5] = {1,3,5,0 };
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
	for (int i = 0; i < topics_num; i++)
	{
		int t = rand();
		int p = sum + rand() % level + level;
		int q = rand() % (p - 2);
		int u = rand() % (p - q - 1);
		cout << "NO." << i + 1 << "：";
		for (int j = 0; j < p; j++)
		{
			if (bracket == 1)
			{
				if (j == q)
					cout << "(";
			}
			if (decimal == 1)
				cout << double(rand() % (magnitude * 100) / 100.0);
			else
				cout << rand() % magnitude;
			if (bracket == 1)
			{
				if (j == q + 1 + u)
					cout << ")";
				if (j == p - 1)
					break;
			}
			cout << sequence[a1[t % int(pow(2, sum))][j]];
		}
		cout << "=" << endl;
	}
	return;
}

void file()//输出文件
{
	ofstream fout("output.txt");
	int sum = 0, num = 0;
	int a[5] = { 0,1,2,3,4 }, b[5] = { 1,3,5,0 };
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
	for (int i = 0; i < topics_num; i++)
	{
		int t = rand();
		int p = sum + rand() % level + level;
		int q = rand() % (p - 2);
		int u = rand() % (p - q - 1);
		fout << "NO." << i + 1 << "：";
		for (int j = 0; j < p; j++)
		{
			if (bracket == 1)
			{
				if (j == q)
					fout << "(";
			}
			if (decimal == 1)
				fout << double(rand() % (magnitude * 100) / 100.0);
			else
				fout << rand() % magnitude;
			if (bracket == 1)
			{
				if (j == q + 1 + u)
					fout << ")";
				if (j == p - 1)
					break;
			}
			fout << sequence[a1[t % int(pow(2, sum))][j]];
		}
		fout << "=" << endl;
	}
	return;
}

void output()//生成算式
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
		cout << "┌────────────────────────────────────────┐" << endl;
		cout << "│        欢迎来到四则运算生成器          │" << endl;
		cout << "│                                        │" << endl;
		cout << "│下一步您想？                            │" << endl;
		cout << "│·1· 继续出题                          │" << endl;
		cout << "│·2· 我要退出                          │" << endl;
		cout << "│";
		cin >> next;
		cout << "                                         │" << endl;

		if (next == 2)//退出
		{
			cout << "│                  bye~                  │" << endl;
			cout << "└────────────────────────────────────────┘" << endl;
			return;
		}

		select_amount();
		select_operation();
		select_data_magnitude();
		select_bracket();
		select_decimal();
		select_output();
		select_level();
		output();
		Sleep(5000);
	}
}

int main()
{
	welcome();
	return 0;
}
