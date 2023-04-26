#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c;
    int a[26]={0};
    int num=-1,i=0;
    while((c=getchar())!='\n'&&c!=EOF)
    {
        if(c==',') {a[++num]=i;i=0;}
        else{i=c-'0'+i*10;}
    }
    a[++num]=i;
    for(int z=0;z<=num;z++)
        printf("%d,",a[z]);
    //数组从零开始，直到num
    
    return 0;
}