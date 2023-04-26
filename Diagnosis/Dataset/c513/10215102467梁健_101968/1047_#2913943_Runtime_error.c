#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char jud[129];
int solve(char s[])
{
    int num=1;
    for(int i=0;i<strlen(s);i++){
        if(num<255&&s[i+1]==s[i])num+=1;
        else if(s[i+1]!=s[i]){
            printf("%d%c",num,s[i]);
            num=1;
        }
        else if(num==255){
            printf("%d%s",num,s[i]);
            num=1;
        }
    }
    printf("\n");

}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[501];scanf("%s",s);
        solve(s);
    }
    return 0;
}
