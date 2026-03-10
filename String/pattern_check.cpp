#include <iostream>
using namespace std;

int main()
{
    string text = "programming";
    string pattern = "gram";

    int n = text.length();
    int m = pattern.length();

    bool found = false;

    for(int i = 0; i <= n - m; i++)
    {
        int j;

        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m)
        {
            found = true;
            break;
        }
    }

    if(found)
        cout << "Pattern Found";
    else
        cout << "Pattern Not Found";
}