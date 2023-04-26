#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int num,a=0,len,b=0,i,sum=0;
    scanf("%d",&num);
    char str1[60];
    int c[60];
    while(a<num){
       scanf("%s",str1);
       len=strlen(str1);
       if(len==1){
           printf("%s","case #","%d:\n",a);
           printf("%d\n",1);
       }
       if(len>=2){
           for(i=0;i<len;i++){
               if(str1[i]>='A'&&str1[i]<='z')break;
           }
           if(i==len){
               for(i=0;i<len;i++){
                   sum=sum+(str1[i]-48)*pow(2,len-1-i);
               }
               printf("%s","case #");
               printf("%d:\n",a);
               printf("%d\n",sum);
           }
           if(i!=len) {
               c[0] = 1;
               c[1] = 0;
               for (i = 2; i <= len-1; i++) {
                   c[i] = i;
               }
               for (i = 0; i < len; i++) {
                   sum = sum + c[i] * pow(len, len - 1 - i);
               }
               printf("%s","case #");
               printf("%d:\n",a);
               printf("%d\n",sum);
           }}
       a++;
       sum=0;
    }
    return 0;
}
