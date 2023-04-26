#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 100
int main()
{
    int n[N]={0},m,i,j,arr=0,a,b,c,num[N][M]={0},temp=0,win[N][M]={0},lose[N][M]={0},sort[N][M]={0};
    do
    {
        
        scanf("%d%d",&n[arr],&m);
        if((n[arr]==0)&&(m==0))
        {
            break;
        }
        for(i=0;i<10;i++)
        {
            sort[arr][i]=i+1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
                num[arr][a]=num[arr][a]+3;
                win[arr][a]=win[arr][a]+1;
                num[arr][b]=num[arr][b]-1;
                lose[arr][b]=lose[arr][b]+1;
            }
            else if(c==-1)
            {
                num[arr][b]=num[arr][b]+3;
                win[arr][b]=win[arr][b]+1;
                num[arr][a]=num[arr][a]-1; 
                lose[arr][a]=lose[arr][a]+1;
            }
            else
            {
                num[arr][b]=num[arr][b]+1;
                num[arr][a]=num[arr][a]+1;
            }
        }
        for(j=0;j<n[arr]-1;j++)
        {
            for(i=j+1;i<n[arr];i++)
            {
                if(num[j]>num[i])
                {
                    temp=num[arr][j];num[arr][j]=num[arr][i];num[arr][i]=temp;
                    temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                    temp=win[arr][i];win[arr][i]=win[arr][j];win[arr][j]=temp;
                    temp=lose[arr][i];lose[arr][i]=lose[arr][j];lose[arr][j]=temp;
                }
                else if(num[i]==num[j])
                {
                    if(win[i]>win[j])
                    {
                        temp=num[arr][j];num[arr][j]=num[arr][i];num[arr][i]=temp;
                        temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                        temp=win[arr][i];win[arr][i]=win[arr][j];win[arr][j]=temp;
                        temp=lose[arr][i];lose[arr][i]=lose[arr][j];lose[arr][j]=temp;
                    }
                    else if(win[i]==win[j])
                    {
                        if(lose[i]<lose[j])
                        {
                            temp=num[arr][j];num[arr][j]=num[arr][i];num[arr][i]=temp;
                            temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                            temp=win[arr][i];win[arr][i]=win[arr][j];win[arr][j]=temp;
                            temp=lose[arr][i];lose[arr][i]=lose[arr][j];lose[arr][j]=temp;
                        }
                        else if(lose[i]==lose[j])
                        {
                            if(sort[i]<sort[j])
                            {
                                temp=num[arr][j];num[arr][j]=num[arr][i];num[arr][i]=temp;
                                temp=sort[arr][j];sort[arr][j]=sort[arr][i];sort[arr][i]=temp;
                                temp=win[arr][i];win[arr][i]=win[arr][j];win[arr][j]=temp;
                                temp=lose[arr][i];lose[arr][i]=lose[arr][j];lose[arr][j]=temp;
                            }
                        }
                    }
                }
            }
        }
        arr++;
    }
    while((m!=0)&&(n[arr]!=0));
    printf("%d\n",arr);
    for(i=0;i<arr;i++)
    {
        for(j=0;j<n[i]-1;j++)
        {
            printf("%d ",sort[i][j]);
        }
        printf("%d\n",sort[i][n[i]-1]);
    }
    return 0;
}
