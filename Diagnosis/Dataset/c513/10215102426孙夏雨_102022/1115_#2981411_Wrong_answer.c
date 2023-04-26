#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    char s[50];
    for(int t=0;t<T;t++){
        scanf("%s",s);
        int len=strlen(s),i=len-1;
        int minw=len-1;
        printf("case #%d:\n",t);
        for(;i>0;i--){
            if(s[i-1]<s[i]){
                char c=s[minw];
                for(int ii=minw;ii>i-1;ii--){
                    s[ii]=s[ii-1];
                }
                s[i-1]=c;
                break;
            }if(s[i]<s[minw]) minw=i;
        }
        if(i>0) printf("%s\n",s);
        else{
            printf("%c0",s[0]);
            for(int j=1;j<len;j++) printf("%c",s[j]);
            printf("\n");
        }
    }
    return 0;
}
