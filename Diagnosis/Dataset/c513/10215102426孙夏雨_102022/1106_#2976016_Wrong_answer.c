#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    int len=strlen(s),butong=1;
    int* p=(int* )malloc(len*sizeof(int));
    if(len==1) printf("1");
    else{
        for(int i=0;i<len;i++){
        butong=1;
        if(i==0) {
            if(s[i+1]!=s[i]) butong++;
        }
        else if(i==len-1) {
            if(s[i-1]!=s[i]) butong++;
        }
        else {
            if(s[i+1]!=s[i]) butong++;
            if(s[i-1]!=s[i]&&s[i-1]!=s[i+1]) butong++;
        }
        *(p+i)=butong;
    }
    int num=0;
    int ans=*(p);
    for(int k=1;k<len;k++){
        int x=*(p+k);
        ans=ans*x%1000000007;
    }
    printf("%d\n",ans);}
    free(p);
    return 0;
}
