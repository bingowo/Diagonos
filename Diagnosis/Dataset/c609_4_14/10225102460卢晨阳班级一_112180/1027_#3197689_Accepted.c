#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	long long int xuehao;
	int sco;
}stu;

int cmp(const void*a,const void*b){
	stu*aa=(stu*)a;
	stu*bb=(stu*)b;
	if((aa->sco)!=(bb->sco)){
		return ((bb->sco)>(aa->sco))?1:-1;
	}else{
		return ((aa->xuehao)>(bb->xuehao))?1:-1;
	}
}



int main()
{
	int t;
	int cnt=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n,m,g;
		scanf("%d %d %d",&n,&m,&g);
		int b[10]={0};//每题的分数 
		for(int k=0;k<m;k++)
		scanf("%d",&b[k]);
		stu a[500];//每个学生的信息 
		for(int k=0;k<n;k++){
			a[k].sco=0;
			a[k].xuehao=0;
		}
		stu c[500];
		for(int k=0;k<n;k++){
			c[k].sco=0;
			c[k].xuehao=0;
		}
		for(int j=0;j<n;j++){
			int l;
			scanf("%lld %d",&a[j].xuehao,&l);
			int q=0;
			for(int p=0;p<l;p++){
				scanf("%d",&q);
				a[j].sco+=b[q-1];
			}
		}
		int num=0;
		for(int j=0;j<n;j++){
			if(a[j].sco>=g){
				c[num].xuehao=a[j].xuehao;
				c[num].sco=a[j].sco;
				num++;
			}
		}
		qsort(c,num,sizeof(c[0]),cmp);
		printf("case #%d:\n",cnt);
		cnt++;
		printf("%d\n",num);
		for(int j=0;j<num;j++){
			printf("%011lld %d\n",c[j].xuehao,c[j].sco);
		}
		
	}
	return 0;
 } 