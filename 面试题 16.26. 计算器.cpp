class Solution {
public:
    int calculate(string s) {
        stack<int> oprands;
        stack<int> opors;
        int i = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                //过滤掉空格
                while(i < s.size() && s[i] == ' '){
                    ++i;
                }
            }else if(isdigit(s[i])){
                //取数字
                int d = 0;
                for(;i < s.size() && isdigit(s[i]);++i){
                    d = 10*d + (s[i] - '0');
                }
                oprands.push(d);
            }else{
                //取运算符
                while(opors.size() && !priority(s[i],opors.top())){
                    calc(oprands,opors);
                }
                opors.push(s[i]);
                ++i;    
            }    
        }
        while(opors.size()){
            calc(oprands,opors);
        }
        return oprands.top();
    }

    void calc(stack<int>& oprands,stack<int>& opors){//计算
        int b = oprands.top();oprands.pop();//有操作数
        int a = oprands.top();oprands.pop();//左操作数
        int op = opors.top();opors.pop();//运算符
        int c;
        switch(op){
            case '+':c = a+b;break;
            case '-':c = a-b;break;
            case '*':c = a*b;break;
            case '/':c = a/b;break; 
            default: assert(0);
        }
        oprands.push(c);
    }

    //a 的优先级是否高于 b
    bool priority(int a,int b){
        if(a == '+' || a == '-'){
            return false;
        }else if(a=='*' || a=='/'){
            return (b=='+' || b == '-');
        }
        printf("%c %c \n",a,b);
        assert(0);
        return false;
    }
};