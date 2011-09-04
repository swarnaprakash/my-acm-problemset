//Author - Santhankrishnan.N
#define N 100
int res(char[100]);
int tr;
main()
{
 int i,j,tc;
 char str[N];
 scanf("%d",&tc);
 while(tc--)
 {
 scanf("%s",str);
 tr=0;

 printf("%d\n",rec(str));
 }
 return 0;


}

int rec(char str[N])
{
 int i,j,k=0,lev=0,lt;
 lt=tr;
 if(str[tr]=='0')
 {            
  
  //printf("tr= %d %c returns %d\n",lt,str[lt],1);
  //tr++;
  return 1;
 }
 i=str[tr]-48;
 
 for(j=0;j<i;j++)
 {
  tr++;
  //printf("calling  %d",tr);        
  k=rec(str)+1;
  if(k>lev)
   lev=k;
 }
  //printf("tr= %d %c returns %d\n",lt,str[lt],lev);
  return lev;

 
}
