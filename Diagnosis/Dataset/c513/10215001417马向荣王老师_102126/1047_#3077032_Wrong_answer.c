#include<stdio.h>
#include<string.h>
void solve(char *strs)
{
    scanf("%s",strs);
    int ll=strlen(strs);
    int cnt=1;
    for(int i=1;i<ll;i++)
    {
        if(strs[i]==strs[i-1])
        {
            if(cnt==255)
            {
                printf("%d%c",cnt,strs[i-1]);
                cnt=1;
            }
            else cnt++;
        }
        else
        {
            printf("%d%c",cnt,strs[i-1]);
            cnt=1;
        }
        printf("%d%c",cnt,strs[ll-1]);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d\n",&t);
    char strs[500];
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        solve(strs);
    }
    return 0;
}