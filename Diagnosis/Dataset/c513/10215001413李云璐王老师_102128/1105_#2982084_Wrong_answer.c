#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


int bj(int a[][100],int m,int b,int c,int d)
{
    if(a[m][b]>=a[c][d]) return 1;
    else return 0;
}

int cmp(const void*a1,const void*a2)
{
    int a=*(int*)a1;
    int b=*(int*)a2;
    return a-b;

}

int cl(int a[][100],int i,int j)
{
    int s[10][10];
    s[0][0]=bj(a,i-1,j-1,i,j);
    s[0][1]=bj(a,i-1,j,i,j);
    s[0][2]=bj(a,i-1,j+1,i,j);
    s[0][3]=bj(a,i,j+1,i,j);
    s[0][4]=bj(a,i+1,j+1,i,j);
    s[0][5]=bj(a,i+1,j,i,j);
    s[0][6]=bj(a,i+1,j-1,i,j);
    s[0][7]=bj(a,i,j-1,i,j);
    for(int k=0;k<8;k++)
        printf("%d ",s[0][k]);
    for(int l=0;l<8;l++)
    for(int k=1;k<8;k++)
    {
        int z=l-k;
        if(z<0) z+=8;
        s[k][z]=s[0][l];
    }
    int ans[8]={0};
    for(int k=0;k<8;k++)
       for(int l=0;l<8;l++)
        ans[k]=ans[k]*2+s[k][l];
    qsort(ans,8,sizeof(int),cmp);
    return ans[0];


}

int main()
{
    int w,h;
    scanf("%d %d",&w,&h);
    int a[110][110];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        scanf("%d",&a[i][j]);
        
    int b[110][110];
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++)
        {
            b[i][j]=cl(a,i,j);
        }
    for(int i=1;i<h-1;i++)
    {for(int j=1;j<w-1;j++)
        printf("%d ",b[i][j]);
        printf("\n");}


    return 0;
}
