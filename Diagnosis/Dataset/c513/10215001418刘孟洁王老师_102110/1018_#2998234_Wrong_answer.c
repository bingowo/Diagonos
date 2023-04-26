#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int d[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,73,79,83,89,91,97};
int main()
{
    int i,a[26],m,tmp,k,cnt,p,b[1007],c[1007],len1,len2,ans[1007];
    char s[1007];
    scanf("%s",s);
    int len = strlen(s);
    for(i = 0,cnt = 0; i < len; i++)
    {
        if(isdigit(s[i]))
          {
              a[cnt] = 0;
              for( ; isdigit(s[i]); i++)a[cnt] = a[cnt]*10 + s[i]-'0';
              cnt++;
          }
    }
    for(i = 0; i <= (cnt-1)/2; i++)
    {
        p = a[i];
        a[i] = a[cnt-1-i];
        a[cnt-1-i] = p;
    }
    memset(ans,0,sizeof(ans));
    memset(b,0,sizeof(b));b[0] = 1;
    memset(c,0,sizeof(c));
    ans[0] = a[0];len = 1;len1 = 1;len2 = 1;
    for(i = 1; i < cnt; i++)
    {
        m = 0;
        for(k = 0; k < len1; k++)
        {
            tmp = b[k]*d[i-1] + m;
            b[k] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            b[len1++] = m%10;
            m /= 10;
        }
        len2 = len2>len1?len2:len1;
        for(k = 0; k < len2; k++)
        {
            tmp = a[i]*b[k] + m;
            c[k] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            c[len2++] = m%10;
            m /= 10;
        }
        len = len>len2?len:len2;
        for(k = 0; k < len; k++)
        {
            tmp = ans[k] + c[k] + m;
            ans[k] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            ans[len++] = m%10;
            m /= 10;
        }
    }
    for(i = len-1; ans[i] == 0&&i > 0; i--);
    for(; i >= 0; i--)printf("%d",ans[i]);
    return 0;
}