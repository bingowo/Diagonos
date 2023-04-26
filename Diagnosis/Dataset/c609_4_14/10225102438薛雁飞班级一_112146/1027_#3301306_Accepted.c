#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char num[11];
    int point;
}student;
int cmp(const void* a,const void* b)
{
    student s1,s2;
    s1=*((student*)a);s2=*((student*)b);
    if(s1.point==s2.point){
        return(strcmp(s1.num,s2.num));
    }
    else{
        if(s1.point<s2.point)return 1;
        else return -1;
    }
}
int jige(student* s,int g,int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        if(s[i].point>=g)
            sum++;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int c=0;c<t;c++){
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);
        int *a;
        a=(int*)malloc(m*sizeof(int));
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        student* s;
        s=(student*)malloc(n*sizeof(student));
        for(int i=0;i<n;i++)s[i].point=0;
        for(int i=0;i<n;i++){
            scanf("%s",s[i].num);
            int y,k;
            scanf("%d",&y);
            for(int j=0;j<y;j++){
                scanf("%d",&k);
                s[i].point=s[i].point+a[k-1];
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        int x=jige(s,g,n);
        printf("case #%d:\n",c);
        printf("%d\n",x);
        for(int i=0;i<x;i++){
            printf("%s %d\n",s[i].num,s[i].point);
        }
    }
        return 0;
}
