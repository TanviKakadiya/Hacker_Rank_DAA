#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // remove the matching pair
        } else {
            st.push(c);
        }
    }

    // Build the reduced string from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    if (result.empty())
        return "Empty String";
    else
        return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
