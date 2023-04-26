#include <stdio.h>
#include <string.h>

int sjz[3]={0,1,-1};
long long a,b,c;
void zs(int x[],int l)
{
    int i,n;
    n=1;
    a=0;
    for(i=l-1;i>=0;i--){
        a=a+n*sjz[x[i]];
        n=n*3;
    }
}
void xs(int x[],int l)
{
    int i;
    b=0;
    c=1;
    for(i=0;i<l;i++){
        b=b*3+sjz[x[i]];
        c=c*3;
    }
}
int main()
{
    int i,j,l0;
    char s[30];
    int a1[30],a2[30];
    scanf("%s",s);
    l0=strlen(s);
    i=0;
    while(s[i]!='.' && i<l0){
        a1[i]=s[i]-'0';
        i++;
    }
    zs(a1,i);
    if(i==l0)
        printf("%lld\n",a);
    else{
        i++;
        j=0;
        while(i<l0){
            a2[j]=s[i]-'0';
            i++;
            j++;
        }
        xs(a2,j);
        if(a>0 && b<0){
            a=a-1;
            b=b+c;
        }
        else if(a<0 && b>0){
            a=a+1;
            b=c-b;
        }
        if(a==0)
            if(b==0)
                printf("0\n");
            else
                printf("%lld %lld\n",b,c);
        else if(b==0)
            printf("%lld\n",a);
        else
            printf("%lld %lld %lld\n",a,b,c);
    }
    return 0;
}