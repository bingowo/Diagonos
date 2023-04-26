#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"


int main()
{
    char s[100]="";
    long long tab['Z'],ans=0;
    scanf("%s",s);
    tab[0]=0;tab['I']=1;tab['V']=5;tab['X']=10;tab['L']=50;tab['C']=100;tab['D']=500;tab['M']=1000;
    for(int i=0;s[i];i++)
    {
        if(tab[s[i]]<tab[s[i+1]])ans-=tab[s[i]];
        else ans+=tab[s[i]];
    }
    printf("%lld",ans);

}
