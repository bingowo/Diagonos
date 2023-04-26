#include<stdio.h>
#include<string.h>

/*int main()
{
    char ch;
    char s[1002]={0};
    int n=0;
    int i;
    while ((ch = getchar()) != '\0')
    {
        printf("%c\n",ch);
        if (ch>='a' && ch<='z')
        {
            ch-=32;
        }
        if (n == 0)
        {
            s[n]=ch;
            n++;
            printf("n=%d\n",n);
            continue;
        }
        else
        {
            if (s[0] <= ch)
            {
                for (i=n;i>=1;i--)
                {
                    s[i]=s[i-1];
                }
                s[0]=ch;
                n++;
                printf("n=%d\n",n);
                continue;
            }
            else
            {
                s[n]=ch;
                n++;
                printf("n=%d\n",n);
                continue;
            }
        }
    }
    printf("%s",s);
    return 0;
}*/

int main()
{
    char s[1001]={0};
    char t[1001]={0};
    int i=0,j;
    int len;
    scanf("%s",s);
    len=strlen(s);
    
    //开始听写
    while (i<len)
    {
        //i记录t数组当前存储的字符数
        if (s[i]>= 'a' && s[i]<='z')
        {
            s[i]-=32;
        }
        if (!i)
        {
            t[i]=s[i];
            i++;
        }
        else
        {
            if (t[0] <= s[i])
            {
                for (j=i;j>=1;j--)
                {
                    t[j]=t[j-1];
                }
                t[0]=s[i++];
            }
            else
            {
                t[i]=s[i];
                i++;
            }
        }
    }
    printf("%s",t);
    return 0;
}