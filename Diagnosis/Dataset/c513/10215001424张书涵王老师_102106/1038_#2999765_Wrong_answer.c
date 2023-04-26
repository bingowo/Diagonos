#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[200][200];
    int i,j,p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            a[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    int number=0,lenth,hang,lie;
    long long int total;
    i=0;j=0;
    for(i=1;i<n;i++)    //右上三角形
    {
        for(j=0;j<(m-1);j++)
        {
            for(lenth=1;(i-lenth)>=0&&(j+lenth)<m;lenth++)
            {
                total=0;
                for(hang=(i-lenth),p=0;hang<=i,p<=lenth;hang++)
                {
                    for(lie=j;lie<=(j+p);lie++)
                        total=total+a[hang][lie];
                    p++;
                    if(total>=k)
                        number=number+1;
                }
            }
        }
    }
    for(i=1;i<n;i++)   //左上三角形
    {
        for(j=1;j<m;j++)
        {
            for(lenth=1;(i-lenth)>=0&&(j-lenth)>=0;lenth++)
            {
                total=0;
                for(hang=(i-lenth),p=0;hang<=i;hang++)
                {
                    for(lie=j;lie>=(j-p);lie--)
                        total=total+a[hang][lie];
                    p++;
                    if(total>=k)
                        number=number+1;
                }
            }
        }
    }
    for(i=0;i<(n-1);i++)  //右下三角形
    {
        for(j=0;j<(m-1);j++)
        {
            for(lenth=1;(i+lenth)<n&&(j+lenth)<m;lenth++)
            {
                total=0;
                for(hang=i,p=0;hang<=(i+lenth);hang++)
                {
                    for(lie=j;lie<=(j+lenth-p);lie++)
                        total=total+a[hang][lie];
                    p++;
                    if(total>=k)
                        number=number+1;
                }
            }
        }
    }
    for(i=0;i<(n-1);i++)
    {
        for(j=1;j<m;j++)
        {
            for(lenth=1;(i+lenth)<n&&(j-lenth)>=0;lenth++)
            {
                total=0;
                for(hang=i,p=0;hang<=(i+lenth);hang++)
                {
                    for(lie=j;lie>=(j-lenth+p);lie--)
                        total=total+a[hang][lie];
                    p++;
                    if(total>=k)
                        number=number+1;
                }
            }
        }
    }
    printf("%d",number);
}