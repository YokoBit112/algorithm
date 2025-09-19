#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<string> a = { "","Error : Incorrect use of parentheses",
						"Error : expected ',' or ';' before '}' token ",
						"Error : Invalid number in octal constant in the number",
						"Error : the exponent part of the number does not specify a number",
						"Error : Chinese characters appear in this line",
						"Error : invalid operands of types 'int' and 'float' to binary 'operator%'",
						"Error : the procedure did not end within the specified time",
						"Error : the else does not detect a matching if",
						"Error : too many initializers,array bounds overflow",
						"Error : invalid operands of types 'int*' and 'int*' to binary 'operator+'",
						"Error : undeclared identifier，expected constant expression，cannot allocate an array of constant size 0",
						"Error : invalid conversion from 'const char*' to 'int' [-fpermissive]" };
	vector<string> b = {
		"int a=0xhh;",
		"float a=123.456E;",
		"int x=081;",
		"int x=071,y=70; if(x>y)( printf(\"x比y大\"); ) else( printf(\"y比x大\"); )",
		"char x; scanf(\"%c\",&x); switch(x){ case \"a\" : printf(\"你输入的是a\"); break; }",
		"int a[n],n=10;",
		"int *pa=10,*pb=20,*a; a = pa + pb;",
		"char a[4]={'a','b','c','d','e'};",
		"int x=100000000; while((x++)<2147483648)",
		"int t=1; if(t>0) if(t>10) printf(\"aaa\"); else printf(\"bbb\") else printf(\"ccc\");",
		"int x=2022; float y=8; printf(\"%d\",x%y);",
		"double x; scanf(\"%2.3lf\",&x); printf(\"%lf\",x);",
		"int a=10；",
		"int x; scanf(\"%d\",&x); printf(\"%d\",&x);",
		"int x=10,y=20; x=x>y?x:y;",
		"int a=0" };
	int n, m;
	vector<string> c = { "0","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NIGHT","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN" };
	vector<int> d = { 0,0,4,3,1,12,11,10,9,7,8,6,0,5,0,0,2 };

	cin >> n >> m;
	cout << "you choose the ERROR INFORMATION " << c[n] << "{" << a[n] << "} and the EXPRESS OPTION " << c[m] << "{" << b[m - 1] << "}" << endl;

	if (d[m] == n) { cout << "MATCH"; }
	else {
		cout << "NO MATCH";
	}
}