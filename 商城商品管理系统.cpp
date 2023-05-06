#include<iostream>
#include<string.h>
using namespace std;
class Good//��Ʒ����
{
protected:
	string name;//��Ʒ����
	double price;//��Ʒ�۸�
	string manufacturer;//��Ʒ����
	double sumdiscount;//������Ʒ�ۿ�
public:
	virtual void display()const
	{
		cout << "��Ʒ���ƣ�" << name << endl;
		cout << "��Ʒ�۸�" << price << endl;
		cout << "��Ʒ���ң�" << manufacturer << endl;
	}
	Good(string a, double b, string c, double d = 10)
	{
		name = a;
		price = b;
		manufacturer = c;
		sumdiscount = d;
	}
	Good() {}
};
class Good_living :public Good//������Ʒ��
{
protected:
	double discount1;//��������Ʒ�ۿ�
public:
	Good_living(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	Good_living() {}
	virtual void display()const
	{
		Good::display();
		cout << "��Ʒ���ͣ���������Ʒ" << endl;
	}
};
class Food :public Good_living//ʳƷ��
{
protected:
	int year, month, day;//��������
	int shelf_time;//������
	double discount2;//�����ۿ�
	double discount;//�ϼ��ۿ�
public:
	Food(string a, double b, string c, int d, int e, int f, int g, double h = 10, double i = 10, double j = 10) :Good_living(a, b, c, h, i)
	{
		year = d;
		month = e;
		day = f;
		shelf_time = g;
		discount2 = j;
		discount = sumdiscount * discount1 * discount2 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_living::display();
		cout << "ʳƷ�������ڣ�" << year << "��" << month << "��" << day << "��" << endl;
		cout << "ʳƷ�����ڣ�" << shelf_time << "��" << endl;
		cout << "ʳƷ���ۿۣ�" << discount << "��" << endl;
	}
};
class Clothes :public Good_living//������
{
protected:
	char sex;//��װŮװ
	char type;//��װ����
	char color;//��װ��ɫ
	string size;//����
	double discount2;//�����ۿ�
	double discount;//�ۿ�
public:
	Clothes(string a, double b, string c, char d, char e, char f, string g, double h = 10, double i = 10, double j = 10) :Good_living(a, b, c, h, i)
	{
		sex = d;
		type = e;
		color = f;
		size = g;
		discount2 = j;
		discount = sumdiscount * discount1 * discount2 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_living::display();
		cout << "��װ�Ա�" << sex << "װ" << endl;
		cout << "��װ���ͣ�" << type << endl;
		cout << "��װ��ɫ��" << color << "ɫ" << endl;
		cout << "��װ���룺" << size << "��" << endl;
		cout << "��װ���ۿۣ�" << discount << "��" << endl;
	}
};
class Good_working :public Good//�칫��Ʒ��
{
protected:
	double discount1;//��������Ʒ�ۿ�
public:
	Good_working(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	virtual void display()const
	{
		Good::display();
		cout << "��Ʒ���ͣ��칫����Ʒ" << endl;
	}
};
class Phone :public Good_working
{
protected:
	string type;//����
	int memory;//�ڴ�
	int size;//�ߴ�
	string color;//��ɫ
	int pixel;//����
	double discount2;//�ֻ��ۿ�
	double discount;//�ۿ�
public:
	Phone(string a, double b, string c, string d, int e, int f, string g, int h, double i = 10, double j = 10, double k = 10) :Good_working(a, b, c, i, j)
	{
		type = d;
		memory = e;
		size = f;
		color = g;
		pixel = h;
		discount2 = k;
		discount = sumdiscount * discount1 * discount2 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_working::display();
		cout << "�ֻ����ͣ�" << type << endl;
		cout << "�ֻ��ڴ棺" << memory << "GB" << endl;
		cout << "�ֻ��ߴ磺" << size << "Ӣ��" << endl;
		cout << "�ֻ���ɫ��" << color << "ɫ" << endl;
		cout << "�ֻ����أ�" << pixel << "C" << endl;
		cout << "�ֻ����ۿۣ�" << discount << "��" << endl;
	}
};
class Camera :public Good_working//�����
{
protected:
	int size;//�������ߴ�
	int pixel;//����
	double discount2;//����ۿ�
	double discount;//�ۿ�
public:
	Camera(string a, double b, string c, int d, int e, double f = 10, double g = 10, double h = 10) :Good_working(a, b, c, f, g)
	{
		size = d;
		pixel = e;
		discount2 = h;
		discount = sumdiscount * discount1 * discount2 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_working::display();
		cout << "����������ߴ磺" << size << endl;
		cout << "������أ�" << pixel << "������" << endl;
		cout << "������ۿۣ�" << discount << "��" << endl;
	}
};
class Computer_type :public Good_working//�������
{
protected:
	double discount2;//������ۿ�
public:
	Computer_type(string a, double b, string c, double d = 10, double e = 10, double f = 10) :Good_working(a, b, c, e, f)
	{
		discount2 = d;
	}
	virtual void dispaly()const
	{
		Good_working::display();
	}
};
class Computer :public Computer_type//������
{
protected:
	string type;//���Ի���
	int memory;//�����ڴ�
	int size;//���Գߴ�
	int resolution_ratio;//���Էֱ���
	int pixel;//��������ͷ����
	string color;//������ɫ
	double discount;//�ۿ�
	double discount3;//�����ۿ�
public:
	Computer(string a, double b, string c, string d, int e, int f, int g, int h, string i, double j = 10, double k = 10, double l = 10, double m = 10) :Computer_type(a, b, c, j, k, l)
	{
		type = d;
		memory = e;
		size = f;
		resolution_ratio = g;
		pixel = h;
		color = i;
		discount3 = j;
		discount = discount1 * discount2 * discount3 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Computer_type::dispaly();
		cout << "���Ի��ͣ�" << type << endl;
		cout << "�����ڴ棺" << memory << "GB" << endl;
		cout << "���Գߴ磺" << size << "Ӣ��" << endl;
		cout << "���Էֱ��ʣ�" << resolution_ratio << endl;
		cout << "��������ͷ���أ�" << pixel << "������" << endl;
		cout << "�������ۿۣ�" << discount << "��" << endl;
	}
};
class Peripheral_equipment :public Computer_type//��Χ�豸��
{
protected:
	char color;//��ɫ
	double discount3;//��Χ�豸�ۿ�
	double discount;//�ۿ�
public:
	Peripheral_equipment(string a, double b, string c, char d, double e = 10, double f = 10, double g = 10, double h = 10) :Computer_type(a, b, c, e, f, g)
	{
		color = d;
		discount3 = e;
		discount = discount1 * discount2 * discount3 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Computer_type::dispaly();
		cout << "�豸��ɫ��" << color << "ɫ" << endl;
		cout << "�豸���ۿۣ�" << discount << "��" << endl;
	}
};
class Good_studying :public Good//ѧϰ��Ʒ��
{
protected:
	double discount1;//��������Ʒ�ۿ�
public:
	Good_studying(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	virtual void display()const
	{
		Good::display();
		cout << "��Ʒ���ͣ�ѧϰ����Ʒ" << endl;
	}
};
class Stationery :public Good_studying//�ľ���
{
protected:
	string user;//Ӧ����Ⱥ
	double discount2;//�ľ��ۿ�
	double discount;//�ۿ�
public:
	Stationery(string a, double b, string c, string d, double e = 10, double f = 10, double g = 10) :Good_studying(a, b, c, f, g)
	{
		user = d;
		discount2 = e;
		discount = sumdiscount * discount1 * discount2 / 100;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_studying::display();
		cout << "�ľ�������Ⱥ��" << user << endl;
		cout << "�ľ��ۿۣ�" << discount << "��" << endl;
	}
};
class Book :public Good_studying//ͼ����
{
protected:
	string language;//ͼ������
	string type;//ͼ������
	string publisher;//ͼ�������
	double discount2;//ͼ���ۿ�
	double discount;//�ۿ�
public:
	Book(string a, double b, string c, string d, string e, string f, double g = 10, double h = 10, double i = 10) :Good_studying(a, b, c, h, i)
	{
		language = d;
		type = e;
		publisher = f;
		discount2 = g;
		discount = sumdiscount * discount1 * discount2 / 1000;
		price *= (discount / 10);
	}
	void display()const
	{
		Good_studying::display();
		cout << "ͼ�����ԣ�" << language << endl;
		cout << "ͼ�����ͣ�" << type << endl;
		cout << "ͼ������磺" << publisher << endl;
		cout << "ͼ���ۿۣ�" << discount << endl;
	}
};
class Node//��������
{
public:
	Node(Good* a)
	{
		_good = a;
		next = NULL;
	};
	Node* next;
	Good* _good;
};
class Goodlist :public Node//������Ʒ��
{
public:
	int size;
	Node* first = NULL;
	Goodlist() :Node(NULL)
	{
		size = 0;
	}
	void Add(Good* a)
	{
		Node* p = new Node(a);
		if (first == NULL)
		{
			first = p;
		}
		else
		{
			p->next = first;
			first = p;
		}
		size++;
	}
	void display(int a)const
	{
		for (Node* p = first; p; p = p->next)
		{

			switch (a)
			{
			case(1):
			{
				if (typeid(*(p->_good)) == typeid(Food))
				{
					(p->_good)->display();
				}
				break;
			}
			case(2):
			{
				if (typeid(*(p->_good)) == typeid(Clothes))
				{
					(p->_good)->display();
				}
				break;
			}
			case(3):
			{
				if (typeid(*(p->_good)) == typeid(Phone))
				{
					(p->_good)->display();
				}
				break;
			}
			case(4):
			{
				if (typeid(*(p->_good)) == typeid(Camera))
				{
					(p->_good)->display();
				}
				break;
			}
			case(5):
			{
				if (typeid(*(p->_good)) == typeid(Computer))
				{
					(p->_good)->display();
				}
				break;
			}
			case(6):
			{
				if (typeid(*(p->_good)) == typeid(Peripheral_equipment))
				{
					(p->_good)->display();
				}
				break;
			}
			case(7):
			{
				if (typeid(*(p->_good)) == typeid(Stationery))
				{
					(p->_good)->display();
				}
				break;
			}
			case(8):
			{
				if (typeid(*(p->_good)) == typeid(Book))
				{
					(p->_good)->display();
				}
				break;
			}
			}
		}
	}
	~Goodlist()
	{
		Node* p = NULL;
		while (first)
		{
			p = first;
			first = first->next;
			delete p;
			p = NULL;
		}
	}
};
int main()
{
	Goodlist good;
	cout << "* * * * * * ��ӭ * * * * * *" << endl << endl;
	cout << "* * * * * * menu * * * * * *" << endl;
	cout << "������������в��������͡���" << endl;
	cout << "���������Ʒ������1��������-" << endl;
	cout << "������ʾ��Ʒ������2��������-" << endl;
	cout << "�����˳�ϵͳ������3��������-" << endl;
	cout << "* * * * * * * * * * * * * * *" << endl;
	int x;
	cin >> x;
	while (x != 3)
	{
		switch (x)
		{
		case(1)://�����Ʒ
		{
			cout << "* * * * * * menu * * * * * *" << endl;
			cout << "������������в��������͡���" << endl;
			cout << "�������������Ʒ������1����-" << endl;
			cout << "������Ӱ칫��Ʒ������2����-" << endl;
			cout << "�������ѧϰ��Ʒ������3����-" << endl;
			cout << "�����˳����������4��������-" << endl;
			cout << "* * * * * * * * * * * * * * *" << endl;
			int y;
			cin >> y;
			while (y != 4)
			{
				string name;//��Ʒ����
				double original_price;//��Ʒ�۸�
				string manufacturer;//��Ʒ����
				double sumdiscount;//������Ʒ�ۿ�
				double discount1;//��������Ʒ�ۿ�
				cout << "������������Ʒ�ۿۣ�" << endl;
				cin >> sumdiscount;
				switch (y)
				{
				case(1)://���������Ʒ
				{
					cout << "������������Ʒ�ۿۣ�" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "�������ʳƷ��Ʒ������1����-" << endl;
					cout << "������ӷ�����Ʒ������2����-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					char z;
					cin >> z;
					switch (z)
					{
					case('1')://���ʳƷ��Ʒ
					{
						int year, month, day;//��������
						int shelf_time;//������
						double discount2;//�����ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "������ʳƷ�������ڣ��ꡢ�¡��գ���" << endl;
						cin >> year >> month >> day;
						cout << "������ʳƷ�����ڣ�" << endl;
						cin >> shelf_time;
						cout << "������ʳƷ�����ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Food(name, original_price, manufacturer, year, month, day, shelf_time, sumdiscount, discount1, discount2));
						break;
					}
					case('2')://��ӷ�����Ʒ
					{
						char sex;//��װŮװ
						char type;//��װ���
						char color;//��װ��ɫ
						string size;//����
						double discount2;//�����ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "�������װ��Ⱥ��" << endl;
						cin >> sex;
						cout << "�������װ���" << endl;
						cin >> type;
						cout << "�������װ��ɫ��" << endl;
						cin >> color;
						cout << "�������װ���룺" << endl;
						cin >> size;
						cout << "�������װ�ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Clothes(name, original_price, manufacturer, sex, type, color, size, sumdiscount, discount1, discount2));
						break;
					}
					}
					break;
				}
				case(2)://��Ӱ칫��Ʒ
				{
					cout << "������칫��Ʒ�ۿۣ�" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "��������ֻ���Ʒ������1����-" << endl;
					cout << "������������Ʒ������2����-" << endl;
					cout << "������Ӽ������Ʒ������3��-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://����ֻ���Ʒ
					{
						string type;//����
						int memory;//�ڴ�
						int size;//�ߴ�
						string color;//��ɫ
						int pixel;//����
						double discount2;//�ֻ��ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "�������ֻ����ͣ�" << endl;
						cin >> type;
						cout << "�������ֻ��ڴ棺" << endl;
						cin >> memory;
						cout << "�������ֻ��ߴ磺" << endl;
						cin >> size;
						cout << "�������ֻ���ɫ��" << endl;
						cin >> color;
						cout << "�������ֻ����أ�" << endl;
						cin >> pixel;
						cout << "�������ֻ��ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Phone(name, original_price, manufacturer, type, memory, size, color, pixel, sumdiscount, discount1, discount2));
						break;
					}
					case(2)://��������Ʒ
					{
						int size;//�������ߴ�
						int pixel;//����
						double discount2;//����ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "����������������ߴ磺" << endl;
						cin >> size;
						cout << "������������أ�" << endl;
						cin >> pixel;
						cout << "����������ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Camera(name, original_price, manufacturer, size, pixel, sumdiscount, discount1, discount2));
						break;
					}
					case(3)://��Ӽ������Ʒ
					{
						cout << "* * * * * * menu * * * * * *" << endl;
						cout << "������������в��������͡���" << endl;
						cout << "������ӵ�����Ʒ������1����-" << endl;
						cout << "���������Χ�豸��Ʒ������2-" << endl;
						cout << "* * * * * * * * * * * * * * *" << endl;
						int q;
						cin >> q;
						double discount2;//������ۿ�
						cout << "�����������ۿۣ�" << endl;
						cin >> discount2;
						switch (q)
						{
						case(1)://��ӵ�����Ʒ
						{
							string type;//���Ի���
							int memory;//�����ڴ�
							int size;//���Գߴ�
							int resolution_ratio;//���Էֱ���
							int pixel;//��������ͷ����
							string color;//������ɫ
							double discount3;//�����ۿ�
							cout << "�����������Ʒ���ƣ�" << endl;
							cin >> name;
							cout << "�����������Ʒ�۸�" << endl;
							cin >> original_price;
							cout << "�����������Ʒ���ң�" << endl;
							cin >> manufacturer;
							cout << "��������Ի��ͣ�" << endl;
							cin >> type;
							cout << "����������ڴ棺" << endl;
							cin >> memory;
							cout << "��������Գߴ磺" << endl;
							cin >> size;
							cout << "��������Էֱ��ʣ�" << endl;
							cin >> resolution_ratio;
							cout << "�������������ͷ���أ�" << endl;
							cin >> pixel;
							cout << "�����������ɫ��" << endl;
							cin >> color;
							cout << "����������ۿۣ�" << endl;
							cin >> discount3;
							good.Add(new Computer(name, original_price, manufacturer, type, memory, size, resolution_ratio, pixel, color, sumdiscount, discount1, discount2, discount3));
							break;
						}
						case(2)://�����Χ�豸��Ʒ
						{
							char color;//��ɫ
							double discount3;//��Χ�豸�ۿ�
							cout << "�����������Ʒ���ƣ�" << endl;
							cin >> name;
							cout << "�����������Ʒ�۸�" << endl;
							cin >> original_price;
							cout << "�����������Ʒ���ң�" << endl;
							cin >> manufacturer;
							cout << "�������豸��ɫ��" << endl;
							cin >> color;
							cout << "�������豸�ۿۣ�" << endl;
							cin >> discount3;
							good.Add(new Peripheral_equipment(name, original_price, manufacturer, color, sumdiscount, discount1, discount2, discount3));
							break;
						}
						}
						break;
					}
					}
					break;
				}

				case(3)://���ѧϰ��Ʒ
				{
					cout << "������ѧϰ��Ʒ�ۿۣ�" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "��������ľ���Ʒ������1����-" << endl;
					cout << "�������ͼ����Ʒ������2����-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://����ľ���Ʒ
					{
						string user;//Ӧ����Ⱥ
						double discount2;//�ľ��ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "�������ľ�Ӧ����Ⱥ��" << endl;
						cin >> user;
						cout << "�������ľ��ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Stationery(name, original_price, manufacturer, user, discount2, sumdiscount, discount1));
						break;
					}
					case(2)://���ͼ����Ʒ
					{
						string language;//ͼ������
						string type;//ͼ������
						string publisher;//ͼ�������
						double discount2;//ͼ���ۿ�
						cout << "�����������Ʒ���ƣ�" << endl;
						cin >> name;
						cout << "�����������Ʒ�۸�" << endl;
						cin >> original_price;
						cout << "�����������Ʒ���ң�" << endl;
						cin >> manufacturer;
						cout << "������ͼ�����ԣ�" << endl;
						cin >> language;
						cout << "������ͼ�����ͣ�" << endl;
						cin >> type;
						cout << "������ͼ������磺" << endl;
						cin >> publisher;
						cout << "������ͼ���ۿۣ�" << endl;
						cin >> discount2;
						good.Add(new Book(name, original_price, manufacturer, language, type, publisher, discount2, sumdiscount, discount1));
						break;
					}
					}
					break;
				}
				}
				cout << "* * * * * * menu * * * * * *" << endl;
				cout << "������������в��������͡���" << endl;
				cout << "�������������Ʒ������1����-" << endl;
				cout << "������Ӱ칫��Ʒ������2����-" << endl;
				cout << "�������ѧϰ��Ʒ������3����-" << endl;
				cout << "�����˳����������4��������-" << endl;
				cout << "* * * * * * * * * * * * * * *" << endl;
				cin >> y;
			}
			break;
		}
		case(2)://��ʾ��Ʒ
		{
			cout << "* * * * * * menu * * * * * *" << endl;
			cout << "������������в��������͡���" << endl;
			cout << "������ʾ������Ʒ������1����-" << endl;
			cout << "������ʾ�칫��Ʒ������2����-" << endl;
			cout << "������ʾѧϰ��Ʒ������3����-" << endl;
			cout << "�����˳���ʾ������4��������-" << endl;
			cout << "* * * * * * * * * * * * * * *" << endl;
			int y;
			cin >> y;
			while (y != 4)
			{
				switch (y)
				{
				case(1)://��ʾ������Ʒ
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "������ʾʳƷ��Ʒ������1����-" << endl;
					cout << "������ʾ������Ʒ������2����-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://��ʾʳƷ��Ʒ
					{
						good.display(1);
						break;
					}
					case(2)://��ʾ������Ʒ
					{
						good.display(2);
						break;
					}
					}
					break;
				}
				case(2)://��ʾ�칫��Ʒ
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "������ʾ�ֻ���Ʒ������1����-" << endl;
					cout << "������ʾ�����Ʒ������2����-" << endl;
					cout << "������ʾ������Ʒ������3����-" << endl;
					cout << "������ʾ��Χ�豸��Ʒ������4-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://��ʾ�ֻ���Ʒ
					{
						good.display(3);
						break;
					}
					case(2)://��ʾ�����Ʒ
					{
						good.display(4);
					}
					case(3)://��ʾ������Ʒ
					{
						good.display(5);
						break;
					}
					case(4)://��ʾ��Χ�豸��Ʒ
					{
						good.display(6);
						break;
					}
					}
					break;
				}

				case(3)://��ʾѧϰ��Ʒ
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "������������в��������͡���" << endl;
					cout << "������ʾ�ľ���Ʒ������1����-" << endl;
					cout << "������ʾͼ����Ʒ������2����-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://��ʾ�ľ���Ʒ
					{
						good.display(7);
						break;
					}
					case(2)://��ʾͼ����Ʒ
					{
						good.display(8);
						break;
					}
					}
					break;
				}
				}
				cout << "* * * * * * menu * * * * * *" << endl;
				cout << "������������в��������͡���" << endl;
				cout << "������ʾ������Ʒ������1����-" << endl;
				cout << "������ʾ�칫��Ʒ������2����-" << endl;
				cout << "������ʾѧϰ��Ʒ������3����-" << endl;
				cout << "�����˳���ʾ������4��������-" << endl;
				cout << "* * * * * * * * * * * * * * *" << endl;
				cin >> y;
			}
			break;
		}
		}
		cout << "* * * * * * menu * * * * * *" << endl;
		cout << "������������в��������͡���" << endl;
		cout << "���������Ʒ������1��������-" << endl;
		cout << "������ʾ��Ʒ������2��������-" << endl;
		cout << "�����˳�ϵͳ������3��������-" << endl;
		cout << "* * * * * * * * * * * * * * *" << endl;
		cin >> x;
	}
	return 0;
}