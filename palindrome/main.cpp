#include <iostream>
#include <string>
#include <algorithm>
#include <string_view>

bool isPalindrome(const std::string_view input)
{
    if (std::equal(input.begin(), input.begin() + input.size() / 2, input.rbegin()))
    {
        return true;
    }

    return false;
}

int solution(const std::string_view input)
{
    /*
    *  result string to add MUST NOT be empty
    if (isPalindrome(input))
    {
        std::cout << input << std::endl;
        return 0;
    }
    */

    std::string palindrome;
    palindrome.reserve(input.size() * 2);
    palindrome.append(input);

    size_t pos = input.size();

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        palindrome.insert(pos, 1, *it);

        if (isPalindrome(palindrome))
        {
            std::cout << palindrome << std::endl;
            return 0;
        }
    }

    return 0;
}

int main()
{
    std::string input;
    std::cin >> input;
    solution(input);


    //std::cout << "a >>  ";  solution("a");
    //std::cout << "aaaaa >>  ";  solution("aaaaa");
    //std::cout << "aba >>  ";  solution("aba");
    //std::cout << "abab >>  "; solution("abab");
    //std::cout << "No >>  "; solution("No");
    //std::cout << "OnLine >>  "; solution("OnLine");
    //std::cout << "AbabaAab >>  "; solution("AbabaAab");

    return 0;
}