//Author - Swarnaprakash.U
#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int);
bool ismersenne(int);

main()
{
	int t;
	int n;
	bool prime,mersenne;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		prime=isprime(n);
		mersenne=ismersenne(n);
		
		if(prime && mersenne)
			cout<<"MERSENNE PRIME"<<endl;
		else if(prime)
			cout<<"PRIME"<<endl;
		else if(mersenne)
			cout<<"MERSENNE"<<endl;
		else
			cout<<"NONE"<<endl;
	}
	return 0;
}

bool ismersenne(int n)
{
	// checking if n+1 is a power of two
	n++;
	
	// a power of two has a one followed by zeros in binary notation
	
	if( (n&(n-1))==0)
		return true;
	else 
		return false;
}

bool isprime(int n)
{
	int i,sq;
	
	 if(n<2)
		  return false;
	  
	 if(n==2)
		  return true;
	  
	 if(n%2==0)
	  	return false;
	
	  sq=(int)(sqrt((double)n)+1);
	  
	  for(i=3;i<=sq;i+=2)
	   	if(n%i==0)
		    return false;
	  
	  return true;      
	        
}
