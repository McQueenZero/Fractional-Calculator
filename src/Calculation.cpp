#include <iostream>
#include "Fraction.h"
#include <string>
void Demo_Function1()
{
	Fraction a(1, 4), b(1, 2), c;
	c = a + b; c.display(); cout << ","; //两个分数相加
	c = a - b; c.display(); cout << ","; //两个分数相减
	c = a * b; c.display(); cout << ","; //两个分数相乘
	c = a / b; c.display(); cout << endl; //两个分数相除
	cout << boolalpha << (a == b) << "," << (a != b) << "," << (a >= b) << "," << (a <= b);//分数比较
}
void Demo_Function2()
{
	Fraction a(1, 4), b(1, 4), c(1, 4), d;
	d = a++; a.display(); cout << ","; d.display(); cout << ",";
	d = ++b; b.display(); cout << ","; d.display(); cout << ",";
	d = -c; c.display(); cout << ","; d.display(); cout << endl;
	/*应用display()规格化显示函数输出计算值*/
}
void Demo_Function3()
{
	Fraction a(2, 5), b(1, 2);
	a += a -= b; a.display(); cout << endl;
	/*(a=a+a<=a=a-b) 复合运算符重载*/
}
void Demo_Function4()
{
	Fraction a, b(1, 2);
	a = 0.125; //double转换为Fraction类型
	cout << (double)(a + b) << endl; //Fraction类型转换为double
}
Fraction FracAdd() //Addition
{
	Fraction a, b; //定义两个分数
	cin >> a >> b; //输入两个分数（应用重载流提取运算符） 
	return a + b;  //返回和
}
Fraction FracSub() //Subtraction
{
	Fraction a, b; //定义两个分数
	cin >> a >> b; //输入两个分数（应用重载流提取运算符） 
	return a - b;  //返回差
}
Fraction FracMul() //Multiplication
{
	Fraction a, b; //定义两个分数
	cin >> a >> b; //输入两个分数（应用重载流提取运算符） 
	return a * b;  //返回积
}
Fraction FracDiv() //Division
{
	Fraction a, b; //定义两个分数
	cin >> a >> b; //输入两个分数（应用重载流提取运算符） 
	return a / b;  //返回商
}
Fraction FracSumm() //Summation 累加
{
	int n, i;
	Fraction *p, s = 0 / 1;
	cin >> n;
	p = new Fraction[n]; //动态分配内存
	for (i = 0; i < n; i++) cin >> p[i];
	for (i = 0; i < n; i++) s += p[i];
	delete[]p;
	return s;
}
Fraction FracCumu() //Cumulation 累乘
{
	int n, i;
	Fraction *p, s = 1 / 1;
	cin >> n;
	p = new Fraction[n];
	for (i = 0; i < n; i++) cin >> p[i];
	for (i = 0; i < n; i++) s = s * p[i];
	delete[]p;
	return s;
}
Fraction FracMupl() //Multiple 倍数（整数*分数）
{
	int n, i;
	Fraction a, s = 0 / 1;
	cin >> n >> a;
	for (i = 0; i < n; i++) s = s + a;
	return s;
}
Fraction FracPow() //Power 整数次幂
{
	int n, i;
	Fraction a, s = 1 / 1;
	cin >> a >> n;
	for (i = 0; i < n; i++) s = s * a;
	return s;
}
void FracRedu() //约分 利用字符串转化分数构造函数调用规格化函数simplify()
{
	int n, i;
	string *inf;         //input fraction
	Fraction *outf;      //output fraction
	cin >> n;
	inf = new string[n];      //动态长度的字符串型数组
	outf = new Fraction[n];   //动态长度的分数数组
	for (i = 0; i < n; i++) cin >> inf[i];
	cout << "Result:";
	for (i = 0; i < n; i++) {
		outf[i] = inf[i];
		cout << outf[i] << ' ';
	}
	cout << endl;
	delete[]inf;
	delete[]outf;
}
void dtof() //实型数化分数
{
	int n, i;
	double *d;
	Fraction *f;
	cin >> n;
	d = new double[n];
	f = new Fraction[n];
	for (i = 0; i < n; i++) cin >> d[i];
	cout << "Result:";
	for (i = 0; i < n; i++) { 
		f[i] = d[i]; 
		cout << f[i] << ' '; 
	}
	cout << endl;
	delete[]d;
	delete[]f;
}
void ftod() //分数化实型
{
	int n, i;
	double *d;
	Fraction *f;
	cin >> n;
	d = new double[n];
	f = new Fraction[n];
	for (i = 0; i < n; i++) cin >> f[i];
	cout << "Result:";
	for (i = 0; i < n; i++) {
		d[i] = (double)f[i];
		cout << d[i] << ' ';
	}
	cout << endl;
	delete[]d;
	delete[]f;
}