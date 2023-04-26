#include <stdio.h>
#include <stdlib.h>

int count=0;
int n,p,m,t;
void mouse(int p,int m);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        count=0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        mouse(p,m);
        printf("%d\n",count);
    }
    return 0;
}


void mouse(int p,int m)
{
    if(m==0){
        if(p==t){
            count++;
            return;
        }
        else{
            return;
        }
    }
    if(p==1)mouse(2,m-1);
    else if(p==n)mouse(n-1,m-1);
    else{
        mouse(p-1,m-1);
        mouse(p+1,m-1);
    }
}
