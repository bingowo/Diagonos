#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[55];
    long long z[51]={0},re=0,flag=1;
    int i,len,j,num;
    int a[128]={0};
    scanf("%s",s);
    len=strlen(s);
    a['I']=1;
    a['V']=5;
    a['X']=10;
    a['L']=50;
    a['C']=100;
    a['D']=500;
    a['M']=1000;
    for(i=0,j=0;i<len;i++)
    {
        switch(s[i])
        {
           case '(':flag*=1000;break;
           case ')':flag/=1000;break;
           default:z[j]=a[s[i]]*flag;j++;break;
        }

    }
    num=j;
    //printf("num=%d\n",num);
    for(i=0;i<num-1;i++)
    {
        if (z[i]<z[i+1]) z[i]=-z[i];
    }
    /*for(i=0;i<num;i++)
    {
        printf("test :z[%d]=%lld\n",i,z[i]);
    }*/
    for(i=0;i<num;i++)
    {
        re+=z[i];
    }
    printf("%lld",re);
    return 0;

}
