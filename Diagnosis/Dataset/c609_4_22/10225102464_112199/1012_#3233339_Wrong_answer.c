#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    int y=0;
    char s[55];
    char a[n][55];
    for(;y<n;y++){
        scanf("%s",s);
        memset(a[y],'0',sizeof(a[y]));
        int index=0;
        int i=strlen(s)-1;
        for(;i!=1;--i){
            int num=s[i]-48;
            int j=0;
            for(;(j<index)||num;j++){
                int temp=num*10+(j<index?a[y][j]-48:0);
                a[y][j]=temp/8+48;
                num=temp%8;
            }
            index=j;
        }
        a[y][index]='\0';
    }
    for(int x=0;x<n;x++)
    {
        printf("case #x:\n0.%s\n",a[x]);
    }
    return 0;
}