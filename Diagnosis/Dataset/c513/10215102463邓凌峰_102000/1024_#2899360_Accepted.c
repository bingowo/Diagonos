#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[12];
    int scores;
}Student;


int cmp(const void *a,const void *b)
{
    Student pa=*(Student*)a,pb=*(Student*)b;
    if(pa.scores!=pb.scores){return (pa.scores>pb.scores)?-1:1;}
    else return strcmp(pa.name,pb.name);
}


int main()
{
	int T;scanf("%d",&T);
	for(int i=0;i<T;i++){
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int fen[M];
        for(int j=0;j<M;j++){scanf("%d",&fen[j]);}
        Student students[N];
        for(int k=0;k<N;k++){students[k].scores=0;}
        int S;
        for(int k=0;k<N;k++){
            scanf("%s%d",&students[k].name,&S);
            for(int m=0;m<S;m++){
                int f;scanf("%d",&f);
                students[k].scores+=fen[f-1];
            }
        }
        qsort(students,N,sizeof(Student),cmp);
        int cnt=0;
        for(int n=0;n<N;n++){
            if(students[n].scores>=G)cnt++;
        }
        printf("case #%d:\n%d\n",i,cnt);
        for(int n=0;n<N;n++){
            if(students[n].scores>=G)
                printf("%s %d\n",students[n].name,students[n].scores);
        }
	}

	return 0;
}
