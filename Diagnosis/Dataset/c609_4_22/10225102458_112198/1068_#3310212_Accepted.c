#include <stdio.h>
#include <stdlib.h>
int time(int n,int p,int m,int t)
{
    if(m==0&&t==p)return 1;
    else if(m==0&&t!=p)return 0;
    if(p==n)return time(n,p-1,m-1,t);
    else if(p==1)return time(n,p+1,m-1,t);
    else return time(n,p+1,m-1,t)+time(n,p-1,m-1,t);
}
int main()
{
    int a;
    scanf("%d",&a);
    int n,p,m,t;
    for(int i=0;i<a;i++){
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",time(n,p,m,t));
    }
    return 0;

}
