#include <stdio.h>
#include <stdlib.h>

int main()
{
    int table[123];
    int T,j=1,num=0;
    long long int ans=0;
    char s[60];
    for(int i=0;i<123;i++)table[i]=-1;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        table[s[0]]=1;
        while(s[j]!='\0'){
            if(table[s[j]]==-1)table[s[j]]=num;
            j++;
        }
        printf("case #%d:\n%lld",i,ans);
    }
    return 0;
}
