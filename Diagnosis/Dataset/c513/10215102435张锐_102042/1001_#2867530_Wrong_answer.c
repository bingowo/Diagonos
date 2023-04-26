#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char s[100]={0};
    scanf("%d",&num);
    int a,b;
    for(int i=0;i<num;i++)
    {
        scanf("%d%d",&a,&b);
        int j;
        for(j=0;a>0;j++)
        {
            s[j]=(a%b>9)?(a%b-10)+'A':a%b+'0';
            a=a/b;
        }
        s[j]='\0';
        char temp;
        for(int k=0;k<j/2;k++)
        {
            temp=s[k];
            s[k]=s[j-k-1];
            s[j-k-1]=temp;
        }
        printf("%s",s);
    }

    return 0;
}
