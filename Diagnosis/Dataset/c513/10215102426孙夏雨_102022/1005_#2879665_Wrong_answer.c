#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        char s[53];
        scanf("%s",s);
        int len=strlen(s);
        char ans[1000];
        int n=0;
        for(int j=len-1;j>=2;j--){
            int w=0,k=0;
            if(w<n) k=ans[w]-'0';
            int rem=s[j]-'0';
            while(rem>0){
                ans[w]=(rem*10+k)/8+'0';
                rem=(rem*10+k)%8;
                w++;
                if(w>n) n=w;
                if(w<n) k=ans[w]-'0';
                else k=0;
            }
            ans[n]=0;
        }
        printf("case #%d:\n",i);
        printf("0.");
        for(int j=0;j<n;j++) printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}
