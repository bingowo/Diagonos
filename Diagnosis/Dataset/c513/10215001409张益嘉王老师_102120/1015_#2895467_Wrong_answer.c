#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readnum(char s[],int a[])
{
    int len,u,j=0,k;
    len=strlen(s);
    int st=0,en;
    for(u=0;u<len;u++)
    {
        if(u==len-1) a[j]=s[u]-'0';
        if(s[u]==',')
        {
            en=u;
            a[j]=0;
            for(k=st;k<en;k++)
            {
                a[j]*=10;
                a[j]+=(s[k]-'0');
            }
            //printf("1 a[%d]=%d\n",j,a[j]);
            st=en+1;
            j++;
        }
        else continue;
    }



}
void reverse(int a[])
{
    int u=0,co=0,m;
    while(a[u]!=-1)
    {
        co++;
        u++;
    }
    co--;
    for(u=0;u<co;u++,co--)
    {
        m=a[u];
        a[u]=a[co];
        a[co]=m;
    }

}

int main()
{
   int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       int len1,j,k,len2,jin=0,coa=0,cob=0,cha,x;
       char s1[60],s2[60];
       int a[31],b[31];
       memset(a,-1,sizeof(int)*30);
       memset(b,-1,sizeof(int)*30);
       int c[1000];
       memset(c,-1,sizeof(int)*1000);
       int sushu[27]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,93,97};
       /*for(j=0;j<27;j++)
       {
           printf("sushu[%d]=%d",j,sushu[j]);
       }*/
       //char s[1000]={0};
        scanf("%s%s",s1,s2);
        //printf("%s%s",s1,s2);
       len1=strlen(s1);
       len2=strlen(s2);
       //printf("%d%d",len1,len2);
       readnum(s1,a);
       readnum(s2,b);

       /*for(j=0;j<30;j++)
       {
           printf("1 a[%d]=%d\n",j,a[j]);
       }
       for(j=0;j<30;j++)
       {
           printf("2 b[%d]=%d\n",j,b[j]);
       }*/

       for(j=0;j<30;j++)
       {
           if(a[j]!=-1) coa++;
           else break;
       }
       for(j=0;j<30;j++)
       {
           if(b[j]!=-1) cob++;
           else break;
       }
       //printf("coa=%d cob=%d\n",coa,cob);
       if (coa>=cob)
       {
            int cha=coa-cob;
            for (j=coa-1,x=0;j>=cha;j--,x++)
            {
                c[x]=a[j]+b[j-cha]+jin;
                jin=c[x]/sushu[x];
                c[x]%=sushu[x];
            }
            for(j=cha-1;j>=0;j--,x++)
            {
                c[x]=a[j]+jin;
                jin=c[x]/sushu[x];
                c[x]%=sushu[x];
            }
            if(jin!=0) {c[x]=jin%sushu[x];x++;}

       }
       else
       {
           int cha=cob-coa;
            for (j=cob-1,x=0;j>=cha;j--,x++)
            {
                c[x]=b[j]+a[j-cha]+jin;
                jin=c[x]/sushu[x];
                c[x]%=sushu[x];
            }
            for(j=cha-1;j>=0;j--,x++)
            {
                c[x]=b[j]+jin;
                jin=c[x]/sushu[x];
                c[x]%=sushu[x];
            }
            if(jin!=0) {c[x]=jin%sushu[x];x++;}
       }
       int z=x-1;
        //printf("z=%d\n",z);
      /* for(j=0;j<=z;j++)
       {
           printf("3 c[%d]=%d\n",j,c[j]);
       }*/

       //reverse(a);
       //reverse(b);


       reverse(c);
       printf("case #%d:\n",i);
       for(j=0;j<z;j++)
       {
           printf("%d,",c[j]);

       }
       printf("%d\n",c[z]);
   }
   return 0;
}

