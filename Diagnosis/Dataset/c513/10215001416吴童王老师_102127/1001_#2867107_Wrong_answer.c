#include<stdio.h>
int main()
{
    char hex[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int T;
    int a[100];
    int b[100];
    char c[1000];
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d\n",&a[i],&b[i]);
    }
    int flag,j,k,l,n;
    for(int j=0;j<T;j++);
    {
        flag=0;
        if(a[j]<0)
        {
            flag=1;
            a[j]=-a[j];
        }
        l=0;
        while(a[j])
        {
          k=a[j]%b[j];
          c[l]=hex[k];
          a[j]/=b[j];
          l++;
        }
        if(flag){
            printf("-");
        }
        for(n=l-1;n>=0;n--)
        {
            printf("%c",c[n]);
        }
        printf("\n");
    }
    return 0;
}