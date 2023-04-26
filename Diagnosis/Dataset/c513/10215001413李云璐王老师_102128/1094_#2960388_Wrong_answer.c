#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void fz(int*a,int k)
{
    for(int i=0;i<k/2;i++)
    {
        int c;
        c=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=c;
    }
}
int cmp(const void*a1,const void*a2)
{
    char*a=(char*)a1;
    char*b=(char*)a2;
    int len1=strlen(a),len2=strlen(b);
    if(a[0]!='-'&&b[0]!='-')
    {
    if(len1!=len2) return len1-len2;
    else return strcmp(a,b);}
    if(a[0]=='-'&&b[0]!='-') return -1;
    if(a[0]!='-'&&b[0]=='-') return 1;
    if(a[0]=='-'&&b[0]=='-')
     {if(len1!=len2) return len2-len1;
    else return strcmp(b,a);}

}
int main()
{
    int n;
    scanf("%d",&n);
    char s[51][130];
    for(int i=0;i<n;i++)
    scanf("%s",s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    int len1=strlen(s[n-1]),len2=strlen(s[0]);
    int a[130]={0},b[130]={0},c[130]={0};
    int max;
    if(s[n-1][0]!='-'&&s[0][0]!='-')
    {
        for(int i=0;i<len1;i++)
        a[i]=s[n-1][i]-'0';
        for(int i=0;i<len2;i++)
        b[i]=s[0][i]-'0';
        max=(len1>len2)?len1:len2;
        fz(a,len1);fz(b,len2);
        int jie=0;
        for(int i=0;i<max;i++)
        {
            c[i]=a[i]-b[i]-jie;
            if(c[i]<0) {c[i]+=10;jie=1;}
            else jie=0;
        }
        fz(c,max);
     }
     if(s[n-1][0]=='-'&&s[0][0]=='-')
     {
         for(int i=1;i<len2;i++)
         a[i-1]=s[0][i]-'0';
         for(int i=1;i<len1;i++)
         b[i-1]=s[n-1][i]-'0';
         len1--;len2--;
        max=(len1>len2)?len1:len2;
        fz(a,len1);fz(b,len2);
        int jie=0;
        for(int i=0;i<max;i++)
        {
            c[i]=a[i]-b[i]-jie;
            if(c[i]<0) {c[i]+=10;jie=1;}
            else jie=0;
        }
        fz(c,max);
     }
     if(s[n-1][0]!='-'&&s[0][0]=='-')
     {
         for(int i=0;i<len1;i++)
         a[i]=s[n-1][i]-'0';
         for(int i=1;i<len2;i++)
         b[i-1]=s[0][i]-'0';
         len2--;
         fz(a,len1);fz(b,len2);
         int yu=0;
         max=(len1>len2)?len1:len2;
         for(int i=0;i<max;i++)
         {
             c[i]=(a[i]+b[i]+yu)%10;
             yu=(a[i]+b[i])/10;
         }
         if(yu>0) {c[max]=yu;max++;}
         fz(c,max);
     }
    
    for(int i=0;i<max;i++)
    printf("%d",c[i]);
    return 0;


}
