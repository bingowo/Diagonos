#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int num,a=0,len,j,k,flag=0,i;
    long long int sum=0;
    scanf("%d",&num);
    char str1[61];
    int c[123];
    for(i=0;i<123;i++){
        c[i]=-1;
    }
    while(a<num){
       scanf("%s",str1);
       len=strlen(str1);
       if(len==1){
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%d\n",1);
       }
       if(len>=2){
           int d=1;
           c[str1[0]]=1;
           if(str1[1]!=str1[0]){
               c[str1[1]]=0;
               d++;}
           if(str1[1]==str1[0]){
               c[str1[1]]=1;
               d=0;
           }
           for(j=2;j<len;j++){
               for(k=0;k<j;k++){
                   if(str1[j]==str1[k]) {flag=1;}}
               if(flag==0){
                   c[str1[j]]=d;
                   d++;
                   if(d==1) d++;
               }flag=0;}
           if(d==0) d=2;
           for(j=0;j<len;j++){
               if(str1[j]!=-1){
                   sum=sum+c[str1[j]]*(int)pow(d,len-1-j);}}
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%lld\n",sum);
           }
       a++;
       sum=0;}
    return 0;
}