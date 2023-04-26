#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
    char s[11];
    int c;
    int m;
    int e;
    int a;
};
int cmpa(const void *pa,const void *pb){
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.a==b.a){
        return strcmp(a.s,b.s);
    }
    else{
        return (b.a)-(a.a);
    }
}
int cmpc(const void *pa,const void *pb){
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.c==b.c){
        return strcmp(a.s,b.s);
    }
    else{
        return b.c-a.c;
    }
}
int cmpe(const void *pa,const void *pb){
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.e==b.e){
        return strcmp(a.s,b.s);
    }
    else{
        return b.e-a.e;
    }
}
int cmpm(const void *pa,const void *pb){
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.m==b.m){
        return strcmp(a.s,b.s);
    }
    else{
        return b.m-a.m;
    }
}
int main(){
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        int num;
        scanf("%d",&num);
        struct data p[num];
        for(int j=0;j<num;j++){
            scanf("%s",p[j].s);
            scanf("%d %d %d",&p[j].c,&p[j].m,&p[j].e);
            p[j].a=(int)((p[j].c+p[j].e+p[j].m)/3-0.5);
        }
        printf("case #%d:\n",i);
        printf("A:\n");
        qsort(p,num,sizeof(p[0]),cmpa);
        printf("%s\n",p[0].s);
        for(int j=1;j<num;j++){
        	if(p[j].a==p[j-1].a){
        		printf("%s\n",p[j].s);
			}
			else{
				break;
			}
		}
        printf("C:\n");
        qsort(p,num,sizeof(p[0]),cmpc);
        printf("%s\n",p[0].s);
        for(int j=1;j<num;j++){
        	if(p[j].c==p[j-1].c){
        		printf("%s\n",p[j].s);
			}
			else{
				break;
			}
		}
        printf("M:\n");
        qsort(p,num,sizeof(p[0]),cmpm);
        printf("%s\n",p[0].s);
        for(int j=1;j<num;j++){
        	if(p[j].m==p[j-1].m){
        		printf("%s\n",p[j].s);
			}
			else{
				break;
			}
		}
        printf("E:\n");
        qsort(p,num,sizeof(p[0]),cmpe);
        printf("%s\n",p[0].s);
        for(int j=1;j<num;j++){
        	if(p[j].e==p[j-1].e){
        		printf("%s\n",p[j].s);
			}
			else{
				break;
			}
		}
    }
    return 0;
    
}