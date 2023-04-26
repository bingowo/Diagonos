#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[100],ans[300];
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len*3;i++)ans[i]='0';
        int m,cnt,t;
        for(int i=len-1;i>1;i--){
            m=s[i]-'0';
            cnt=0;
            while(m||cnt<t){
                m=m*10+(ans[cnt]-'0');
                ans[cnt]=m/8+'0';
                cnt++;
                m%=8;
            }
            t=cnt;
        }
        while(ans[t]=='0')t--;
        ans[t+1]='\0';
        printf("case #%d:\n0.",i);
        printf("%s\n",ans);
    }
    return 0;
}
