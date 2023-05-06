#include<iostream>
#include<string.h>
using namespace std;
class Good//商品基类
{
protected:
	string name;//商品名称
	double price;//商品价格
	string manufacturer;//商品厂家
	double sumdiscount;//所有商品折扣
public:
	virtual void display()const
	{
		cout << "商品名称：" << name << endl;
		cout << "商品价格：" << price << endl;
		cout << "商品厂家：" << manufacturer << endl;
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
class Good_living :public Good//生活商品类
{
protected:
	double discount1;//生活类商品折扣
public:
	Good_living(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	Good_living() {}
	virtual void display()const
	{
		Good::display();
		cout << "商品类型：生活类商品" << endl;
	}
};
class Food :public Good_living//食品类
{
protected:
	int year, month, day;//生产日期
	int shelf_time;//保质期
	double discount2;//单独折扣
	double discount;//合计折扣
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
		cout << "食品生产日期：" << year << "年" << month << "月" << day << "日" << endl;
		cout << "食品保质期：" << shelf_time << "日" << endl;
		cout << "食品总折扣：" << discount << "折" << endl;
	}
};
class Clothes :public Good_living//服饰类
{
protected:
	char sex;//男装女装
	char type;//服装类型
	char color;//服装颜色
	string size;//尺码
	double discount2;//服饰折扣
	double discount;//折扣
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
		cout << "服装性别：" << sex << "装" << endl;
		cout << "服装类型：" << type << endl;
		cout << "服装颜色：" << color << "色" << endl;
		cout << "服装尺码：" << size << "号" << endl;
		cout << "服装总折扣：" << discount << "折" << endl;
	}
};
class Good_working :public Good//办公商品类
{
protected:
	double discount1;//生活类商品折扣
public:
	Good_working(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	virtual void display()const
	{
		Good::display();
		cout << "商品类型：办公类商品" << endl;
	}
};
class Phone :public Good_working
{
protected:
	string type;//机型
	int memory;//内存
	int size;//尺寸
	string color;//颜色
	int pixel;//像素
	double discount2;//手机折扣
	double discount;//折扣
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
		cout << "手机机型：" << type << endl;
		cout << "手机内存：" << memory << "GB" << endl;
		cout << "手机尺寸：" << size << "英寸" << endl;
		cout << "手机颜色：" << color << "色" << endl;
		cout << "手机像素：" << pixel << "C" << endl;
		cout << "手机总折扣：" << discount << "折" << endl;
	}
};
class Camera :public Good_working//相机类
{
protected:
	int size;//传感器尺寸
	int pixel;//像素
	double discount2;//相机折扣
	double discount;//折扣
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
		cout << "相机传感器尺寸：" << size << endl;
		cout << "相机像素：" << pixel << "万像素" << endl;
		cout << "相机总折扣：" << discount << "折" << endl;
	}
};
class Computer_type :public Good_working//计算机类
{
protected:
	double discount2;//计算机折扣
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
class Computer :public Computer_type//电脑类
{
protected:
	string type;//电脑机型
	int memory;//电脑内存
	int size;//电脑尺寸
	int resolution_ratio;//电脑分辨率
	int pixel;//电脑摄像头像素
	string color;//电脑颜色
	double discount;//折扣
	double discount3;//电脑折扣
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
		cout << "电脑机型：" << type << endl;
		cout << "电脑内存：" << memory << "GB" << endl;
		cout << "电脑尺寸：" << size << "英寸" << endl;
		cout << "电脑分辨率：" << resolution_ratio << endl;
		cout << "电脑摄像头像素：" << pixel << "万像素" << endl;
		cout << "电脑总折扣：" << discount << "折" << endl;
	}
};
class Peripheral_equipment :public Computer_type//外围设备类
{
protected:
	char color;//颜色
	double discount3;//外围设备折扣
	double discount;//折扣
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
		cout << "设备颜色：" << color << "色" << endl;
		cout << "设备总折扣：" << discount << "折" << endl;
	}
};
class Good_studying :public Good//学习商品类
{
protected:
	double discount1;//生活类商品折扣
public:
	Good_studying(string a, double b, string c, double d = 10, double e = 10) :Good(a, b, c, d)
	{
		discount1 = e;
	}
	virtual void display()const
	{
		Good::display();
		cout << "商品类型：学习类商品" << endl;
	}
};
class Stationery :public Good_studying//文具类
{
protected:
	string user;//应用人群
	double discount2;//文具折扣
	double discount;//折扣
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
		cout << "文具适用人群；" << user << endl;
		cout << "文具折扣：" << discount << "折" << endl;
	}
};
class Book :public Good_studying//图书类
{
protected:
	string language;//图书语言
	string type;//图书类型
	string publisher;//图书出版社
	double discount2;//图书折扣
	double discount;//折扣
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
		cout << "图书语言：" << language << endl;
		cout << "图书类型：" << type << endl;
		cout << "图书出版社：" << publisher << endl;
		cout << "图书折扣：" << discount << endl;
	}
};
class Node//链表结点类
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
class Goodlist :public Node//管理商品类
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
	cout << "* * * * * * 欢迎 * * * * * *" << endl << endl;
	cout << "* * * * * * menu * * * * * *" << endl;
	cout << "——请输入进行操作的类型——" << endl;
	cout << "——添加商品请输入1————-" << endl;
	cout << "——显示商品请输入2————-" << endl;
	cout << "——退出系统请输入3————-" << endl;
	cout << "* * * * * * * * * * * * * * *" << endl;
	int x;
	cin >> x;
	while (x != 3)
	{
		switch (x)
		{
		case(1)://添加商品
		{
			cout << "* * * * * * menu * * * * * *" << endl;
			cout << "——请输入进行操作的类型——" << endl;
			cout << "——添加生活商品请输入1——-" << endl;
			cout << "——添加办公商品请输入2——-" << endl;
			cout << "——添加学习商品请输入3——-" << endl;
			cout << "——退出添加请输入4————-" << endl;
			cout << "* * * * * * * * * * * * * * *" << endl;
			int y;
			cin >> y;
			while (y != 4)
			{
				string name;//商品名称
				double original_price;//商品价格
				string manufacturer;//商品厂家
				double sumdiscount;//所有商品折扣
				double discount1;//生活类商品折扣
				cout << "请输入所有商品折扣：" << endl;
				cin >> sumdiscount;
				switch (y)
				{
				case(1)://添加生活商品
				{
					cout << "请输入生活商品折扣：" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——添加食品商品请输入1——-" << endl;
					cout << "——添加服饰商品请输入2——-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					char z;
					cin >> z;
					switch (z)
					{
					case('1')://添加食品商品
					{
						int year, month, day;//生产日期
						int shelf_time;//保质期
						double discount2;//单独折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入食品生产日期（年、月、日）：" << endl;
						cin >> year >> month >> day;
						cout << "请输入食品保质期：" << endl;
						cin >> shelf_time;
						cout << "请输入食品单独折扣：" << endl;
						cin >> discount2;
						good.Add(new Food(name, original_price, manufacturer, year, month, day, shelf_time, sumdiscount, discount1, discount2));
						break;
					}
					case('2')://添加服饰商品
					{
						char sex;//男装女装
						char type;//服装类别
						char color;//服装颜色
						string size;//尺码
						double discount2;//服饰折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入服装人群：" << endl;
						cin >> sex;
						cout << "请输入服装类别：" << endl;
						cin >> type;
						cout << "请输入服装颜色：" << endl;
						cin >> color;
						cout << "请输入服装尺码：" << endl;
						cin >> size;
						cout << "请输入服装折扣：" << endl;
						cin >> discount2;
						good.Add(new Clothes(name, original_price, manufacturer, sex, type, color, size, sumdiscount, discount1, discount2));
						break;
					}
					}
					break;
				}
				case(2)://添加办公商品
				{
					cout << "请输入办公商品折扣：" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——添加手机商品请输入1——-" << endl;
					cout << "——添加相机商品请输入2——-" << endl;
					cout << "——添加计算机商品请输入3—-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://添加手机商品
					{
						string type;//机型
						int memory;//内存
						int size;//尺寸
						string color;//颜色
						int pixel;//像素
						double discount2;//手机折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入手机机型：" << endl;
						cin >> type;
						cout << "请输入手机内存：" << endl;
						cin >> memory;
						cout << "请输入手机尺寸：" << endl;
						cin >> size;
						cout << "请输入手机颜色：" << endl;
						cin >> color;
						cout << "请输入手机像素：" << endl;
						cin >> pixel;
						cout << "请输入手机折扣：" << endl;
						cin >> discount2;
						good.Add(new Phone(name, original_price, manufacturer, type, memory, size, color, pixel, sumdiscount, discount1, discount2));
						break;
					}
					case(2)://添加相机商品
					{
						int size;//传感器尺寸
						int pixel;//像素
						double discount2;//相机折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入相机传感器尺寸：" << endl;
						cin >> size;
						cout << "请输入相机像素：" << endl;
						cin >> pixel;
						cout << "请输入相机折扣：" << endl;
						cin >> discount2;
						good.Add(new Camera(name, original_price, manufacturer, size, pixel, sumdiscount, discount1, discount2));
						break;
					}
					case(3)://添加计算机商品
					{
						cout << "* * * * * * menu * * * * * *" << endl;
						cout << "——请输入进行操作的类型——" << endl;
						cout << "——添加电脑商品请输入1——-" << endl;
						cout << "——添加外围设备商品请输入2-" << endl;
						cout << "* * * * * * * * * * * * * * *" << endl;
						int q;
						cin >> q;
						double discount2;//计算机折扣
						cout << "请输入计算机折扣：" << endl;
						cin >> discount2;
						switch (q)
						{
						case(1)://添加电脑商品
						{
							string type;//电脑机型
							int memory;//电脑内存
							int size;//电脑尺寸
							int resolution_ratio;//电脑分辨率
							int pixel;//电脑摄像头像素
							string color;//电脑颜色
							double discount3;//电脑折扣
							cout << "请输入添加商品名称：" << endl;
							cin >> name;
							cout << "请输入添加商品价格：" << endl;
							cin >> original_price;
							cout << "请输入添加商品厂家：" << endl;
							cin >> manufacturer;
							cout << "请输入电脑机型：" << endl;
							cin >> type;
							cout << "请输入电脑内存：" << endl;
							cin >> memory;
							cout << "请输入电脑尺寸：" << endl;
							cin >> size;
							cout << "请输入电脑分辨率：" << endl;
							cin >> resolution_ratio;
							cout << "请输入电脑摄像头像素：" << endl;
							cin >> pixel;
							cout << "请输入电脑颜色：" << endl;
							cin >> color;
							cout << "请输入电脑折扣：" << endl;
							cin >> discount3;
							good.Add(new Computer(name, original_price, manufacturer, type, memory, size, resolution_ratio, pixel, color, sumdiscount, discount1, discount2, discount3));
							break;
						}
						case(2)://添加外围设备商品
						{
							char color;//颜色
							double discount3;//外围设备折扣
							cout << "请输入添加商品名称：" << endl;
							cin >> name;
							cout << "请输入添加商品价格：" << endl;
							cin >> original_price;
							cout << "请输入添加商品厂家：" << endl;
							cin >> manufacturer;
							cout << "请输入设备颜色：" << endl;
							cin >> color;
							cout << "请输入设备折扣：" << endl;
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

				case(3)://添加学习商品
				{
					cout << "请输入学习商品折扣：" << endl;
					cin >> discount1;
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——添加文具商品请输入1——-" << endl;
					cout << "——添加图书商品请输入2——-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://添加文具商品
					{
						string user;//应用人群
						double discount2;//文具折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入文具应用人群：" << endl;
						cin >> user;
						cout << "请输入文具折扣：" << endl;
						cin >> discount2;
						good.Add(new Stationery(name, original_price, manufacturer, user, discount2, sumdiscount, discount1));
						break;
					}
					case(2)://添加图书商品
					{
						string language;//图书语言
						string type;//图书类型
						string publisher;//图书出版社
						double discount2;//图书折扣
						cout << "请输入添加商品名称：" << endl;
						cin >> name;
						cout << "请输入添加商品价格：" << endl;
						cin >> original_price;
						cout << "请输入添加商品厂家：" << endl;
						cin >> manufacturer;
						cout << "请输入图书语言：" << endl;
						cin >> language;
						cout << "请输入图书类型：" << endl;
						cin >> type;
						cout << "请输入图书出版社：" << endl;
						cin >> publisher;
						cout << "请输入图书折扣：" << endl;
						cin >> discount2;
						good.Add(new Book(name, original_price, manufacturer, language, type, publisher, discount2, sumdiscount, discount1));
						break;
					}
					}
					break;
				}
				}
				cout << "* * * * * * menu * * * * * *" << endl;
				cout << "——请输入进行操作的类型——" << endl;
				cout << "——添加生活商品请输入1——-" << endl;
				cout << "——添加办公商品请输入2——-" << endl;
				cout << "——添加学习商品请输入3——-" << endl;
				cout << "——退出添加请输入4————-" << endl;
				cout << "* * * * * * * * * * * * * * *" << endl;
				cin >> y;
			}
			break;
		}
		case(2)://显示商品
		{
			cout << "* * * * * * menu * * * * * *" << endl;
			cout << "——请输入进行操作的类型——" << endl;
			cout << "——显示生活商品请输入1——-" << endl;
			cout << "——显示办公商品请输入2——-" << endl;
			cout << "——显示学习商品请输入3——-" << endl;
			cout << "——退出显示请输入4————-" << endl;
			cout << "* * * * * * * * * * * * * * *" << endl;
			int y;
			cin >> y;
			while (y != 4)
			{
				switch (y)
				{
				case(1)://显示生活商品
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——显示食品商品请输入1——-" << endl;
					cout << "——显示服饰商品请输入2——-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://显示食品商品
					{
						good.display(1);
						break;
					}
					case(2)://显示服饰商品
					{
						good.display(2);
						break;
					}
					}
					break;
				}
				case(2)://显示办公商品
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——显示手机商品请输入1——-" << endl;
					cout << "——显示相机商品请输入2——-" << endl;
					cout << "——显示电脑商品请输入3——-" << endl;
					cout << "——显示外围设备商品请输入4-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://显示手机商品
					{
						good.display(3);
						break;
					}
					case(2)://显示相机商品
					{
						good.display(4);
					}
					case(3)://显示电脑商品
					{
						good.display(5);
						break;
					}
					case(4)://显示外围设备商品
					{
						good.display(6);
						break;
					}
					}
					break;
				}

				case(3)://显示学习商品
				{
					cout << "* * * * * * menu * * * * * *" << endl;
					cout << "——请输入进行操作的类型——" << endl;
					cout << "——显示文具商品请输入1——-" << endl;
					cout << "——显示图书商品请输入2——-" << endl;
					cout << "* * * * * * * * * * * * * * *" << endl;
					int z;
					cin >> z;
					switch (z)
					{
					case(1)://显示文具商品
					{
						good.display(7);
						break;
					}
					case(2)://显示图书商品
					{
						good.display(8);
						break;
					}
					}
					break;
				}
				}
				cout << "* * * * * * menu * * * * * *" << endl;
				cout << "——请输入进行操作的类型——" << endl;
				cout << "——显示生活商品请输入1——-" << endl;
				cout << "——显示办公商品请输入2——-" << endl;
				cout << "——显示学习商品请输入3——-" << endl;
				cout << "——退出显示请输入4————-" << endl;
				cout << "* * * * * * * * * * * * * * *" << endl;
				cin >> y;
			}
			break;
		}
		}
		cout << "* * * * * * menu * * * * * *" << endl;
		cout << "——请输入进行操作的类型——" << endl;
		cout << "——添加商品请输入1————-" << endl;
		cout << "——显示商品请输入2————-" << endl;
		cout << "——退出系统请输入3————-" << endl;
		cout << "* * * * * * * * * * * * * * *" << endl;
		cin >> x;
	}
	return 0;
}