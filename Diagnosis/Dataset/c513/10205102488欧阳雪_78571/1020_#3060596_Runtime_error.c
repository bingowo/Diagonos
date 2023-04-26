#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	char s[200];
	char time[50];
	char size[10];
	char name[100];
};
int cmp_name(const void*a,const void*b)
{
	struct data f1=*(struct data*)a;
	struct data f2=*(struct data*)b;
	return strcmp(f1.name,f2.name);
}
int cmp_size(const void*a,const void*b)
{
	struct data f1=*(struct data*)a;
	struct data f2=*(struct data*)b;
	int temp1=0,temp2=0;
	int i=0;
	while(f1.size[i]!='\0')
	{
		temp1*=10;
		temp1+=(f1.size[i]-'0');
		i++;
	}
	i=0;
	while(f2.size[i]!='\0')
	{
		temp2*=10;
		temp2+=(f2.size[i]-'0');
		i++;
	}
	if(temp1!=temp2)
	{
		if(temp1>temp2)
		{
			return -1;
		}
		else{
			return 1;
		}
	}
	else{
		return strcmp(f1.name,f2.name);
	}
}
int cmp_time(const void*a,const void*b)
{
	struct data f1=*(struct data*)a;
	struct data f2=*(struct data*)b;
	int year1=0,year2=0;
	int month1=0,month2=0;
	int hour1=0,hour2=0;
	int min1=0,min2=0;
	int sec1=0,sec2=0;
	int i=0;
	for(i=0;i<3;i++)
	{
		year1*=10;
		year1+=(f1.time[i]-'0');
		year2*=10;
		year2+=(f2.time[i]-'0');
	}
	for(i=5;i<7;i++)
	{
		month1*=10;
		month1+=(f1.time[i]-'0');
		month2*=10;
		month2+=(f2.time[i]-'0');
	}
	for(i=8;i<10;i++)
	{
		hour1*=10;
		hour1+=(f1.time[i]-'0');
		hour2*=10;
		hour2+=(f2.time[i]-'0');
	}
	for(i=11;i<13;i++)
	{
		min1*=10;
		min1+=(f1.time[i]-'0');
		min2*=10;
		min2+=(f2.time[i]-'0');
	}
	for(i=14;i<16;i++)
	{
		sec1*=10;
		sec1+=(f1.time[i]-'0');
		sec2*=10;
		sec2+=(f2.time[i]-'0');
	}
	if(year1!=year2)
	{
		return year1-year2;
	}
	else{
		if(month1!=month2)
		{
			return month1-month2;
		}
		else{
			if(hour1!=hour2)
			{
				return hour1-hour2;
			}
			else{
				if(min1!=min2)
				{
					return min1-min2;
				}
				else{
					if(sec1!=sec2)
					{
						return sec1-sec2;
					}
					else{
						return strcmp(f1.name,f2.name);
					}
				}
			}
		}
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=0)
	{
		if(n==0)
		{
			return 0;
		}
		int i=0,j=0,k;
		struct data file[101];
		char c;
		for(i=0;i<n;i++)
		{
			k=0;
			//gets(file[i].s);
			while((c=getchar())!='\n')
			{
				file[i].s[k++]=c;
			}
			file[i].s[k]='\0';
			k=0;
			for(j=0;j<16;j++)
			{
				file[i].time[k++]=file[i].s[j];
			}
			file[i].time[k]='\0';
		//	printf("time:%s\n",file[i].time);
			while(file[i].s[j]==' ')
			{
				j++;
			}
			k=0;
			while(file[i].s[j]!=' ')
			{
				file[i].size[k++]=file[i].s[j];
				j++;
			}
			file[i].size[k]='\0';
		//	printf("size:%s\n",file[i].size);
			k=0;
			j++;
			while(file[i].s[j]!='\0')
			{
				file[i].name[k++]=file[i].s[j];
				j++;
			}
			file[i].name[k]='\0';
		//	printf("name:%s\n",file[i].name);
		}
		char list[10]={0};
		gets(list);
		if(list[6]=='N')
		{
			qsort(file,n,sizeof(file[0]),cmp_name);
		}
		if(list[6]=='S')
		{
			qsort(file,n,sizeof(file[0]),cmp_size);
		}
		if(list[6]=='T')
		{
			qsort(file,n,sizeof(file[0]),cmp_time);
		}
		for(i=0;i<n;i++)
		{
			//printf("%s\n",file[i].s); 
			puts(file[i].s);
		}
		printf("\n");
	}
	return 0;
}