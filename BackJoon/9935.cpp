#include <iostream>
#include <string>

using namespace std;



int main()
{
    ios_base :: sync_with_stdio(0);
    string input_str, bomb, check;

    bool fire;

    cin >> input_str;
    cin >> bomb;


    if(input_str.length() < bomb.length()){
        cout << input_str;
        return 0;
    }
    for (int i = 0; i < input_str.length(); i++)
    {
        check += input_str[i]; // 한글자 한글자 넣어주기

        
        if (input_str[i] == bomb[bomb.length() - 1] && i >= bomb.length()-1) //마지막 글자가 폭발할 문자열의 마지막과 똑같다면
        {
         
            
            for (int j = 0; j < bomb.length(); j++) // 폭발 문자열의 전 길이만큼 비교
            {
                
                if (check[check.size()-1 - j] != bomb[bomb.length()-1 - j]){ // 폭발문자열과 다르다면
                    fire = false;
                    break;
                } 
                    fire = true; // 결국 똑같다면 폭발해야해!
            }

            if (fire) //폭발해야한다면
            {
                for (int k = 0; k < bomb.length(); k++)
                    check.pop_back();   //문자열 길이만큼 빼줘
            }
        }
    }

    if (check != "")
    {
        cout << check << '\n';
    }
    else
        cout << "FRULA" << '\n';

    return 0;
}