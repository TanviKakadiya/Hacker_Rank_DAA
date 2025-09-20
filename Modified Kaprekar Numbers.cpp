#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    bool found = false;

    for (long long i = p; i <= q; i++) {
        long long sq = i * i;
        string s = to_string(sq);
        int d = to_string(i).length();

        // Split into right (last d digits) and left (remaining)
        string right = s.substr(max(0, (int)s.size() - d));
        string left  = s.substr(0, max(0, (int)s.size() - d));

        long long r = (right.empty() ? 0 : stoll(right));
        long long l = (left.empty() ? 0 : stoll(left));

        if (l + r == i) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "INVALID RANGE";
    }
}


int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
