#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

char * itor(int n, int r);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n,r;
        scanf("%d %d",&n,&r);
        char *s;
        s = itor(n,r);
        int ans = 0;
        for(int i = 0; i < strlen(s); i++){
            char j;
            int m;
            j = *(s + i);
            if(j >= '0' && j <= '9'){
                m = j - '0';
            }else if(j >= 'a' && j <= 'z'){
                m = j - 'a' + 10;
            }else if(j >= 'A' && j <= 'Z'){
                m = j - 'A' + 10;
            }
            ans = ans + m;
        }
        char * ans0 = itor(ans,r);
        printf("case #%d:\n",t);
        printf("%s\n",ans0);
    }
    return 0;
}


char * itor(int n, int r){
    static char ans[500] = {"\0"};
    itoa(n,ans,r);
    return ans;
}
