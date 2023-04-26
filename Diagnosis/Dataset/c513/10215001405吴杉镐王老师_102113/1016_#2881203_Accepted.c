#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m;
char ans[2005];
int main() {
 int cnt=0;
 scanf("%d%d",&n,&m);
 while(n!=0){
  int p=n%m;
  if(p<0) p-=m;
  n-=p,n/=m;
  if(p>9) ans[++cnt]=p-10+'A';
  else ans[++cnt]=p+'0';
 }
 for(int i=cnt;i;i--) printf("%c",ans[i]);
 if(cnt==0) puts("0");
 return 0;
}