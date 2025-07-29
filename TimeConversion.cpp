#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
 string period = s.substr(8, 2);  
    int hour = stoi(s.substr(0, 2));

    
    if (period == "AM") {
        if (hour == 12) hour = 0;  
    } else { // PM
        if (hour != 12) hour += 12;  
    }


    char buffer[9];
    sprintf(buffer, "%02d:%s", hour, s.substr(3, 5).c_str());  
    return string(buffer);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
