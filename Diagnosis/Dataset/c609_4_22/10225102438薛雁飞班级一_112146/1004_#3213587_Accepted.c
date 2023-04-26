#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A,B,i;
    char s[33];
    scanf("%d %s %d",&A,s,&B);
    int t[36];
    for(i=0;i<strlen(s);i++){
        if(s[i]>='a')s[i]=s[i]-32;
        if(s[i]<'K'&&s[i]>='A'){
            t[i]=s[i]-17-'0';
            t[i]=t[i]+10;
        }
        else if(s[i]>='K'&&s[i]<'U'){
            t[i]=s[i]-27-'0';
            t[i]=t[i]+20;
        }
        else if(s[i]>='U'&&s[i]<='Z'){
            t[i]=s[i]-37-'0';
            t[i]=t[i]+30;
        }
        else if(s[i]<='9')t[i]=s[i]-'0';
    }
    int N=0,r;
    i=0;
    while(i<strlen(s)){
        N=N*A+t[i];
        i++;
    }
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a[33];
    int k=0;
    do{
        r=N%B;
        a[k++]=table[r];
        N=N/B;
    }while(N);
    for(k=k-1;k!=-1;k--)printf("%c",a[k]);
    return 0;
}
