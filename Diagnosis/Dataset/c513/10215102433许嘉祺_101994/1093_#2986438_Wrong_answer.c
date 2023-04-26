#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int a[120];
    memset(a,0,sizeof(a));
    for(int i=0;i<strlen(s);i++)
        a[i]=s[strlen(s)-i-1]-'0';
    int carry=1;
    int count=0;
    for (int i=0;i<120;i++){
        a[i]=a[i]+carry;
        carry=a[i]/9;
        a[i]=a[i]%9;
        count+=a[i];
        count=count%9;
    }
    while (count==0){
        carry=1;
        count=0;
        for (int i=0;i<120;i++){
            a[i]=a[i]+carry;
            carry=a[i]/9;
            a[i]=a[i]%9;
            count+=a[i];
            count=count%9;
        }

    }
    int i=119;
    while (a[i]==0) i--;
    for (;i>=0;i--) printf("%d",a[i]);
    return 0;
}