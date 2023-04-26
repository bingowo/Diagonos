#include<stdio.h>
#include<string.h>
void swap(char* x,char* y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
char* rev(char* s,int n)
{
    int i;
    for(i=0;i<n/2;i++)
    {
        swap(s+i,s+n-i-1);
    }
}
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
        scanf("%s",s);
        printf("case #%d:\n",i);
        s=rev(s,strlen(s));
        printf("%s\n",s)
    }
    return 0;
}