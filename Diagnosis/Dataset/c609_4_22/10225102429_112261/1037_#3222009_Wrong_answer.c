#include <stdio.h>
#include <string.h>
int a[128];
#define Maxlen 1000001
char s[Maxlen];
int main()
{
    scanf("%s",s);
    memset(a,0,sizeof(a));
    int begin = 0,end = 0,rb = 0,re = 0;
//    for(; end< strlen(s); end++)
//    {
//        if(!a[s[end]])
//        {
//            a[s[end]] = 1;
//        }
//        else {
//            end--;
//            break;
//        }
//    }
    for(re = end+1; re<strlen(s); re++)
    {
        if(end-begin<re-rb)
        {
            end = re; begin = rb;
        }
        if(!a[s[re]])
        {
            a[s[re]] = 1;
        }
        else
        {
            while(s[rb]!=s[re])
            {
                a[s[rb]] = 0;
                rb++;
            }
            rb++;
        }
        if(end-begin<re-rb)
        {
            end = re; begin = rb;
            // re++;
        }
    }
    for(int i = begin; i<=end; i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}