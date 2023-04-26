#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int re[],int wei)
{
    int i;
    for(i=0;i<wei/2;i++)
    {
        int m;
        m=re[i];
        re[i]=re[wei-1-i];
        re[wei-1-i]=m;
    }
}

int xiaojia(int a[],int b[],int lena,int lenb,int x[])
{
    int jin=0,len,i,j=0;
    if(lena>=lenb) len=lena;
    else len=lenb;
    for(i=len-1;i>=0;i--)
    {
        x[i]=(a[i]+b[i]+jin)%10;
        jin=(a[i]+b[i]+jin)/10;
    }
    //printf("test:jin=%d\n",jin);
    return jin;
}

int zhengjia(int az[],int bz[],int laz,int lbz,int z[],int jin)
{
    reverse(az,laz);
    reverse(bz,lbz);
    int i;
    //printf("test:");
    for(i=0;(jin!=0)||(i<laz)||(i<lbz);i++)
    {
        int mid=az[i]+bz[i]+jin;
        jin=mid/10;
        z[i]=mid%10;
        //printf("%d",z[i]);
    }
    //printf("\n");
    reverse(z,i);
    return i;
}

int sishewuru(int x[],int n)
{
    int i,ru;
    if(x[n]>=5) ru=1;
    else ru=0;
    for(i=n-1;i>=0;i--)
    {
        int mid=x[i]+ru;
        x[i]=mid%10;
        ru=mid/10;
    }
    return ru;
}
int main()
{
    char a[600],b[600];
    int n,i,j=0,lax,lbx,laz,lbz,st;
    scanf("%s%s%d",a,b,&n);
    int axiao[510],bxiao[510],azheng[510],bzheng[510],x[510],z[510];
    memset(axiao,0,sizeof(int)*510);
    memset(bxiao,0,sizeof(int)*510);
    memset(azheng,0,sizeof(int)*510);
    memset(bzheng,0,sizeof(int)*510);
    memset(z,0,sizeof(int)*510);
    memset(x,0,sizeof(int)*510);
    int alen=strlen(a),blen=strlen(b);
    for(i=0;i<alen;i++)
    {
        if(a[i]=='.') break;
        azheng[j++]=a[i]-'0';
    }
    if(j==0) laz=1;
    else laz=j;
    st=i+1;
    j=0;
    for(i=st;i<alen;i++)
    {
        axiao[j++]=a[i]-'0';
    }
    if(j==0) lax=1;
    else lax=j;
    j=0;

    for(i=0;i<blen;i++)
    {
        if(b[i]=='.') break;
        bzheng[j++]=b[i]-'0';
    }
    st=i+1;
    if(j==0) lbz=1;
    else lbz=j;
    j=0;
    for(i=st;i<blen;i++)
    {
        bxiao[j++]=b[i]-'0';
    }
    if(j==0) lbx=1;
    else lbx=j;

    //printf("test:laz=%d,lbz=%d,lax=%d,lbx=%d\n",laz,lbz,lax,lbx);
    int jin=xiaojia(axiao,bxiao,lax,lbx,x);
    int ru=sishewuru(x,n);
    jin+=ru;
    int zhengshuwei=zhengjia(azheng,bzheng,laz,lbz,z,jin);

    for(i=0;i<zhengshuwei;i++)
    {
        if(z[i]!=0) break;
    }
    int qi;
    if(zhengshuwei==1) qi=0;
    else qi=i;
    for(i=qi;i<zhengshuwei;i++)
    {
        printf("%d",z[i]);
    }
    if(n) printf(".");
    for(i=0;i<n;i++)
    {
        printf("%d",x[i]);
    }
    return 0;


}