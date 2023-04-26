#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i,N,R;
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        int k;
        if(N>0) k=N;
        else k=-N;
        char a[100];
        int j=0;
        int m,t;
        while(k>0)
        {
           t=k%R;
           if(t>9)
           {
               a[j]=t-10+'A';
           }
           else a[j]=t+'0';
           k=k/R;
           j++;
        }
        if (N<0)
        {a[j]='-';
        j++;}
        for(m=j-1;m>=0;m--){

                if(m==0)
               printf("%c\n",a[m]);
               else printf("%c",a[m]);

        }

    }

    return 0;
}

