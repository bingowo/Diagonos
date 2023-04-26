#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int count=1,i=0,len;
        char c[510];
        scanf("%s\n",c);
        len=strlen(c);
        for(int k=0;k<len;k++)
        {
            if(c[k+1]==c[k]&&count<=255) count++;
            else {printf("case #%d:\n",i);printf("%d%c\n",count,c[k]);count=1;}
        }
        
    }
    return 0;
}