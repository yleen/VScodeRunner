#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include <complex>
using namespace std;
typedef std::complex<double> Complex;  // STL complex
const double PI = acos(-1.0);
/*
*进行FFT和IFFT前的反置变换 
*位置i和i的二进制反转后的位置互换 
*len必须为2的幂 
*/ 
void change(Complex y[],int len){
	int i,j,k;
	for(int i = 1,j = len/2;i<len-1;i++){
		if(i < j)	swap(y[i],y[j]);
		//交换互为小标反转的元素，i<j保证交换一次
		//i做正常的+1，j做反转类型的+1，始终保持i和j是反转的
		k = len/2;
		while(j >= k){
			j = j - k;
			k = k/2;
		} 
		if(j < k)	j+=k;
	}
} 
/*
*做FFT 
*len必须是2^k形式 
*on == 1时是DFT，on == -1时是IDFT 
*/
void fft(Complex y[],int len){
	change(y,len);
	for(int h = 2;h <= len;h<<=1){
		Complex wn(cos(-2*PI/h),sin(-2*PI/h));
		for(int j = 0;j < len;j += h){
			Complex w(1,0);
			for(int k = j;k < j + h/2;k++){
				Complex u = y[k];
				Complex t = w*y[k + h/2];
				y[k] = u + t;
				y[k + h/2] = u - t;
				w = w*wn;
			}
		}
	}
} 

const int MAXN = 200020;
Complex x1[MAXN],x2[MAXN];
char str1[MAXN/2],str2[MAXN/2];
int sum[MAXN];


int main(){
	while(scanf("%s%s",str1,str2) == 2){
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int len = 1;
		while(len < len1*2||len < len2*2)	len <<= 1;
		for(int i = 0;i < len1;i++)
			x1[i] = Complex(str1[len-1-i] - '0',0);
		for(int i = len1;i < len;i++)
			x1[i] = Complex(0,0);
		for(int i = 0;i < len2;i++)
			x2[i] = Complex(str2[len2-1-i] - '0',0);
		for(int i = len2;i < len;i++)
			x2[i] = Complex(0,0);
		fft(x1,len);
		fft(x2,len);
	}
	return 0;
}

