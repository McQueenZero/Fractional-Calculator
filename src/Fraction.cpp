#include "Fraction.h"
#include <cmath>
Fraction::Fraction(const string& str) : nume(0), deno(1)
{	//字符串"1/3"转换为分数类
	char buf[200];
	int i = str.find('/'), j = str.length() - i - 1;
	if (i >= 0) {
		str.copy(buf, i, 0); buf[i] = 0; nume = atoi(buf);//前面子串转换为分子
		str.copy(buf, j, i + 1); buf[j] = 0; deno = atoi(buf);//后面子串转换为分母
	}
	simplify();//规格化分数
}
Fraction::Fraction(double d) : nume(d), deno(1) //分子初始为d的整数部份
{
	d = d - nume; //d的小数部分 0.55
	d = floor(d * 1000000 + 0.5) / 1000000.0;  //为防止实型数计算时因最后几位的不精确性而导致的运算出错，我特此设置了此转化手动四舍五入精确到小数点后6位！！
	while (int(d * 10) != 0) //0.55=>55/100
		nume = nume * 10 + int(d * 10), deno = deno * 10, d = d * 10 - int(d * 10);
	simplify();//规格化分数
}
void Fraction::simplify()
{	//分数规格化
	int m, n, r, s = 1;
	if (nume != 0 && deno != 0) { //分母不能为0
		if (deno < 0) s = -s, deno = -deno; //分母取正数
		if (nume < 0) s = -s, nume = -nume; //分子取正数，s为分数符号，符号在分子上
		m = nume, n = deno;
		while (n != 0) r = m % n, m = n, n = r; //求nume和deno的最大公约数m
		if (m != 0) nume = s * nume / m, deno = deno / m; //分子分母去除公约数
	}
	else nume = 0, deno = 1; //分子或分母为0时规格化为分子=0，分母=1
}
void Fraction::display() //显式规格化的分数
{	
	if (deno != 0 && deno != 1 && nume != deno) cout << nume << "/" << deno;
	else cout << nume; //当出现nume/0,nume/1,nume/nume时只显示nume
}
Fraction operator+(const Fraction& a, const Fraction& b) //a+b
{
	return Fraction(a.nume*b.deno + a.deno*b.nume, a.deno*b.deno);
} //返回新对象
Fraction operator-(const Fraction& a, const Fraction& b) //a-b
{
	return Fraction(a.nume*b.deno - a.deno*b.nume, a.deno*b.deno);
} //返回新对象
Fraction operator*(const Fraction& a, const Fraction& b) //a*b
{
	return Fraction(a.nume*b.nume, a.deno*b.deno);
} //返回新对象
Fraction operator/(const Fraction& a, const Fraction& b) //a/b
{
	return Fraction(a.nume*b.deno, a.deno*b.nume);
} //返回新对象
bool operator==(const Fraction& a, const Fraction& b) //a==b
{
	return a.nume*b.deno == a.deno*b.nume;
}
bool operator!=(const Fraction& a, const Fraction& b) //a!=b
{
	return a.nume*b.deno != a.deno*b.nume;
}
bool operator>(const Fraction& a, const Fraction& b) //a>b
{
	return a.nume*b.deno > a.deno*b.nume;
}
bool operator>=(const Fraction& a, const Fraction& b) //a>=b
{
	return a.nume*b.deno >= a.deno*b.nume;
}
bool operator<(const Fraction& a, const Fraction& b) //a<b
{
	return a.nume*b.deno < a.deno*b.nume;
}
bool operator<=(const Fraction& a, const Fraction& b) //a<=b
{
	return a.nume*b.deno <= a.deno*b.nume;
}
Fraction Fraction::operator++() //++a
{
	nume = nume + deno; simplify(); //计算后需要重新规格化分数
	return *this; //前置自增返回新对象
}
Fraction Fraction::operator--() //--a
{
	nume = nume - deno; simplify(); //计算后需要重新规格化分数
	return *this; //前置自减返回新对象
}
Fraction Fraction::operator++(int) //a++，函数不使用整型形参因此可以无参数名
{
	Fraction old(*this); //复制旧对象
	nume = nume + deno; simplify(); //计算后需要重新规格化分数
	return old; //后置自增返回旧对象
}
Fraction Fraction::operator--(int) //a--，函数不使用整型形参因此可以无参数名
{
	Fraction old(*this); //复制旧对象
	nume = nume - deno; simplify(); //计算后需要重新规格化分数
	return old; //后置自减返回旧对象
}
Fraction Fraction::operator-() //-a
{
	return Fraction(-nume, deno);
} //返回新对象
Fraction& Fraction::operator+=(const Fraction& b) //a+=b
{
	nume = nume * b.deno + deno * b.nume, deno = deno * b.deno; simplify();
	return *this; //返回左运算对象
}
Fraction& Fraction::operator-=(const Fraction& b) //a-=b
{
	nume = nume * b.deno - deno * b.nume, deno = deno * b.deno; simplify();
	return *this; //返回左运算对象
}
ostream& operator<<(ostream& os, const Fraction& a) //os<<a
{	//显式规格化的分数
	if (a.deno != 0 && a.deno != 1 && a.nume != a.deno) os << a.nume << "/" << a.deno;
	else os << a.nume; //当出现nume/0,nume/1,nume/nume时只显示nume
	return os; //必须返回ostream对象
}
istream& operator>>(istream& is, Fraction& a) //is>>a
{
	char ch;
	is >> a.nume >> ch >> a.deno; //按 分子/分母 形式输入数据
	return is; //必须返回istream对象
}
Fraction::operator double()
{
	return (double)nume / deno;
}
Fraction::~Fraction()
{
}
