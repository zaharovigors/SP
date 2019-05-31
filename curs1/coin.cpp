/*  ZIS2019   */
#include "mlisp.h"
double VARIANT = 4;
double LAST__DIGIT__OF__GROUP__NUMBER = 8;
double LARGEST__COIN = 50;
bool implication_Q(bool x_Q, bool y_Q);
double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
//________________ 
bool implication_Q(bool x_Q, bool y_Q) {
	return (!(x_Q && (!y_Q)));
}
double cc(double amount, double largest__coin) {
	return (((amount == 0) && (largest__coin == 1)) ? (1)
	: implication_Q((0 <= amount), (largest__coin == 0)) ? (0)
	:true ? ((cc(amount, next__coin(largest__coin)) + cc((amount-largest__coin), largest__coin)))
	: _infinity);
}
double count__change(double amount) {
	return cc(amount, LARGEST__COIN);
}
double next__coin(double coin) {
	return ((coin == 50) ? (5)
	: (coin == 5) ? (3)
	: (coin == 3) ? (2)
	: (coin == 2) ? (1)
	:true ? (0)
	: _infinity);
}
double GR__AMOUNT() {
	return remainder(((100 * LAST__DIGIT__OF__GROUP__NUMBER) + VARIANT), 137);
}
int main(){
display(" ZIS variant ");
display(VARIANT);
newline();
display(" 1-2-3-5-50");
newline();
display("count-change for 100 \t= ");
display(count__change(100));
newline();
display("count-change for ");
display(GR__AMOUNT());
display(" \t= ");
display(count__change(GR__AMOUNT()));
 std::cin.get();
 return 0;
}

