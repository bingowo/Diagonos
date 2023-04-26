#include <stdio.h>
#include <string.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    char s[501];
    for(int i=0;i<cnt;i++)
    {
        scanf("%s",s);
        printf("case #%d:\n",i);
        int num=1;
        for(int k=1;k<(int)strlen(s)+1;k++)
        {
            if(s[k]==s[k-1]) num++;
            else if(s[k]!=s[k-1]){
                if(num>255) printf("255%c%d%c",s[k-1],num-255,s[k-1]);
                else printf("%d%c",num,s[k-1]);
                num=1;
            }
        }
        printf("\n");
    }
    return 0;
}