#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 50
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
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            sort[arr][a-1]=a;
            sort[arr][b-1]=b;
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
        for(j=0;j<n-1;j++)
        {
            for(i=j+1;i<n;i++)
            {
                if(num[i]>num[j])
                {
                    temp=num[j];num[j]=num[i];num[i]=temp;
                    temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                    temp=win[i];win[i]=win[j];win[j]=temp;
                    temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                }
                else if(num[i]==num[j])
                {
                    if(win[i]>win[j])
                    {
                        temp=num[j];num[j]=num[i];num[i]=temp;
                        temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                        temp=win[i];win[i]=win[j];win[j]=temp;
                        temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                    }
                    else if(win[i]==win[j])
                    {
                        if(lose[i]<lose[j])
                        {
                            temp=num[j];num[j]=num[i];num[i]=temp;
                            temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                            temp=win[i];win[i]=win[j];win[j]=temp;
                            temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                        }
                        else if(lose[i]==lose[j])
                        {
                            if(sort[i]<sort[j])
                            {
                                temp=num[j];num[j]=num[i];num[i]=temp;
                                temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                                temp=win[i];win[i]=win[j];win[j]=temp;
                                temp=lose[i];lose[i]=lose[j];lose[j]=temp;
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
