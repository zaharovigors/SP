#include "mlisp.h"

double even__bits(double n);
double odd__bits(double n);
double display__bin(double n);
double report__result(double n);

double even__bits(double n) {
    return (n == 0 ? 1
            : remainder(n,2) == 0 ?
                even__bits(quotient(n,2))
            : odd__bits(quotient(n,2))
            );
}

double odd__bits(double n) {
  return (n == 0 ? 0
       : remainder(n,2) == 0 ?
                odd__bits (quotient(n,2))
       : true ? even__bits(quotient(n,2))
       : _infinity);
}

double display__bin(double n) {
    display(remainder(n,2));
    return (n == 0 ? 0 : display__bin(quotient(n,2)));
}

double report__result(double n) {
    display("Happy birthday to you!\n\t");
    display(n); display(" (decimal)\n\t");
    display__bin(n); display(" (reversed bynary)\n");
    display("\teven?\t");
    even__bits(n) == 1 ? display("yes") : display("no");
    newline();
    display("\todd?\t");
    odd__bits(n) == 1 ? display("yes") : display("no");
    newline();
    return 0;
}

double dd = 02;
double mm = 07;
double yyyy = 2000;

int main() {
    report__result(dd * 1000000 + mm * 10000 + yyyy);
    return 0;
}
