#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(a,b)

int a,b;

{

if (a>b) return a;

else return b;

}
int main()
{
    char s[51];
    scanf("%s",s);
    int temp=1;
    int cnt[101];
    cnt[0]=1;
    int len=strlen(s);
    for(int i=1;i<len;i++){
            if(s[i]!=s[i-1]){
                cnt[i]=cnt[i-1]+1;
                temp=max(temp,cnt[i]);
            }
            else cnt[i]=1;
    }
    printf("%d",temp);

    return 0;
}
