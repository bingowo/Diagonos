#include<stdio.h>
#include<string.h>

//转化为-2进制
void re(int a,char s[])
{
    int i=0,l=0;
    char t;
    while(a)
    {
        s[i++]=a%(-2)+'0';
        a/=-2;
    }
    l=strlen(s);
    for(i=0;i<=(l-1)/2;i++)
    {
        t=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=t;
    }
}

int main()
{
    int R,N,ln=0,lr=0,i=0,j=0,k=0,d=0;
    scanf("%d -%d",&N,&R);
    char sn[100000000]={0},sr[100000]={0},s[100000000]={0};
    re(N,sn);
    re(R,sr);
    ln=strlen(sn);
    lr=strlen(sr);
    k=ln/lr;
    for(j=0;j<k;j++)
    {
        for(i=j*lr;i<j*lr+lr;i++)
       {
           d=d*(-2)+sn[i]-'0';
       }
       if(d>=0&&d<10) s[j]=d+'0';
       else if(d==11) s[j]='A';
       else if(d==12) s[j]='B';
       else if(d==13) s[j]='C';
       else if(d==14) s[j]='D';
       else if(d==15) s[j]='E';
       else if(d==16) s[j]='F';
       else if(d==17) s[j]='G';
       else if(d==18) s[j]='H';
       else if(d==19) s[j]='I';
       else if(d==20) s[j]='J';
    }
    if(ln%lr==0) printf("%s",s);
    else
    {
       d=0;j++;
       for(i=k*lr;i<ln;i++)
            d=d*(-2)+sn[i]-'0';
       if(d>=0&&d<10) s[j]=d+'0';
       else if(d==11) s[j]='A';
       else if(d==12) s[j]='B';
       else if(d==13) s[j]='C';
       else if(d==14) s[j]='D';
       else if(d==15) s[j]='E';
       else if(d==16) s[j]='F';
       else if(d==17) s[j]='G';
       else if(d==18) s[j]='H';
       else if(d==19) s[j]='I';
       else if(d==20) s[j]='J';
       printf("%s",s);
    }
    return 0;
}
