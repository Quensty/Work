#include<iostream>
#include<iomanip>
using namespace std;
int a[1000001] = { 0 }, n, ans = -100000, temp = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (temp > 0)
			temp += a[i];
		else
			temp = a[i];
		ans = max(ans, temp);
	}
	ans = max(ans, 0);
	cout << ans;
	return 0;
}