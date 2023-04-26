#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"


int main()
{
    char s[100]="",s0[100]="";
    long long tab['Z'],ans=0;
    scanf("%s",s0);
    tab[0]=0;tab[1]=1;tab[')']=0;tab['I']=1;tab['V']=5;tab['X']=10;tab['L']=50;tab['C']=100;tab['D']=500;tab['M']=1000;
    for(int i=0,n=0;s0[i];i++)
    {
        if(s0[i]!='('&&s0[i]!=')')s[n++]=s0[i];
        else if(s0[i]=='(')
        {
            while(s0[i]=='('){i++;tab[1]*=1000;}
            for(;s0[i]!=')';i++)
            {
                if(tab[s0[i]]<tab[s0[i+1]])ans-=tab[s0[i]];
                else ans+=tab[s0[i]];
            }
            tab[1]*=ans;
            s[n++]=1;
        }
    }

    ans=0;
    for(int i=0;s[i];i++)
    {
        if(tab[s[i]]<tab[s[i+1]])ans-=tab[s[i]];
        else ans+=tab[s[i]];
    }
    printf("%lld",ans);

}
