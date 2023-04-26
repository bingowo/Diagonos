#include<stdio.h>
#include<string.h>
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
    while(b[cnt]!='.'&&a[cnt]>='0'&&a[cnt]<='9')
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
    /*for(int i=480;i<501;i++)
    {
        printf("%d",az[i]);
    }
    printf("\n");
    for(int i=480;i<501;i++)
    {
        printf("%d",bz[i]);
    }
    /*printf("\n%d  %d\n",ax[0],bx[0]);
    printf("\n");
    printf("%d %d\n",axlen,bxlen);*/
    int xlen;
    if(axlen>=bxlen)
    {
        xlen=axlen;
        for(int i=axlen;i>=1;i--)
        {
            int temp=ax[i]+bx[i];
            if(temp>=10) ax[i-1]++;
            ax[i]=temp%10;
        }
    }
    else
    {
        xlen=bxlen;
        for(int i=bxlen;i>=1;i--)
        {
            int temp=ax[i]+bx[i];
            if(temp>=10) ax[i-1]++;
            ax[i]=temp%10;
        }
    }
    int zlen;
    if(azlen>=bzlen)
    {
        zlen=azlen;
        for(int i=500;i>=0;i--)
        {
            int temp=az[i]+bz[i];
            if(temp>=10) az[i-1]++;
            az[i]=temp%10;
        }
    }
    else
    {
        zlen=bzlen;
        for(int i=500;i>=0;i--)
        {
            int temp=az[i]+bz[i];
            if(temp>=10) az[i-1]++;
            az[i]=temp%10;
        }
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
