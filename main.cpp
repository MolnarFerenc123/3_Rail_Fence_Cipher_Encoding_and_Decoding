#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

string encode_rail_fence_cipher(string str, int n)
{
    if (str == "" || n == 1)
    {
        return str;
    }
    string result = "";
    vector<pair<int, char>> fence;
    int row = 1;
    char dir = 'd';
    for (int i = 0; i < str.length(); i++)
    {
        fence.push_back(pair(row, str[i]));
        if (dir == 'd')
        {
            row++;
            if (row == n + 1)
            {
                row = n - 1;
                dir = 'u';
            }
        }
        else if (dir == 'u')
        {
            row--;
            if (row == 0)
            {
                row = 2;
                dir = 'd';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < fence.size(); j++)
        {
            if (fence[j].first == i + 1)
            {
                result += fence[j].second;
            }
        }
    }
    return result;
}

string decode_rail_fence_cipher(string str, int n)
{
    if (str == "" || n == 1)
    {
        return str;
    }
    int rows = n;
    int block_size = n * 2 - 2;
    int str_length = str.length();
    while (str_length % block_size != 0)
    {
        str_length--;
    }
    cout << str_length << endl;
    for (int i = 0; i < str_length; i++)
    {
    }
    /*
Hello, World!
H !e,Wdloollr
H     _     !
 e   , W   d
  l o   o l
   l     r
    */
    return "";
}

int main()
{
    cout << decode_rail_fence_cipher("H !e,Wdloollr", 4) << endl;
    ;
    cout << decode_rail_fence_cipher("WECRLTEERDSOEEFEAOCAIVDEN", 3) << endl;
    cout << decode_rail_fence_cipher("", 3) << endl;
}