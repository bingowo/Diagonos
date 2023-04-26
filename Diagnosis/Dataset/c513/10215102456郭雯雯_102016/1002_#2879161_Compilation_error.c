#include<stdio.h>
#include<stdlib.h>
int num(char* a){//字符串中不同字符的个数
    int n=strlen(a);
    char s[n];
    strcpy(s,a);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s[j]==s[i]){
                n--;break;
            }
}
int trans(char* a){
    int r=num(a),n=strlen(a);
    char* b[n];
    b+0=='1';
    //for (int i=1;i<n;i++)
    //  if((a+i)!=(a+0)){
    //      b+i='0';
      //      break;
        //}
    char s[61]='023456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    int m=0
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a+j==a+i)
                b+j=b+i;
            else{
                b+j=s[m];
                m++;
            }
        }
    }
}
