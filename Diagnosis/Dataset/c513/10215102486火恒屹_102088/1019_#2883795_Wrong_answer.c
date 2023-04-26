#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=-1,n=-1;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if((n==0)&&(m==0))
            break;
        int score[11]={0};
        int win[11]={0};
        int lose[11]={0};
        for (int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                score[a]+=3;
                win[a]++;
                lose[b]++;
                score[b]=score[b]-1;
            }
            else if(c==0)
            {
                score[a]++;
                score[b]++;
            }
            else
            {
                score[b]+=3;
                win[b]++;
                lose[a]++;
                score[a]=score[a]-1;
            }
        }
        int result[11]={0};
        int max=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(j==max)
                    continue;
                else
                {
                    if (score[j]>score[max])
                        max=j;
                    else if(score[j]==score[max])
                    {
                        if(win[j]>win[max])
                            max=j;
                        else if(win[j]==win[max])
                        {
                            if(lose[j]<lose[max])
                                max=j;
                        }
                    }

                }
            }
            result[i]=max;
            score[max]=-100;
            max=1;
        }
        for(int i=1;i<n;i++)
            printf("%d ",result[i]);
        printf("%d\n",result[n]);
        printf("fuck\n");
    }
    return 0;
}
