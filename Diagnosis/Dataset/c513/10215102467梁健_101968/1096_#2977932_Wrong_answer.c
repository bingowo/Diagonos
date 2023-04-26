#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        int n;scanf("%d",&n);
        int s[n][2];
        for(int i=0;i<n;i++)
            scanf("%d %d",&s[i][0],&s[i][1]);
        int fair=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(s[i][1]==s[j][0]||s[i][0]==s[j][0]){
                    fair=0;
                    break;
                }
            }
            if(fair==0)break;
        }
        if(fair==1)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
