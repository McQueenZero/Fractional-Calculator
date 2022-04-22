#include <iostream>
#include <iomanip>
#include "Fraction.h"
#include "Calculation.h"
using namespace std;
int main()
{
	cout << "//============================================================================" << endl;
	cout << "//Program name:����������" << endl;
	cout << "//============================================================================" << endl;
	cout << setfill(' ') << setw(70) << "***��ӭʹ�÷���������***" << endl; //w24
	cout << setfill(' ') << setw(78) << "***�˳���ɽ��з����������ݵļ�����***" << endl;//w40
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	char ins1, ins2, ins3, ins4; //input switch key
	while (1) {
		cout << "���� D ������ʾģʽ��	���� F ���빦�����㣨�������㣩ģʽ��	��������������˳���	���س���ȷ�ϣ�" << endl;
		cout << "ģʽ��";
		cin >> ins1;
		while (ins1 == 'd') {
			cout << '\t' << "ʾ������1���ֱ����a=1/4��b=1/2 �ĺ͡�������̲��������" << endl;
			cout << '\t' << "           �жϹ�ϵʽa==b��a!=b��a>=b��a<=b���߼�ֵ��������ʾ" << endl;
			cout << '\t' << "ʾ������2����a=1/4��b=1/4��c=1/4 ����ʹd=a++��d=++b��d=-c" << endl;
			cout << '\t' << "           ���a,d;b,d;c,d;" << endl;
			cout << '\t' << "ʾ������3����a=2/5��b=1/2"<<endl;
			cout << '\t' << "           �Ⱥ����a-=b��a+=a�����a"<<endl;
			cout << '\t' << "ʾ������4��a=0.125,��ʵ����ת���ɷ���,b=1/2"<<endl;
			cout << '\t' << "           ��������ǿ������ת����(double) Fraction ʵ��(double)(a+b)�����"<<endl;
			cout << "�������˳�" << endl;
			cout << "����������ѡ�񣨰���1-4)��";
			cin >> ins2;
			if (ins2=='1'||ins2=='2'||ins2=='3'||ins2=='4') cout << "ʾ�������" << endl;
			switch (ins2){ //ins2 is char
			case '1':cout<<'\t',Demo_Function1(), cout << endl; break;
			case '2':cout << '\t', Demo_Function2(), cout << endl; break;
			case '3':cout << '\t', Demo_Function3(), cout << endl; break;
			case '4':cout << '\t', Demo_Function4(), cout << endl; break;
			default:ins2 = NULL; break;
			}
			if (ins2==NULL) break;
		}
		while (ins1 == 'f') {
			cout << '\t' << "��ѡ������ģʽ��" << endl;
			cout << '\t' << "1���������ӷ�             2������������                    3���������˷�                  4������������" << endl;
			cout << '\t' << "5����������ۼ�           6����������۳�                  7�������˷���                  8������" << endl;
			cout << '\t' << "9��С��������             0��������С��                    r��Լ��"<< endl;
			//cout << "////////" << "����������������Ļ�ϼ��㣬����ʱ�뽫����ת���ɷ������ƣ�a/1��" << "////////" << endl;
			//cout << "////////" << "������С���������ϼ��㣬����ʹ��С������������ת���ɷ������㡣" << "////////" << endl;
			cout << "����ģʽ������0-9,r�����������˳�����";
			cin >> ins3; 
			if (ins3 <= '8'&&ins3 >= '1') {
				cout << "�����ʽ��0��С����1����������Ĭ�Ϸ�������";
				cin >> ins4;
			}
			switch (ins3) { //ins2 is char
				case '1': {
					cout << ">>���Է�����ʽ����a,b �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracAdd() << endl;
					else cout << "Result:" << FracAdd() << endl;
					break;
				}
				case '2': {
					cout << ">>���Է�����ʽ����a,b �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracSub() << endl;
					else cout << "Result:" << FracSub() << endl;
					break;
				}
				case'3' : {
					cout << ">>���Է�����ʽ����a,b �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracMul() << endl;
					else cout << "Result:" << FracMul() << endl;
					break;
				}
				case '4': {
					cout << ">>���Է�����ʽ����a,b �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracDiv() << endl;
					else cout << "Result:" << FracDiv() << endl;
					break;
				}
				case '5': {
					cout << ">>��һ����������ĸ���n" << endl;
					cout << ">>�ڶ�����������n������" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracSumm() << endl;
					else cout << "Result:" << FracSumm() << endl;
					break;
				}
				case '6': {
					cout << ">>��һ����������ĸ���n" << endl;
					cout << ">>�ڶ�����������n������" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracCumu() << endl;
					else cout << "Result:" << FracCumu() << endl;
					break;
				}
				case '7': {
					cout << ">>�������뱶��n�����ͣ���>>����a �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracMupl() << endl;
					else cout << "Result:" << FracMupl() << endl;
					break;
				}
				case '8': {
					cout << ">>�����������a��>>��������n �Կո����" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracPow() << endl;
					else cout << "Result:" << FracPow() << endl;
					break;
				}
				case '9': {
					cout << ">>��һ��������ת����ʵ�����ĸ���n" << endl;
					cout << ">>�ڶ�����������n��ʵ����" << endl;
					dtof();
					break;
				}
				case '0': {
					cout << ">>��һ��������ת���ķ����ĸ���n" << endl;
					cout << ">>�ڶ�����������n������" << endl;
					ftod();
					break;
				}
				case 'r': {
					cout << ">>��һ��������Լ�ֵĸ���n" << endl;
					cout << ">>�ڶ�����������n������" << endl;
					FracRedu();
					break;
				}
				default: ins3 = NULL; break;
			}
			if (ins3 == NULL) break;
		}
		if (ins1 != 'd'&&ins1 != 'f') break;
	}
	cout << setfill(' ') << setw(66) << "***ллʹ��***" << endl;
	return 0;
}