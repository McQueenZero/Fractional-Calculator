#pragma once
#include <iostream>
using namespace std;
class Fraction { //Fraction类表示分数
public:
	Fraction(int n = 0, int d = 1) : nume(n), deno(d) { simplify(); }
	Fraction(double d); //double类型转换Fraction构造函数
	Fraction(const string& str); //string类型转换Fraction构造函数
	Fraction(const Fraction& f) :nume(f.nume), deno(f.deno) { }//复制构造函数
	void display(); //显示分数
	Fraction operator++(); //前置自增运算符
	Fraction operator++(int); //后置自增运算符
	Fraction operator--(); //前置自减运算符
	Fraction operator--(int); //后置自减运算符
	Fraction operator-(); //取负运算符
	Fraction& operator+=(const Fraction& b); //复合赋值运算符
	Fraction& operator-=(const Fraction& b); //复合赋值运算符
	operator double(); //double类型转换运算符
	~Fraction();
private:
	void simplify(); //简化分数
	int nume, deno; //分子numerator，分母denominator
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