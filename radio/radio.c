main()
{
 int i,j,k,n,q,lx[100],ly[100],rx[100],ry[100],x,y,cnt;
 while(1)
 {
  scanf("%d %d",&n,&q);
  if(n==0&&q==0)
   break;
  for(i=0;i<n;i++)
  {
   scanf("%d %d %d %d",&lx[i],&ly[i],&rx[i],&ry[i]);
  }
  while(q--)
  {
   scanf("%d %d",&x,&y);
   cnt=0;
   for(i=0;i<n;i++)
   {
    if((x>=lx[i]&&x<=rx[i])&&(y>=ly[i]&&y<=ry[i]))
     cnt++;
   }
   printf("%d\n",cnt);
  }
 }
 return 0;
}
