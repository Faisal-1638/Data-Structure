#include <iostream>
using namespace std;

int main()
{
    string text = "programming";
    string pattern = "gram";

    int n = text.length();
    int m = pattern.length();

    bool found = false;
    int indx= -1;

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
            indx=i;
            break;
        }
    }

    if(found)
        cout << "Pattern Found At Index "<<indx;
    else
        cout << "Pattern Not Found";

return 0;

}