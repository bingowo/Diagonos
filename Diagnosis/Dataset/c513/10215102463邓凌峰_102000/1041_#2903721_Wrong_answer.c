#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char fence[51];
    gets(fence);
    int cnt=0,ans=0;
    for(int i=1;fence[i];i++){
        if(fence[i]!=fence[i-1]){
            if(cnt==0) cnt=1;
            cnt++;
            if(cnt>ans) ans=cnt;
        }
        else if(fence[i]==fence[i-1]){
            if(cnt>ans) ans=cnt;
            cnt=0;
        }


    }
    printf("%d",ans);
    return 0;
}
