#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[55][125];
int flag1=0,flag2=0;
typedef struct{int cnt,v[130];}BIGINT;
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt && i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp =S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp =T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry) R.v[i++]=carry%10;
    for(i=i-1;R.v[i]==0;i--);
    R.cnt=i;
    return R;
}
BIGINT DEL(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i=0;
    for(i=0;i<T.cnt;i++)
    {
        if(S.v[i]<T.v[i])
        {
            S.v[i]+=10;
            S.v[i+1]--;
        }
        R.v[i]=S.v[i]-T.v[i];
    }
    while(i<S.cnt)
    {
        R.v[i]=S.v[i];i++;
    }
    for(i=i-1;R.v[i]==0;i--);
    R.cnt=i;
    return R;
}
int cmp(char s[],char t[])
{
    int len1=strlen(s);
    int len2=strlen(t);
    flag1=0;flag2=0;
    if(s[0]=='-')
    {
        flag1=1;len1--;
    }
    if(t[0]=='-')
    {
        flag2=1;len2--;
    }
    if(flag1==1 && flag2==0) return -1;
    if(flag1==0 && flag2==1) return 1;
    if(flag1==0 && flag2==0)
    {
        if(len1!=len2) return len1-len2;
        return strcmp(s,t);
    }
    if(flag1==1 && flag2==1)
    {
        if(len1!=len2) return len2-len1;
        return strcmp(t,s);
    }
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%s",s[i]);
   }
   char a[125]={},b[125]={};
   strcpy(a,s[0]);strcpy(b,s[0]);
   int len1=strlen(a),len2=strlen(b);
   int sign1,sign2;
   if(s[0][0]=='-')
   {
       sign1=1;sign2=1;
   }
   else
   {
       sign1=0;sign2=0;
   }
   for(int i=1;i<n;i++)
   {
        int x=cmp(a,s[i]);sign1=flag1;
        if(x<0)
        {
            strcpy(a,s[i]);len1=strlen(s[i]);
            sign1=flag2;
        }
        int y=cmp(b,s[i]);sign2=flag1;
        if(y>=0)
        {
            strcpy(b,s[i]);len2=strlen(s[i]);
            sign2=flag2;
        }
   }
   BIGINT A={0,{0}},B={0,{0}};
   BIGINT ANS={0,{0}};
   if(sign1==0 && sign2==0)
   {
       for(int i=len1-1;i>=0;i--) A.v[A.cnt++]=a[i]-'0';
       for(int i=len2-1;i>=0;i--) B.v[B.cnt++]=b[i]-'0';
       ANS=DEL(A,B);
   }
   else if(sign1==1 && sign2==1)
   {
        for(int i=len1-1;i>=1;i--) A.v[A.cnt++]=a[i]-'0';
        for(int i=len2-1;i>=1;i--) B.v[B.cnt++]=b[i]-'0';
        ANS=DEL(A,B);
   }
   else if(sign1==1 && sign2==0)
   {
       for(int i=len1-1;i>=1;i--) A.v[A.cnt++]=a[i]-'0';
       for(int i=len2-1;i>=0;i--) B.v[B.cnt++]=b[i]-'0';
       ANS=ADD(A,B);
   }
   else if(sign1==0 && sign2==1)
   {
       for(int i=len1-1;i>=0;i--) A.v[A.cnt++]=a[i]-'0';
       for(int i=len2-1;i>=1;i--) B.v[B.cnt++]=b[i]-'0';
       ANS=ADD(A,B);
   }
   for(int i=ANS.cnt;i>=0;i--) printf("%d",ANS.v[i]);
   return 0;
}
