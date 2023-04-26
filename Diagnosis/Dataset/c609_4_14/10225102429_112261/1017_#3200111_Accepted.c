#include <stdio.h>
int main()
{
    char c; scanf("%c",&c);
    int a[1001] = {0};
    int i;
    while(scanf("%d",&i)!=EOF)
    {
        a[i]++;
    }
    if(c=='A'){
        for(int j = 0; j<1001; j++)
        {
            if(a[j]) printf("%d ",j);
        }
    }
    else{
        for(int j = 1000; j>-1; j--){if(a[j]) printf("%d ",j);}
    }
    return 0;
}