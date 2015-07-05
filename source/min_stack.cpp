class MinStack {
public:
    void push(int x) {
        if(st1.size() > 0){
            st1.push(x);
            int tmp = st2.top();
            if(x < tmp)
                st2.push(x);
            else
                st2.push(tmp);
        }
        else{
            st1.push(x);
            st2.push(x);
        }
    }

    void pop() {
        if(st1.size() > 0){
            st1.pop();
            st2.pop();
        }
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return st2.top();
    }
private:
    stack<int> st1;
    stack<int> st2;
};