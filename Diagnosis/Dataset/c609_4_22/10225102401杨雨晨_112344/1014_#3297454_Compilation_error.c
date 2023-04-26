 #include <stdio.h>
2 int main(){
3    // Ç义⻓l型变量 a,b,c,d
4    long long int a,b,c,d;
5    // Ç义两if组 s、s1 和⼀il型f组 s2
6    int  s[60]={0};
7    int  s1[30]={0};
8    int s2[30] ={0};
9    // Y标M输·中读·两ilong long型的lf
10    scanf("%lld%lld",&a,&b);
11    // 使⽤F*>算符计算¹和f
12    c = a/b;
13    d = a%b;
14    // ÏY变量i为0
15    int i =0;
16    // 计算c的3进制!⽰，C储在f组s1中
17    do{
18        s1[i] = c%3;
19        c = c/3;
20        i++;
21   }while(c);
22    // ÏY变量j为0,¥s1f组中的元INú制èsf组中
23    int j = 0,q;
24    for(i = i-1;i>=0;i--,j++){
25        s[j] =  s1[i];
26   }
27    q = j;
28    int n=d;
29    // Ô果d不为e，则计算d的3进制!⽰，C储在f组s2中
30    if(d){
31        int p =0;
32        do{
33            s2[p] = d%3;
34            d = d/3;
35            p++;
36            b = b/3;
37       }while(d||(b!=1));
38        // ¥s2f组中的元INú制èsf组中
39        for(p = p-1;p>=0;p--,q++){
40            s[q] = s2[p];
41       }
42   }
43    // ÏY变量l为0,¥sf组中的i元加1
44    int l = 0;
45    int t = q;
46    for(q = q-1;q>=0;q--){
47        if(s[q]+1+l>=3){
48            s[q] = s[q]+1+l-3;
49            l = 1;
50       }else{
51            s[q] = s[q] +1+l;
52            l = 0;
53       }
54   }
55
56    // ¥sf组中的i元`1
57    for (q=0;q<t;q++){
58        s[q] = (s[q]-1==-1?2:s[q]-1);
59   }
60
61    // Yã&前历sf组，j掉ã⾯的0
62    for(q = q-1;q>=j;q--){
63        if (s[q] == 0){
64            t = t-1;
65       }
66        else{
67            break;
68       }
69   }
70
71    // Ô果进，则输1
72    if(l == 1){
73        printf("1");
74   }
75    // 输sf组中的元，sè⼩f点则输
76    for(int m = 0;m<t;m++){
77        printf("%d",s[m]);
78        if(n){
79            if(m == j-1){
80                printf(".");
81           }
82       }
83   }
84    return 0;
85 }
86