#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    void plus(int *a,int *b,int n1,int n2,int *out,int *cnt);
    int m;
    char h;
    scanf("%d",&m);
    for(int s=0;s<m;s++)
    {
        int n1=0,n2=0,i=0,cnt1=0,cnt2=0;
        int cnt=0;
        int ans[31]={0};
        int s1[25]={0},s2[25]={0};
        do{
            scanf("%d%c",s1+i,&h);
            i++;
            cnt1++;
        }while(h!=' ');
        i=0;
        do{
            scanf("%d%c",s2+i,&h);
            i++;
            cnt2++;
        }while(h!='\n');
        k(s1,cnt1);
        k(s2,cnt2);
        plusz(s1,s2,cnt1,cnt2,ans);
        printf("case #%d:\n",s);
        for(int g=ans[30];g>=0;g--)
        {
            if(g!=0) printf("%d,",ans[g]);
            else printf("%d",ans[g]);
        }

}
return 0;
}
void plusz(int *a,int *b,int n1,int n2,int *out)
{
    int num[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int i=0,j=0;
    while(j<n1||j<n2)
    {
        if((a[j]+b[j])>num[i])
            {out[j]+=(a[j]+b[j])%num[i]; out[j+1]+=(a[j]+b[j])/num[i];}
        else if((a[j]+b[j])==num[i])
            {out[j]=0;out[j+1]+=1;}
        else out[j]=a[j]+b[j];
        j++;i++;
    }
        out[30]=j;
}

void k(int *a,int n)
{
    int i=0,j=n-1,temp;
    for(;i<j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}