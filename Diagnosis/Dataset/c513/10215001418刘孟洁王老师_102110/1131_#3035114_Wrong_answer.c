#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char s[])
{
    int len = strlen(s);
    for(int i = 0; i <= (len-1)/2; i++)
    {
        char p = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = p;
    }
    s[len] = '\0';
}

void turnz(int z,char s[])
{
    int i = 0;
    if(z == 0)strcpy(s,"0");
    else
    {
      while(z)
     {
        s[i++] = z%3 + '0';
        z /= 3;
     }
     s[i] = '\0';
    }
}

void turnx(int b,int x,char s[])
{
    int i = 0;
    b /= 3;
    while(b)
    {
        s[i++] = x/b + '0';
        x %= b;
        b /= 3;
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int a,b,i,j,len,llen,len1,len2,m,tmp,x,z,sign = 1;
    char s1[1007] = {0},s2[1007] = {0},zsum[1007] = {0},xsum[1007] = {0};
    scanf("%d%d",&a,&b);
    if(a < 0){sign = -1;a = -a;}
    z = a/b;
    x = a%b;
    turnz(z,zsum);
    len1 = strlen(zsum);
    for(i = 0; i < len1; i++)s1[i] = '1';
    s1[len1] = '\0';
    len = len1;
    if(x != 0)turnx(b,x,xsum);
    len2 = strlen(xsum);
    for(i = 0; i < len2; i++)s2[i] = '1';
    s2[len2] = '\0';
    llen = len2;
    if(strlen(xsum) != 0)
    {
        if(sign == 1)
        {
            for(i = 0,m = 0; i < len2; i++)
          {
             tmp = s2[i]-'0' + xsum[i]-'0' + m;
             xsum[i] = tmp%3 + '0';
             m = tmp/3;
          }
        }
        else if(sign == -1)
            {
               for(i = 0,m = 0; i < len2; i++)
              {
                tmp = s2[i] - xsum[i];
                if(tmp >= 0)xsum[i] = tmp%3 + '0';
                else if(tmp < 0&&i != len2-1){xsum[i] = tmp%3 + 3 + '0';s2[i+1] -= 1;}
                else if(tmp < 0&&i == len2-1){xsum[i] = tmp%3 + 3 + '0';s1[0] -= 1;}
               }
            }
    }
    if(!strlen(xsum))m = 0;
    if(sign == 1)
    {
        for(i = 0; i < len1; i++)
       {
        tmp = s1[i]-'0' + zsum[i]-'0' + m;
        zsum[i] = tmp%3 + '0';
        m = tmp/3;
       }
       while(m)
      {
        zsum[len1++] = m%3 + '0';
        m /= 3;
      }
    }
    else if(sign == -1)
    {
        for(i = 0,m = 0; i < len1; i++)
      {
        tmp = s1[i] - zsum[i];
        if(tmp >= 0)zsum[i] = tmp%3 + '0';
        else if(tmp < 0&&i != len1-1){zsum[i] = tmp%3 + 3 + '0';s1[i+1] -= 1;}
        else if(tmp < 0&&i == len1-1){zsum[i] = tmp%3 + '0';}
      }
    }
    for(i = 0; i < len; i++)s1[i] = '1';
    s1[len] = '\0';
    for(i = 0; i < llen; i++)s2[i] = '1';
    s2[llen] = '\0';
    for(i = len; i < len1; i++)s1[i] = '0';
    s1[i] = 0;
    for(i = llen; i < len2; i++)s2[i] = '0';
    s2[i] = 0;
    for(i = 0; i < len1; i++)
    {
        tmp = zsum[i] - s1[i];
        tmp = tmp<0?tmp+3:tmp;
        zsum[i] = tmp + '0';
    }
    for(i = 0; i < len2; i++)
    {
        tmp = xsum[i] - s2[i];
        tmp = tmp<0?tmp+3:tmp;
        xsum[i] = tmp + '0';
    }
    for(i = 0; xsum[i] == '0' && i < len2; i++);
    reverse(zsum);reverse(xsum+i);
    for(j = 0; zsum[j] == '0' && j < len1; j++);
    if(strlen(zsum)&&strlen(xsum))printf("%s.%s",zsum+j,xsum+i);
    else if(!strlen(zsum))
    {
        if(!strlen(xsum))printf("0");
        else printf("0.%s",xsum+i);
    }
    else if(!strlen(xsum))printf("%s",zsum+j);
    return 0;
}
