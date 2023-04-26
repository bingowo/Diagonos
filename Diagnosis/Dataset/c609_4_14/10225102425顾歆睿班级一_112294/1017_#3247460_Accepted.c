#include<stdio.h>
#include<stdlib.h>

int cmpa(const void* p,const void* q)
{
    return *(int*)p-*(int*)q;
}
int cmpd(const void* p,const void* q)
{
    return *(int*)q-*(int*)p;
}

int main()
{
    char order;
    scanf("%c",&order);
    int s[100],ans[100],c=getchar(),cnt=0;
        for(int i=0;;i++){
            scanf("%d",&s[i]);
            cnt++;
            if(getchar()=='\n')break;
        }
    if(order=='A')qsort(s,cnt,sizeof(int),cmpa);
    else qsort(s,cnt,sizeof(int),cmpd);
    for(int i=0;i<cnt-1;i++){
            for(int j=i+1;j<cnt;j++){
                if(s[i]==s[i+1]){
                    for(int k=j;k<cnt-1;k++)
                            s[k]=s[k+1];
                    cnt--;
                    j--;
                }
        }
    }
    for(int i=0;i<cnt;i++){
            if(i==cnt-1){
                    printf("%d",s[i]);
                    break;
            }
            printf("%d ",s[i]);
    }
    return 0;
}
