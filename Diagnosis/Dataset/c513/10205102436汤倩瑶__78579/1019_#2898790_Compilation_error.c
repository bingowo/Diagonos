#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int num,win,fail,sum;
}bs;
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=eof&&m!=0&&n!=0)
    {
        bs *p=(bs *)malloc(sizeof(bs)*n);
        for(int i=0;i<n;i++)
       { p[i].sum=0;p[i].win=0;p[i].fail=0;p[i].num=i+1;}
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                p[a-1]+=3;
                p[b-1]-=1;
            }
            else if(c==0){
                p[a-1]+=1;
                p[b-1]+=1;
            }
            else {
                p[a-1]-=1;
                p[b-1]+=3;
            }
        }
        for(int )
        
    }
    
}