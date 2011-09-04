#include<stdio.h>

# define M 305

main()
{
int i,ns,nq,a,j,c;
int l[M],r[M];

while(1)

{
scanf("%d %d",&ns,&nq);

if(ns==0 & nq==0)
 break;

for(i=0;i<ns;++i)
 scanf("%d %d",&l[i],&r[i]);

for(i=0;i<nq;++i)
{
scanf("%d",&a);
c=0;
 for(j=0;j<ns;++j)
  if(a>=l[j] && a<=r[j])
   ++c;

if(c%2==0)
 puts("NO");
else
 puts("YES");

}
puts("");
}

return 0;

}
