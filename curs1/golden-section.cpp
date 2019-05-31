/*  ZIS2019   */
#include "mlisp.h"
double a = 7;
double b = 8;
double fun(double x);
double eps = 0.00001;
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double mphi = 0;
double __ZIS2019__try(double a, double b, double xa, double ya, double xb, double yb);
double xmin = 0;
//________________ 
double fun(double x) {
	x = (x-(104 * (double(1) / 105) * (double(1) / e)));
	return ((0.3 + expt((x-7), 4))-sin(x));
}
double golden__section__search(double a, double b) {
	{//let
	double	xmin(((a <= b) ? (golden__start(a, b))
	:true ? (golden__start(b, a))
	: _infinity));
	newline();
	return xmin;
	}//let
}
double golden__start(double a, double b) {
	mphi = (0.5 * (3-sqrt(5)));
	{//let
	double	xa((a + (mphi * (b-a)))),
		xb((b-(mphi * (b-a))));
	return __ZIS2019__try(a, b, xa, fun(xa), xb, fun(xb));
	}//let
}
double __ZIS2019__try(double a, double b, double xa, double ya, double xb, double yb) {
	return ((abs((a-b)) <= eps) ? (((a + b) * 0.5))
	:true ? (display("+"), ((ya <= yb) ? (b = xb, xb = xa, yb = ya, xa = (a + (mphi * (b-a))), __ZIS2019__try(a, b, xa, fun(xa), xb, yb))
	:true ? (a = xa, xa = xb, ya = yb, xb = (b-(mphi * (b-a))), __ZIS2019__try(a, b, xa, ya, xb, fun(xb)))
	: _infinity))
	: _infinity);
}
int main(){
xmin = golden__section__search(a, b);
display("interval=\t[");
display(a);
display(" , ");
display(b);
display("]\n");
display("xmin=\t\t");
 display(xmin); newline();
display("f(xmin)=\t");
 display(fun(xmin)); newline();
 std::cin.get();
 return 0;
}

