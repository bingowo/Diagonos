#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[200000];
    char oc[200000];
    int res[200000];
    scanf("%s",s);
    int sum=0,test=0,count=0,j=0,i,r;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            i=i+2;
            j=0;
            sum=0;
            while((s[i]<='9'&&s[i]>='0')||(s[i]<='f'&&s[i]>='a'))
            {
                if((s[i]=='0'&&s[i+1]=='x')&&((s[i+2]<='9'&&s[i+2]>='0')||(s[i+2]<='f'&&s[i+2]>='a')))
                {
                    i-=1;
                    break;
                }
                oc[j++]=s[i++];
            }
            int test=0;
            for(r=j-1;r>=0;r--)
            {
                if(oc[r]<='f'&&oc[r]>='a')
                {
                    sum+=(oc[r]-'a'+10)*pow(16,j-1-r);
                    test=1;
                }
                else
                {
                    sum+=(oc[r]-'0')*pow(16,j-1-r);
                    test=1;
                }
            }
            if(test==1)
            {
            res[count]=sum;
            count++;
            }
        }
    }
    if(count==0)
    {
        printf("-1");
        return 0;
    }
   for(int x=0;x<count;x++) printf("%d ",res[x]);
}
