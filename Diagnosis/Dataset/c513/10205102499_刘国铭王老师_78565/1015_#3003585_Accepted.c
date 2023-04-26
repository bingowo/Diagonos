#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int a[26]={0},b[26]={0},c[26]={0}, x[26]={0};
char s[100];
void add(int *a,int *b,int *c)
{
    int temp2=0;
    for(int i=25;i>=0;i--)
    {
        int d=a[i]+b[i]+temp2;
       c[i]=d%prime[i];
        temp2=d/prime[i];
        //printf("%d %d %d \n",d,c[i],temp);
    }
}

void output()
{
    int flag=25;
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


void Readnumber(char *s,int *a)
{
    int num=strlen(s);
    int j=0;
    int i;
    for(i=0;i<num;i++)
    {
        if(s[i]!=',')
            a[j]=a[j]*10+s[i]-'0';
        else
            j++;
    }

    int op1=25-j;
    for(i=0;i<26;i++)
    {
        x[op1++]=a[i];
    }
    for(i=0;i<26;i++)
        a[i]=x[i];
   /* for(int m=0;m<26;m++)
    {
        printf("%d ",a[m]);
    }
    printf("\n");*/
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        memset(s,'0',sizeof(s));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s",s);
        Readnumber(s,a);
        memset(x,0,sizeof(x));
        scanf("%s",s);
        Readnumber(s,b);
        memset(x,0,sizeof(x));
        add(a,b,c);
        printf("case #%d:\n",i);
        output();
    }
    return 0;
}
