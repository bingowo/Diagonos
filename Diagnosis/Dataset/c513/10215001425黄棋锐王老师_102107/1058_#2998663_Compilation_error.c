 #include <stdio.h>
11 #define debug
12 //#define debug(fmt, args...) fprintf(stderr, fmt, ##args)
13 
14 void dfa();
15 
16 int main(void)
17 {
18     dfa();
19     return 0;
20 }
21 
22 void dfa()
23 {
24     int c, state;
25 
26     state = 0;
27     while ((c = getchar()) != EOF) {
28         if (state == 0 && c == '/')         // ex. [/]
29             state = 1;
30         else if (state == 1 && c == '*')     // ex. [/*]
31             state = 2;
32         else if (state == 1 && c == '/')    // ex. [//]
33             state = 4;
34         else if (state == 1) {                // ex. [<secure/_stdio.h> or 5/3]
35             putchar('/');
36             state = 0;
37         }
38 
39         else if (state == 2 && c == '*')    // ex. [/*he*]
40             state = 3;
41         else if (state == 2)                // ex. [/*heh]
42             state = 2;
43 
44         else if (state == 3 && c == '/')    // ex. [/*heh*/]
45             state = 0;
46         else if (state == 3)                // ex. [/*heh*e]
47             state = 2;
48 
49         else if (state == 4 && c == '\\')    // ex. [//hehe\]
50             state = 9;
51         else if (state == 9 && c == '\\')    // ex. [//hehe\\\\\]
52             state = 9;
53         else if (state == 9)                // ex. [//hehe\<enter> or //hehe\a]
54             state = 4;
55         else if (state == 4 && c == '\n')    // ex. [//hehe<enter>]
56             state = 0;
57 
58         else if (state == 0 && c == '\'')     // ex. [']
59             state = 5;
60         else if (state == 5 && c == '\\')     // ex. ['\]
61             state = 6;
62         else if (state == 6)                // ex. ['\n or '\' or '\t etc.]
63             state = 5;
64         else if (state == 5 && c == '\'')    // ex. ['\n' or '\'' or '\t' ect.]
65             state = 0;
66 
67         else if (state == 0 && c == '\"')    // ex. ["]
68             state = 7;
69         else if (state == 7 && c == '\\')     // ex. ["\]
70             state = 8;
71         else if (state == 8)                // ex. ["\n or "\" or "\t ect.]
72             state = 7;
73         else if (state == 7 && c == '\"')    // ex. ["\n" or "\"" or "\t" ect.]
74             state = 0;
75 
76         //debug("c = %c, state = %d\n", c, state);
77 
78         if ((state == 0 && c != '/') || state == 5 || state == 6 || state == 7 || state == 8)
79             putchar(c);
80     }
81 }