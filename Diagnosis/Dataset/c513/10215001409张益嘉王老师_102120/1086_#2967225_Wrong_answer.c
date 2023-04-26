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

int xiaojian(int *a,int *b,int la,int lb,int re[])
{
    int i,j,k,en,wei,l;
    int jie=0;
    if(la>=lb) l=la;
    else l=lb;
    for(i=l-1;i>=0;i--)
    {
        if(a[i]>=b[i]) re[i]=a[i]-b[i];
        else
        {
            for(j=i;j>0;j--)
            {
                if(a[j-1]>0) {en=j-1;a[j-1]--;break;}
            }
            if(j==0) {jie=1;en=1;}
            for(k=en-1;k<i;k++)
            {
                a[k]+=9;
            }
            a[i]+=10;
            re[i]=a[i]-b[i];
        }
    }
    return jie;
}

int cmp(int *azheng,int*bzheng,int*axiao,int* bxiao, int laz,int lbz,int lax,int lbx)
{
    int i;
    if(laz>lbz) return 1;
    else if(laz<lbz) return -1;
    else
    {
        for(i=0;i<laz;i++)
        {
            if(azheng[i]>bzheng[i]) return 1;
            else if(azheng[i]<bzheng[i]) return -1;
        }
        for(i=0;(i<lax)||(i<lbx);i++)
        {
            if(axiao[i]>bxiao[i]) return 1;
            else if(axiao[i]<bxiao[i]) return -1;
        }
        return 0;
    }
}

int zhengjian(int *a,int la,int* b,int lb,int* re,int jin)
{
    reverse(a,la);
    reverse(b,lb);
    int i,j,k,en,wei;
    for(i=0;i<la;i++)
    {
        if(a[i]>=b[i]) re[i]=a[i]-b[i];
        else
        {
            for(j=i;j<la;j++)
            {
                if(a[j+1]>0) {en=j+1;a[j+1]--;break;}
            }
            for(k=en-1;k>i;k--)
            {
                a[k]+=9;
            }
            a[i]+=10;
            re[i]=a[i]-b[i];
        }
        //printf("test:re[%d]=%d\n",i,re[i]);
    }
    wei=la;
    if(jin<0)
    {
        jin=abs(jin);
        if(re[0]>=jin) re[0]=re[0]-jin;
        else
        {
            for(j=0;j<wei;j++)
            {
                if(re[j+1]>0) {en=j+1;re[j+1]--;break;}
            }
            for(k=en-1;k>0;k--)
            {
                re[k]+=9;
            }
            re[0]+=10;
            re[0]=re[0]-jin;
            //printf("test:re[%d]=%d\n",i,re[i]);
        }
    }
    else if(jin>0)
    {
        for(i=0;(jin!=0)||(i<wei);i++)
        {
            int mid=re[i]+jin;
            jin=mid/10;
            re[i]=mid%10;
            //printf("%d",z[i]);
        }
    }

    reverse(re,wei);
    return wei;

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

    int jud=cmp(azheng,bzheng,axiao,bxiao,laz,lbz,lax,lbx),zhengshuwei;

    //printf("test:laz=%d,lbz=%d,lax=%d,lbx=%d\n",laz,lbz,lax,lbx);
    if(jud==1)
    {
        int flag=1;
        int jie=xiaojian(axiao,bxiao,lax,lbx,x);
        int ru=sishewuru(x,n);
        int jin=ru-jie;
        zhengshuwei=zhengjian(azheng,laz,bzheng,lbz,z,jin);
    }
    else if(jud==-1)
    {
        int flag=-1;
        int jie=xiaojian(bxiao,axiao,lbx,lax,x);
        int ru=sishewuru(x,n);
        int jin=ru-jie;
        zhengshuwei=zhengjian(bzheng,lbz,azheng,laz,z,jin);
    }
    if(jud)
    {
        if(jud==-1) printf("-");
        for(i=0;i<zhengshuwei;i++)
        {
            if(z[i]!=0) break;
        }
        int qi;
        if(i==zhengshuwei) qi=i-1;
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
    }
    else
    {
        printf("0");
        if(n) printf(".");
        for(i=0;i<n;i++)
        {
            printf("0");
        }
    }

    return 0;


}
