#include <bits/stdc++.h>
using namespace std;

// Function to return precedence
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}

// Function to perform operation
int applyOperation(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
    }

    return 0;
}

// Function to evaluate infix expression
int evaluate(string exp)
{
    stack<int> values;
    stack<char> ops;

    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // Ignore spaces
        if(ch == ' ')
            continue;

        // If digit
        if(isdigit(ch))
        {
            values.push(ch - '0');
        }

        // Left parenthesis
        else if(ch == '(')
        {
            ops.push(ch);
        }

        // Right parenthesis
        else if(ch == ')')
        {
            while(ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(val1, val2, op));
            }

            ops.pop();
        }

        // Operator
        else
        {
            while(!ops.empty() &&
                  precedence(ops.top()) >= precedence(ch))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(val1, val2, op));
            }

            ops.push(ch);
        }
    }

    // Remaining operations
    while(!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string exp = "2+3*4";

    cout << "Result = "
         << evaluate(exp);

    return 0;
}