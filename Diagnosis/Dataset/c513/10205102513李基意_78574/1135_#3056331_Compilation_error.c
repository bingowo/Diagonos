int z[501]; //储存从低位到高位答案
void add(int a[],int b[]){
    int temp[501];
    memset(temp, -1, sizeof(z));
    int carry=0,len1=0,i; //carry表示进位
    for(i=0;i<501;i++){
        if(a[i]==-1){
            len1=i;
            break;
        }
    }
    for(i=0;i<len1;i++){ //从低位到高位相加
        if(b[i]!=-1){
            temp[i]=b[i]+a[i]+carry;
        }
        else temp[i]=a[i]+carry;
        if(temp[i]>=10) carry=1;
        else carry=0;
        temp[i]%=10;
    }
    if(carry) temp[len1]=1;
    for(int i=0;i<501;i++){
        z[i]=temp[i];
    }
}
int main(){
    int res[501][501];
    memset(res, -1, sizeof(res));
    res[0][0]=res[1][0]=1,res[2][0]=2,res[3][0]=3, res[4][0]=6; //初始化
    for(int i=5;i<501;i++){
        memset(z, -1, sizeof(z));
        add(res[i-1],res[i-2]);
        add(z,res[i-4]);
        for(int j=0;j<501;j++){
            res[i][j]=z[j];
        }
    }
    int n,len;
    scanf("%d",&n);
    for(int i=0;i<501;i++){
        if(res[n][i]==-1){
            len=i;
            break;}
    }
    for(int i=len-1;i>-1;i--){
        printf(“%d”,res[n][i]);
    }
    return 0;
}