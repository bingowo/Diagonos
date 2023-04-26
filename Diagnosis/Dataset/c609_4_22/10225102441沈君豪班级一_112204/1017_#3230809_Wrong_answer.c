#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int A=*(int*)a;
    int B=*(int*)b;
    return A-B;
}

int main()
{
    char c;
    scanf("%c",&c);
    int s[100];
    int i=0;
    while(scanf("%d",&s[i])!=EOF){
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    if(c=='A'){
        for(int j=0;j<i;j++){
            if(s[j]!=s[j-1]&&s[j]!=s[j+1])
               printf("%d ",s[j]);
        }
    }else{
        for(;i>=0;i--){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1])
                printf("%d ",s[i]);
        }
    }
    return 0;
}
