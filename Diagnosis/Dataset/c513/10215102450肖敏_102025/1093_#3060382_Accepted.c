#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s",s);
    int len= strlen(s);
    int a[101];
    memset(a,0,sizeof (a));
    for(int i=len-1,j=0;i>=0;j++,i--)
    {
        a[j]=s[i]-'0';
    }
    a[0]++;
    if(a[0]>=10)
    {
        int loc=0;
        while(a[loc]>= 10 && loc<len)
        {
            a[loc]%=10;
            a[loc+1]++;
            loc++;
            if(loc==len)
                len++;
        }
    }
    int temp = 0;
    for(int i = 0; i < len; i++)
    {
        temp += a[i];
        if(a[i] == 9)
        {
            a[i + 1]++;
            for(int j = i; j >= 0; j--)
                a[j] = 0;

            if(i == len - 1)
                len++;
            while(a[i] >= 10)
            {
                a[i + 1] ++;
                a[i]%=10;
                i++;
                if(i == len - 1)
                    len++;
            }
        }
    }
    if(temp%9==0)
    {
        a[0]++;
    }
    if(a[0]==9)
    {
        for(int i=0;i<len;i++)
        {
            if(a[i]==9)
            {
                a[i+1]++;
                for(int j=i;j>=0;j--)
                    a[j]=0;
            }
        }
    }
    for(int i=len-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
