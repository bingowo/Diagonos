#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N,R;
        int s[100];
        int q= 0;
        int a=1;
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            N=-N;
            a=-1;
        }
        while(N/R>0)
        {
            s[q]=N%R;
            q=q+1;
            N=N/R;
        }
        s[q]=N;
        if(a<0) printf("-");
        while(q>=0)
        {
            if(s[q]>=10) printf("%c",s[q]+55);
            else printf("%d",s[q]);
            q=q-1;
        }
        printf("\n");
    }
    return 0;
}
