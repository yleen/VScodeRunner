#include <cmath>
#include <complex>
#define M_PI 3.14
typedef std::complex<double> Comp;  // STL complex

const Comp I(0, 1);  // i
const int MAX_N = 1 << 20;

Comp tmp[MAX_N];

Comp omega(int n, int k){
    return Comp(cos(2 * M_PI * k / n), sin(2 * M_PI * k / n));
}
void fft(Comp  *a, int n, bool inv){
    if(n == 1) return;
    static Comp buf[N];
    int m = n / 2;
    for(int i = 0; i < m; i++){ //将每一项按照奇偶分为两组
	    buf[i] = a[2 * i];
	    buf[i + m] = a[2 * i + 1];
    }
    for(int i = 0; i < n; i++)
	    a[i] = buf[i];
    fft(a, m, inv); //递归处理两个子问题
    fft(a + m, m, inv);
    for(int i = 0; i < m; i++){ //枚举x，计算A(x)
	    Comp x = omega(n, i); 
	    if(inv) x = conj(x); 
	    //conj是一个自带的求共轭复数的函数，精度较高。当复数模为1时，共轭复数等于倒数
	    buf[i] = a[i] + x * a[i + m]; //根据之前推出的结论计算
	    buf[i + m] = a[i] - x * a[i + m];
    }
    for(int i = 0; i < n; i++)
	    a[i] = buf[i];
}