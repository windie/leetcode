class MinStack {
public:
    MinStack();
    void push(int x) {
        s.push_back(x);
        if(minVal.size() > 0){
			if(x <= minVal.back()) {
				minVal.push_back(x);
			}
        }else{
            minVal.push_back(x);
        }
    }

    void pop() {
		if(s.size()>0){
			if(s.back() == minVal.back()){
				minVal.pop_back();
			}
			s.pop_back();
		}
    }

    int top() {
        if(s.size()>0){
            return s.back();
        }else{
            return 0;
        }
    }

    int getMin() {
        if(minVal.size() > 0){
            return minVal.back();
        }else{
            return 0;
        }
    }

private:
    list<int> s;
    list<int> minVal;
};

MinStack::MinStack(){
    s.clear();
    minVal.clear();
}