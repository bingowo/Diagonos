#include<stdio.h>
#include<string.h>
int T,hash[300];
char s[1005];
int main(){
 scanf("%d",&T);
 for(int c=0;c<T;c++){
  for(int i=0;i<300;i++) hash[i]=-1;
  scanf("%s",s);
  long long ans=0,cnt=0;
  for(int i=0;s[i]!='\0';i++){
   if(hash[s[i]]==-1){
    if(cnt==0) hash[s[i]]=1;
    else if(cnt==1) hash[s[i]]=0;
    else hash[s[i]]=cnt;
    cnt++;
   }
  }
  if(cnt==1) cnt++;
  for(int i=0;s[i]!='\0';i++){
   ans=ans*cnt+hash[s[i]];
  }
  printf("case #%d:\n%lld\n",c,ans);
 }
 return 0;
}