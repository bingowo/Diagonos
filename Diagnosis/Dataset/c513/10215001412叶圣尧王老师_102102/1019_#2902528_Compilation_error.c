#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void swop(int a,int b,int c,int d)
{
    int t;
    t=a;a=b;b=t;
    t=c;c=d;d=t;
}

int main()
{
    int n,m,i,j;int line[3];
    scanf("%d %d",&n,&m);
    while(n!=0&&m!=0)
    {
        int score[n]={0},vic[n]={0},los[n]={0},k[n];
        for(i=0;i<n;i++)k[i]=i+1;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",line[0],line[1],line[2]);
            if(line[2]==1){score[line[0]]+=3;score[line[1]]-=1;vic[line[0]]++;los[line[1]]++;}
            else if(line[2]==-1){score[line[1]]+=3;score[line[0]]-=1;vic[line[1]]++;los[line[0]]++;}
            else {score[line[1]]+=1;score[line[0]]+=1;}
        }
        int t;
        for(i=0;i<n;i++)
            for(j=n-1;j>i;j--)
            {
                if(score[j]>score[j-1])swop(score[j],score[j-1],k[j],k[j-1]);
                else if(score[j]==score[j-1]&&vic[j]>vic[j-1])swop(score[j],score[j-1],k[j],k[j-1]);
                else if(score[j]==score[j-1]&&vic[j]==vic[j-1]&&los[j]<los[j-1])swop(score[j],score[j-1],k[j],k[j-1]);
                else if(score[j]==score[j-1]&&vic[j]==vic[j-1]&&los[j]==los[j-1]&&k[j]<k[j-1])swop(score[j],score[j-1],k[j],k[j-1]);
            }
        printf()
        scanf("%d %d",&n,&m);
    }
    
}