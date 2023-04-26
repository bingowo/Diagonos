#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long cToNum(char c)
{
    long long ans = 0;
    switch(c)
    {
        case 'I':ans = 1;break;
        case 'V':ans = 5;break;
        case 'X':ans = 10;break;
        case 'L':ans = 50;break;
        case 'C':ans = 100;break;
        case 'D':ans = 500;break;
        case 'M':ans = 1000;break;
        default :ans = 0;
    }
    return ans;
}

long long stoNum(char s[])
{
    int len = strlen(s);
    if(len == 1){return cToNum(s[0]);}
    int cnt = 0,j = 0;
    long long ans = 0;
    long long n[len+1];memset(n,0,(len+1)*sizeof(long long));
    for(int i = 0;i<len;i++)
    {
        if(s[i]=='('){cnt++;}
        else{n[j] = cToNum(s[i]);j++;}
    }
    //printf("j = %d\n",j);
    for(int k = 0;k<j;k++)
    {
        //printf("n[%d] = %d\n",k,n[k]);
        if(n[k]<n[k+1]){ans-=n[k];}
        else{ans+=n[k];}
    }
    for(int k1 = 0;k1<cnt;k1++)
    {
        ans*=1000;
    }
    return ans;
}


int main()
{
    char s[60];memset(s,0,60*sizeof(char));
    scanf("%s",s);
    int slen = strlen(s);
    long long n[60];memset(n,0,60*sizeof(long long));
    char sn[60][10];memset(sn,0,60*10*sizeof(char));
    int i = 0,cnt = 0,k = 0,j = 0;
    for(i = 0;i<slen;i++)
    {
        if(isalpha(s[i]))
        {
            sn[cnt][k] = s[i];
            n[cnt] = stoNum(sn[cnt]);
            //printf("sn[%d] = %s\n",cnt,sn[cnt]);
            cnt++;
            k = 0;
        }
        else if(s[i]=='(')
        {
            int tmp = 1;//'('num
            while(s[i] != ')')
            {
                sn[cnt][k] = s[i];

                k++;i++;
            }
            n[cnt] = stoNum(sn[cnt]);
            //printf("sn[%d] = %s\n",cnt,sn[cnt]);
            cnt++;
            k = 0;
        }
    }

    //for(int j = 0;j<cnt;j++)
    //{
    //    n[j] = stoNum(sn[j]);
    //    printf("%lld %s\n",n[j],sn[j]);
    //}

    long long ans = 0;
    for(int j = 0;j<cnt;j++)
    {
        if(n[j]<n[j+1])
        {
            ans-=n[j];
        }
        else
        {
            ans+=n[j];
        }
    }
    printf("%lld",ans);
    return 0;
}
