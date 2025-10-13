#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    // If length is odd, it's not possible to split equally
    if (s.length() % 2 != 0)
        return -1;

    int n = s.length() / 2;
    string s1 = s.substr(0, n);
    string s2 = s.substr(n);

    // Count frequency of characters in s1
    vector<int> freq(26, 0);
    for (char c : s1)
        freq[c - 'a']++;

    // Subtract frequency using s2
    for (char c : s2)
        freq[c - 'a']--;

    // Sum positive differences (extra chars in s1)
    int changes = 0;
    for (int val : freq)
        if (val > 0)
            changes += val;

    return changes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

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
    