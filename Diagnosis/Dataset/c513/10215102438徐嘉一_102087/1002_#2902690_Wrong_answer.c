#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void judge(char* keych,char* key )
{
    keych[0]=key[0];
    int i,j=0,k=0,flag;
    for(i=0;key[i]!='\0';i++)
    {
        flag=1;
        for(k=0;k<j+1;k++)
        {
            if(key[i]==keych[k])
                flag=0;
        }
        if(flag)
        {
            j=j+1;keych[j]=key[i];
        }
    }
    keych[j+1]='\0';
}
long long int tran(char str[],int i)
{
    int k,j,l,a[61],c;long long sum=0;char m[128];
    judge(m,str);
    if(sizeof(m)==2)
    {
        for(int n=0,c=i;n<i;n++,c--)
        {
            sum+=str[n]*(int)pow(2,(double)c-1);
        }
    }
    else
    {
        if(i==1) return 1;
        else if(i==2) return 2;
        else
        {
            a[0]=1;a[1]=0;
            sum=(int)pow((double)i,i-1);
            for(k=2,l=i-2;k<i;k++,l--)
            {
                a[k]=k;sum+=a[k]*(int)pow((double)i,(double)l-1);
            }
        }
    }
    return sum;

}
int main()
{
    int i,n,a;char str[61];long long sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        a=strlen(str);
        printf("case #%d:\n",i);
        sum=tran(str,a);
        printf("%lld\n",sum);
    }
    return 0;
}
