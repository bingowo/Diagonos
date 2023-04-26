#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int wei;
    int shu[1100];
    int sign;
}bigint;

typedef struct
{
    bigint shibu;
    bigint xubu;
}fushu;

//fushu r0;

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

int find0(bigint a)
{
    int i;
    for(i=0;i<a.wei;i++)
    {
        if(a.shu[i]!=0) return 0;
    }
    return 1;
}

int jud (bigint a,bigint b)
{
    int i;
    if(a.wei>b.wei) return 1;
    else if(a.wei<b.wei) return 0;
    else
    {
        for(i=a.wei-1;i>=0;i--)
        {
            if(a.shu[i]>b.shu[i]) return 1;
            else if (a.shu[i]<b.shu[i]) return 0;
        }
        return 1;
    }
}

bigint jianpu(bigint a,bigint b)
{
    bigint re;
    int j,i;
    re.sign=1;
    memset(re.shu,0,sizeof(int)*1100);
    for(i=0;(i<a.wei)||(i<b.wei);i++)
    {
        if(a.shu[i]>=b.shu[i]) {re.shu[i]=a.shu[i]-b.shu[i];/*if((re.shu[i]==0)&&(i==(a.wei-1))&&(a.wei>1)) a.wei--;*/}
        else
        {
            re.shu[i]=a.shu[i]+10-b.shu[i];
            for(j=i+1;j<a.wei;j++)
            {
                if(a.shu[j]==0) a.shu[j]=9;
                else
                    {
                        a.shu[j]--;
                        if((a.shu[j]==0)&&(j==(a.wei-1))&&(a.wei>1)) a.wei--;
                        break;
                    }
            }
        }

    }
    re.sign=1;
    re.wei=a.wei;
    while(re.shu[re.wei-1]==0) re.wei--;
    if(re.wei<=0) re.wei=1;
    return re;
}

bigint jiapu(bigint a,bigint b)
{
    int i,jin=0,mid;
    bigint re;
    memset(re.shu,0,sizeof(int)*1100);
    re.sign=1;
    if(find0(a)) return b;
    if(find0(b)) return a;
    if(a.sign==b.sign)
    {
        for(i=0;(i<a.wei)||(i<b.wei)||(jin!=0);i++)
        {
            mid=a.shu[i]+b.shu[i]+jin;
            re.shu[i]=mid%10;
            jin=mid/10;
        }
        re.sign=a.sign;
        re.wei=i;
        return re;
    }
    else
    {
        if(jud(a,b))
        {
            re=jianpu(a,b);
            re.sign=a.sign;
        }
        else
        {
            re=jianpu(b,a);
            re.sign=b.sign;
        }
        return re;

    }
}

fushu cheng(fushu re)
{
    fushu m=re;
    //if(find0(m.shibu)&&find0(m.xubu)) return r0;
    re.shibu=jiapu(m.shibu,m.xubu);
    re.shibu.sign*=-1;
    m.xubu.sign*=-1;
    re.xubu=jiapu(m.shibu,m.xubu);
    return re;
}

bigint int2bigint(int c)
{
	bigint re;

	memset(re.shu, 0, sizeof(int)*1100);
	if( c==0 )
	{
		re.wei = 1;
		re.sign = 1;
		return re;
	}

	re.sign = c>=0?1:0;
	c = abs(c);
	re.wei = 0;
	while( c>0 )
	{
		re.shu[re.wei] = c%10;
		re.wei++;
		c /= 10;
	}

	return re;
}

fushu jia(fushu re, int c)
{
	re.shibu = jiapu(re.shibu, int2bigint(c));

	return re;
}

/*fushu jia(fushu re,int c)
{
    int i=1,jin=0,mid;
    if(re.shibu.sign==1)
    {
        mid=re.shibu.shu[0]+c;
        re.shibu.shu[0]=mid%10;
        jin=mid/10;
        re.shibu.wei=re.shibu.wei;
        while(jin!=0)
        {
            mid=re.shibu.shu[i]+jin;
            re.shibu.shu[i]=mid%10;
            jin=mid/10;
            i++;
            re.shibu.wei=i;
        }

    }
    else
    {
        if(re.shibu.shu[0]>=c) re.shibu.shu[0]-=c;
        else
        {
            re.shibu.shu[0]+=10;
            re.shibu.shu[0]-=c;
            while(re.shibu.shu[i]==0)
            {
                re.shibu.shu[i]=9;
                i++;
            }
            re.shibu.shu[i]--;
            if((re.shibu.shu[i]==0)&&(i==(re.shibu.wei-1))&&(re.shibu.wei>1)) re.shibu.wei--;

        }
         while(re.shibu.shu[re.shibu.wei-1]==0) re.shibu.wei--;
        if(re.shibu.wei<=0) re.shibu.wei=1;

    }
    return re;

}*/

void shuchu(fushu re)
{
    int i;
    if(find0(re.xubu))
    {
        if(re.shibu.sign==1)
        {
            for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
        }
        else
        {
            printf("-");
            for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
        }
        return;
    }
    else
    {
        if(find0(re.shibu))
        {
            if(re.xubu.sign==1)
            {
                if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
            }
            else
            {
                printf("-");
                if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
            }
            printf("i");
            return;
        }
        else
        {
            if(re.shibu.sign==1)
            {
                for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
                if(re.xubu.sign==1)
                {
                    printf("+");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                else
                {
                    printf("-");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                printf("i");
            }
            else
            {
                printf("-");
                for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
                if(re.xubu.sign==1)
                {
                    printf("+");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                else
                {
                    printf("-");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                printf("i");
            }
        }
    }
}

int main()
{
    char *s;
    s=(char*)malloc(sizeof(char)*10000);
    scanf("%s",s);
    int *c,i,j,len,lc;
    c=(int*)malloc(sizeof(int)*40000);
    fushu re;
    memset(re.shibu.shu,0,sizeof(int)*1100);
    memset(re.xubu.shu,0,sizeof(int)*1100);
    //memset(flag.shibu.shu,0,sizeof(int)*1000);
    //memset(flag.xubu.shu,0,sizeof(int)*1000);

    /*r0.shibu.sign=1;
    r0.xubu.sign=1;
    memset(r0.shibu.shu,0,sizeof(int)*1100);
    memset(r0.xubu.shu,0,sizeof(int)*1100);
    r0.shibu.wei=1;
    r0.xubu.wei=1;*/

    re.shibu.sign=1;
    re.xubu.sign=1;
    re.shibu.wei=1;
    re.xubu.wei=1;

    len=strlen(s);


    for(i=2,j=0;i<len;i++,j+=4)
    {
        switch(s[i])
        {
            case '0':c[j]=0;c[j+1]=0;c[j+2]=0;c[j+3]=0;break;
            case '1':c[j]=0;c[j+1]=0;c[j+2]=0;c[j+3]=1;break;
            case '2':c[j]=0;c[j+1]=0;c[j+2]=1;c[j+3]=0;break;
            case '3':c[j]=0;c[j+1]=0;c[j+2]=1;c[j+3]=1;break;
            case '4':c[j]=0;c[j+1]=1;c[j+2]=0;c[j+3]=0;break;
            case '5':c[j]=0;c[j+1]=1;c[j+2]=0;c[j+3]=1;break;
            case '6':c[j]=0;c[j+1]=1;c[j+2]=1;c[j+3]=0;break;
            case '7':c[j]=0;c[j+1]=1;c[j+2]=1;c[j+3]=1;break;
            case '8':c[j]=1;c[j+1]=0;c[j+2]=0;c[j+3]=0;break;
            case '9':c[j]=1;c[j+1]=0;c[j+2]=0;c[j+3]=1;break;
            case 'A':c[j]=1;c[j+1]=0;c[j+2]=1;c[j+3]=0;break;
            case 'B':c[j]=1;c[j+1]=0;c[j+2]=1;c[j+3]=1;break;
            case 'C':c[j]=1;c[j+1]=1;c[j+2]=0;c[j+3]=0;break;
            case 'D':c[j]=1;c[j+1]=1;c[j+2]=0;c[j+3]=1;break;
            case 'E':c[j]=1;c[j+1]=1;c[j+2]=1;c[j+3]=0;break;
            case 'F':c[j]=1;c[j+1]=1;c[j+2]=1;c[j+3]=1;break;
            default:break;
        }
    }
    lc=j;
    /*for(j=0;j<lc;j++)
    {
       printf("c[%d]=%d\n",j,c[j]);
    }*/

    for(j=0;j<lc;j++)
    {
        re=cheng(re);
        re=jia(re,c[j]);
    }

    re.shibu=reverse(re.shibu);
    re.xubu=reverse(re.xubu);

    /*printf("shibu:\n");
    printf("sign=%d\n",re.shibu.sign);
    printf("实部wei=%d\n",re.shibu.wei);
    for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
    printf("\nxubu:\n");
    printf("sign=%d\n",re.xubu.sign);
    printf("虚部wei=%d\n",re.xubu.wei);
    for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
    printf("\n以下是规范格式:\n");*/

    shuchu(re);

    return 0;
}
