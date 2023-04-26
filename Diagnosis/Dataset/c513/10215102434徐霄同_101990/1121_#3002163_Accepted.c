#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,x,s;
    int w[10],pos[11]={0},ans[1001]={0};
    scanf("%d",&n);
    s=0;
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
        s=s+w[i];
    }
    while(pos[n]==0){
        pos[0]++;
        i=0;
        while(pos[i]==3){
            pos[i]=0;
            pos[i+1]++;
            i++;
        }
        x=0;
        for(i=0;i<n;i++){
            if(pos[i]==1)
                x=x+w[i];
            else if(pos[i]==2)
                x=x-w[i];
        }
        if(ans[abs(x)]==0)
            ans[abs(x)]=1;
    }
    for(i=1;i<=s;i++)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}
