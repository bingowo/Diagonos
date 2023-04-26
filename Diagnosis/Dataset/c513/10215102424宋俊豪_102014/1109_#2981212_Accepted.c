#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void sol(int a[])
{
    int f=0;
    for(int i=8; i>=0; i--)
    {
        if(a[i]==0)
            continue;
        else
        {
            f++;
            if(i==8)
            {
                if(a[i]==1)
                {
                    printf("x^8");
                }
                else if(a[i]==-1)
                {
                    printf("-x^8");
                }
                else
                {
                    printf("%dx^8",a[i]);
                }
            }
            else if(i>1)
            {
                if(a[i]==1)
                {
                    if(f==1)
                        printf("x^%d",i);
                    else
                        printf("+x^%d",i);
                }
                else if(a[i]==-1)
                {
                    printf("-x^%d",i);
                }
                else if(a[i]>0)
                {
                    if(f==1)
                        printf("%dx^%d",a[i],i);
                    else
                        printf("+%dx^%d",a[i],i);
                }
                else
                {
                    printf("%dx^%d",a[i],i);
                }
            }
            else if(i==1)
            {
                if(a[i]==1)
                {
                    if(f==1)
                        printf("x");
                    else
                        printf("+x");
                }
                else if(a[i]==-1)
                {
                    printf("-x");
                }
                else if(a[i]>0)
                {
                    if(f==1)
                        printf("%dx",a[i]);
                    else
                        printf("+%dx",a[i]);
                }
                else
                {
                    printf("%dx",a[i]);
                }
            }
            else if(i==0)
            {
                if(a[i]==1)
                {
                    if(f==1)
                        printf("1");
                    else
                        printf("+1");
                }
                else if(a[i]==-1)
                {
                    printf("-1");
                }
                else if(a[i]>0)
                {
                    if(f==1)
                        printf("%d",a[i]);
                    else
                        printf("+%d",a[i]);
                }
                else
                {
                    printf("%d",a[i]);
                }
            }
        }
    }
    printf("\n");
    return;
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int f=0,a[10]= {0};
        printf("case #%d:\n",i);
        for(int j=0; j<9; j++)
        {
            scanf("%d",&a[8-j]);
            if(a[8-j]!=0)
                f++;
        }
        if(f==0)
            printf("0\n");
        else
            sol(a);
    }
}

