#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int length;
        scanf("%d%c",&length);
        char s[2000];
        gets(s);
        int l=strlen(s);
        int n=l/length;
        for(int j=0;j<n;j++)
        {
            for(int k=length*j;k<length*j+length;k++)
            {
                printf("%c",s[k]);
            }
            printf("\n");
        }
        for(int j=n*length;j<l;j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}