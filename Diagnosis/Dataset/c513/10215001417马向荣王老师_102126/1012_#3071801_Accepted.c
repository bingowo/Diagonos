#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[100]={'\0'};scanf("%s",str);
     if(str[0]=='0' && str[1]=='\0'){
        printf("0");
    }
   int start = 0;
    int rSig = 1, iSig = 1;
    if(str[0]=='-'){
        start = 1;
        rSig = -1;
    }
    
    long long tmp=0,a=0,b=0;
    while(str[start]!='+' && str[start]!='-' && str[start]!='\0' && str[start]!='i')
        tmp = tmp*10 + str[start++] - 48;
    if(str[start]=='i'){
        if(!tmp) b=1*rSig;
        else b= tmp*rSig;
    }
    else{
        a=tmp*rSig;
        if(str[start]=='-')
            iSig = -1;
        start++;
        tmp = 0;
        while(str[start]!='\0' && str[start]!='i')
            tmp = tmp*10 + str[start++] - 48;
        if(str[start]=='i'){
            if(!tmp) b= 1*iSig;
            else b= tmp*iSig;
}    
}
    int r[200];long long qr,qi;int k,i;
    while(a!=0||b!=0)
    {
        if(abs(a)%2==abs(b)%2)r[k]=0;
        else r[k]=1;
        qr=(b-a+r[k])/2;
        qi=-(a+b-r[k])/2;
        a=qr;
        b=qi;
        k++;
    }
for(i=k-1;i>=0;i--)
printf("%d",r[i]);  
}