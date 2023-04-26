#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int mi;
    int xishu;
}group;

int trana2i(char *s)
{
	if( strlen(s)<=0 ) return 1;
	
	int nFlag = 1;
	int nStart = 1;
	int i;
	
	if( s[0]=='-' ) 
	{
		if( strlen(s)==1 )
			return -1;
		nFlag = -1;
	}
	else if( s[0]=='+' ) 
	{
		if( strlen(s)==1 )
			return 1;
		nFlag = 1;
	}
	else nStart = 0;
	
	int re = 0;
	for(i=nStart;i<strlen(s);i++)
	{
		re *= 10;
		re += s[i]-'0';
	}
	
	re *= nFlag;
	return re;
}

group tranone(char *s)
{
	group a;
	char *p;
	
	//printf("TranOne [%s]", s);
	p = strstr(s, "x^");
	if( p!=NULL )
	{
		p[0] = 0;
		p += 2;
		
		a.xishu = trana2i(s);
		a.mi = trana2i(p);
	}
	else
	{
		p = strstr(s, "x");
		if( p!=NULL )
		{
			p[0] = 0;
			a.xishu = trana2i(s);
			a.mi = 1;
		}
		else
		{
			a.xishu = trana2i(s);
			a.mi = 0;
		}
	}
	
	//printf(" Result %d, %d\n", a.xishu, a.mi);
	return a;
}

int transtring(char *s, group *a)
{
	int i, nLen = strlen(s);
	int nCount = 0;
	int ns = 0;
	char temp[20];
	
	for(i=0;i<nLen;i++)
	{
		if( s[i]=='-' || s[i]=='+' )
		{
			if( i-ns>0 )
			{
				memset(temp, 0, 20);
				strncpy(temp, s+ns, i-ns);
				a[nCount++] = tranone(temp);
			}
			ns = i;
		}
	}
	
	if( ns<nLen )
	{
		memset(temp, 0, 20);
		strncpy(temp, s+ns, nLen-ns);
		a[nCount++] = tranone(temp);
	}
		
	return nCount;
}

int cheng(group a[],int nofa,group b[],int nofb,group re[])
{
    int i,j,k;
    for(i=0;i<nofa;i++)
    {
        for(j=0;j<nofb;j++)
        {
            re[k].mi=a[i].mi+b[j].mi;
            re[k].xishu=a[i].xishu*b[j].xishu;
            k++;
        }
    }
    return k;

}

int chongpai(group *a, int k, group *b)
{
	int i, j, n, m;
	
	n = 0;
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if( b[j].mi==a[i].mi )
			{
				b[j].xishu += a[i].xishu;
				break;
			}
			else if( b[j].mi<a[i].mi )
			{
				for(m=n-1;m>j;m--)
					b[m] = b[m-1];
				n++;
				b[j] = a[i];
				break;
			}
		}
		if(j>=n )
		{
			b[n] = a[i];
			n++;
		}
	}
	
	return n;
}

int main()
{
    int i,j;
    char fir[120],sec[120];
    group one[60],two[60],res[200],ans[60];

    memset(fir,0,sizeof(char)*120);
    memset(sec,0,sizeof(char)*120);

    memset(one,0,sizeof(group)*60);
    memset(two,0,sizeof(group)*60);
    memset(res,0,sizeof(group)*200);
    memset(ans,0,sizeof(group)*60);

    while(scanf("%s%s",fir,sec)!=EOF)
    {
        int nof1,nof2,nofr,nofans;
        nof1=transtring(fir,one);
        /*for(i=0;i<nof1;i++)
        {
            printf("test test: one的第%d项=%d x (%d)\n",i,one[i].xishu,one[i].mi);
        }*/
        nof2=transtring(sec,two);
        /*for(i=0;i<nof2;i++)
        {
            printf("test test: two的第%d项=%d x (%d)\n",i,two[i].xishu,two[i].mi);
        }*/
        nofr=cheng(one,nof1,two,nof2,res);
        /*printf("After cheng\n");
        for(i=0;i<nofr;i++)
        {
        	printf("[%d]= %d x(%d)\n", i, res[i].xishu, res[i].mi);
		}*/
        nofans=chongpai(res,nofr,ans);
        /*printf("After chongpai\n");
        for(i=0;i<nofans;i++)
        {
        	printf("[%d]= %d x(%d)\n", i, ans[i].xishu, ans[i].mi);
		}*/

        for(i=0;i<nofans-1;i++)
        {
        	if( ans[i].xishu!=0 )
            	printf("%d ",ans[i].xishu);
        }
        printf("%d\n",ans[i].xishu);
    }
    return 0;
}
