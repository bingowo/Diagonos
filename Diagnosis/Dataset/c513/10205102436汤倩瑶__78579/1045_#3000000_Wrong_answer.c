#include<stdio.h>
#include<string.h>
typedef struct {
char c;
int num;
}node;
node p[105][105]={0};

int main()
{
    int n;
    scanf("%d",&n);
    char s[105];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int k=0;
        p[i][k].c=s[0];
        p[i][k].num++;
        for(int j=1;s[j]!=0;j++)
        {
            if(s[j]!=s[j-1]){p[i][++k].c=s[j]; p[i][k].num++;}
            else p[i][k].num++;
        }
    }
int flag=0;
for(int j=0;j<100;j++)
{
    for(int i=1;i<n;i++)
    {
        if(p[i][j].c!=p[0][j].c){flag=1;break;}
    }
}
if(flag==1)printf("-1");




}
