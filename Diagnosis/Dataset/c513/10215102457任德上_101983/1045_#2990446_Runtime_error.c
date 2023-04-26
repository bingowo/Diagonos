#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
    int cnt;
    char c;
}Pair;
int cal(char *s,Pair* p){
    int i=0,cnt1=1;
    char last=*s,*s1;
    s1=s+1;
    while(*s1){
        if(last==*s1)cnt1++;
        else{
            (p+i)->cnt=cnt1;
            (p+i)->c=last;
            last=*s1;
            cnt1=1;
            i++;
        }
        s1++;
    }
    (p+i)->c=last;
    (p+i)->cnt=cnt1;
    return i+1;
}
int allsame(Pair **f,int t,int *co){
    for(int i=1;i<t;i++)if(co[0]!=co[i])return 0;
    for(int i=0;i<co[0];i++)
    for(int j=1;j<t;j++){
        char a=f[j][i].c,b=f[0][i].c;
        if(a!=b)return 0;
    }
    return 1;
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int t,*co,a[101],ans=0;
    scanf("%d",&t);
    Pair **p;
    co=(int*)malloc(t*sizeof(int));
    p=(Pair**)malloc(10000*sizeof(Pair*));
    for(int k=0;k<t;k++){
        p[k]=(Pair*)malloc(101*sizeof(Pair));
    }
    for(int i=0;i<t;i++){
        char s[101]={0};
        scanf("%s",s);
        co[i]=cal(s,p[i]);
    }
    if (allsame(p,t,co)){
        for (int i=0;i<co[0];i++){
            for (int j=0;j<t;j++)a[j]=p[j][i].cnt;
            qsort(a,t,sizeof(a[0]),cmp);
            for (int j=0;j<t;j++)ans+=abs(a[j]-a[t/2]);
        }
        printf("%d\n",ans);
  }
  else printf("-1\n");
  for(int i=0;i<t;i++)free(p[i]);
  free(p);
  return 0;
}