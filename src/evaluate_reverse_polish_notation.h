class Solution {
	int cal(int a, int b, string op) {
		if (op == "+") {
			return a + b;
		} else if (op == "-") {
			return a - b;
		} else if (op == "*") {
			return a * b;
		} else {
			return a / b;
		}
	}
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"
					|| tokens[i] == "/") {
				int operd2 = s.top();
				s.pop();
				int operd1 = s.top();
				s.pop();
				s.push(cal(operd1, operd2, tokens[i]));
			} else {
				int val;
				sscanf(tokens[i].c_str(), "%d", &val);
				s.push(val);
			}
		}
		return s.top();
	}
};
