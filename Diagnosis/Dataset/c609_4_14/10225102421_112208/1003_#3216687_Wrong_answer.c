#include<stdio.h>
int main()
{
    int a,k,j;
    scanf("%d",&a);
    int s[100];
    for (int i=0;i<a;i++)
    {
        int x[100];
        scanf("%d",&s[i]);
        if (s[i]==0)
            printf ("0");
        else
        {
            while (s[i]!=0)
            {
                x[k]=s[i]%2333;
                s[i]=s[i]/2333;
                k+=1;
            }
            for (j=i;j>0;j--)
                printf("%d ",x[j]);
        }
        printf("\n");
    }
}