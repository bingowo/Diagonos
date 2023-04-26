#include<stdio.h>
#include<stdlib.h>

typedef struct
{int val; char dir;}Elem;
Elem a[200][200]={0};
void output(int i,int j)
{
    if(i==0&&j==0)
        return;
    if(a[i][j].dir=='D')
    {
        output(i-1,j);
        printf("D");
    }
    else{output(i,j-1); printf("R");}



}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j].val);
        }
    }
    for(int i=1;i<m;i++)
    {
        a[i][0].val+=a[i-1][0].val;
        a[i][0].dir='D';
    }
    for(int j=1;j<n;j++)
    {
        a[0][j].val+=a[0][j-1].val;
        a[0][j].dir='R';
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i-1][j].val<a[i][j-1].val)
            {a[i][j].val+=a[i-1][j].val;a[i][j].dir='D';}
            else {a[i][j].val+=a[i][j-1].val;a[i][j].dir='R';}
        }
    }
    printf("%d\n",a[m-1][n-1].val);
    output(m-1,n-1);

}
