#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int w[10],len=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        len+=w[i];
    }
    int s[1000]={0};
    int n_states=pow(3,n);
    for(int i=0;i<n_states;i++)
    {
        int tmp=i;
        int left=0,right=0;
        for(int j=0;j<n;j++)
        {
            if(tmp%3==0) left+=w[j];//放左
            else if(tmp%3==1) right+=w[j];//放右
            tmp/=3;//不放
        }
        if(left>=right) continue;
        s[right-left-1]=1;
    }
    for(int i=0;i<len;i++)
        printf("%d",s[i]);
    printf("\n");
    return 0;
}
