#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N,R,r;
    int i=0;
    char ans[40];
    scanf("%d %d",&N,&R);
    getchar();
    do
    {
        r=N%R;
        N=N/R;
        if (r<0)
        {
            ++N;
            r-=R;
        }
        if(r>=10)
            ans[i++]=r-10+'A';
        else
            ans[i++]=r+'0';
    } while (N);
    for(int j=i-1;j>=0;--j)
    {
        printf("%c",ans[j]);
    }
    printf("\n");
    system("pause");
    return 0;
}