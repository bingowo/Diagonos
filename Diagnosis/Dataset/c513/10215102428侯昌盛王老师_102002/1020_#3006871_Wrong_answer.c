#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char day[20],time[20];
	int size;
	char s[64];
	
}h;
int cmp_name(const void*m,const void*n)
{
	h *p,*q;
	p=(h*)m;q=(h*)n;
	if(strcmp(p->s,q->s)>0) return 1;
	else if(strcmp(p->s,q->s)<=0) return -1;
}
int cmp_size(const void*m,const void*n)
{
	h *p,*q;
	p=(h*)m;q=(h*)n;
	if((p->size)>(q->size)) return 1;
	else if((p->size)<(q->size))return -1;
	else{
		if(strcmp(p->s,q->s)>0) return 1;
		else if(strcmp(p->s,q->s)<=0) return -1;
	}
}
int cmp_time(const void*m,const void*n)
{
	h *p,*q;
	p=(h*)m;q=(h*)n;
	if(strcmp(p->day,q->day)!=0)
	{
		
		if(strcmp(p->day,q->day)>0) return 1;
		else return -1;
	}
	else if(strcmp(p->time,q->time)!=0){
		
		if(strcmp(p->time,q->time)>0) return 1;
		else return -1;
	}
	else{
		
		if(strcmp(p->s,q->s)>0) return 1;
		else if(strcmp(p->s,q->s)<=0) return -1;
	}
}
int main()
{
	int n;
	
	while(scanf("%d",&n)&&n!=0)
	{
		h a[101];
		int i=0;
		//printf("%d\n",n);
		for(i;i<n;i++)
		{
			//printf("%d\n",i);
			scanf("%s %s %d %s",a[i].day,a[i].time,&a[i].size,a[i].s);
			
			
			
		}
		
		char way[11];
		char c;
		c=getchar();
		gets(way);
		//printf("%c\n",way[6]);
		if(way[6]=='N') qsort(a,n,sizeof(a[0]),cmp_name);
		else if(way[6]=='S') qsort(a,n,sizeof(a[0]),cmp_size);
		else if(way[6]=='T') qsort(a,n,sizeof(a[0]),cmp_time);
		//printf("%s\n",a[3].s);
		for(i=0;i<n;i++)
		{
			printf("%s %s %d %s\n",a[i].day,a[i].time,a[i].size,a[i].s);
		}
		c=getchar();
		
	}
	return 0;
}