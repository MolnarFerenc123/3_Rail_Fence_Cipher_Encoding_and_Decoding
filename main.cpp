#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

string encode_rail_fence_cipher(string str, int n)
{
    if(str == "" || n == 1){
        return str;
    }
    string result = "";
    vector<pair<int, char>> fence;
    int row = 1;
    char dir = 'd';
    for (int i = 0; i < str.length(); i++)
    {
        fence.push_back(pair(row,str[i]));
        if(dir == 'd'){
            row++;
            if(row == n+1){
                row = n-1;
                dir = 'u';
            }
        }else if(dir == 'u'){
            row--;
            if(row == 0){
                row = 2;
                dir = 'd';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < fence.size(); j++){
            if (fence[j].first == i+1)
            {
                result += fence[j].second;
            }
        }
    }
    return result;
}

string decode_rail_fence_cipher(const string &str, int n)
{
    if(str == "" || n == 1){
        return str;
    }
    string result = "";
    vector<pair<int, char>> fence;
    int row = 1;
    char dir = 'd';
    for (int i = 0; i < str.length(); i++)
    {
        fence.push_back(pair(row,str[i]));
        if(dir == 'd'){
            row++;
            if(row == n+1){
                row = n-1;
                dir = 'u';
            }
        }else if(dir == 'u'){
            row--;
            if(row == 0){
                row = 2;
                dir = 'd';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < fence.size(); j++){
            if (fence[j].first == i+1)
            {
                result += fence[j].second;
            }
        }
    }
    return result;
}

int main()
{
    cout << encode_rail_fence_cipher(encode_rail_fence_cipher(encode_rail_fence_cipher(encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3),3),3),3) << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 3) << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 4) << endl;
    cout << encode_rail_fence_cipher("", 3) << endl;
}