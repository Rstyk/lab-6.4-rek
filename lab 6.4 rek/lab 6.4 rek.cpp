#include<iostream>
#include<iomanip>
#include <time.h>

using namespace std;

void Input(double* a, const int size, int i)
{
	cout << "a[" << i << "] = ";
	cin >> a[i];
	if (i < size - 1)
		Input(a, size, i + 1);
	else
		cout << endl;
}
void Print(double* a, const int size, int i)
{
	cout << setw(8) << fixed << setprecision(3) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
double Max(double* a, const int size, int i, double max)
{
	if (fabs(a[i]) > fabs(max))
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}
int Find(double* a, const int size, int i)
{
	if (i >= size) {
		return -1;
	}
	else
	{
		if (a[i] > 0) {
			return i;
		}
		return Find(a, size, i + 1);
	}
}
double Sum(double* a, const int size, int first, int second, int i, double s)
{
	if (i < size)
	{
		if (i > first && i < second)
		{
			s += a[i];
		}
		return Sum(a, size, first, second, i + 1, s);
	}
	return s;
}
void Sort(double* a, const int size, int i, int j, int& k)
{
	if (a[j] == 0)
	{
		int tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
		k = 1;
	}
	if (j < size - i - 1)
		Sort(a, size, i, j + 1, k);
	if (k == 0)
		return;
	if (i < size - 1)
	{
		k = 0;
		Sort(a, size, i + 1, 0, k);
	}
}
int main()
{
	int n;
	cout << "n = "; cin >> n;
	double* p = new double[n];
	int k = 0;
	Input(p, n, 0);

	cout << "a[n] =";
	Print(p, n, 0);
	cout << "module max = " << Max(p, n, 0, p[0]) << endl;
	int first = Find(p, n, 0);
	int second = Find(p, n, first + 1);

	cout << "S = " << Sum(p, n, first, second, 0, 0) << endl;

	Sort(p, n, 1, 0, k);
	cout << "a[n] =";
	Print(p, n, 0);
	delete[] p;
	return 0;
}

