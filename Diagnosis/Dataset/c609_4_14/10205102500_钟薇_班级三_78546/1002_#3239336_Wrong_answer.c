#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d\n",i);
        int bin[32];
        int N;
        int j=0;
        scanf("%d",&N);
        while(N!=0)
        {
            bin[j]=N%2;
            N=N/2;
            j++;
        }
        j--;
        int temp=1;
        int max_bin=0;
        for(j;j>=0;j--)
        {
            if(bin[j]!=bin[j-1])    temp++;
            else 
            {
                if(max_bin<temp)    max_bin=temp;
                temp=1;
            }
        }
        printf("%d\n",max_bin);
    }
    return 0;
}