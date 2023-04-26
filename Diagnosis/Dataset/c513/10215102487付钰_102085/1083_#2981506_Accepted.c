#include <stdlib.h>
#include <stdlib.h>
#define L 500
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        scanf("%d",&n);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
}
