#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int deal(char *s,int *a){
 int tot=0,res=0;
 for(int i=0;s[i]!='\0';i++){
  if(s[i]==',') a[++tot]=res,res=0;
  else res=res*10+s[i]-'0';
 }
 a[++tot]=res,res=0;
 for(int i=1;i<=tot/2;i++){
  int tmp=a[i];
  a[i]=a[tot-i+1],a[tot-i+1]=tmp;
 }
 return tot;
}
int a[100],b[100],la,lb,T;
int pri[30]={0, 2, 3, 5 ,7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
char s[505];
int main(){
 scanf("%d",&T);
 for(int c=0;c<T;c++){
  scanf("%s",s),la=deal(s,a);
  scanf("%s",s),lb=deal(s,b);
  int ml=la;
  if(la<lb) ml=lb;
  for(int i=la+1;i<=ml;i++) a[i]=0;
  for(int i=lb+1;i<=ml;i++) b[i]=0;
  int up=0;
  for(int i=1;i<=ml;i++){
   a[i]=a[i]+up+b[i],up=0;
   if(a[i]>=pri[i]) up=1;
   a[i]%=pri[i];
  }
  if(up) a[++ml]=up;
  printf("case #%d:\n",c);
  for(int i=ml;i;i--) printf("%d%c",a[i],i==1?'\n':',');
 }
 return 0;
}