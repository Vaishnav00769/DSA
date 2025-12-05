class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> a;
        for(char i : s)
        {
            if(i == '(' || i == '{' || i == '[') a.push(i);
            else 
            {
                if(a.empty()) return false;
                char temp = a.top();
                a.pop();
                if(i == ')' && temp != '(') return false;
                if(i == '}' && temp != '{') return false;
                if(i == ']' && temp != '[') return false;
            }
        }
        return a.empty();
        
    }
};