int main(){
    int n,num,now=0;
    long long int res;
    scanf("%d",&num);
    while(now<num){
        scanf("%d",&n);
        res=(int)pow(2,n);
        printf("case #");
        printf("%d\n",now);
        printf("%lld",res);
        now++;
    }
    return 0;
}