#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>

void haozi(int n,int p,int m,int t)
{
    
    if(m<=0) {if(p==t) data++;return;}
    if(p==1) haozi(n,2,m-1,t);
    else if(p==n)  haozi(n,n-1,m-1,t);
    else { haozi(n,p-1,m-1,t);haozi(n,p+1,m-1,t);}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int n,p,m,t,data=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        haozi(n,p,m,t);
        printf("%d\n",data);
        
    }
    return 0;
}