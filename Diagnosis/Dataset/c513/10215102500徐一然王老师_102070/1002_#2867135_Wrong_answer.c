#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int num,num1,len,len1,digit=0,o=1;
    long long int sum=0;
    scanf("%d",&num);
    num1=num;
    char s[61];
    int a[129];
    while(num--)
    {
        for (int i=0;i<128;i++) {a[i]=-1;}
        char *p;
        scanf("%s",s);
        p=s;
        len=strlen(s);
        while(len--)
        {
            if(p==s)
            {
                a[*p]=1;

            }
            else if(a[*p]==-1)
            {
                a[*p]=digit;
                digit++;
                o++;
            }
            if(digit==1)
            {
                digit++;
            }
            p++;
        }
        len1=strlen(s);
        p=s;
        while(len1)
        {
            sum=sum*o+a[*p];
            p++;
            len1--;
        }
    printf("case #%d:\n",num1-num-1);
    printf("%lld\n",sum);
    sum=0;
    digit=0;
    o=1;
    }
}
