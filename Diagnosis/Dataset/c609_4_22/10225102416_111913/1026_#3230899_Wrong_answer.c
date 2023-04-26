#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[10000];
    while(scanf("%s",a)!=EOF)
    {
        int i=0,b[10000];
        char x=' ',j=-1;
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]==x)
                b[j]++;
            else {x=a[i];j++;b[j]=1;}
        }
        j=0;
        for(i=0;a[i]!='\0';)
            if(b[j]>=2)
            {
                printf("%d",b[j]);
            printf("%c",a[i]);
                i+=b[j];
                j++;
            }
            else
            {printf("%c",a[i]);i++;j++;}
        printf("\n");
    }
}
 
