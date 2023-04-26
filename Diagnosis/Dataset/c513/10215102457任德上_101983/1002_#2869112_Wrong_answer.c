#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int num,a=0,len,j,k,flag=0;
    long long int sum=0;
    scanf("%d",&num);
    char str1[61];

    while(a<num){
    int c[123];
       scanf("%s",str1);
       len=strlen(str1);
       if(len==1){
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%d\n",1);
       }
       if(len>=2){
           c[str1[0]]=1;
           int d=1;
           if(str1[1]!=str1[0]){
               c[str1[1]]=0;
               d++;}
           if(str1[1]==str1[0]){
               c[str1[1]]=1;
               d=0;

           }
           for(j=2;j<len;j++){
               for(k=0;k<j;k++){
                   if(str1[j]==str1[k]) flag=1;
                   }
               if(flag==0){
                   c[str1[j]]=d;
                   d++;
                   if(d==1)d++;
               }}
            if(d==0)d=2;
           for(j=0;j<len;j++){
               sum=sum+c[str1[j]]*(long long int)pow(d,len-1-j);}
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%d\n",sum);
           flag=0;
           }
       a++;
       sum=0;}
    return 0;
}
