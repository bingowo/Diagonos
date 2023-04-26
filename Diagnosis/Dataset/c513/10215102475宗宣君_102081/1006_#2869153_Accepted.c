#include <stdio.h>
int main()
{
    int T,i,n,j,k;
    char a[100][100],b[] = "-01";
    scanf("%d",&T);
    for(i = 0;i<T;i++)
        scanf("%s",a[i]);
    for(i = 0;i<T;i++)
    {
        n = 0;k = 0;
        while(a[i][k]!='\0')
        {for(j = 0;j<3;j++)
            if(a[i][k]==b[j]) n = n*3+j-1;

        k++;}
        printf("case #%d:\n%d\n",i,n);

    }
    return 0;
}
