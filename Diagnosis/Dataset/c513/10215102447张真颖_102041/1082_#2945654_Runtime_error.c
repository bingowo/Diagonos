#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(char sa[],char sb[],char s[])
{
    char saa[501]={0},sbb[501]={0};
    char st[502]={0};
    int af=0,bf=0,sf;
    for(;sa[af]!='.';af++);
    for(;sb[bf]!='.';bf++);
    if(af<bf)
    {
        for(int i=0;i<bf-af;i++)
            saa[i]='0';
        strcat(saa,sa);
        strcpy(sbb,sb);
    }
    else if(af>bf)
    {
        for(int i=0;i<af-bf;i++)
            sbb[i]='0';
        strcat(sbb,sb);
        strcpy(saa,sa);
    }
    else
    {
        strcpy(saa,sa);
        strcpy(sbb,sb);
    }
    if(strlen(saa)>strlen(sbb))
    {
        for(int i=strlen(sbb);i<strlen(saa);i++)
            sbb[i]='0';
    }
    else if(strlen(saa)<strlen(sbb))
    {
        for(int i=strlen(saa);i<strlen(sbb);i++)
            saa[i]='0';
    }
    int carry=0;
    for(int i=strlen(saa)-1;i>=0;i--)
    {
        if(saa[i]=='.') st[i]='.',sf=i;
        else
        {
            int tmp=saa[i]-'0'+sbb[i]-'0'+carry;
            st[i]=tmp%10+'0';
            carry=tmp/10;
        }
    }
    if(carry)
        s[0]=carry+'0',strcat(s,st),sf+=1;
    else
        strcpy(s,st);
    return sf;
}

int main()
{
    char sa[501]={0},sb[501]={0};
    char s[502]={0},sr[502]={0};
    int N;
    scanf("%s%s%d",sa,sb,&N);
    int sf=add(sa,sb,s);
    if(strlen(s)-sf<N)
    {
        for(int i=0,f=0;f<N;i++)
       {
           if(i>sf) f++;
           if(i==0&&s[i]=='.') printf("0.");
           else if(i<strlen(s))
               printf("%c",s[i]);
           else printf("0");
        }
    }
    else
    {
        int carry=s[sf+N+1]-'0'>=5?1:0;
        for(int i=sf+N;i>=0;i--)
        {
            if(s[i]=='.') sr[i]='.';
            else
            {
                int tmp=s[i]-'0'+carry;
                sr[i]=tmp%10+'0';
                carry=tmp/10;
            }
         }
         memset(s,0,sizeof(s));
        if(carry)
              s[0]=carry+'0',strcat(s,sr),sf+=1;
        else
            strcpy(s,sr);
        for(int i=0,f=0;f<N;i++)
        {
            if(i>sf) f++;
            if(i==0&&s[i]=='.') printf("0.");
            else
                printf("%c",s[i]);
        }
    }
    return 0;
}