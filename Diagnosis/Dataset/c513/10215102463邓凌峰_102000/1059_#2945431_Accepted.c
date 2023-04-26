#include <stdio.h>
#include <stdlib.h>

int n;


int cmp(const void *a,const void *b){
    int pa=*(int*)a,pb=*(int*)b;
    return pa>pb?1:-1;
}


int GCD(int a,int b){
    if(a==0) return b;
    else return GCD(b%a,a);
}

int main()
{
    int s;scanf("%d%d",&n,&s);
    int hight[n];
    for(int i=0;i<n;i++){
        scanf("%d",&hight[i]);
    }
    qsort(hight,n,sizeof(int),cmp);

        int left=0,right=0,wid=0,level=hight[0],dh=0;
        while(1){
            while(right!=n && hight[left]==hight[right]){
                right++;
            }
            wid+=right-left;
            if(s<wid) break;
            else{
                dh=(s/wid)*wid;
                if(right!=n){
                    if(dh>(hight[right]-hight[left])*wid){
                        dh=(hight[right]-hight[left])*wid;
                    }
                }
                s-=dh;
                level+=dh/wid;
                if(s<wid && level!=hight[right]) break;
            }
            left=right;
        }
        if(level!=0) printf("%d",level);
        if(s!=0){
            int m=GCD(s,wid);
            printf("%s%d/%d",level==0?"":"+",s/m,wid/m);
        }

}
