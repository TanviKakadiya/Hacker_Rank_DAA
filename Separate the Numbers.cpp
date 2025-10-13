#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    int n = s.size();
    bool beautiful = false;
    long long firstNum = -1;

    // Try all possible starting number lengths
    for (int len = 1; len <= n / 2; ++len) {
        string first = s.substr(0, len);
        if (first[0] == '0') break; // leading zero not allowed

        long long num = stoll(first);
        string built = first;

        // Build sequence by adding consecutive numbers
        while (built.size() < n) {
            num++;
            built += to_string(num);
        }

        if (built == s) {
            beautiful = true;
            firstNum = stoll(first);
            break;
        }
    }

    if (beautiful)
        cout << "YES " << firstNum << "\n";
    else
        cout << "NO\n";
}


int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
