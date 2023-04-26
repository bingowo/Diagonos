#include<stdio.h>
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[200][200]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    int s=0;
    //左上角
 //printf("左上角：\n");
    for(int p=2;p<=n&&p<=m;p++)
    {
        for(int i=0;i<=n-p;i++)
       {
        for(int j=0;j<=m-p;j++)
            {int sum=0;
                for(int q=0;q<p;q++)
                {
                for(int t=0;t<=q;t++)
                {

                    sum+=a[i+t][j+q-t];
                }

                }
   //             printf("%d\n",sum);
            if(sum>=k)s++;
            }
          }

        }
//右上角
 //printf("右上角：\n");
    for(int p=2;p<=n&&p<=m;p++)
    {
        for(int i=0;i<=n-p;i++)
       {
        for(int j=m-1;j>=p-1;j--)
            {int sum=0;
                for(int q=0;q<p;q++)
                {
                for(int t=0;t<=q;t++)
                {

                    sum+=a[i+t][j-q+t];
                }

                }
  //              printf("%d\n",sum);
            if(sum>=k)s++;
            }
          }

        }
//右下角
// printf("右下角：\n");
 for(int p=2;p<=n&&p<=m;p++)
    {
        for(int i=n-1;i>=p-1;i--)
       {
        for(int j=m-1;j>=p-1;j--)
            {int sum=0;
                for(int q=0;q<p;q++)
                {
                for(int t=0;t<=q;t++)
                {

                    sum+=a[i-t][j-q+t];
                }

                }
   //             printf("%d\n",sum);
            if(sum>=k)s++;
            }
          }

        }
//左下角
 //printf("左下角：\n");
    for(int p=2;p<=n&&p<=m;p++)
    {
        for(int i=n-1;i>=p-1;i--)
       {
         for(int j=0;j<=m-p;j++)
            {int sum=0;
                for(int q=0;q<p;q++)
                {
                for(int t=0;t<=q;t++)
                {

                    sum+=a[i-t][j+q-t];
                }

                }
//printf("%d\n",sum);
            if(sum>=k)s++;
            }
          }

        }
    printf("%d",s);
    }

