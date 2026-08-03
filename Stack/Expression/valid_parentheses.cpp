//[Approach 1] Using Stack - O(n) Time and O(n) Space
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string& s) {
   
    stack<char> st; 
   
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            
            // No opening bracket
            if (st.empty()) return false; 
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) 
            {
                return false;
            }
            
            // Pop matching opening bracket
            st.pop(); 
        }
    }
    
    // Balanced if stack is empty
    return st.empty(); 
}

int main() {
     string s="[()()]{}"; // true
    //string s="({})[ ])"; // false
    cout<<(isBalanced(s)?"true":"false");
    return 0;
}

//[Approach 2] using array - O(n) Time and O(1) Space  (very Efficient , no extra memory needed)

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isBalanced(string& s) {
    
    // stack top index in string
    int top = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            
            // push opening bracket
            s[++top] = s[i]; 
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            
        
            if (top == -1) 
              return false; 

            if ((s[i] == ')' && s[top] != '(') ||
                (s[i] == '}' && s[top] != '{') ||
                (s[i] == ']' && s[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    
    // balanced if stack empty
    return top == -1; 
}

int main() {
      string s="[()()]{}";
      cout<<(isBalanced(s)?"true":"false");
}
*/

/*
Key Mechanics: The In-Place Stack Strategytop: 
An integer initialized to -1, representing an empty stack. 
It keeps track of the index where the most recent unclosed opening bracket 
is saved.String Re-use: When an opening bracket is encountered, 
it is overwritten onto the front of the string at position ++top. 
This acts exactly like a stack push.Step-by-Step Code Walkthrough1. 
Processing Opening BracketsC++if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
    s[++top] = s[i]; 
}
Every time the loop encounters an opening bracket ((, {, [), 
it increments top and stores that character at s[top].Any non-bracket character 
(like letters or spaces, if present) 
is completely ignored by this conditional structure and skipped over.2. 
Processing Closing BracketsC++else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
    if (top == -1) 
        return false; 
When a closing bracket is found, the code first checks if top == -1. If true, 
it means a closing bracket appeared without any prior opening bracket to match it, 
immediately rendering the sequence invalid (false).C++    
if ((s[i] == ')' && s[top] != '(') ||
        (s[i] == '}' && s[top] != '{') ||
        (s[i] == ']' && s[top] != '[')) {
        return false;
    }
    top--;
}
It compares the current closing bracket s[i] with the last saved opening bracket at the top of our simulated stack (s[top]).If they mismatch (e.g., a } tries to close a (), it returns false.If they match successfully, top-- pops the opening bracket off the stack by moving the boundary back.3. Final ValidationC++return top == -1;
After traversing the entire string, if top has returned to -1, it confirms all opened brackets were successfully matched and closed. If top > -1, some opening brackets were left unclosed, making it unbalanced.Dry Run Example: s = "[()()]{}"Let's trace how the string and top shift over the loop iterations:Step (i)Character s[i]Condition MetActionString State (s)top ValueStart——Initialize[ ( ) ( ) ] { }-10[Openings[++top] = '['[ ( ) ( ) ] { }01(Openings[++top] = '('[ ( ) ( ) ] { }12)ClosingMatch s[1] (()? Yes. top--[ ( ) ( ) ] { }03(Openings[++top] = '('[ ( ) ( ) ] { }14)ClosingMatch s[1] (()? Yes. top--[ ( ) ( ) ] { }05]ClosingMatch s[0] ([)? Yes. top--[ ( ) ( ) ] { }-16{Openings[++top] = '{'{ ( ) ( ) ] { }07}ClosingMatch s[0] ({)? Yes. top--{ ( ) ( ) ] { }-1At the end of the loop, top == -1, so main() prints true.Complexity AnalysisTime Complexity: $O(n)$ where $n$ is the length of the string, as it scans the string exactly once.Space Complexity: $O(1)$ auxiliary memory. Because it modifies the characters directly inside the existing input string structure instead of instantiating an external array or vector stack, it operates in perfect constant extra space.
*/