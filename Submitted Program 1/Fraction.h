#pragma once
#include <iostream>
using namespace std;
class Fraction { //Fraction���ʾ����
public:
	Fraction(int n = 0, int d = 1) : nume(n), deno(d) { simplify(); }
	Fraction(double d); //double����ת��Fraction���캯��
	Fraction(const string& str); //string����ת��Fraction���캯��
	Fraction(const Fraction& f) :nume(f.nume), deno(f.deno) { }//���ƹ��캯��
	void display(); //��ʾ����
	Fraction operator++(); //ǰ�����������
	Fraction operator++(int); //�������������
	Fraction operator--(); //ǰ���Լ������
	Fraction operator--(int); //�����Լ������
	Fraction operator-(); //ȡ�������
	Fraction& operator+=(const Fraction& b); //���ϸ�ֵ�����
	Fraction& operator-=(const Fraction& b); //���ϸ�ֵ�����
	operator double(); //double����ת�������
	~Fraction();
private:
	void simplify(); //�򻯷���
	int nume, deno; //����numerator����ĸdenominator
	friend Fraction operator+(const Fraction& a, const Fraction& b); //a+b
	friend Fraction operator-(const Fraction& a, const Fraction& b); //a-b
	friend Fraction operator*(const Fraction& a, const Fraction& b); //a*b
	friend Fraction operator/(const Fraction& a, const Fraction& b); //a/b
	friend bool operator==(const Fraction& a, const Fraction& b); //a==b
	friend bool operator!=(const Fraction& a, const Fraction& b); //a!=b
	friend bool operator>(const Fraction& a, const Fraction& b); //a>b
	friend bool operator>=(const Fraction& a, const Fraction& b); //a>=b
	friend bool operator<(const Fraction& a, const Fraction& b); //a<b
	friend bool operator<=(const Fraction& a, const Fraction& b); //a<=b
	friend ostream& operator<<(ostream& os, const Fraction& a); //os<<a
	friend istream& operator>>(istream& is, Fraction& a); //is>>a
};