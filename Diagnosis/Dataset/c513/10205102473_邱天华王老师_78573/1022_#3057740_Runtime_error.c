#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct address{
	char username[110];
	char adminname[110];
}arr;

int cmp(const void* a,const void* b)
{
	
    arr * add1=(arr *)a;
    arr * add2=(arr *)b;
	if(strcmp(add1->adminname,add2->adminname)!=0)
		return strcmp(add1->adminname,add2->adminname);
	else
		return strcmp(add2->username,add1->username);
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    arr res[500];
    for(int i=0;i<n;i++){
    	char s[110];
    	gets(s);
    	strcpy(res[i].username,strtok(s, "@"));
    	strcpy(res[i].adminname,strtok(NULL, "@"));
	}
	qsort(res,n,sizeof(res[0]),cmp);
	for(int i=0;i<n;i++){
    	printf("%s@%s\n",res[i].username,res[i].adminname);
	}
    return 0;
}
