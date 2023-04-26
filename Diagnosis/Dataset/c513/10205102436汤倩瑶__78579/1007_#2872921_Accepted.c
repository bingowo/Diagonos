#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int x)
{
    int cnt=0;
    int ans=0;
int pre=-1;
    while(x!=0)
    {

        if((x&1)!=pre){cnt++;
if(cnt>ans)ans=cnt;
       }
    else {cnt=1;}
        pre=x&1;
        x>>=1;
    }
    return ans;

}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
    printf("case #%d:\n%d\n",i,f(n));
    }


}
