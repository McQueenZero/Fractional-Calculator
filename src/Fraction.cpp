#include "Fraction.h"
#include <cmath>
Fraction::Fraction(const string& str) : nume(0), deno(1)
{	//�ַ���"1/3"ת��Ϊ������
	char buf[200];
	int i = str.find('/'), j = str.length() - i - 1;
	if (i >= 0) {
		str.copy(buf, i, 0); buf[i] = 0; nume = atoi(buf);//ǰ���Ӵ�ת��Ϊ����
		str.copy(buf, j, i + 1); buf[j] = 0; deno = atoi(buf);//�����Ӵ�ת��Ϊ��ĸ
	}
	simplify();//��񻯷���
}
Fraction::Fraction(double d) : nume(d), deno(1) //���ӳ�ʼΪd����������
{
	d = d - nume; //d��С������ 0.55
	d = floor(d * 1000000 + 0.5) / 1000000.0;  //Ϊ��ֹʵ��������ʱ�����λ�Ĳ���ȷ�Զ����µ�����������ش������˴�ת���ֶ��������뾫ȷ��С�����6λ����
	while (int(d * 10) != 0) //0.55=>55/100
		nume = nume * 10 + int(d * 10), deno = deno * 10, d = d * 10 - int(d * 10);
	simplify();//��񻯷���
}
void Fraction::simplify()
{	//�������
	int m, n, r, s = 1;
	if (nume != 0 && deno != 0) { //��ĸ����Ϊ0
		if (deno < 0) s = -s, deno = -deno; //��ĸȡ����
		if (nume < 0) s = -s, nume = -nume; //����ȡ������sΪ�������ţ������ڷ�����
		m = nume, n = deno;
		while (n != 0) r = m % n, m = n, n = r; //��nume��deno�����Լ��m
		if (m != 0) nume = s * nume / m, deno = deno / m; //���ӷ�ĸȥ����Լ��
	}
	else nume = 0, deno = 1; //���ӻ��ĸΪ0ʱ���Ϊ����=0����ĸ=1
}
void Fraction::display() //��ʽ��񻯵ķ���
{	
	if (deno != 0 && deno != 1 && nume != deno) cout << nume << "/" << deno;
	else cout << nume; //������nume/0,nume/1,nume/numeʱֻ��ʾnume
}
Fraction operator+(const Fraction& a, const Fraction& b) //a+b
{
	return Fraction(a.nume*b.deno + a.deno*b.nume, a.deno*b.deno);
} //�����¶���
Fraction operator-(const Fraction& a, const Fraction& b) //a-b
{
	return Fraction(a.nume*b.deno - a.deno*b.nume, a.deno*b.deno);
} //�����¶���
Fraction operator*(const Fraction& a, const Fraction& b) //a*b
{
	return Fraction(a.nume*b.nume, a.deno*b.deno);
} //�����¶���
Fraction operator/(const Fraction& a, const Fraction& b) //a/b
{
	return Fraction(a.nume*b.deno, a.deno*b.nume);
} //�����¶���
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
	nume = nume + deno; simplify(); //�������Ҫ���¹�񻯷���
	return *this; //ǰ�����������¶���
}
Fraction Fraction::operator--() //--a
{
	nume = nume - deno; simplify(); //�������Ҫ���¹�񻯷���
	return *this; //ǰ���Լ������¶���
}
Fraction Fraction::operator++(int) //a++��������ʹ�������β���˿����޲�����
{
	Fraction old(*this); //���ƾɶ���
	nume = nume + deno; simplify(); //�������Ҫ���¹�񻯷���
	return old; //�����������ؾɶ���
}
Fraction Fraction::operator--(int) //a--��������ʹ�������β���˿����޲�����
{
	Fraction old(*this); //���ƾɶ���
	nume = nume - deno; simplify(); //�������Ҫ���¹�񻯷���
	return old; //�����Լ����ؾɶ���
}
Fraction Fraction::operator-() //-a
{
	return Fraction(-nume, deno);
} //�����¶���
Fraction& Fraction::operator+=(const Fraction& b) //a+=b
{
	nume = nume * b.deno + deno * b.nume, deno = deno * b.deno; simplify();
	return *this; //�������������
}
Fraction& Fraction::operator-=(const Fraction& b) //a-=b
{
	nume = nume * b.deno - deno * b.nume, deno = deno * b.deno; simplify();
	return *this; //�������������
}
ostream& operator<<(ostream& os, const Fraction& a) //os<<a
{	//��ʽ��񻯵ķ���
	if (a.deno != 0 && a.deno != 1 && a.nume != a.deno) os << a.nume << "/" << a.deno;
	else os << a.nume; //������nume/0,nume/1,nume/numeʱֻ��ʾnume
	return os; //���뷵��ostream����
}
istream& operator>>(istream& is, Fraction& a) //is>>a
{
	char ch;
	is >> a.nume >> ch >> a.deno; //�� ����/��ĸ ��ʽ��������
	return is; //���뷵��istream����
}
Fraction::operator double()
{
	return (double)nume / deno;
}
Fraction::~Fraction()
{
}
