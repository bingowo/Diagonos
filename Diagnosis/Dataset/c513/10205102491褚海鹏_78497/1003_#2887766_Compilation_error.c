#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
char ans[11],start[10];
bool isUsed[11];
int changeId[9][4]={{-1,-1,3,1},{-1,0,4,2},{-1,1,5,-1},{0,-1,6,4},{1,3,7,5},{2,4,8,-1},{3,-1,-1,7},{4,6,-1,8},{5,7,-1,-1}};
const int M=400000;
int n[M],len=0,des=123456780;
bool isV[M];
int que[M][3];
void swap(char *c,int a,int b)
{
    char t=c[a];
    c[a]=c[b];
    c[b]=t;
}
void paiLie(int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(!isUsed[i])
        {
            ans[k]=i+'0';
            isUsed[i]=1;
            if(k==n)
            {
                ans[k+1]='\0';
                sscanf(ans+1,"%d",&num[len++]);
            }
            else{paiLie(n,k+1);}
            isUsed[i]=0;
        }
    }
}
int halfFind(int l,int r,int n)
{
    int mid=1+(r-1)/2;
    if(num[mid]==n)return mid;
    else if(l<r&&num[mid]>n)return halfFind(l,mid-1,n);
    else if(l<r&&num[mid]<n)return halfFind(mid+1,r,n);
    return -1;
}
int bfs(int n,int p)
{
    int head=0,tail=1,temp;
    que[head][0]=n,que[head][1]=p,que[head][2]=head;
    while(head!=tail)
    {
        char cur[10];
        int pos=que[head][1];
        sprintf(cur,"%09d",que[head][0]);
        for(int i=0;i<4;i++)
        {
            int swapTo=changeId[pos][i];
            if(swapTo!=-1){
                swap(cur,pos,swapTo);
                sscanf(cur,"%d",&temp);
                if(temp==des)
                    return que[head][2]+1;
                int k=halfFind(0,len,temp);
                if(!isV[k])
                {
                    que[tail][0]=temp,que[tail][1]=swapTo,que[tail][2]=que[head][2]+1;
                    tail++;
                    isV[k]=1;
                }
                swap(cur,pos,swapTo);
            }
        }
        head++;
    }
}
int main()
{
    int n,i=-1,count=0;
    paiLie(9,1);
    scanf("%s",start);
    while(start[++i]!='0');
    sscanf(start,"%d",&n);
    if(n!=des)
        count=btf(n,i);
    printf("%d\n",count);
    return 0;
}