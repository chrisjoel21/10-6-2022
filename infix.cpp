#include <iostream>
#include <iomanip>
#include <stack>
#include <math.h>
using namespace std;
 
int prec(char c) {
  if (c == '/' ||  c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

string getPostfix(string s) {
  stack<char> st;
  string postfix;
 
  for (int i=0; i<s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9')
      postfix += s[i];

    else if (s[i] == '(')
      st.push('(');

    else if (s[i] == ')') {
      while (st.top() != '(') {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }

    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
          postfix += st.top();
          st.pop();
      }
      st.push(s[i]);
    }
  } 

  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }
 
  return postfix;
}

/*int evaluatePostfix(string s) {
  stack<int> st;

  for (int i=0; i<s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9')
      st.push(s[i] - '0');
    else {
      int val1 = st.top(); st.pop();
      int val2 = st.top(); st.pop();
      switch (s[i]) {
        case '+': st.push(val2 + val1); break;
        case '-': st.push(val2 - val1); break;
        case '*': st.push(val2 * val1); break;
        case '/': st.push(val2 / val1); break;
      }
    }
  }
  return st.top();
}*/
string applyOp(int dig2, char op, int dig1){
  if(op == '^'){
    return to_string(pow(dig2,dig1));
  }else if(op == '*'){
    return to_string(dig2*dig1);
  }else if(op == '/'){
    return to_string(dig2/dig1);
  }else if(op == '+'){
    return to_string(dig2+dig1);
  }else if(op == '-'){
    return to_string(dig2-dig1);
  }else{
    return "-1"; 
  }
}
int evaluatePostfix(string str){
  stack<string> s;
  int solution;
  for(int i =0; i < str.length();i++){
    if(isdigit(str[i])){
      string c="";
      c+=str[i];
      s.push(c);
    }else{
      string dig1 = s.top();
      s.pop();
      string dig2 = s.top();
      s.pop();

      s.push(applyOp(stoi(dig2), str[i],stoi(dig1)));
    }
  }
  solution  =stoi(s.top());
  return solution;
}
int main() {
  // x-9=4
 string exp = "(8*9-(0+(9/3*2)*2*3)*2+9)";
 //string exp = "(2+4)";
 //9-X=4    X-9=4


  string postfix = getPostfix(exp);
  cout << postfix << endl;
  //int result = evaluatePostfix(postfix);
  int result = evaluatePostfix(postfix);
  cout<< result << endl;
}