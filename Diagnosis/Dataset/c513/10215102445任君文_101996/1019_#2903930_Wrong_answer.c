#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 500
int main()
{
    int temp,t[N]={0},n,m,i,j,arr=0,a,b,c,num[M]={0},win[M]={0},lose[M]={0},sort[N][M]={0};
    do
    {
        
        scanf("%d%d",&n,&m);
        if((n==0)&&(m==0))
        {
            break;
        }
        t[arr]=n;
        for(i=0;i<M;i++)
        {
            num[i]=0;
            win[i]=0;
            lose[i]=0;
            sort[arr][i]=i+1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                num[a]=num[a]+3;
                win[a]=win[a]+1;
                num[b]=num[b]-1;
                lose[b]=lose[b]+1;
            }
            else if(c==-1)
            {
                num[b]=num[b]+3;
                win[b]=win[b]+1;
                num[a]=num[a]-1; 
                lose[a]=lose[a]+1;
            }
            else
            {
                num[b]=num[b]+1;
                num[a]=num[a]+1;
            }
        }
        for(j=0;j<n;j++)
        {
            for(i=j+1;i<n;i++)
            {
                if(num[i-1]<num[i])
                {
                    temp=num[i-1];num[i-1]=num[i];num[i]=temp;
                    temp=sort[arr][i-1];sort[arr][i-1]=sort[arr][i];sort[arr][i]=temp;
                    temp=win[i-1];win[i-1]=win[i];win[i]=temp;
                    temp=lose[i-1];lose[i-1]=lose[i];lose[i]=temp;
                }
                else if(num[i-1]==num[i])
                {
                    if(win[i-1]<win[i])
                    {
                        temp=num[i-1];num[i-1]=num[i];num[i]=temp;
                        temp=sort[arr][i-1];sort[arr][i-1]=sort[arr][i];sort[arr][i]=temp;
                        temp=win[i-1];win[i-1]=win[i];win[i]=temp;
                        temp=lose[i-1];lose[i-1]=lose[i];lose[i]=temp;
                    }
                    else if(win[i-1]==win[i])
                    {
                        if(lose[i-1]>lose[i])
                        {
                            temp=num[i-1];num[i-1]=num[i];num[i]=temp;
                            temp=sort[arr][i-1];sort[arr][i-1]=sort[arr][i];sort[arr][i]=temp;
                            temp=win[i-1];win[i-1]=win[i];win[i]=temp;
                            temp=lose[i-1];lose[i-1]=lose[i];lose[i]=temp;
                        }
                        else if(lose[i-1]==lose[i])
                        {
                            if(sort[i-1]>sort[i])
                            {
                                temp=num[i-1];num[i-1]=num[i];num[i]=temp;
                                temp=sort[arr][i-1];sort[arr][i-1]=sort[arr][i];sort[arr][i]=temp;
                                temp=win[i-1];win[i-1]=win[i];win[i]=temp;
                                temp=lose[i-1];lose[i-1]=lose[i];lose[i]=temp;
                            }
                        }
                        
                    }
                }
            }
        }
        arr++;
    }
    while((m!=0)||(n!=0));
    printf("%d\n",arr);
    for(i=0;i<arr;i++)
    {
        temp=t[i]-1;
        for(j=0;j<temp;j++)
        {
            printf("%d ",sort[i][j]);
        }
        printf("%d\n",sort[i][temp]);
    }
    return 0;
}
