#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int bin[33];
        int N;
        int j=0;
        scanf("%d",&N);
        if (N==0)    printf("1\n");
        else
        {
            while(N!=0)
            {
                bin[j]=N%2;
                N=N/2;
                j++;
            }
            j--;
            int temp=1;
            int max_bin=1;
            for(j;j>=0;j--)
            {
                if(bin[j]!=bin[j-1])    temp++;
                else 
                {
                    if(max_bin<temp)    max_bin=temp;
                    temp=1;
                }
            }
            if(max_bin<temp)    max_bin=temp;
            printf("%d\n",max_bin);
        }
    }
    return 0;
}