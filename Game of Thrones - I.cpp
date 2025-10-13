#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s)
        freq[c - 'a']++;

    int oddCount = 0;

    // Count how many characters appear an odd number of times
    for (int f : freq) {
        if (f % 2 != 0)
            oddCount++;
    }

    // A string can form a palindrome if at most one character has an odd frequency
    if (oddCount > 1)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
