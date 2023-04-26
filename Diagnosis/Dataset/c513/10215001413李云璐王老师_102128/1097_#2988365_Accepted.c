#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[81];
    while(scanf("%s",s)!=EOF)
    {int len=strlen(s);
    char a[200][200];
    for(int k=0;k<162;k++)
    {for(int j=0;j<81;j++)
        a[k][j]=' ';
        a[k][81]='\0';}
    a[79][0]=s[0];
    int hang=79,max=79,min=79;
    for(int i=1;i<len;i++)
    {
        if(s[i]>s[i-1]) hang--;
        else if(s[i]<s[i-1]) hang++;
        a[hang][i]=s[i];
        if(max<hang) max=hang;
        if(min>hang) min=hang;
    }
    for(int i=min;i<=max;i++)
        printf("%s\n",a[i]);}
        
    return 0;
}