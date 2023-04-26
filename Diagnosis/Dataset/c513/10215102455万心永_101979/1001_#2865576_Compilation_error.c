#include<stdio.h>
#include<string.h>

int main()
{
    int n,N,R;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&N,&R);
        int r=0,j=0;
        char a[10];
        do
        {
            r=N%R;
            N=N/R;
            if (r<10)
                a[j]=r+'0';
            else 
                a[j]=r-10+'A';
            j++;
        }   while(N!=0);
        printf("%s\n",strrev(a));
    }   
    return 0;
}