#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    int cnt;
    int i,j;
    char ch;
    char s[501];
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%s",s);
        int len=strlen(s);
        j=0;
        printf("case #%d:\n",i);
        while (j<len-1){
            cnt=1;
            ch=s[j];
            while (s[j] == s[j+1] && cnt <255){
                cnt++;
                j++;
                if (j >= len-1)
                    break;
            }
            printf("%d%c",cnt,ch);
            j++;
        }
        ch=s[j];
        printf("%d%c",cnt,ch);
        putchar('\n');
    }
    return 0;
}