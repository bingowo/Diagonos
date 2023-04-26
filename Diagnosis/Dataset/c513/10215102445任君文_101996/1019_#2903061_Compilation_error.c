#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
int main()
{
    int n,m,i,j,a,b,c,num[M]={0},temp=0,win[M]={0},lose[M]={0},sort[M]={0};
    do
    {
        
        scanf("%d%d",&n,&m);
        for(i=0;i<10;i++)
        {
            sort[i]=i+1;
            num[i]=0;
            lose[i]=0;
            win[i]=0;
            sort[i]=0;
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
            for(j=0;j<n-1;j++)
            {
                for(i=j+1;i<n;i++)
                {
                    if(num[j]>num[i])
                    {
                        temp=num[j];num[j]=num[i];num[i]=temp;
                        temp=sort[j];srot[j]=sort[i];sort[i]=sort[j];
                        temp=win[i];win[i]=win[j];win[j]=temp;
                        temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                    }
                    else if(num[i]==num[j])
                    {
                        if(win[i]>win[j])
                        {
                            temp=num[j];num[j]=num[i];num[i]=temp;
                            temp=sort[j];srot[j]=sort[i];sort[i]=sort[j];
                            temp=win[i];win[i]=win[j];win[j]=temp;
                            temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                        }
                        else if(win[i]==win[j])
                        {
                            if(lose[i]<lose[j])
                            {
                                temp=num[j];num[j]=num[i];num[i]=temp;
                                temp=sort[j];srot[j]=sort[i];sort[i]=sort[j];
                                temp=win[i];win[i]=win[j];win[j]=temp;
                                temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                            }
                            else if(lose[i]==lose[j])
                            {
                                if(sort(i)<sort(j))
                                {
                                    temp=num[j];num[j]=num[i];num[i]=temp;
                                    temp=sort[j];srot[j]=sort[i];sort[i]=sort[j];
                                    temp=win[i];win[i]=win[j];win[j]=temp;
                                    temp=lose[i];lose[i]=lose[j];lose[j]=temp;
                                }
                            }
                        }
                    }
                }
            }
    
    for(i=0;i<n-1;i++)
    {
        printf("%d ",sort[i]);
    }
    printf("%d\n",sort[n-1]);
    }
    while((m!=0)&&(n!=0));

    return 0;
}
