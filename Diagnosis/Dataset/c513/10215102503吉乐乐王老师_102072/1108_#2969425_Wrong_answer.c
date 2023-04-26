#include<stdio.h>
typedef struct{
    int yushu;
    int shang;
}node;
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        int fz,fm;
        scanf("%d %d",&fz,&fm);getchar();
        node data[1000];
        int idx=0;
        int start=0,end=0;
        int flag1=0,flag2=0;
        while(fz%fm){
            data[idx].yushu=fz%fm;
            data[idx].shang=fz/fm;
            fz=fz%fm*10;
            idx++;
            for(int i=idx-1;i>=0;i--){
                if(data[i].yushu==fz%fm&&data[i].shang==fz/fm){
                    start=i;end=idx-1;
                    flag1=1;break;
                }
            }
            if(flag1)break;
            else {
                if(fz%fm==0&&fz!=0){data[idx++].shang=fz/fm;flag2=1;break;}}
        }
        printf("case #%d:\n0.",cas++);
        if(flag1){
            for(int i=1;i<idx;i++){
                printf("%d",data[i].shang);
            }
            printf("\n%d-%d\n",start,end);
        }
        else if(flag2){
            for(int i=1;i<idx;i++){
                printf("%d",data[i].shang);
            }
            putchar('\n');
        }
    }
}