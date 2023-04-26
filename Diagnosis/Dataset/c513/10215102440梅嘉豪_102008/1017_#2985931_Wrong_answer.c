#include <stdio.h>
#include <string.h>
int d[128]={0};

int pos=0;
int roman_to_int(char *s);

int main()
{
    char s[100];
    char t[100];
    d['I']=1;
    d['X']=10;
    d['C']=100;
    d['M']=1000;
    d['V']=5;
    d['L']=50;
    d['D']=500;
    int ans=0;
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;)
    {
        if(s[i+1]=='(')
        {
            ans-=d[s[i++]];
        }
        else if(s[i]=='(')
        {
            int begin=i,end=i;
            while(s[end++]!=')');
            end--;
            if(s[begin+1]=='(') begin+=2;
            else begin++;
            int j=0;
            while(begin<end)    t[j++]=s[begin++];
            t[j]==0;
            if(s[end+1]==')')
            {
            ans=ans+1000000*roman_to_int(t);
            i=end+2;
            }
            else 
            {
            ans=ans+1000*roman_to_int(t);
            i=end+1;
            }
        }
        else
        {
            int value=d[s[i]];
            if(i<n-1&&value<d[s[i+1]])    ans-=value;
            else ans+=value;
            i++;
        }
    }
    printf("%d",ans);
    
}
int roman_to_int(char *s)
{
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int value=d[s[i]];
        if(i<n-1&&value<d[s[i]])    ans-=value;
        else ans+=value;
    }
    return ans;
}
