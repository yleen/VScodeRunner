/*
于雷 2020180010
求解问题：FFT算法
说明离散FOURIER变换的定义，用分治法给出计算该变换的算法，并注意如何将递归形式的算法转换成迭代形式。比较直接计算和FFT算法的复杂度，探讨相关思想如何应用在其它一些变换上得到相应的快速算法。
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;
typedef std::complex<double> Complex; // STL complex
const double PI = acos(-1.0);
void change(Complex y[], int len)
{
	int i, j, k;
	for (int i = 1, j = len / 2; i < len - 1; i++)
	{
		if (i < j)
			swap(y[i], y[j]);
		k = len / 2;
		while (j >= k)
		{
			j = j - k;
			k = k / 2;
		}
		if (j < k)
			j += k;
	}
}
void fft(Complex y[], int len)
{
	change(y, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		Complex wn(cos(-2 * PI / h), sin(-2 * PI / h));
		for (int j = 0; j < len; j += h)
		{
			Complex w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				Complex u = y[k];
				Complex t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
}

const int MAXN = 200020;
Complex x1[MAXN], x2[MAXN];
char str1[MAXN / 2], str2[MAXN / 2];
int sum[MAXN];

int main()
{
	while (scanf("%s%s", str1, str2) == 2)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int len = 1;
		while (len < len1 * 2 || len < len2 * 2)
			len <<= 1;
		for (int i = 0; i < len1; i++)
			x1[i] = Complex(str1[len - 1 - i] - '0', 0);
		for (int i = len1; i < len; i++)
			x1[i] = Complex(0, 0);
		for (int i = 0; i < len2; i++)
			x2[i] = Complex(str2[len2 - 1 - i] - '0', 0);
		for (int i = len2; i < len; i++)
			x2[i] = Complex(0, 0);
		fft(x1, len);
		fft(x2, len);
	}
	return 0;
}