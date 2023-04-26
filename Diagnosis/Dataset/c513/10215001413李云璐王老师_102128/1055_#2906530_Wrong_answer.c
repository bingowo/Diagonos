#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[1000001];
    scanf("%s",a);
    int len=strlen(a),count=1,max=1,wei=0,k;
    for(k=0;k<len;k++)
    {
        for(int l=k;l<len-1;l++)
        {if(a[l+1]!=a[l]) count++;
        else {max=(count>max)?count:max;wei=(count>max)?k:wei;break;}
        }
        count=1;
    }
    for(int f=k;f<k+max;f++)
    printf("%c",a[f]);
    return 0;
}