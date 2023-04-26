#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int ID;
    int Dis;
}ROOM;
int cmp(const void*a,const void*b)
{
	ROOM *p1=(ROOM*)a,*p2=(ROOM*)b;
    return p1->Dis > p2->Dis ? 1 : -1;
}
int main()
{
	int n,i;
    while((scanf("%d",&n))!=EOF){
		ROOM data[100];
		int flag=0;
		for(i=0;i<n;i++){
			int a[15][15];
			int id,dis,r,c;
			scanf("%d%d%d%d",&id,&dis,&r,&c);
			int j,p,count=0;
            getchar();
			for(j=0;j<r;j++){
				char *s=(char*)malloc(sizeof(char)*(c+1));
                gets(s);
				for(p=0;p<c;p++){a[j][p]=s[p]-'0';}
                for(p=0;p<c;p++)
                {
				 if(j==0&&p==0){if(a[j][p+1]==0&&a[j][p]==0)count++;}
				 if(j==0&&p==c-1){if(a[j][p-1]==0&&a[j][p]==0)count++;}
				 if(j==0&&p>0&&p<c-1){if(a[j][p-1]==0&&a[j][p+1]==0&&a[j][p]==0)count++;}
				 if(j>0&&p==0){if(a[j-1][p]==0&&a[j][p+1]==0&&a[j][p]==0)count++;}
				 if(j>0&&p==c-1){if(a[j-1][p]==0&&a[j][p-1]==0&&a[j][p]==0)count++;}
				 if(j>0&&p>0&&p<c-1){if(a[j][p+1]==0&&a[j-1][p]==0&&a[j][p-1]==0&&a[j][p]==0)count++;}
			   }
			}
            //printf("%d\n",count);
			if(count){data[flag].ID=id;data[flag].Dis=dis;flag++;}
            
		}
		if(!flag)printf("Bad Luck,Rocker!\n");
		else{
		   qsort(data,flag,sizeof(ROOM),cmp);
		   printf("%d\n",data[0].ID);
		}
    }
	system("pause");
	return 0;
}