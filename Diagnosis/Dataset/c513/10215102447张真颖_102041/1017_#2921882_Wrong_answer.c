#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[50];
    long long r=0,mul=1,sign=-1,sum=0;
    int arr[91];
    arr['I']=1,arr['V']=5,arr['X']=10,arr['L']=50,arr['C']=100,arr['D']=500,arr['M']=1000;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='(') mul*=1000,sign=0;
        else if(s[i]==')')
        {
            sign=-1;
            if(s[i+1]!=')')
            {
                r+=mul*sum;
                sum=0;
                mul=1;
            }
        }
        else
        {
            if(s[i]==s[i+1]||s[i]==s[i-1])
            {
                if(sign==-1) r+=arr[s[i]];
                else sum+=arr[s[i]];

            }
            else if((s[i]=='I'||s[i]=='X'||s[i]=='L')&&arr[s[i+1]]>arr[s[i]]&&i+1<strlen(s))
            {
                if(sign==-1)
                {
                    r=r-arr[s[i]];
                }
                else
                    sum+=-arr[s[i]];
            }
            else if(arr[s[i+1]]<arr[s[i]]&&i+1<strlen(s)||i+1==strlen(s))
            {
                if(sign==-1)
                {
                    r=r+arr[s[i]];
                }
                else
                    sum+=arr[s[i]];
            }

        }
    }
    printf("%lld",r);
    return 0;
}
