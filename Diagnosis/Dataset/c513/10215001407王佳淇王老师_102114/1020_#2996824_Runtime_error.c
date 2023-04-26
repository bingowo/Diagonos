#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int year;
    int mon;
    int day;
    int hour;
    int min;
    long long size;
    char name[100];
	
}file;

int Ncmp(const void* A ,const void* B)
{
	char*a=((file*)A)->name;
	 char*b=((file*)B)->name;
	 int ans=strcmp(a,b);
	 if(ans>0) return 1;
	 else if(ans<0) return -1;
    else return 0;
};
int Scmp(const void* A ,const void* B)
{
	long long a=((file*)A)->size;
	long long b=((file*)b)->size;
    if(a != b)
    return (a>b)?1:-1;
    else 
        //return A.name < B.name;
    {
    	char*a1=((file*)A)->name;
	 char*b1=((file*)B)->name;
	 int ans=strcmp(a1,b1);
	 if(ans>0) return 1;
	 else if(ans<0) return -1;
    else return 0;
	}
};

int  Tcmp(const void* A ,const void* B)
{
   file*a=(file*)A;
   file*b=(file*)B;
    if(a->year < b->year) return 1;
    else if(a->year > b->year) return -1;
    else
    {
        if(a->mon < b->mon) return 1;
        else if(a->mon > b->mon) return -1;
        else
        {
            if(a->day < b->day) return 1;
            else if(a->day > b->day) return -1;
            else
            {
                if(a->hour < b->hour) return 1;
                else if(a->hour > b->hour) return -1;
                else
                {
                    if(a->min < b->min) return 1;
                    else if(a->min > b->min) return -1;
                    
                    else{
    char*a2=((file*)A)->name;
	 char*b2=((file*)B)->name;
	 int ans=strcmp(a2,b2);
	 if(ans>0) return 1;
	 else if(ans<0) return -1;
    else return 0;     
                    }
                    
                    
                }
            }
        }
    }

}



void func(int n)
{
    file* F = (file*)malloc(n*sizeof(file));
    
    for(int i = 0; i < n; i++)
    {
        char c;
        scanf("%d %c %d %c %d %c %d %c %d %d %s",&F[i].year,&c,&F[i].mon,&c,&F[i].day,&c,&F[i].hour,&c,F[i].min,&F[i].size,&F[i].name);
    }

    char opera[15];//输入的操作有空格。。。
    scanf("%s",opera);
    int len=strlen(opera);
    if(opera[len-4] == 'N')
    {
        qsort(F,n,sizeof(file),Ncmp);
    }
    else if (opera[len-4] == 'S')//
    {
        qsort(F,n,sizeof(file),Scmp);
    }
    else if (opera[len-4] == 'T')
    {
        qsort(F,n,sizeof(file),Tcmp);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d%17lld ",F[i].year,F[i].mon,F[i].day,F[i].hour,F[i].min,F[i].size);
        //cout <<  << endl;
        printf("%s\n",F[i].name);
    }
    //cout << endl;
     printf("\n");
}
int main(){
	int n;
	while((scanf("%d",&n))&&n){
		func(n);	
	}	
	return 0;
} 