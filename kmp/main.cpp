#include <iostream>
#include <string>
#include <vector>


std::vector<int> build(const std::string& s)
{
    size_t len = s.size();
    std::vector<int> next{ 0,0 };
    for (int i = 1, j = 0; i < len; i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = next[j];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        next.push_back(j);
    }
    return next;
}

// returns an index of the string where the substring ends or -1
int match(const std::string& s, const std::string& p)
{
    size_t len1 = s.size();
    size_t len2 = p.size();
    std::vector<int> next = build(p);

    for (int i = 0, j = 0; i < len1; i++)
    {
        //  cout<<i<<endl;
        while (j > 0 && s[i] != p[j])
        {
            j = next[j];
        }
        if (s[i] == p[j])
        {
            j++;
        }
        if (j == len2)
        {
            return i;
        }
    }
    return -1;
}


int rotateString(const std::string& A, const std::string& B)
{
    if (A.size() != B.size())
    {
        return -1;
    }
    if (A.empty())
    {
        return 0;
    }

    if (A == B)
    {
        return 0;
    }

    std::string s = A + A;
    int res = match(s, B);

    if (-1 == res)
    {
        return res;
    }

    return static_cast<int>(s.length()) - res - 1;

}


int main()
{
    int N = 0;
    std::cin >> N;

    std::string a;
    std::string b;
    a.reserve(N);
    b.reserve(N);

    std::cin >> a;
    std::cin >> b;

    std::cout << rotateString(a, b) << std::endl;

    /*
    std::cout << rotateString("abracadabra", "racadabraab") << std::endl;

    rotateString("abaababc", "ababcaba");
    rotateString("ababcaba", "abaababc");

    std::cout << rotateString("aaaaaab", "abaaaaa") << std::endl;
    std::cout << rotateString("abaaaaa", "aaaaaab") << std::endl;
    */

    return 0;
}