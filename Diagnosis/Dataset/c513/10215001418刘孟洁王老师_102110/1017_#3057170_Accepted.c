#include<stdio.h>
#include<string.h>
///switch分类的使用
int main()
{
    char s[1000];
    long long int data[1000],flag=1,ans=0;;
    int i,k;
    int rome[1000];
    scanf("%s",s);
    int l=strlen(s);
    rome['I']=1;rome['V']=5;rome['X']=10;
    rome['L']=50;rome['C']=100;rome['D']=500;rome['M']=1000;
    for(i=0,k=0;i<l;i++)
    {
        switch(s[i])
        {
            case'(':flag*=1000;break;
            case')':flag/=1000;break;
            default:data[k++]=rome[s[i]]*flag;break;
        }

    }
    for(i=0;i<k-1;i++)
    {
        if(data[i]<data[i+1]) ans-=data[i];
        else ans+=data[i];
    }
    ans+=data[k-1];
    printf("%lld",ans);
    return 0;
}
