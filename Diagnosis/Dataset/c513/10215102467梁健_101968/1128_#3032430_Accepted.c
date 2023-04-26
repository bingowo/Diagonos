#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int n;scanf("%d",&n);
    char s[n][301],res[n][301];
    int k=0;
    for(int i=0;i<n;i++){
        char jud[301];
        scanf("%s",jud);
        if(jud[4]=='s')continue;
        else strcpy(res[k++],jud);
    }
    qsort(*res,k,sizeof(res[0]),strcmp);
    for(int i=0;i<k;printf("%s\n",res[i++]));
    return 0;
}
