#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step = 0; step < T; step++){
        int n;scanf("%d",&n);
        int fair=1;
        int s[n+1][3];
        for(int i=0;i<n;i++)
            scanf("%d %d",&s[i][0],&s[i][1]);
        if(n==1){
            printf("Lucky dxw!\n");
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(s[i][0]==s[j][0]&&s[i][1]!=s[j][1]){
                    fair=0;break;
                }
                if(s[j][1]==s[i][0]){
                    fair=0;break;
                }
            }
            if(fair==0){
                printf("Poor dxw!\n");
                break;
            }
        }
        if(fair)printf("Lucky dxw!\n");
    }
    return 0;
}