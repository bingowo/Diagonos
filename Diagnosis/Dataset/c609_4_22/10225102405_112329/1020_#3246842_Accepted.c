#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int number(char *s)
{
    int sum=0,flag=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
     if(s[i]>='0'&&s[i]<='9')
     {
         sum=10*sum+s[i]-48;flag=1;
     }
     if(flag==0) {sum=-1;}
     return sum;
}

int strnumcmp(const void*a,const void*b)
{
    char *A,*B;
    A=(char(*)[31])a;B=(char(*)[31])b;
    int n1,n2;
    n1=number(A);n2=number(B);
    if(n1==n2) return strcmp(A,B);
    else return n1-n2;
}

int main()
{
    char s[110][31];
    int count=0;
    while (scanf("%s",&s[count])!=EOF)
    {
        count++;
    }
    qsort(s,count,sizeof(s[0]),strnumcmp);
    for(int i=0;i<count;i++)
    {
        printf("%s%c",s[i],i==count-1?'\n':' ');
    }
}
