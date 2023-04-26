#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a,b,l;
char s[1005],ans[10005];
int main() {
 scanf("%s",s);
 l=strlen(s);
 if(s[l-1]!='i') a=atoll(s),b=0;
 else{
  for(int i=l-1;i>=0;i--)
   if(s[i]=='+'||s[i]=='-'||i==0){
    if(s[i+1]=='i') b=s[i]=='+'?1:-1;
    else if(s[i]=='i') b=1;
    else s[l-1]='\0',b=atoll(s+i);
    if(i!=0) s[i]='\0',a=atoll(s);
    else a=0;
    break;
   }
 }
 int top=0;
 while(a!=0||b!=0){
  long long lasa=a,lasb=b;
  if((a-b)%2 == 0) ans[++top]='0',a=(lasa-lasb)/-2,b=(lasa+lasb)/-2;
  else ans[++top]='1',a=(lasa-lasb-1)/-2,b=(lasa+lasb-1)/-2;
 }
 if(top==0) puts("0");
 while(top) printf("%c",ans[top--]);
 return 0;
}