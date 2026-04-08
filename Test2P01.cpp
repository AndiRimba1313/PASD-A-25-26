#include <iostream>
#include <ctype.h>
using namespace std;

int main ()
{
    int i;
	char *namaKu, NM[5]= {'R','I','M','B','A'};
	cout << " Nama KU " << endl;
	cout << "~~~~~~~~~" << endl;
	for (i=0; i<5; i++)
	{
	  namaKu = &NM[i];
	  cout << "    " << *namaKu << endl;
	}
	cin.get();
}