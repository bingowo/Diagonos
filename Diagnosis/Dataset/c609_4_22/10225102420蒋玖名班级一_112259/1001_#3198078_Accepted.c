#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int N[T],R[T],j[T];
    char ans[T][100];
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&N[i],&R[i]);
        int r;
        j[i]=0;
        if(N[i]<0)
        {


            N[i]=abs(N[i]);
            while(N[i]>0)
            {
                r=N[i]%R[i];
                if(r>=10)
                    ans[i][j[i]]=r-10+'A';
                else
                    ans[i][j[i]]=r+'0';
                j[i]=j[i]+1;
                N[i]=N[i]/R[i];
            }
            ans[i][j[i]]='-';
            j[i]=j[i]+1;
        }
        else
        {
            if(N[i]==0)
                ans[i][j[i]]='0';
            while(N[i]>0)
            {
                r=N[i]%R[i];
                if(r>=10)
                    ans[i][j[i]]=r-10+'A';
                else
                    ans[i][j[i]]=r+'0';
                j[i]=j[i]+1;
                N[i]=N[i]/R[i];
            }
        }
    }
    for(int k=0;k<T;k++)
    {
        for(int l=j[k]-1;l>=0;l--)
            printf("%c",ans[k][l]);
        printf("\n");
    }
    return 0;
}
