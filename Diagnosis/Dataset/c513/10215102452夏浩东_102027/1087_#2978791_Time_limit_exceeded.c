#include <stdio.h>
#include <string.h>
int plus(char *s,int i,int len)
{
    int left=(s[i]+1-'0')/10;
    s[i]=(s[i]+1-'0')%10+'0';
    while(left!=0 && i>=0) {
        int temp = s[--i]-'0'+left;
        left=temp/10;
        s[i]=temp%10+'0';
    }
    if(i==-1) 
    {
        for(int k=len;k>=0;k--) s[k+1]=s[k];
        s[0]='1';
        return len+1;
    }
    else return len;
}
void func(char*s,int len)
{
    if (len==1) return;
    else{
        int i=0,hh=0,flag=0;
        for(i=0;i<len-1;i++) if(s[i]==s[i+1]) {flag=1;i++;break;}
        for(int k=i+1;k<len;k++) 
        {
            if(hh==0) {s[k]='0'; hh=1;}
            else {s[k]='1';hh=0;}
        }
        if(flag==1) {len=plus(s,i,len);func(s,len);return;}
        else return;
    }
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int m=0;m<cnt;m++)
    {
    	char s[110];
        scanf("%s",s);
        int len = strlen(s);
        len=plus(s,len-1,len);
        func(s,len);
        printf("case #%d:\n",m);
        printf("%s\n",s);
    }
    
}