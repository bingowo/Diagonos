#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int zi;
    int mu;
    char s[25];
}fenshu;

int stoi(char *x)
{
    int i,len=strlen(x),mid,re=0;
    for(i=0;i<len;i++)
    {
        re*=10;
        mid=x[i]-'0';
        re+=mid;
    }
    return re;
}

int quzi(char* x)
{
    int i,re,len=strlen(x);
    char s[20];
    for(i=0;i<len;i++)
    {
        if(x[i]=='/') break;
        s[i]=x[i];
    }
    s[i]=0;
    re=stoi(s);
    return re;
}

int qumu(char* x)
{
    
    int j,i,re,len=strlen(x);
    char s[20];
    for(i=0;i<len;i++)
    {
        if(x[i]=='/') break;
    }
    int mid=i+1;
    for(i=mid,j=0;i<len;i++,j++)
    {
        s[j]=x[i];
    }
    s[j]=0;
    re=stoi(s);
    return re;
}

int maxyue(int a,int b)
{
    if((a==0)||(b==0)) return 0;
    else if(a==b) return a;
    else if(a>b)
    {
        if(a%b==0) return b;
        else return maxyue(b,a%b);
    }
    else return maxyue(b,a);
}

int minbei(int a,int b)
{
    long long c=a*b;
    return c/maxyue(a,b);
}

fenshu jia(fenshu a,fenshu b)
{
    int z,m;
    fenshu re;
    re.mu=minbei(a.mu,b.mu);
    a.zi*=(re.mu/a.mu);
    b.zi*=(re.mu/b.mu);
    re.zi=a.zi+b.zi;
    int mid=maxyue(re.zi,re.mu);

    re.zi/=mid;
    re.mu/=mid;
    return re;

}

int main()
{
   int n,i;
   scanf("%d",&n);
   fenshu a[102];
   //memset(a,0,sizeof(fenshu)*102);
   for(i=0;i<n;i++)
   {
        scanf("%s",a[i].s);
        a[i].zi=quzi(a[i].s);
        a[i].mu=qumu(a[i].s);
        /*printf("case#%d:\n",i);
        printf("zi=%d\n",a[i].zi);
        printf("mu=%d\n",a[i].mu);*/
   }
   fenshu re;
   for(i=0;i<n;i++)
   {
       if((a[i].zi!=0)&&(a[i].mu!=0)) break;
   }
   re.zi=a[i].zi;
   re.mu=a[i].mu;
   int mid=i+1;
   for(i=mid;i<n;i++)
   {
       if((a[i].zi==0)||(a[i].mu==0)) continue;
       re=jia(re,a[i]);
       //printf("test[%d]=%d/%d",i,re.zi,re.mu);
   }
   printf("%d/%d",re.zi,re.mu);



}
