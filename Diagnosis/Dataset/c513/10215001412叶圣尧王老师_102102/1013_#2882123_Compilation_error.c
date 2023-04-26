#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char str1[30],str2[30];int i,j,k,len;long long num=0,B=1,C=0;int dot;
    scanf("%s",str1);
    dot=strchr(str1,'.')-str1+1;
    if(strchr(str1,'.')==NULL){
    for(i=0;i<strlen(str1);i++)
    {
        if(str1[i]=='2')k=-1;
        else k=str1[i]-'0';
        num=num*3+k;
    }printf("%lld",num);}
    else
    {
        len=dot;num=0;
        for(i=0;i<len-1;i++)
        {
            if(str1[i]=='2')k=-1;
            else k=str1[i]-'0';
            num=num*3+k;
        }
        for(j=dot;j<strlen(str1);j++)
        {
            if(str1[j]=='2')k=-1;
            else k=str1[j]-'0';
            B=B*3;C=3*C+k;
        }if(num>0&&C<0){num=num-1;C=B+C;}
        else(num<0&&C>0){num=num+1;C=abs(B-C);}
        printf("%lld %lld %lld",num,C,B);
    }
}
