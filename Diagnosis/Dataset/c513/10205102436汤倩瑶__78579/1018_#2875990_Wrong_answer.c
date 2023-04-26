#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bigint{
int t[100];
int cnt;
}BIGINT;
BIGINT inttobigint(int x)
{

    BIGINT ans;
    for(int i=0;i<100;i++)
    {
        ans.t[i]=0;
    }
if(x==0){
    ans.cnt=1;}
else{
    int c=0;

    while(x!=0)
    {
        ans.t[c++]=x%10;
        x=x/10;
    }
    ans.cnt=c;
    }
    return ans;

}
BIGINT add(BIGINT a,BIGINT b)
{  BIGINT ans=inttobigint(0);
    int carry=0;
    int max=a.cnt>b.cnt?a.cnt:b.cnt;
    for(int i=0;i<max;i++){
        ans.t[i]=(a.t[i]+b.t[i]+carry)%10;
        carry=(a.t[i]+b.t[i]+carry)/10;
    }

    if(carry>0)ans.t[max++]=carry;
    ans.cnt=max;
    return ans;
}
BIGINT mul(BIGINT a,BIGINT b)
{  BIGINT ans=inttobigint(0);
int carry=0;
for(int i=0;i<a.cnt;i++)
{

    for(int j=0;j<b.cnt;j++)

    {int temp=ans.t[i+j];
        ans.t[i+j]=(a.t[i]*b.t[j]+temp+carry)%10;
carry=(a.t[i]*b.t[j]+temp+carry)/10;
    }

}
/*99*2=198
 18
18*/


//printf("%d\n",carry);
ans.cnt=b.cnt+a.cnt-1;ans.t[ans.cnt++]=carry;

return ans;
/*    12*2=24
    12*211=
     12
    12
   24*/
}
int main()
{
 int a[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91};
int b[26];

int cnt=0;
char s[30];
scanf("%s",s);
int l=strlen(s);
int tmp=0;

for(int i=0;i<=l;i++)
{

    if(s[i]>='0'&&s[i]<='9')
    {
        tmp=10*tmp+s[i]-'0';
    }
    else {b[cnt++]=tmp;tmp=0;}

}
BIGINT temp;
BIGINT p=inttobigint(1);
BIGINT ANS=inttobigint(0);
for(int i=0;i<cnt;i++)
{
    p=mul(p,inttobigint(a[i]));
    temp=mul(inttobigint(b[cnt-i-1]),p);

    ANS=add(ANS,temp);
}

//BIGINT ANS=mul(inttobigint(2000),inttobigint(99));
for(int i=ANS.cnt-1;i>=0;i--)
    printf("%d",ANS.t[i]);
//printf(":%d",p);

}
