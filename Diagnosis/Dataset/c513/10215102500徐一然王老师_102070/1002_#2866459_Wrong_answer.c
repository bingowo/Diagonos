#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int num,num1,len,len1,digit=0,sum=0,o;
    scanf("%d",&num);
    num1=num;
    while(num--)
    {
        char s[61];
        int a[129];
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
                p++;
            }
            else if(a[*p]==-1)
            {
                a[*p]=digit;
                p++;
                digit++;
            }
        }
        len1=strlen(s);
        o=len1;
        p=s;
        while(len1)
        {
            sum=sum+a[*p]*pow(o,len1-1);
            p++;
            len1--;
        }
    printf("case #%d:\n",num1-num-1);
    printf("%d\n",sum);
    }
}
