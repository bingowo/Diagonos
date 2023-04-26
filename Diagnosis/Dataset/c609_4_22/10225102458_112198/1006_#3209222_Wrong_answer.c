#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[124];
    for(int i=0;i<n;i++){
        int s=0;
            for(int i=0;i<124;i++)a[i]=-1;
            char app[60];
            char *p;
            p=app;
        scanf("%s",app);
        a[*app]=1;
        while(*(++p)){
            if(a[*p]==-1){
                a[*p]=s;
                if(!s)s=2;
                else s++;
            }
        }
        long long int max=0;
        long long int u=1;
    for(int i=strlen(app)-1;i>=0;i--){
        max+=u*a[*(app+i)];
        u*=s;
    }

    printf("case #%d:\n%lld\n",i,max);
    }

    return 0;
}
