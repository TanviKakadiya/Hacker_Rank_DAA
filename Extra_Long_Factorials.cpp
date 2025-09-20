#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */


void extraLongFactorials(int n) {
    vector<int> result(1, 1);  // store digits in reverse order

    for (int x = 2; x <= n; x++) {
        int carry = 0;

        for (int i = 0; i < result.size(); i++) {
            long long val = 1LL * result[i] * x + carry;
            result[i] = val % 10;
            carry = val / 10;
        }

        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
