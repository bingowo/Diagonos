#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char c[100];
    int n[100];
    int sum;
}pair;
pair p[1000];
void f(char s[],int x)
{
    int i,l,n;
    l=strlen(s);
    p[x].c[0]=s[0];
    p[x].n[0]=1;
    n=1;
    for(i=1;i<l;i++){
        if(s[i]==s[i-1])
            p[x].n[n-1]++;
        else{
            p[x].c[n]=s[i];
            p[x].n[n]=1;
            n++;
        }
    }
    p[x].sum=n;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    char s[1000][101];
    char s0[101],s1[101];
    int n0[1000];
    int n,i,j,t,p0,ans;
    scanf("%d",&n);
    t=1;
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
        f(s[i],i);
        if(i==0){
            for(j=0;j<p[0].sum;j++)
                s0[j]=p[0].c[j];
            s0[j]=0;
        }
        else{
            for(j=0;j<p[i].sum;j++)
                s1[j]=p[i].c[j];
            s1[j]=0;
            if(strcmp(s0,s1)!=0)
                t=0;
        }
    }
    if(t==0)
        printf("-1\n");
    else{
        ans=0;
        p0=p[0].sum;
        for(j=0;j<p0;j++){
            for(i=0;i<n;i++)
                n0[i]=p[i].n[j];
            qsort(n0,n,sizeof(n0[0]),cmp);
            for(i=0;i<n;i++)
                ans=ans+abs(n0[i]-n0[n/2]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
