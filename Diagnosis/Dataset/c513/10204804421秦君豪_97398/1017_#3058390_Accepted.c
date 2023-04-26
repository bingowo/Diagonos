#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef long long int lli;






int main()
{
    lli roman[148];
    roman['I']=1;roman['X']=10;roman['V']=5;
    roman['L']=50;roman['C']=100;roman['D']=500;roman['M']=1000;

    char* s=(char*)malloc(sizeof(char)*51);
    scanf("%s",s);

    lli data[51];
    int cnt=0;
    lli flag=1;
    for(int i=0;s[i];i++)
    {
        switch(s[i])
        {
            case'(':flag=flag*1000;break;
            case')':flag=flag/1000;break;
            default:data[cnt++]=flag*roman[s[i]];break;
        }
    }

    lli ans=0;
    for(int i=0;i<cnt-1;i++)
    {
        if(data[i]<data[i+1]) ans-=data[i];
        else ans+=data[i];
    }
    ans+=data[cnt-1];
    printf("%lld\n",ans);
    free(s);
    return 0;
}
