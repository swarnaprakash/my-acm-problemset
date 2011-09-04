#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int t=0;
	char i,j,k,l;
	
	cout<<"1000\n";
	
	for(i='a';i<='d' && t<1000;++i)
		for(j='1';j<='4' && t<1000;++j)
			for(k='a';k<='h' && t<1000;++k)
				for(l='1';l<='8' && t<1000;++l)
				{
					printf("%c%c %c%c\n",i,j,k,l);
					++t;
				}
	return 0;
}
