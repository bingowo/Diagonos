#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void reverse(char*a,char*b,int k)
{int i;
    for(i=0;i<8-k;i++)
{
    b[i]=a[k+1];
}
for(i=0;i<k;i++)
{
    b[8-k+i]=a[i];
}
}
int cmp(const void*a,const void*b)
{
    char*p1=(char*)a;
    char*p2=(char*)b;
    return strcmp(p1,p2);
}
int two(char*a)
{
int    sum=0;
    for(int i=0;i<8;i++)
    {
        sum=sum*2+a[i]-'0';
    }
    return sum;
}
int main()
{
    int w,m,i,j;
    char b[8][9]={0};
    scanf("%d%d",&w,&m);
    int a[100][100];
    for(i=0;i<w;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     for(i=1;i<w-1;i++)
     {
         for(j=1;j<m-1;j++)
         {
             if(a[i][j]<a[i-1][j-1]) b[0][0]='0';
             else b[0][0]='1';
             if(a[i][j]<a[i-1][j]) b[0][1]='0';
             else b[0][1]='1';
             if(a[i][j]<a[i-1][j+1]) b[0][2]='0';
             else b[0][2]='1';
             if(a[i][j]<a[i][j+1]) b[0][3]='0';
             else b[0][3]='1';
             if(a[i][j]<a[i+1][j+1]) b[0][4]='0';
             else b[0][4]='1';
             if(a[i][j]<a[i+1][j]) b[0][5]='0';
             else b[0][5]='1';
             if(a[i][j]<a[i+1][j-1]) b[0][6]='0';
             else b[0][6]='1';
             if(a[i][j]<a[i][j-1]) b[0][7]='0';
             else b[0][7]='1';
             for(int k=1;k<8;k++)
             {
                 reverse(b[0],b[k],k);
             }
             qsort(b,8,sizeof(b[0]),cmp);

             printf("%d ",two(b[0]));
         }
         printf("\n");
     }

}
