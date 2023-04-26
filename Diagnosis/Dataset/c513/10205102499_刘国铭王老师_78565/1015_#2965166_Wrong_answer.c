#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int prime[26]={101,97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,19,17,13,11,7,5,3,2};
int a[26]={0},b[26]={0},c[26]={0};
void Readnumber(char *s,int *a)
{
        int j=25;
        for(int i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]!=',')
            {
                a[j]=s[i]-'0';
                j--;
            }
        }
}

void add(int *a,int *b,int *c)
{
    int temp=0;
    for(int i=25;i>=0;i--)
    {
        int d=a[i]+b[i]+temp;
       c[i]=d%prime[i];
        temp=d/prime[i];
        //printf("%d %d %d \n",d,c[i],temp);
    }
}

void output()
{
    int flag=0;
    for(int i=0;i<26;i++)
        if(c[i]!=0)
        {
            flag=i;
            break;
        }
    for(int j=flag;j<25;j++)
    {
        printf("%d,",c[j]);
    }
    printf("%d",c[25]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s1[100],s2[100];
        scanf("%s",&s1);
        Readnumber(s1,a);
        scanf("%s",&s2);
        Readnumber(s2,b);
        add(a,b,c);
        printf("case #%d:\n",i);
        output();
    }
    return 0;
}
