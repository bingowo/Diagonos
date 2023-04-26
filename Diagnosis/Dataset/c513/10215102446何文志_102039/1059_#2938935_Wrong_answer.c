#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int main()
{
    int n = 0,s = 0;
    scanf("%d%d",&n,&s);
    int height[n];memset(height,0,n*sizeof(int));
    for(int i = 0;i<n;i++){
        scanf("%d",&height[i]);
    }
    qsort(height,n,sizeof(height[0]),cmp);
    for(int i = 0;i<n;i++){
        printf("%d ",height[i]);
        if(i==n-1){printf("\n");}
    }
    int dif = 0,sameHeight = 1;
    int res[3];memset(res,0,3*sizeof(int));
    for(int i = 0;i<n-1;i++){
        if(height[i]==height[i+1]){
            sameHeight++;
            if(i==n-2){
                res[0] = height[i];
                while(s>0){
                    s-=n;
                    res[0]+=1;
                }
                s+=n;
                res[1] = s;
                res[2] = n;
                break;
            }
            printf("sameHeight = %d\n",sameHeight);
        }
        else{
            if(i==n-2){
                
            }
            dif = height[i+1]-height[i];
            int volume = (i+1)*dif;
            printf("volume = %d\n",volume);
            if(s>=volume){
                s-=volume;
                res[0] = height[i+1];
                printf("s = %d, res[0] = %d\n",s,res[0]);
            }
            else{
                res[1] = s;
                res[2] = i+1;
                printf("res[1] = %d, res[2] = %d, break\n",res[1],res[2]);
                break;
            }
            sameHeight = 1;
        }
    }

    printf("%d %d/%d\n",res[0],res[1],res[2]);
    return 0;
}
