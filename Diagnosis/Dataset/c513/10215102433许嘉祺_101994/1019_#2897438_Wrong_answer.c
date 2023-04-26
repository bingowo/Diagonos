                           #include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    while (scanf("%d %d",&a,&b)!=0){
        if(a==0&&b==0) break;
        int* m=(int*)malloc(sizeof(int)*a*3);
        for (int i=0;i<a*3;i++) m[i]=0;
        for (int i=0;i<b;i++){
            int x1,x2,x3;
            scanf("%d%d%d",&x1,&x2,&x3);
            switch (x3){
            case 1:m[x1-1]+=3;m[x2-1]-=1;m[x2-1+2*a]++;m[x1-1+a]++;break;
            case -1:m[x2-1]+=3;m[x1-1]-=1;m[x1-1+2*a]++;m[x2-1+a]++;break;
            case 0:m[x1-1]+=1;m[x2-1]+=1;break;
            default:break;
            }
        }
        int k[10];
        for (int i=0;i<a;i++) k[i]=i;
        for (int i=0;i<a-1;i++){
            int p=i;
            for (int j=i+1;j<a;j++){
                if (m[k[p]]<m[k[j]]) p=j;
                else if(m[k[p]]==m[k[j]])
                    if(m[k[p]+a]<m[k[j]+a]) p=j;
                    else if(m[k[p]+a]==m[k[j]+a])
                    if(m[k[p]+a*2]>m[k[j]+a*2]) p=j;
                    else if(m[k[p]+a*2]==m[k[j]+a*2]&&p>k[j]) p=j;

            }
            if (p!=i) {int s=k[p];k[p]=k[i];k[i]=s;}
        }

        for(int i=0;i<a-1;i++) printf("%d ",k[i]+1);
        printf("%d\n",k[a-1]);
        free(m);
    }
    return 0;
}