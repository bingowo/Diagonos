#include<stdio.h>
#include<stdlib.h>
int i;
typedef struct 
{
    char ch;
    int cnt;
}onech;
typedef struct{
    onech arr[101];
    int nofch;
}node;
int cmp(const void *a,const void *b){
    node x=*(node*)a;
    node y=*(node*)b;
    return x.arr[i].cnt<y.arr[i].cnt?1:-1;
}
int main(){
    int n;
    scanf("%d",&n);getchar();
    node *f=(node*)malloc(sizeof(node)*n);
    for(int k=0;k<n;k++){
        char temp[101];
        scanf("%s",temp);getchar();
        char *p=temp;
        int arri=0;
        while(*p){
            f[k].arr[arri].ch=*p;
            f[k].arr[arri].cnt=0;
            while(*p==f[k].arr[arri].ch){
                f[k].arr[arri].cnt++;p++;
            }
            arri++;
        }
        f[k].nofch=arri;
    }
    int flag=0;
    for(int k=1;k<n;k++){
        if(f[k].nofch!=f[k-1].nofch){flag=1;break;}
    }
    if(flag)printf("-1");
    else{
        int ans=0;
        for(i=0;i<f[0].nofch;i++){
            qsort(f,n,sizeof(f[0]),cmp);
            int mid=n/2;
            for(int j=0;j<n;j++){
                if(f[j].arr[i].ch!=f[mid].arr[i].ch){flag=1;break;}
                ans+=abs(f[j].arr[i].cnt-f[mid].arr[i].cnt);
            }
            if(flag)break;
        }
        if(flag)printf("-1");
        else printf("%d",ans);
    }
}