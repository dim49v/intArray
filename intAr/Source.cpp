#include "intAr.h"
//Class IntegerArray with methods
int main(){
	int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9};
	intAr ar (a, 4);
	cout << ar;
	intAr ar2 =	ar;
	ar2--;
	cout << ar2;
	intAr ar3;
	ar3 =  ar + ar2;
	cout << ar3;
	ar = ar2 + 1;
	cout << ar;
	system("pause");
}