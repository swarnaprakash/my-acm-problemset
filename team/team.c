// Author - santhanakrishnan.N
#define MAX 2147483647
main()
{
 int arr[100],i,j,k,n,c,st,end,mid,sum,fnd;
 while(1)
 {
  scanf("%d",&n);
  if(n==0)
   break;
  for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
  scanf("%d",&c);
  st=1;end=MAX;
  while(st<end)
  {
   mid=st+(end-st+1)/2;
   sum=0;
   for(i=0;i<n;i++)
   {
    sum+=mid/arr[i];
    fnd=0;
    if(sum<0)
    {
     fnd=1;
     break;
    }
   }
   if(sum<0||sum>=c)
   {
    end=mid-1;
   }
   else
   {
    st=mid;
   }
  }
  printf("%d\n",st+1);
 }
 return 0;
}
