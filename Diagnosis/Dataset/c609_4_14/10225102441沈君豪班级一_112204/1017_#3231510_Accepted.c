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
    int s[100],t[100];
    int i=0;
    int b=1;
    while(scanf("%d",&s[i])!=EOF){
        t[0]=s[0];
        for(int k=0;k<i;k++){
            if(s[i]==s[k])
                break;
            if(k==i-1){
                t[b]=s[i];
                b++;
            }
        }
        i++;
    }
    qsort(t,b,sizeof(t[0]),cmp);
    if(c=='A'){
        for(int j=0;j<b;j++){
            printf("%d ",t[j]);
        }
    }else{
        for(b=b-1;b>=0;b--){
            printf("%d ",t[b]);
        }
    }
    return 0;
}
