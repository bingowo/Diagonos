#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    if(m==0)
        return 0;
    else
    {
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
        int max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
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
            score[i]=-100;
            max=0;
        }
        for(int i=0;i<n-1;i++)
            printf("%d ",result[i]+1);
        printf("%d\n",result[n-1]+1);
        return 0;
    }
}
