#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    char a[200][200];
    for(int k=0;k<162;k++)
    {for(int j=0;j<81;j++)
        a[k][j]=' ';
        a[k][81]='\0';}
    a[80][0]=s[0];
    int hang=80,max=80,min=80;
    for(int i=1;i<len;i++)
    {
        if(strcmp(s[i],s[i-1])>0) hang--;
        else if(strcmp(s[i],s[i-1])<0) hang++;
        a[hang][i]=s[i];
        if(max<hang) max=hang;
        if(min>hang) min=hang;
    }
    printf("%d %d",min,max);
    for(int i=min;i<=max;i++)
        printf("%s\n",a[i]);
    return 0;
}
