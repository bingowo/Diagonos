#include <stdio.h>
#include <string.h>

void trans(int num,int length) {
    int i;
    int arr[10]={0};
    for(i=0;num/2!=0;i++) {
        arr[i]=num%2;
        num=num/2;
    }
    arr[i]=num;
    for(i=length;i>=0;i--)
        printf("%d",arr[i]);
}

int main()
{
    char s[510];
    int arr[510]={0};
    scanf("%s",s);
    printf("0001");
    int len=strlen(s);
    for(int i=0;i<len;i++)
        arr[i]=s[i]-'0';
    trans(len,9);
    int a=len/3;
    for(int i=1;i<=a;i++) {
        int j=3*i-1;
        int num=0;
        for(;j>=3*i-3;j--)
            num=num*10+arr[j];
        trans(num,9);
    }
    int b=len%3;
    if(b==2) {
        int num;
        num=arr[len-1]+arr[len-2]*10;
        trans(num,6);
    }
    if(b==1) {
        int num;
        num=arr[len-1];
        trans(num,3);
    }
    return 0;
}
