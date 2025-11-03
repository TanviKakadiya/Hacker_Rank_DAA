#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr) {
    int n = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    // If already sorted
    if (arr == sorted) {
        cout << "yes" << endl;
        return;
    }

    // Find indices where arr differs from sorted
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }

    // Try swapping
    swap(arr[l], arr[r]);
    if (arr == sorted) {
        cout << "yes" << endl;
        cout << "swap " << l + 1 << " " << r + 1 << endl;
        return;
    }

    // Undo swap and try reversing
    swap(arr[l], arr[r]);
    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (arr == sorted) {
        cout << "yes" << endl;
        cout << "reverse " << l + 1 << " " << r + 1 << endl;
        return;
    }

    // If neither works
    cout << "no" << endl;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
