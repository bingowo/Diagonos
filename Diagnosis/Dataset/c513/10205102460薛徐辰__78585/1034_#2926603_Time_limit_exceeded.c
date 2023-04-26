#include<stdio.h>

void dsort(char* c,double* num,int m)
{
    for(int i=0;i<m-1;i++)
    {
        char tc=c[i],tcm=c[i];
        int tmax,nmax=i;
        if(tc>='A'&&tc<='Z')tmax=c[i]-'A';
        else tmax=c[i]-'a';
        for(int j=i+1;j<m;j++)
        {
            int t1;
            if(c[j]>='A'&&c[j]<='Z')t1=c[j]-'A';
            else t1=c[j]-'a';
            if(num[t1]>num[tmax]){nmax=j;tmax=t1;tcm=c[j];}
            else if(num[t1]=num[tmax]&&tcm<c[j]){nmax=j;tcm=c[j];}
        }
        if(nmax!=i){c[i]=tcm;c[nmax]=tc;}
    }
}

void solve(int k)
{
    double num[26];char c[100];int m=0;
    for(int i=0;i<26;i++)scanf("%lf",&num[i]);
    while(scanf("%c",&c[m])!='\n')m++;
    printf("case#%d:\n",k);
    for(int i=0;i<m,i++;)printf("%c",c[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)solve(i);
}