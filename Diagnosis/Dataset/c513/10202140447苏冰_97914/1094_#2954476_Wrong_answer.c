#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[55][125];
typedef struct{int cnt,v[130];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
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
    if(len1!=len2)
    {
        return len1-len2;
    }
    return strcmp(s,t);
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
   for(int i=1;i<n;i++)
   {
        int x=cmp(a,s[i]);
        if(x<0)
        {
            strcpy(a,s[i]);len1=strlen(s[i]);
        }
        int y=cmp(b,s[i]);
        if(y>=0)
        {
            strcpy(b,s[i]);len2=strlen(s[i]);
        }
   }
   //printf("%s %s",a,b);
   //printf("%d %d",len1,len2);
   BIGINT A={0,{0}},B={0,{0}};
   for(int i=len1-1;i>=0;i--) A.v[A.cnt++]=a[i]-'0';
   for(int i=len2-1;i>=0;i--) B.v[B.cnt++]=b[i]-'0';
   BIGINT ANS=DEL(A,B);
   for(int i=ANS.cnt;i>=0;i--) printf("%d",ANS.v[i]);
   return 0;
}
