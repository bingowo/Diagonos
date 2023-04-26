#include<stdio.h>
#include<stdlib.h>
int a[200][200]={0};

long long int min(long long int a,long long int b)
{
    if(a<b)return a;
    else return b;

}
long long int dis(int i,int j)
{
    if(i==0&&j==0)return 0;
    if(i!=0&&j!=0) {

            return min(dis(i-1,j)+a[i-1][j],dis(i,j-1)+a[i][j-1]);}
    if(i==0&&j!=0) {return dis(i,j-1)+a[i][j-1];}
    if(i!=0&&j==0) {return dis(i-1,j)+a[i-1][j];}
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("%lld\n",dis(m-1,n-1)+a[m-1][n-1]);


}
