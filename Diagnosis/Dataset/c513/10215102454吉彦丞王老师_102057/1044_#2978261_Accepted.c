#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    scanf("%s",&s);
    int l=strlen(s);
    int t=0;
    int k=0;
    int number=0;
    for(int i=0;i<l;i++)
    {
        long long int n=0;
        if(s[i]=='0'&&s[i+1]=='x')
        {
            t++;
            int m=i+2;
            for(int j=m;j<l;j++)
            {;
                if(s[j]-'0'<10)
                {
                	k++;
                    n=(n+(s[j]-'0'))*16;
                }
                else if(s[j]-'0'>=49&&s[j]-'0'<=54)
                {
                    k++;
                    n=(n+(s[j]-'0')-39)*16;
                }
                else
                {
                    break;
                }
            }
            if(n!=0||k!=0)
            {
            	printf("%lld ",n/16);
			}
			else
			{
			    number++;
			}
            n=0;
            k=0;
        }
        else
        {
            continue;
        }
    }
    if(t==0||t==number)
    {
        printf("-1");
    }
    return 0;
}