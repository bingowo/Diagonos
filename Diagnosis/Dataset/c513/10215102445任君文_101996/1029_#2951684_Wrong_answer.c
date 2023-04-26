#include<stdio.h>
#include<string.h>
#define M 250
int swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int T;
    int i,j,k,an,a;
    int f[M]={0};
    int n=0,m=0;
    int arr[M]={0};
    char s[M]={0};
    scanf("%d",&T);
    char c;
    c=getchar();
    for(i=0;i<T;i++)
    {
        m=0;
        n=0;
        k=0;
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                n++;
                m++;
            }
            else
            {
                if(('A'<=c)&&(c<='Z'))
                {
                    s[m]=c;
                    arr[k]=c-'A';
                    f[m]=1;
                    m++;
                    k++;
                }
                else
                {
                    s[m]=c;
                    f[m]=2;
                    m++;
                }
            }
            
        }
        n=n+1;
        an=k+1;
        for(j=0;j<an-1;j++)
        {
            for(k=0;k<an-1-j;k++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
        for(j=0;j<an;j++)
        {
            printf("test=%d ",arr[j]);
        }
        printf("\n");
        k=0;
        printf("case #%d:\n",i);
        for(j=0;j<m;j++)
        {
            if(f[j]==0)
            {
                printf(" ");
            }
            else if(f[j]==1)
            {
                printf("%c",arr[k]+65);
                f[j]=0;
                arr[k]=0;
                k++;
            }
            else
            {
                printf("%c",s[j]);
                f[j]=0;
                s[j]=0;
            }
        }
        printf("\n");
    }

    return 0;
}