class MinStack {
public:
    stack<long long> st;
    long long mini=LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }else{
            if(val >= mini) st.push(val);
            else{
                long long newval=2LL*val-mini;
                st.push(newval);
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x=st.top();
        st.pop();
        if(x<mini){
            mini=2LL*mini-x;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(x<mini){
            return mini;
        } 
        return x;
    }
    
    int getMin() {
        return mini;
    }
};
