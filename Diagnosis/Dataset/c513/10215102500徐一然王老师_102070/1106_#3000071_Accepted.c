#include <stdio.h>
#include <string.h>

int main()
{
    char s[2001];
    scanf("%s",s);
    char *p=s;
    long long int R=1;
    if(strlen(s)==1)
    {
        printf("1");
        return 0;
    }
    while(*p)
    {
        if(p==s)
        {
            if(*(p+1)==*p)
                R=1;
            else
                R=2;
        }
        else if(*(p+1)=='\0')
        {
            if(*(p-1)==*p)
                R=R;
            else
                R=(R%1000000007*2%1000000007)%1000000007;
        }
        else
        {
            if(*(p-1)==*p)
            {
                if(*(p+1)==*p)
                {
                    R=R;
                }
                else
                {
                    R=(R%1000000007*2%1000000007)%1000000007;
                }
            }
            else
            {
                if(*(p+1)==*p||*(p+1)==*(p-1))
                {
                    R=(R%1000000007*2%1000000007)%1000000007;
                }
                else
                {
                    R=(R%1000000007*3%1000000007)%1000000007;
                }
            }
        }
        p++;
    }
    printf("%lld",R);

}
