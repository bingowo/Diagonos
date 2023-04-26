#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    char nums[1000][1000]={0};
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        while((c=getchar())!='\n'{
            scanf("%s",&nums[i]);
        }
    }
    for(int j=0;j<T;j++){
        int leng=lens(nums[j]);
        int max=pow(3,leng-1);
        int sum=0;
        for(int k=0;k<leng;k++){
            if(nums[j][k]=='1') sum+=max/(k+1);
            else if(nums[j][k]=='0');
            else sum-=max/(k+1);
        }
    }

    return 0;
}
