#include<stdio.h>
#include<string.h>
void swap(char* x,char* y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void rev(char* s,int n)
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
    int i,n1,n2;
    char s1[80],s2[80],s[80];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        n1=0;
        n2=0;
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        printf("case #%d:\n",i);
        rev(s2,strlen(s2));
        n1=strstr(s,s1);
        rev(s,strlen(s2));
        n2=strstr(s,s2);
        n2=strlen(s)-n2;
        printf("%d\n",n2-n1);
    }
    return 0;
}