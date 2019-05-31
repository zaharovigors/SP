#include "mlisp.h"

double a = 7;
double b = 8;
double fun(double x);
double eps = 0.00001;
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double mphi = 0;
double __nev__try(double a, double b, double xa, double ya, double xb, double yb);
double xmin = 0;

double fun(double x) {
    x = x - double(104) / 105 / e;
    return -sin(x) + expt(x - 7, 4) + 0.3;
}

double golden__section__search(double a, double b) {
    { // let
    double xmin(a < b ? golden__start(a, b) : golden__start (b, a));
    newline();
    return xmin;
    } // let
}

double golden__start(double a, double b) {
    mphi = 0.5 * (3 - sqrt(5));
    {  // let
    double xa = a + mphi * (b - a);
    double xb = b - mphi * (b - a);
    return __nev__try(a, b, xa, fun(xa), xb, fun(xb));
    }
}

double __nev__try(double a, double b, double xa, double ya, double xb, double yb) {
    return (abs(a - b) < eps) ? ((a + b) * 0.5) :
    ((true) ?   (display("+"),
                    (ya < yb) ? (   b = xb, 
                                    xb = xa, 
                                    yb = ya, 
                                    xa = a + mphi * (b - a), 
                                    __nev__try(a, b, xa, fun(xa), xb, yb)
                                ) :
                                (   a = xa,
                                    xa = xb,
                                    ya = yb,
                                    xb = b - mphi * (b - a),
                                    __nev__try(a, b, xa, ya, xb, fun(xb))
                                )
                ) :
        (_infinity)
    );
}

int main() {
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
    return 0;
}
