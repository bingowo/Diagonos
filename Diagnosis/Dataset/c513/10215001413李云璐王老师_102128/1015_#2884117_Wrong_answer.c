#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int h=0;h<n;h++)
    {
        char s1[100],s2[100];
        int a[26]={0},b[26]={0},c[26]={0};
        char d;
        int a1,b1;
        int num1=-1,i1=0;
    while((d=getchar())!=' ')
    {
        if(d==',') {a[++num1]=i1;i1=0;}
        else{i1=d-'0'+i1*10;}
    }
    a[++num1]=i1;
    for(int r=0;r<=num1;r++)
    printf("%d",a[r]);
    //数组从零开始，直到num1
    a1=num1+1;
    int num2=-1,i2=0;
    while((d=getchar())!='\n'&&d!=EOF)
    {
        if(d==',') {b[++num2]=i2;i2=0;}
        else{i2=d-'0'+i2*10;}
    }
    b[++num1]=i2;
    b1=num2+1;
    for(int r=0;r<=num2;r++)
    printf("%d",b[r]);}
    ////数组从零开始，直到num2
       
    return 0;
}
