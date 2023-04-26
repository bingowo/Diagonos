#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char list[7];
struct files{
	char total[100];
	char name[64];
	char time[6];
	char date[12];
	char size[12];
};
int cmp(const void*a,const void*b){
	struct files p1,p2;
	char t[5];
	int i;
	p1=*(struct files*)a;p2=*(struct files*)b;
	for(i=1;i<5;i++)t[i-1]=list[i]+32;t[i]='\0';
	if(strcmp(t,"name")==0)return strcmp(p1.name,p2.name);
	else if(strcmp(t,"size")==0)return strcmp(p1.size,p2.size);
	else if(strcmp(t,"time")==0){
		if(strcmp(p1.date,p2.date)==0)return strcmp(p1.time,p2.time);
		else return strcmp(p1.date,p2.date);
	}
}
int main() {
	struct files file[101];
	char s[5];
	char c;
	int n,i,j,k,z,x,flag;
	while(scanf("%d",&n)!=0){  //判断N 
		getchar();
		for(i=0;i<n;i++){  //录入文件信息 
		    j=0;
		    gets(file[i].total);
			z=0;flag=0;
		    for(k=0;k<strlen(file[i].total);k++){
		    	if(file[i].total[k]!=' '){
		    		if(!flag)file[i].date[z++]=file[i].total[k];
		    		else if(flag==1)file[i].time[z++]=file[i].total[k];
		    		else if(flag==2)file[i].size[z++]=file[i].total[k];
		    		else if(flag==3)file[i].name[z++]=file[i].total[k];
				}
				else {
					if(flag==0)file[i].date[z]='\0';
					else if(flag==1)file[i].time[z]='\0';
					else if(flag==2)file[i].size[z]='\0';
					z=0;
					if(file[i].total[k-1]!=' ')flag++;
				}
			}
			file[i].name[z]='\0';
    }  
    scanf("%s%s",s,list);  //输入List命令 
	qsort(file,n,sizeof(file[0]),cmp);
	for(j=0;j<n;j++)printf("%s\n",file[j].total);
	for(j=0;j<n;j++){
		for(k=0;k<100;k++){
			if(k<6){
				file[j].date[k]='\0';file[j].time[k]='\0';file[j].size[k]='\0';file[j].total[k]='\0';file[j].name[k]='\0';
			}
			else if(k<12){
				file[j].date[k]='\0';file[j].size[k]='\0';file[j].total[k]='\0';file[j].name[k]='\0';
			}
			else if(k<64){
				file[j].total[k]='\0';file[j].name[k]='\0';
			}
		}
	}  //初始化 
	printf("\n");
    }
	return 0;
}