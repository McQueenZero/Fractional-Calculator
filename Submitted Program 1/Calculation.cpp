#include "pch.h"
#include <iostream>
#include "Fraction.h"
#include <string>
void Demo_Function1()
{
	Fraction a(1, 4), b(1, 2), c;
	c = a + b; c.display(); cout << ","; //�����������
	c = a - b; c.display(); cout << ","; //�����������
	c = a * b; c.display(); cout << ","; //�����������
	c = a / b; c.display(); cout << endl; //�����������
	cout << boolalpha << (a == b) << "," << (a != b) << "," << (a >= b) << "," << (a <= b);//�����Ƚ�
}
void Demo_Function2()
{
	Fraction a(1, 4), b(1, 4), c(1, 4), d;
	d = a++; a.display(); cout << ","; d.display(); cout << ",";
	d = ++b; b.display(); cout << ","; d.display(); cout << ",";
	d = -c; c.display(); cout << ","; d.display(); cout << endl;
	/*Ӧ��display()�����ʾ�����������ֵ*/
}
void Demo_Function3()
{
	Fraction a(2, 5), b(1, 2);
	a += a -= b; a.display(); cout << endl;
	/*(a=a+a<=a=a-b) �������������*/
}
void Demo_Function4()
{
	Fraction a, b(1, 2);
	a = 0.125; //doubleת��ΪFraction����
	cout << (double)(a + b) << endl; //Fraction����ת��Ϊdouble
}
Fraction FracAdd() //Addition
{
	Fraction a, b; //������������
	cin >> a >> b; //��������������Ӧ����������ȡ������� 
	return a + b;  //���غ�
}
Fraction FracSub() //Subtraction
{
	Fraction a, b; //������������
	cin >> a >> b; //��������������Ӧ����������ȡ������� 
	return a - b;  //���ز�
}
Fraction FracMul() //Multiplication
{
	Fraction a, b; //������������
	cin >> a >> b; //��������������Ӧ����������ȡ������� 
	return a * b;  //���ػ�
}
Fraction FracDiv() //Division
{
	Fraction a, b; //������������
	cin >> a >> b; //��������������Ӧ����������ȡ������� 
	return a / b;  //������
}
Fraction FracSumm() //Summation �ۼ�
{
	int n, i;
	Fraction *p, s = 0 / 1;
	cin >> n;
	p = new Fraction[n]; //��̬�����ڴ�
	for (i = 0; i < n; i++) cin >> p[i];
	for (i = 0; i < n; i++) s += p[i];
	delete[]p;
	return s;
}
Fraction FracCumu() //Cumulation �۳�
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
Fraction FracMupl() //Multiple ����������*������
{
	int n, i;
	Fraction a, s = 0 / 1;
	cin >> n >> a;
	for (i = 0; i < n; i++) s = s + a;
	return s;
}
Fraction FracPow() //Power ��������
{
	int n, i;
	Fraction a, s = 1 / 1;
	cin >> a >> n;
	for (i = 0; i < n; i++) s = s * a;
	return s;
}
void FracRedu() //Լ�� �����ַ���ת���������캯�����ù�񻯺���simplify()
{
	int n, i;
	string *inf;         //input fraction
	Fraction *outf;      //output fraction
	cin >> n;
	inf = new string[n];      //��̬���ȵ��ַ���������
	outf = new Fraction[n];   //��̬���ȵķ�������
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
void dtof() //ʵ����������
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
void ftod() //������ʵ��
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