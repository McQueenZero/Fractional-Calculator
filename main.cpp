#include <iostream>
#include <iomanip>
#include "Fraction.h"
#include "Calculation.h"
using namespace std;
int main()
{
	cout << "//============================================================================" << endl;
	cout << "//Program name:分数计算器" << endl;
	cout << "//============================================================================" << endl;
	cout << setfill(' ') << setw(70) << "***欢迎使用分数计算器***" << endl; //w24
	cout << setfill(' ') << setw(78) << "***此程序可进行分数类型数据的简单运算***" << endl;//w40
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	char ins1, ins2, ins3, ins4; //input switch key
	while (1) {
		cout << "按下 D 进入演示模式；	按下 F 进入功能运算（自由运算）模式：	按下其他任意键退出；	按回车键确认；" << endl;
		cout << "模式：";
		cin >> ins1;
		while (ins1 == 'd') {
			cout << '\t' << "示例函数1：分别计算a=1/4，b=1/2 的和、差、积、商并依次输出" << endl;
			cout << '\t' << "           判断关系式a==b，a!=b，a>=b，a<=b的逻辑值并依次显示" << endl;
			cout << '\t' << "示例函数2：对a=1/4，b=1/4，c=1/4 依次使d=a++，d=++b，d=-c" << endl;
			cout << '\t' << "           输出a,d;b,d;c,d;" << endl;
			cout << '\t' << "示例函数3：对a=2/5，b=1/2"<<endl;
			cout << '\t' << "           先后计算a-=b，a+=a；输出a"<<endl;
			cout << '\t' << "示例函数4：a=0.125,将实型数转化成分数,b=1/2"<<endl;
			cout << '\t' << "           后用重载强制类型转换符(double) Fraction 实现(double)(a+b)并输出"<<endl;
			cout << "其他键退出" << endl;
			cout << "请输入您的选择（按键1-4)：";
			cin >> ins2;
			if (ins2=='1'||ins2=='2'||ins2=='3'||ins2=='4') cout << "示例结果：" << endl;
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
			cout << '\t' << "请选择运算模式：" << endl;
			cout << '\t' << "1：两分数加法             2：两分数减法                    3：两分数乘法                  4：两分数除法" << endl;
			cout << '\t' << "5：多个分数累加           6：多个分数累乘                  7：整数乘分数                  8：次幂" << endl;
			cout << '\t' << "9：小数化分数             0：分数化小数                    r：约分"<< endl;
			//cout << "////////" << "若进行整数与分数的混合计算，输入时请将整数转换成分数形势（a/1）" << "////////" << endl;
			//cout << "////////" << "若进行小数与分数混合计算，请先使用小数化分数功能转化成分数计算。" << "////////" << endl;
			cout << "运算模式（按键0-9,r）（其他键退出）：";
			cin >> ins3; 
			if (ins3 <= '8'&&ins3 >= '1') {
				cout << "输出格式（0：小数；1：分数）（默认分数）：";
				cin >> ins4;
			}
			switch (ins3) { //ins2 is char
				case '1': {
					cout << ">>请以分数格式输入a,b 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracAdd() << endl;
					else cout << "Result:" << FracAdd() << endl;
					break;
				}
				case '2': {
					cout << ">>请以分数格式输入a,b 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracSub() << endl;
					else cout << "Result:" << FracSub() << endl;
					break;
				}
				case'3' : {
					cout << ">>请以分数格式输入a,b 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracMul() << endl;
					else cout << "Result:" << FracMul() << endl;
					break;
				}
				case '4': {
					cout << ">>请以分数格式输入a,b 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracDiv() << endl;
					else cout << "Result:" << FracDiv() << endl;
					break;
				}
				case '5': {
					cout << ">>第一行输入分数的个数n" << endl;
					cout << ">>第二行依次输入n个分数" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracSumm() << endl;
					else cout << "Result:" << FracSumm() << endl;
					break;
				}
				case '6': {
					cout << ">>第一行输入分数的个数n" << endl;
					cout << ">>第二行依次输入n个分数" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracCumu() << endl;
					else cout << "Result:" << FracCumu() << endl;
					break;
				}
				case '7': {
					cout << ">>依次输入倍数n（整型），>>分数a 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracMupl() << endl;
					else cout << "Result:" << FracMupl() << endl;
					break;
				}
				case '8': {
					cout << ">>依次输入分数a，>>整数次幂n 以空格隔开" << endl;
					if (ins4 == '0') cout << "Result:" << (double)FracPow() << endl;
					else cout << "Result:" << FracPow() << endl;
					break;
				}
				case '9': {
					cout << ">>第一行输入需转化的实型数的个数n" << endl;
					cout << ">>第二行依次输入n个实型数" << endl;
					dtof();
					break;
				}
				case '0': {
					cout << ">>第一行输入需转化的分数的个数n" << endl;
					cout << ">>第二行依次输入n个分数" << endl;
					ftod();
					break;
				}
				case 'r': {
					cout << ">>第一行输入需约分的个数n" << endl;
					cout << ">>第二行依次输入n个分数" << endl;
					FracRedu();
					break;
				}
				default: ins3 = NULL; break;
			}
			if (ins3 == NULL) break;
		}
		if (ins1 != 'd'&&ins1 != 'f') break;
	}
	cout << setfill(' ') << setw(66) << "***谢谢使用***" << endl;
	return 0;
}