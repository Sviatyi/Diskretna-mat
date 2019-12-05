#include <iostream>

using namespace std;

int fakt(int n) {
	int fakt=1;
	for (int i = 1; i <= n; i++) {
		fakt *= i;
	}
	
	return fakt;
}
bool NextSet(int* a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}
void Print(int* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int comb(int n, int m) {
	int c=1;
	c = fakt(n)/(fakt(m)*fakt(n-m));

	return c;
}
int main()
{
	int x, y, n, m = 0, c;
	long int binom = 0;
	
	cout << "Enter n: ";	
	cin >> n;
	
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = i+1;
	}
	for (int m = 1; m <=n ; m++) {
		Print(a, m);
		if (n >= m) {
			while (NextSet(a, n, m))
				Print(a, m);
		}
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
	}
	
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter n: ";
	cin >> n;

	cout << "(x+y)^" << n << " = ";
	c = n;
	while (n != -1) {
		cout << comb(c, m) << "x^" << n << "*" << "y^" << m;
		if (n != 0) {
			cout << " + ";
		}
		binom += comb(c, m) * pow(x, n) * pow(y, m);
		n--;
		m++;
	}
	cout << endl << "binom = " << binom << endl;
	cout << "pow = " << pow(x + y, c) << endl;

	return 0;
}

