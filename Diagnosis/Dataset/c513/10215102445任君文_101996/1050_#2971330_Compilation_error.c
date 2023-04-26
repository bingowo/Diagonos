#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    int i,j,k;
    char s1[80],s2[80],s[80];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s3);
        printf("case #%d:\n",i);
        s3=strrev(s3);
        printf("%s\n",s3)
    }
    return 0;
}