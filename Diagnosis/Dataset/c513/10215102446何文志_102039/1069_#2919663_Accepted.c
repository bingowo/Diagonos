#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int toReverseInt(int n)
{
    int ans = 0;
    char s[20];memset(s,0,20*sizeof(char));
    sprintf(s,"%d",n);
    int len = strlen(s);
    int i = 0,j = len-1;
    for(i = 0,j = len-1;i<j;i++,j--)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    sscanf(s,"%d",&ans);
    return ans;
}
int isPalindrome(int n)
{
    char s[20];memset(s,0,20*sizeof(char));
    sprintf(s,"%d",n);
    int flag = 1;
    int len = strlen(s);
    int i = 0,j = len-1;
    for(i = 0,j = len-1;i<j;i++,j--)
    {
        if(s[i]!=s[j]){flag = 0;break;}
    }
    return flag;
}
int main()
{
    int n = 0;
    scanf("%d",&n);
    int cnt = 0;
    while(1)
    {
        if(isPalindrome(n)){break;}
        else
        {
            int tmp = toReverseInt(n);
            n+=tmp;
            cnt++;
        }
    }

    printf("%d %d",cnt,n);
    //printf("%d\n",isPalindrome(n));
    //printf("%d\n",toReverseInt(n));
    return 0;
}
