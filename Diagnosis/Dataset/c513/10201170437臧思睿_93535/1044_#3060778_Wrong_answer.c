#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[10000],s1[10000];
    scanf("%s",s);
    int i,j,len=strlen(s),flag=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='0' && s[i+1]=='x')
        {
            int k=0;
            unsigned int r=0,temp=0;
            memset(s1,0,sizeof(s1));
            for(j=i+2;(s[j]<='9'&&s[j]>='0')||(s[j]>='a'&&s[j]<='e');j++)
            {
                s1[k++]=s[j];
                //printf("%s\n",s1);
            }
            if(k==0){printf("0 ");}
            else
            {
                for(j=0;j<k;j++)
                {
                    if(s1[j]>='a')
                    {
                        temp=(s1[j]-'a'+10)*pow(16,k-j-1);
                        r+=temp;
                    }
                    if(s1[j]<='9')
                    {
                        temp=(s1[j]-'0')*pow(16,k-j-1);
                        r+=temp;
                    }
                }
                printf("%u ",r);
            }
            flag=1;
        }
    }
    if(flag==0){printf("-1");}
    return 0;
}
