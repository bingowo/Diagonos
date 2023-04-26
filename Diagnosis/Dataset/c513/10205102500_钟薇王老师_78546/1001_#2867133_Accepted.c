#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);//测试组数
    int i=0;
    while(i<T)
    {
        int j=0;
        int N,R;
        int trans[1000]= {0};
        scanf("%d%d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=abs(N);
        }
        if(R<=10)
        {
            while(N!=0)
            {
                trans[j]=N%R;
                N=N/R;
                j++;
            }
            for(j-=1; j>=0; j--)
                printf("%d",trans[j]);
            printf("\n");
        }
        else
        {
            char trans_[1000]= {'0'};
            while(N!=0)
            {
                char tmp=N%R;
                if(tmp>9)
                    trans_[j]=tmp+55;
                else
                    trans_[j]=tmp+48;
                N=N/R;
                j++;
            }
            for(j-=1; j>=0; j--)
                printf("%c",trans_[j]);
            printf("\n");
        }
        i++;
    }
    return 0;
}
