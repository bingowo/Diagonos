#include<stdio.h>
#include<string.h>
int main()
{
    int T,sum;
    int count(char s[]);
    scanf("%d\n",&T);
    char c;
    for(int i=0;i<T;i++)
    {
        int j=0;
        char s[100]="";
        while((c=getchar())!='\n')
        {
            s[j]=c;
            j++;
        }
        sum=count(s);
       
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
int count(char s[])
{
    int sum=0;
    int m=strlen(s);
    for(int i=0;i<m;i++)
    {
        if(s[i]=='-')sum=sum*3-1;
        else if(s[i]=='0')sum=sum*3;
        else sum=sum*3+1;
    }
    return sum;
}
