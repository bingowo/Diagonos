#include<stdio.h>
#include<string.h>
int main()
{
 int min(int x,int y);
 int max(int x,int y);
 


 char numberN[1000], numberM[1000];
 while(scanf("%s%s",numberN,numberM) != EOF)//当出现EOF时，结束测试。
{

    int n = strlen(numberN), m = strlen(numberM);
    int a[n], b[m];
    int i, j;
    for (i = 0, j = n - 1; i < n; i++, j--) {
        a[i] = numberN[j] - '0';
    }
    for (i = 0, j = m - 1; i < m; i++, j--) {
        b[i] = numberM[j] - '0';
    }
 int c[1500];
 for(i=0;i<1500;i++)
 {
 c[i]=0;
 }
 for(i=0;i<min(n,m);i++)
 {
  c[i]=a[i]+b[i];
 }
 for(i=min(n,m);i<max(n,m);i++){
  if(n==max(n,m))
  c[i]=a[i];
  else
  c[i]=b[i];
 }
 for(i=0;i<max(n,m)+1;i++)
 {
  if(c[i]>=10){
   c[i+1] +=c[i]/10;
   c[i]%=10;
  }
 }
 for(j=1499;j>0;j--){
  if(c[j] !=0)
  break;
 }
 for(i=j;i>=0;i--){
  printf("%d",c[i]);
 }
 printf("\n");
}
 return 0;
}
int min(int x,int y)
{
 if(x>y)
 return y;
 else
 return x;
}
int max(int x,int y)
{
 if(x>y)
 return x;
 else
 return y;
}