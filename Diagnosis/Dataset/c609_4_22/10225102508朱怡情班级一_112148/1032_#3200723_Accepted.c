#include <stdio.h>
#include <math.h>

int main()
{
    char c,target;
    target=getchar();
    int cnt=1;
    int ans=1;
    while((c=getchar())!='\n'){
        if(c!=target)cnt++;
        else cnt=1;
        target=c;
        ans=ans>cnt?ans:cnt;
    }
    printf("%d",ans);
    return 0;
}
