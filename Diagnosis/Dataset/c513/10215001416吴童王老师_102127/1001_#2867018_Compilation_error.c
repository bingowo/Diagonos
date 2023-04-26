#include<stdio.h>
int main()
{
    char hex[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int T;
    int a[100];
    int b[100];
    char ch[1000];
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%d\n",&a[i],&b[i]);
    }
    int flag,j,k,l;
    for(int j=0;j<T;j++);
    {
        flag=0;
        if(a[i]<0)
        {
            flag=1;
            a[i]=-a[i];
        }
        l=0;
        while(a[i])
        {
          k=a[i]%b[i];
          c[l]=hex[k];
          a[i]/=b[i];
          l++;
        }
        if(flag){
            printf("-");
        }
        for(j=l-1;j>0;j--)
        {
            printf("%c",c(j));
        }
        printf("\n");
    }
    return 0;
}