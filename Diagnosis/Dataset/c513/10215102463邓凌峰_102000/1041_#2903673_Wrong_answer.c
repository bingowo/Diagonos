#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char fence[51];
    gets(fence);
    int cnt=1,ans=1;
    for(int i=1;i<51;i++){
        if(fence[i]!=fence[i-1]){
            cnt++;
            if(cnt>ans) ans=cnt;
        }
        else if(fence[i]==fence[i-1]){
            if(cnt>ans) ans=cnt;
            cnt=1;
        }


    }
    printf("%d",ans);
    return 0;
}
