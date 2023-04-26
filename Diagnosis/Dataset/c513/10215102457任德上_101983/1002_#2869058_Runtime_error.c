#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int num,a=0,len,j,k;
    long long int sum=0;
    scanf("%d",&num);
    char str1[61];
    while(a<num){
        int c[61];
       scanf("%s",str1);
       len=strlen(str1);
       if(len==1){
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%d\n",1);
        }
       if(len>=2){
           c[str1[0]]=1;
           int d=0;
           for(j=1;j<len;j++){
               int flag=0;
               for(k=0;k<j;k++){
                   if(str1[j]==str1[k]) flag=1;
                   }
               if(flag==0){
                   c[str1[j]]=d;
                   d++;

               }
               if(d==1)d++;

               }
           for(j=0;j<len;j++){
               sum=sum+c[str1[j]]*(long long int)pow(d,len-1-j);}
           printf("%s","case #");
           printf("%d:\n",a);
           printf("%d\n",sum);
           }
       a++;
       sum=0;}
    return 0;
}
