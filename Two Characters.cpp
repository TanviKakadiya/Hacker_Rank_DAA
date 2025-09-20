#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    // Step 1: Get all unique characters
    set<char> unique_chars(s.begin(), s.end());
    vector<char> chars(unique_chars.begin(), unique_chars.end());

    int max_len = 0;

    // Step 2: Try all pairs of characters
    for (int i = 0; i < (int)chars.size(); i++) {
        for (int j = i + 1; j < (int)chars.size(); j++) {
            char c1 = chars[i];
            char c2 = chars[j];
            string filtered = "";

            // Step 3: Build string with only c1 and c2
            for (char c : s) {
                if (c == c1 || c == c2) {
                    filtered += c;
                }
            }

            // Step 4: Check if filtered string is alternating
            bool valid = true;
            for (int k = 1; k < (int)filtered.size(); k++) {
                if (filtered[k] == filtered[k - 1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                max_len = max(max_len, (int)filtered.size());
            }
        }
    }

    return max_len;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

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
