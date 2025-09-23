#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    // Convert all characters to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Use a set to store unique letters
    unordered_set<char> letters;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            letters.insert(c);
        }
    }

    // Check if we got all 26 letters
    if (letters.size() == 26) {
        return "pangram";
    } else {
        return "not pangram";
    }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
