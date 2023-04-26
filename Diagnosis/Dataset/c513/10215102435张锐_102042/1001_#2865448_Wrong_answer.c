#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,s[100];
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int j;
        for(j=0;a>0;j++)
        {
            if(a%b<10)s[j]=a%b;
            else s[j]='A'+(a%b-10);
            a=a/b;
        }
        int temp;
        for(int k=0;k<=j/2;k++)
        {
            temp=s[k];
            s[k]=s[j-k];
            s[j-k]=temp;
        }
        printf("%d",s);
    }

    return 0;
}
