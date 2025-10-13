#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'decentNumber' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void decentNumber(int n) {
    int fives = n;
    
    // Reduce fives count until it becomes divisible by 3
    // and remaining digits (threes) are divisible by 5
    while (fives % 3 != 0) {
        fives -= 5;
    }

    if (fives < 0) {
        cout << -1 << endl;
        return;
    }

    // Print '5' for the first fives digits
    for (int i = 0; i < fives; i++) cout << 5;
    // Print '3' for the remaining digits
    for (int i = 0; i < n - fives; i++) cout << 3;
    cout << endl;
}


int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
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
