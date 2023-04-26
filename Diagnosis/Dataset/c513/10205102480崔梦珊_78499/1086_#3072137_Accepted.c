#include<stdio.h>
#include<string.h>
void f(int* az,int* ax,int* bz,int* bx,int axlen,int bxlen,int azlen,int bzlen,int n,int xlen,int zlen)
{
    if(axlen>=bxlen)
    {
        xlen=axlen;
        for(int i=axlen;i>=1;i--)
        {
            int temp=ax[i]-bx[i];
            if(temp<0)
            {
                ax[i-1]--;
                ax[i]=10+temp;
            }
            else
            {
                ax[i]=temp;
            }

        }
    }
    else
    {
        xlen=bxlen;
        for(int i=bxlen;i>=1;i--)
        {
            int temp=ax[i]-bx[i];
            if(temp<0)
            {
                ax[i-1]--;
                ax[i]=10+temp;
            }
            else
            {
                ax[i]=temp;
            }
        }
    }
    if(ax[0]<0)
    {
        az[500]+=ax[0];
        ax[0]=0;
    }
    zlen=azlen;
    for(int i=500;i>=0;i--)
    {
        int temp=az[i]-bz[i];
        if(temp<0)
        {
            az[i-1]--;
            az[i]=10+temp;
        }
        else az[i]=temp;
        /*printf("%d\n",az[i]);*/
    }

    if(ax[n+1]>=5)
    {
        ax[n]++;
        for(int i=n;i>=0;i--)
        {
            if(ax[i]>=10)
            {
                ax[i-1]++;
                ax[i]=ax[i]%10;
            }
        }
    }
    if(ax[0]>0)
    {
        az[500]+=ax[0];
        for(int i=500;i>=0;i--)
        {
            if(az[i]>=10)
            {
                az[i-1]++;
                az[i]=az[i]%10;
            }
        }
    }

}
int main()
{
    char a[501]={0};
    char b[501]={0};
    int n;
    scanf("%s %s %d",a,b,&n);
    int alen=strlen(a);
    int blen=strlen(b);
    int apoint=0;
    int cnt=0;
    while(a[cnt]!='.'&&a[cnt]>='0'&&a[cnt]<='9')
    {
        cnt++;
    }
    apoint=cnt;
    int bpoint=0;
    cnt=0;
    while(b[cnt]!='.'&&b[cnt]>='0'&&b[cnt]<='9')
    {
        cnt++;
    }
    bpoint=cnt;
    int axlen=alen-apoint-1;
    int bxlen=blen-bpoint-1;
    int azlen=apoint;
    int bzlen=bpoint;
    /*printf("%d %d\n",apoint,bpoint);*/
    int az[501]={0};
    int ax[501]={0};
    int bz[501]={0};
    int bx[501]={0};//定义数组
    int xlen=0,zlen=0;
    int flag=0;
    for(int i=1;i<=alen;i++)
    {
        if(flag==0&&a[i-1]!='.')
        {
            az[500-azlen+i]=a[i-1]-'0';
            continue;
        }
        if(flag==0&&a[i-1]=='.')
        {
            flag=i+1;
            continue;
        }
        if(flag!=0)
        {
            ax[i-flag+1]=a[i-1]-'0';
            continue;
        }
    }
    flag=0;
    for(int i=1;i<=blen;i++)
    {
        if(flag==0&&b[i-1]!='.')
        {
            bz[500-bzlen+i]=b[i-1]-'0';
            continue;
        }
        if(flag==0&&b[i-1]=='.')
        {
            flag=i+1;
            continue;
        }
        if(flag!=0)
        {
            bx[i-flag+1]=b[i-1]-'0';
            continue;
        }
    }
    flag=1;
    for(int i=0;i<=500;i++)
    {
        if(az[i]>bz[i])
        {
            flag=1;
            break;
        }
        if(az[i]<bz[i])
        {
            flag=-1;
            break;
        }
        if(az[i]==bz[i])
        {
            flag=0;
        }
    }
    if(flag==0)
    {
         for(int i=0;i<=500;i++)
        {
            if(ax[i]>bx[i])
            {
                flag=1;
                break;
            }
            if(ax[i]<bx[i])
            {
                flag=-1;
                break;
            }
            if(ax[i]==bx[i])
            {
                flag=0;
            }
        }
    }/*比较大小结束******************************************/
    if(flag==0)
    {
        printf("0.");
        for(int i=0;i<n;i++)
        {
            printf("0");
        }
        return 0;
    }
    if(flag==1)
    {
        f(az,ax,bz,bx,axlen,bxlen,azlen,bzlen,n,xlen,zlen);
        flag=0;
    if(az[0]!=0)
    {
        zlen++;
        for(int i=0;i<zlen;i++)
        {
            if(flag==0&&az[i]==0) continue;
            if(flag==0&&az[i]!=0)
            {
                flag=1;
                printf("%d",az[i]);
                continue;
            }
            if(flag!=0) printf("%d",az[i]);
        }
    }
    else
    {
        for(int i=0;i<=500;i++)
        {
            if(flag==0&&az[i]==0) continue;
            if(flag==0&&az[i]!=0)
            {
                flag=1;
                printf("%d",az[i]);
                continue;
            }
            if(flag!=0) printf("%d",az[i]);
        }
    }
    if(flag==0) printf("0.");
    else printf(".");
    if(ax[0]!=0)
    {
        xlen++;
        for(int i=1;i<=n;i++)
        {
            printf("%d",ax[i]);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ax[i]);
        }
    }
    }
    if(flag==-1)
    {
        f(bz,bx,az,ax,bxlen,axlen,bzlen,azlen,n,xlen,zlen);
        printf("-");
        flag=0;
    if(bz[0]!=0)
    {
        zlen++;
        for(int i=0;i<zlen;i++)
        {
            if(flag==0&&bz[i]==0) continue;
            if(flag==0&&bz[i]!=0)
            {
                flag=1;
                printf("%d",bz[i]);
                continue;
            }
            if(flag!=0) printf("%d",bz[i]);
        }
    }
    else
    {
        for(int i=0;i<=500;i++)
        {
            if(flag==0&&bz[i]==0) continue;
            if(flag==0&&bz[i]!=0)
            {
                flag=1;
                printf("%d",bz[i]);
                continue;
            }
            if(flag!=0) printf("%d",bz[i]);
        }
    }
    if(flag==0) printf("0.");
    else printf(".");
    if(bx[0]!=0)
    {
        xlen++;
        for(int i=1;i<=n;i++)
        {
            printf("%d",bx[i]);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",bx[i]);
        }
    }
    }/***************************************/





}

