#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	char s[11];
	int A;
	int C;
	int M;
	int E;
};
int cmp1(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return (d.A-c.A );
}
int cmp2(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return (d.C -c.C  );
}
int cmp3(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return (d.M -c.M  );
}
int cmp5(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return (d.E -c.E  );
}
int cmp4(const void*a,const void*b)
{
	return strcmp((char*)a,(char*)b);
}
int main()
{
    int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		struct data cj[100];
		int j=0;
		for(j=0;j<n;j++)
		{
			long long int num;
			scanf("%s",&cj[j].s );
			scanf("%d",&cj[j].C);
			scanf("%d",&cj[j].M );
			scanf("%d",&cj[j].E);
			int tp=0;
			tp=cj[j].C+cj[j].M+cj[j].E;
			tp=(int)((float)tp/3+0.5);//四舍五入到个位
			cj[j].A=tp; 
			//printf("A:%d\n",tp);
		}
		printf("case #%d:\n",i);
		
		qsort(cj,n,sizeof(cj[0]),cmp1);
		//printf("%d %d\n",cj[0].C );
		j=0;
		char s[100][12]={0};
		int k=1;
		strcpy(s[0],cj[j].s );
		while(cj[j].A ==cj[j+1].A )//易错 
		{
			strcpy(s[k],cj[j+1].s);
			k++;
			j++;
		}
		qsort(s,k,sizeof(s[0]),cmp4);
		printf("A:\n");
		if(k<2)
		{
			printf("%s\n",cj[0].s);
		}
		else
		{
			for(j=0;j<=k;j++)
		{
			printf("%s\n",s[j]);
		}
		}

		
		qsort(cj,n,sizeof(cj[0]),cmp2);
		j=0;
		k=1;
		memset(s,sizeof(s),0);
		strcpy(s[0],cj[j].s );
		while(cj[j].C ==cj[j+1].C  )//易错 
		{
			strcpy(s[k],cj[j+1].s);
			k++;
			j++;
		}
		qsort(s,k,sizeof(s[0]),cmp4);
		printf("C:\n");
		if(k<2)
		{
			printf("%s\n",cj[0].s);
		}
		else
		{
			for(j=0;j<=k;j++)
		{
			printf("%s\n",s[j]);
		}
		}
		
		qsort(cj,n,sizeof(cj[0]),cmp3);
		j=0;
		k=1;
		memset(s,sizeof(s),0);
		strcpy(s[0],cj[j].s );
		while(cj[j].M  ==cj[j+1].M   )//易错 
		{
			strcpy(s[k],cj[j+1].s);
			k++;
			j++;
		}
		qsort(s,k,sizeof(s[0]),cmp4);
		printf("M:\n");
		if(k<2)
		{
			printf("%s\n",cj[0].s);
		}
		else
		{
			for(j=0;j<=k;j++)
		{
			printf("%s\n",s[j]);
		}
		}
		
		qsort(cj,n,sizeof(cj[0]),cmp5);
		j=0;
		k=1;
		memset(s,sizeof(s),0);
		strcpy(s[0],cj[j].s );
		while(cj[j].E  ==cj[j+1].E   )//易错 
		{
			strcpy(s[k],cj[j+1].s);
			k++;
			j++;
		}
		qsort(s,k,sizeof(s[0]),cmp4);
		printf("C:\n");
		if(k<2)
		{
			printf("%s\n",cj[0].s);
		}
		else
		{
			for(j=0;j<=k;j++)
		{
			printf("%s\n",s[j]);
		}
		}
}
}