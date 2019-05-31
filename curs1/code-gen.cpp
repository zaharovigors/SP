/* $b04 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //   PROG -> CALCS
  	S1->obj = "int main(){\n" + S1->obj 
  	+ " std::cin.get();\n return 0;\n}\n";
	return 0;}
int tCG::p03(){ //   PROG -> DEFS
	return 0;}
int tCG::p04(){ //   PROG -> DEFS CALCS
    S1->obj += "int main(){\n" + S2->obj
    + " std::cin.get();\n return 0;\n}\n";
	return 0;}

int tCG::p05(){ //  CALCS -> CALC
	return 0;}
int tCG::p06(){ //  CALCS -> CALCS CALC
    S1->obj += S2->obj;
	return 0;}

int tCG::p07(){ //   CALC -> E
    S1->obj = " display("+S1->obj+"); newline();\n";
	return 0;}
int tCG::p08(){ //   CALC -> BOOL
    S1->obj = "display("+S1->obj+"); newline();\n";
	return 0;}
int tCG::p09(){ //   CALC -> STR
    S1->obj = "display("+S1->obj+"); newline();\n";
	return 0;}
int tCG::p10(){ //   CALC -> DISPSET
    S1->obj += ";\n";
	return 0;}
	
int tCG::p11(){ //      E -> $id
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p12(){ //      E -> CONST
	return 0;}
int tCG::p13(){ //      E -> ADD
	return 0;}
int tCG::p14(){ //      E -> SUB
	return 0;}
int tCG::p15(){ //      E -> DIV
	return 0;}
int tCG::p16(){ //      E -> MUL
	return 0;}
int tCG::p17(){ //      E -> COND
	return 0;}
int tCG::p18(){ //      E -> CPROC
	return 0;}

int tCG::p19(){ //  CONST -> $zero
	S1->obj = S1->name;
	return 0;}
int tCG::p20(){ //  CONST -> $dec
	S1->obj = S1->name;
	return 0;}
int tCG::p21(){ //    ADD -> HADD E )
	if(S1->count == 0) {
		S1->obj = S2->obj;
	} else {
		S1->obj += S2->obj;
	}
	S1->obj += ")";
	S1->count = 0;
	return 0;}
int tCG::p22(){ //   HADD -> ( +
	S1->obj = "(";
	return 0;}
int tCG::p23(){ //   HADD -> HADD E
	S1->obj += S2->obj + " + ";
	S1->count++;
	return 0;}

int tCG::p24(){ //    SUB -> ( - E E )
	S1->obj = "(" + S3->obj + "-" + S4->obj + ")"; 
	return 0;}
int tCG::p25(){ //    DIV -> ( / E )
	S1->obj = "(double(1) / "+ S3->obj + ")";
	return 0;}
int tCG::p26(){ //    MUL -> HMUL E )
	if(S1->count == 0) {
		S1->obj = S2->obj;
	} else {
		S1->obj += S2->obj;
	}
	S1->obj += ")";
	S1->count = 0;
	return 0;}
int tCG::p27(){ //   HMUL -> ( *
	S1->obj = "(";
	return 0;}

int tCG::p28(){ //   HMUL -> HMUL E
    S1->obj += S2->obj + " * ";
	S1->count++;
	return 0;}
int tCG::p29(){ //   COND -> HCOND CLAUS )
	S1->obj = S1->obj + "\n\t:" + S2->obj + "\n\t: _infinity)";
	return 0;}
int tCG::p30(){ //  HCOND -> ( cond
	S1->obj = "(";
	return 0;}
int tCG::p31(){ //  HCOND -> HCOND CLAUS
	if(S1->count) S1->obj += "\n\t: ";
	S1->obj += S2->obj; 
	S1->count++;
	return 0;}
int tCG::p32(){ //  CLAUS -> HCLAUS E )
	S1->obj += S2->obj;
	S1->obj += ")";
	S1->count = 0;
	return 0;}
int tCG::p33(){ // HCLAUS -> ( BOOL
	S1->obj = S2->obj + " ? ";
	if(S1->count == 0) S1->obj += "(";
	return 0;}
int tCG::p34(){ // HCLAUS -> HCLAUS INTER
	//if(S1->count == 0) S1->obj += "(";
	S1->obj += S2->obj + ", ";
	S1->count++;
	return 0;}
int tCG::p35(){ //   ELSE -> HELSE E )
	S1->obj += S2->obj;
	if(S1->count) S1->obj += ")";
	S1->count = 0;
	return 0;}
int tCG::p36(){ //  HELSE -> ( else
	return 0;}
int tCG::p37(){ //  HELSE -> HELSE INTER
	if(S1->count == 0) S1->obj += "(";
	S1->obj += S2->obj + ", ";
	S1->count++;
	return 0;}
int tCG::p38(){ //  CPROC -> HCPROC )
	S1->obj += ")";
	S1->count++;
	return 0;}
int tCG::p39(){ // HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p40(){ // HCPROC -> HCPROC E
	if(S1->count) S1->obj += ", ";
	S1->obj +=  S2->obj;
	S1->count++;
	return 0;}
int tCG::p41(){ //   BOOL -> $bool
	S1->obj = (S1->name == "#t" ? "true" : "false");
	return 0;}
int tCG::p42(){ //   BOOL -> $idq
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p43(){ //   BOOL -> CPRED
	return 0;}
int tCG::p44(){ //   BOOL -> REL
	return 0;}
int tCG::p45(){ //   BOOL -> AND
	return 0;}
int tCG::p46(){ //   BOOL -> ( not BOOL )
	S1->obj = "(!" + S3->obj + ")";
	return 0;}
int tCG::p47(){ //  CPRED -> HCPRED )               
	S1->obj += ")";
	return 0;}
int tCG::p48(){ // HCPRED -> ( $idq
	S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p49(){ // HCPRED -> HCPRED ARG
	if(S1->count) S1->obj += ", "; 
	S1->obj += S2->obj;
	S1->count++;
	return 0;}
int tCG::p50(){ //    ARG -> E
	return 0;}
int tCG::p51(){ //    ARG -> BOOL
	return 0;}
int tCG::p52(){ //    REL -> ( <= E E )
	S1->obj = "(" + S3->obj + " <= " + S4->obj + ")";
	return 0;}
int tCG::p53(){ //    REL -> ( = E E )
	S1->obj = "(" + S3->obj + " == " + S4->obj + ")";
	return 0;}
int tCG::p54(){ //    AND -> HAND BOOL )
	if(S1->count == 0) {
		S1->obj = S2->obj;
	} else {
		S1->obj += S2->obj;
	}
	S1->obj += ")";
	S1->count = 0;;
	return 0;}
int tCG::p55(){ //   HAND -> ( and             
    S1->obj = "(";
	return 0;}
int tCG::p56(){ //   HAND -> HAND BOOL
	S1->obj += S2->obj + " && ";
	S1->count++;
	return 0;}
int tCG::p57(){ //    STR -> $str
	S1->obj = S1->name;
	return 0;}
int tCG::p58(){ //    STR -> SIF
	return 0;}
int tCG::p59(){ //    SIF -> ( if BOOL STR STR )
	S1->obj = S3->obj + " ? " + S4->obj + " : " + S5->obj;
	return 0;}
int tCG::p60(){ //    SET -> ( set! $id E )
	S1->obj = decor(S3->name) + " = " + S4->obj;
	return 0;}
int tCG::p61(){ //DISPSET -> ( display E )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p62(){ //DISPSET -> ( display BOOL )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p63(){ //DISPSET -> ( display STR )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p64(){ //DISPSET -> ( newline )
	S1->obj = "newline()";
	return 0;}
int tCG::p65(){ //DISPSET -> SET
	return 0;}
int tCG::p66(){ //  INTER -> DISPSET
	return 0;}
int tCG::p67(){ //  INTER -> E
	return 0;}
int tCG::p68(){ //   DEFS -> DEF
	return 0;}
int tCG::p69(){ //   DEFS -> DEFS DEF
	S1->obj += S2->obj;
	return 0;}
int tCG::p70(){ //    DEF -> PRED
	return 0;}
int tCG::p71(){ //    DEF -> VAR
	return 0;}
int tCG::p72(){ //    DEF -> PROC
	return 0;}
int tCG::p73(){ //   PRED -> HPRED BOOL )
	S1->obj += "\treturn " + S2->obj + ";\n}\n";
	return 0;}
int tCG::p74(){ //  HPRED -> PDPAR )
	declarations += S1->obj + ");\n";
	S1->obj += ") {\n";
	S1->count = 0;
	return 0;}
int tCG::p75(){ //  PDPAR -> ( define ( $idq
	S1->obj = "bool " + decor(S4->name) + "(";
	return 0;}
int tCG::p76(){ //  PDPAR -> PDPAR $idq
	if(S1->count) S1->obj += ", ";
	S1->obj += "bool " + decor(S2->name);
	S1->count++;
	return 0;}
int tCG::p77(){ //  PDPAR -> PDPAR $id
	if(S1->count) S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	S1->count++;
	return 0;}
int tCG::p78(){ //    VAR -> ( define $id CONST )
	declarations += "double " + decor(S3->name) + " = " + S4->obj + ";\n";
	return 0;}
int tCG::p79(){ //   PROC -> HPROC LET )
	S1->obj += "\t{//let\n\t" + S2->obj + "\n\t}//let\n}\n";
	return 0;}
int tCG::p80(){ //   PROC -> HPROC E )
	S1->obj += "\treturn " + S2->obj + ";\n}\n";
	return 0;}
int tCG::p81(){ //  HPROC -> PCPAR )
	declarations += S1->obj + ");\n";
	S1->obj = S1->obj + ") {\n";
	S1->count = 0;
	return 0;}
int tCG::p82(){ //  HPROC -> HPROC INTER
	S1->obj += "\t" + S2->obj + ";\n"; 
	return 0;}
int tCG::p83(){ //  PCPAR -> ( define ( $id
	S1->obj = "double " + decor(S4->name) + "(";
	return 0;}
int tCG::p84(){ //  PCPAR -> PCPAR $id
	if(S1->count) S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	S1->count++;
	return 0;}
int tCG::p85(){ //    LET -> HLET E )
	S1->obj += "return " + S2->obj + ";";
	return 0;}
int tCG::p86(){ //   HLET -> LETLOC )
	if(S1->count) S1->obj += ";\n\t";
	S1->count = 0;
	return 0;}
int tCG::p87(){ //   HLET -> HLET INTER
	S1->obj += S2->obj + ";\n\t";
	return 0;}
int tCG::p88(){ // LETLOC -> ( let (
	return 0;}
int tCG::p89(){ // LETLOC -> LETLOC LETVAR
	if(S1->count) {
		S1->obj += ",\n\t\t";
	} else {
		S1->obj = "double\t" + S1->obj;
	}
	S1->obj += S2->obj;
	S1->count++; 
	return 0;}
int tCG::p90(){ // LETVAR -> ( $id E )
	S1->obj = decor(S2->name) + "(" + S3->obj + ")";
	return 0;}
//_____________________
int tCG::p91(){return 0;} int tCG::p92(){return 0;} 
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


