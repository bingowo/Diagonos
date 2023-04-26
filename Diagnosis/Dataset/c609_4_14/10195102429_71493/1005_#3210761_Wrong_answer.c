#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char a[100];
        scanf("%s",a);
        int len=strlen(a);
        int sum=0;
        int w=1;
        for(int j=len-1;j>=0;j--){
            if(a[j]=='1'){
                sum+=1*w;
            }
            if(a[j]=='-'){
                sum-=1*w;
            }
            if(a[j]=='0'){
                sum+=0;
            }
            w*=3;
        }
    printf("case #%d:\n",i);
    printf("%d",sum);
    }
    return 0;
}
