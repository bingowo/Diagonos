#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001];
int main()
{
    memset(s,0,1000001*sizeof(char));
    scanf("%s",s);
    int i = 0,j = 1;
    char cur[100];memset(cur,0,100*sizeof(char));
    char ans[100];memset(ans,0,100*sizeof(char));
    if(strlen(s)<=1){printf("%s",s);return 0;}

    while(s[j]!=0)
    {
        int tmp = 0;
        for(tmp=i;tmp<j;tmp++)
        {
            if(s[tmp] == s[j])
            {
                i = tmp+1;
                break;
            }
        }
        int tmp1 = 0;
        for(int k = i;k<=j;k++){cur[tmp1++] = s[k];}
        //printf("cur = %s\n",cur);
        if(strlen(cur)>strlen(ans)){strcpy(ans,cur);}
        j++;
    }

    printf("%s\n",ans);
    return 0;
}
