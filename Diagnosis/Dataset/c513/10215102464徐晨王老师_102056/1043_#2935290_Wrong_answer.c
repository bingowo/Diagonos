#include <stdio.h>
#include <string.h>

void insert(char *s, char c, int index)
{
	int lens = strlen(s);
	memmove(s + index + 1, s + index, lens - index + 1);
	*(s + index) = c;
}
int del(char *s){
    int a=0;
    int b;
    while(1){

   int lens = strlen(s);
       if(b==lens)break;
   //printf("%d\n",b);
   if(s[0]==s[1]){
       a=a+2;
       s[0]=-1;
       s[1]=-1;
   }
   for(int j=2;j<lens;j++){
      if(s[j]==s[j-1]&&s[j-1]==s[j-2]){
          a=a+1;
          s[j]=-1;
          s[j-1]=-1;
          s[j-2]=-1;
      }
      if(s[j]==s[j-1]&&s[j-1]!=s[j-2]){
          a=a+2;
          s[j]=-1;
          s[j-1]=-1;
      }
   }
   char ss[100];
   int r=0;
   for(int l=0;l<lens;l++){
       if(s[l]!=-1){
           ss[r]=s[l];
           r=r+1;
   }
   }
   s=ss;
   b=lens;

   }
   return a;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s1[100],s2[100];
        scanf("%s",s1);
        strcpy(s2,s1);
        int dele=0;
        int len=strlen(s1);
        int sum;
        for(int i=0;i<len+1;i++){
            strcpy(s2,s1);
            insert(s2,'A',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'B',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
            strcpy(s2,s1);
            insert(s2,'C',i);
            sum=del(s2);
            if(dele<sum)dele=sum;
        }
        printf("case #%d:\n%d\n",t,dele);
    }
    return 0;
}
