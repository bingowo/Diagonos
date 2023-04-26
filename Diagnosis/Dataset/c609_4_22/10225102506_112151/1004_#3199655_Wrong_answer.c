#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B;
    char s[32];
    scanf("%d%s%d",&A,s,&B);
    int t,i,temp=0,x;
    char a[]="0123456789ABCDEF";
    char b[50];
    for(i=0;s[i];i++){
        t=0;
        if(s[i]>='0' && s[i]<='9')
            t=s[i]-'0';
        if(s[i]>='a' && s[i]<='f')
            t=s[i]-'a'+10;
        if(s[i]>='A' && s[i]<='F')
            t=s[i]-'A'+10;
        temp=temp*A+t;
    }
    int j=0;
    while(temp){
        x=temp%B;
        temp/=B;
        b[j++]=a[x];
    }
    if(s[0]=='0'&&s[1]!='0')
        printf("0");
    else{
        for(int k=j-1;k>=0;k--)
            printf("%c",b[k]);
    }
    return 0;
}
