#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> st;

    for(char ch : exp)
    {
        if(isdigit(ch))
        {
            st.push(ch - '0');
        }

        else
        {
            int val2 = st.top();
            st.pop();

            int val1 = st.top();
            st.pop();

            switch(ch)
            {
                case '+':
                    st.push(val1 + val2);
                    break;

                case '-':
                    st.push(val1 - val2);
                    break;

                case '*':
                    st.push(val1 * val2);
                    break;

                case '/':
                    st.push(val1 / val2);
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string exp = "23*54*+9-";

    cout << "Result = "
         << evaluatePostfix(exp);

    return 0;
}