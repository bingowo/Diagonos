#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define L 100

typedef struct cha{
    char x;int n;
};

int mid(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int main(){
    int num;scanf("%d",&num);
    struct cha in[N][L]={0};int j[N]={0};
    for (int i=0;i<num;i++){
        char input[L];scanf("%s",input);
        int size=strlen(input),ch=0;
        j[i]=1;
        in[i][0].x=input[0];in[i][0].n=1;
        for (int pos=1;pos<size;pos++){
            if (input[pos]==in[i][ch].x)in[i][ch].n++;
            else {ch++; in[i][ch].x=input[pos];    in[i][ch].n++; j[i]++;}
        }
    }//input
    //j:num pf chars;
    for (int i=0;i<num-1;i++){
        if(j[i]!=j[i+1]){printf("-1\n");return 0;}
    }
    for (int i=0;i<num-1;i++){
        for (int c=0;c<j[0];c++){
            if(in[i][c].x!=in[i+1][c].x){printf("-1\n");return 0;}
        }
    }

    int sum=0;int a[N];
    for(int i=0;i<j[0];i++){
        for(int k=0;k<num;k++){
            a[k]=in[k][i].n;
        }
        int avg=0;
        qsort(a,num,sizeof(a[0]),mid);
        if(num%2==1)avg=a[(num-1)/2];
        else avg=(a[num/2]+a[(num-2)/2])/2;
        sum+=avg;
    }
    printf("%d\n",sum);
    return 0;
 }
