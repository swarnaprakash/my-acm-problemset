#include<stdio.h>

main()
{
int i,n,t;

scanf("%d",&t);

while(t--)
{

scanf("%d",&n);

for(i=29;i>=0;--i)
if(n&(1<<i))
 printf("%d\n",i);

puts("");
}

return 0;
}

