#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char S[10005];
int main()
{
    int ansh,ansm,anss,hav=0;
    while(~scanf("%s",S))
    {
        if(S[0]=='E')
            break;
        if(S[0]!='$'||S[1]!='G'||S[2]!='P'||S[3]!='R'||S[4]!='M'||S[5]!='C')
            continue;
        l=strlen(S);
        int h=0,m,s,loc=0;
        for(int i=0;i<l;i++)
        {
            if(S[i]==','&&S[i-1]=='C')
            {
                for(int j=i+1;j<i+7;j++)
                    if(S[j]>'9'||S[j]<'0')
                        h=-1;
                if(h==-1)
                    break;
                h=(S[i+1]-'0')*10+S[i+2]-'0';
                m=(S[i+3]-'0')*10+S[i+4]-'0';
                s=(S[i+5]-'0')*10+S[i+6]-'0';
                if(h>=24||m>=60||s>=60)
                    h=-1;
                if(h==-1)
                    break;
                h=(h+8)%24;
                break;
            }
        }
        if(h==-1)
            continue;
        int sm=0,xsum;
        sscanf(S+l-2,"%x",&xsum);
        for(int i=1;i<l-3;i++)
        {
            if(S[i]=='A'&&S[i-1]==','&&S[i+1]==','&&loc!=-1)
                loc=1;
            if(S[i]=='V'&&S[i-1]==','&&S[i+1]==',')
                loc=-1;
            sm^=S[i];
        }
        //printf("%d %d %d\n",loc,sm,xsum);
        if(loc>0 && sm==xsum)
        {
            hav=1;
            ansh=h;
            ansm=m;
            anss=s;
        }
    }
    if(hav)
        printf("%02d:%02d:%02d\n",ansh,ansm,anss);
    return 0;
}