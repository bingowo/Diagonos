#include<stdio.h>
#include<string.h>
int main(){
    char f;
    int arr[101],a,i=0,mid;
    int* p=NULL;
    scanf("%c",&f);
    while(scanf("%d",&a)!=EOF){
        arr[i++]=scanf("%d",&a);
    }
    if(f=='A'){
        p=arr;
        if(*p>*(p+1)&&p<=(arr+i-3)){
            mid=*p;
            *p=*(p+1);
            *(p+1)=mid;
            p++;
        }
        for(int k=0;k<i;){
            if(k!=i-1){
                if(arr[k]!=arr[k+1]){
                    printf("%d",arr[k]);
                    k++;
            }
                else{
                    printf("%d",arr[k]);
                    k++;
                    while(arr[k]=arr[k+1]&&k<i-1){
                        k++;
                    }
                }
                if(k!=i-1){
                    prinrf(' ');
                }
            }
            if(k==i-1&&arr[k-1]!=arr[k]){
                printf("%d",arr[k]);
            }
        }
    }
    if(f=='D'){
        p=arr;
        if(*p>*(p+1)&&p<=(arr+i-3)){
            mid=*p;
            *p=*(p+1);
            *(p+1)=mid;
            p++;
        }
        for(int k=i-1;k>=0;){
            if(k!=0){
                if(arr[k]!=arr[k-1]){
                    printf("%d",arr[k]);
                    k--;
            }
                else{
                    printf("%d",arr[k]);
                    k--;
                    while(arr[k]=arr[k-1]&&k>=1){
                        k--;
                    }
                }
                if(k!=0){
                    prinrf(' ');
                }
            }
            if(k==0&&arr[k+1]!=arr[k]){
                printf("%d",arr[k]);
            }
        }
    }
    
    
    return 0;
}