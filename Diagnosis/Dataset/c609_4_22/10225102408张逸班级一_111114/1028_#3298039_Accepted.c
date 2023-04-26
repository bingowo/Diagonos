#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a1,const void*a2){
    int*p1=*(int**)a1;int*p2=*(int**)a2;
    while(*p1==*p2){p1++;p2++;}
    return *p2-*p1;
}
int main(){
    int problem;
    scanf("%d",&problem);
    while(problem--){
        int num;
        scanf("%d",&num);
        int** all=(int**)malloc(sizeof (int*)*num);
        int k=0;
        for(int j=0;j<num;j++){
        int i=0;
        int* line=(int*)malloc(sizeof (int)*51);
        int a;
        scanf("%d",&a);
        while(a!=-1){
           *(line+i++)=a;
            scanf("%d",&a);
        }
        *(line+i)=-1;
        *(all+k++)=line;
        }
        qsort(all,num,sizeof(int*),cmp);
        for(int i=0;i<num;i++){
            int j=0;
            while(*(*(all+i)+j)!=-1){
                printf("%d ",*(*(all+i)+j));
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}