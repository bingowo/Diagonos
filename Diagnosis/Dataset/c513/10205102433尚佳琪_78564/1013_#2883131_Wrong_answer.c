#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[50];
    scanf("%s",a);
    int len=strlen(a);
    int i,c=0,c2=0;
    for(i=0;i<len;i++)
    {
        if(a[i]!='.')
        {
            if(a[i]=='2')
                c=c*3-1;
            else
                c=c*3+a[i]-'0';
        }
        else
            break;
    }
    i++;
    int temp=pow(3,len-i);
    for(;i<len;i++)
    {
        if(a[i]=='2')
            c2=c2*3-1;
        else
            c2=c2*3+a[i]-'0';
    }
    if(c>0&&c2<0)
        printf("%d %d %d",--c,temp+c2,temp);
    else if(c<0&&c2>0)
        printf("%d %d %d",++c,temp-c2,temp);
    else if(c2==0)
        printf("%d",c);
    else if(c==0)
        printf("%d %d",c2,temp);
    else
        printf("%d %d %d",c,c2,temp);
    return 0;
}
