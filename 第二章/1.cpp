#include <iostream>
#include <string>
using namespace std;
 
int main()
{
                int n, i, j;
                string str;
 
                cin >> n;
                getchar();
                while(n-- > 0){
                                getline(cin, str);
                                for(i = 0; i < str.length(); i++)
                                                if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z'))
                                                {              
                                                                str[i]++;
                                                                if((str[i] - 'a') > 25 || str[i] - 'A' > 'Z')
                                                                                str[i] -= 26;
                                                }
                                cout << str << endl;
                }
                return 0;
}