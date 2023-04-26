#include<stdio.h>
#include<math.h>
#define N 80
int main()
{
    int n;char s[N];
    scanf("%d\n",&n);
    int i,j;double num=0;
    for(i=0;i<n;i++)
    {
        scanf("%s\n",s);
        for(j=0;s[j]!='\0';j++)
        num=num+(s[j]-'0')*pow(8,-j-1);
        printf("case #%d:\n",i);
        printf("%f\n",num);
    }
    return 0;
}