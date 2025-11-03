#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    unordered_map<char, int> freq;
    bool hasEmpty = false;

    // Count frequency of each color and check for empty cells
    for (char c : b) {
        if (c == '_')
            hasEmpty = true;
        else
            freq[c]++;
    }

    // Case 1: If no empty spaces, check if already happy
    if (!hasEmpty) {
        for (int i = 0; i < (int)b.size(); i++) {
            if ((i > 0 && b[i] == b[i - 1]) || (i < (int)b.size() - 1 && b[i] == b[i + 1])) {
                continue;
            } else {
                return "NO";
            }
        }
        return "YES";
    }

    // Case 2: If any color occurs only once, can't make it happy
    for (auto &p : freq) {
        if (p.second == 1)
            return "NO";
    }

    // Otherwise, we can rearrange to make all happy
    return "YES";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
