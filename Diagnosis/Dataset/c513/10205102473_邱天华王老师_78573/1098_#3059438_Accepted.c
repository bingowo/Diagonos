#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct caideng
{
    char color;
    int n;
    int num;
    int flag;
}cd;
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[101];
        scanf("%s",s);
        cd a[4];
        a[0].color='R';
        a[1].color='B';
        a[2].color='Y';
        a[3].color='G';
        for(int k=0;k<4;k++)
        {   
            a[k].flag=0;
            a[k].num=0;
            a[k].n=-1;
        }
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            if(s[j]!='!')
            {
                if(s[j]=='R'){a[0].n=j%4;a[0].flag=1;}
                if(s[j]=='B'){a[1].n=j%4;a[1].flag=1;}
                if(s[j]=='Y'){a[2].n=j%4;a[2].flag=1;}
                if(s[j]=='G'){a[3].n=j%4;a[3].flag=1;}
                
            }
        }
        for(int g=0;g<4;g++)
        {
            if(a[g].n==-1)a[g].num=1;
        }
        for(int j=0;j<len;j++)
        {
            if(s[j]=='!')
            {
                for(int m=0;m<4;m++)
                {
                    if(j%4==a[m].n)a[m].num++;
                }
            }
        }
        printf("case #%d: \n",i);
        for(int k=0;k<4;k++)
        {
            printf("%d ",a[k].num);
        }
        printf("\n");
    }
    return 0;
}