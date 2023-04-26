#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
void myprint(int res[]){
    if(res[1]==0){
        printf("%d",res[0]);
        return;
    }
    else{
        int gcd = GCD(res[1],res[2]);
        res[1]/=gcd;
        res[2]/=gcd;
        printf("%d+%d/%d",res[0],res[1],res[2]);
    }
    return;
}

int GCD(int a, int b)
{
    int r = 0;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
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
    //for(int i = 0;i<n;i++){
    //    printf("%d ",height[i]);
    //    if(i==n-1){printf("\n");}
    //}
    int sameHeight = 1;
    int res[3];memset(res,0,3*sizeof(int));
    for(int i = 0;i<n-1;i++){
        if(height[i]==height[i+1]){
            sameHeight++;
            if(i==n-2){
                res[0] = height[i];
                while(s>=n){
                    s-=n;
                    res[0]+=1;
                }
                res[1] = s;
                res[2] = n;
                //printf("res[1] = %d, res[2] = %d, break1\n",res[1],res[2]);
                break;
            }
            //printf("sameHeight = %d\n",sameHeight);
        }
        else{
            if(i==n-2){
                int dif = height[i+1]-height[i];
                int volume = (n-1)*dif;
                if(s>=volume){
                    s-=volume;
                    res[0] = height[i+1];
                    while(s>=n){
                        s-=n;
                        res[0]+=1;
                    }
                    res[1] = s;
                    res[2] = n;
                    //printf("res[1] = %d, res[2] = %d, break21\n",res[1],res[2]);
                    break;
                }
                else{
                    res[0] = height[i];
                    res[1] = s;
                    res[2] = i+1;
                    //printf("res[1] = %d, res[2] = %d, break22\n",res[1],res[2]);
                    break;
                }
            }
            int dif = height[i+1]-height[i];
            int volume = (i+1)*dif;
            //printf("volume = %d\n",volume);
            if(s>=volume){
                s-=volume;
                res[0] = height[i+1];
                //printf("s = %d, res[0] = %d\n",s,res[0]);
            }
            else{
                res[1] = s;
                res[2] = i+1;
                //printf("res[1] = %d, res[2] = %d, break3\n",res[1],res[2]);
                break;
            }
            sameHeight = 1;
        }
    }
    myprint(res);
    return 0;
}
