#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// A number is [+-]?digits(.digits)?; no numeric conversion is used.
bool validNumber(const string& s) {
    if (s.empty()) return false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    if (i == s.size()) return false;
    size_t before = 0, after = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') { ++before; ++i; }
    if (before == 0) return false;
    if (i < s.size() && s[i] == '.') {
        ++i;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') { ++after; ++i; }
        if (after == 0) return false;
    }
    return i == s.size();
}

struct Number {
    bool negative;
    string digits; // absolute value, without a decimal point
    size_t scale;  // digits after the decimal point
};

Number parseNumber(const string& s) {
    Number n;
    n.negative = s[0] == '-';
    size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    size_t dot = s.find('.', start);
    n.scale = dot == string::npos ? 0 : s.size() - dot - 1;
    n.digits = s.substr(start, dot == string::npos ? string::npos : dot - start);
    if (dot != string::npos) n.digits += s.substr(dot + 1);
    return n;
}

string stripLeadingZeros(const string& s) {
    size_t first = s.find_first_not_of('0');
    return first == string::npos ? "0" : s.substr(first);
}

// Compare unsigned, equal-scale integer strings.
int compareAbs(string a, string b) {
    a = stripLeadingZeros(a);
    b = stripLeadingZeros(b);
    if (a.size() != b.size()) return a.size() > b.size() ? 1 : -1;
    if (a == b) return 0;
    return a > b ? 1 : -1;
}

string addAbs(const string& a, const string& b) {
    string result;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.insert(result.begin(), char('0' + sum % 10));
        carry = sum / 10;
    }
    return stripLeadingZeros(result);
}

// Requires a >= b.
string subtractAbs(const string& a, const string& b) {
    string result;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int borrow = 0;
    while (i >= 0) {
        int digit = (a[i--] - '0') - borrow;
        if (j >= 0) digit -= b[j--] - '0';
        borrow = digit < 0 ? 1 : 0;
        if (borrow) digit += 10;
        result.insert(result.begin(), char('0' + digit));
    }
    return stripLeadingZeros(result);
}

string addNumbers(const string& first, const string& second) {
    Number a = parseNumber(first), b = parseNumber(second);
    size_t scale = a.scale > b.scale ? a.scale : b.scale;
    a.digits.append(scale - a.scale, '0');
    b.digits.append(scale - b.scale, '0');

    string digits;
    bool negative = false;
    if (a.negative == b.negative) {
        digits = addAbs(a.digits, b.digits);
        negative = a.negative;
    } else {
        int cmp = compareAbs(a.digits, b.digits);
        if (cmp >= 0) {
            digits = subtractAbs(a.digits, b.digits);
            negative = a.negative;
        } else {
            digits = subtractAbs(b.digits, a.digits);
            negative = b.negative;
        }
    }

    if (digits == "0") return "0";
    if (scale > 0) {
        if (digits.size() <= scale) digits.insert(0, scale + 1 - digits.size(), '0');
        digits.insert(digits.size() - scale, 1, '.');
        while (!digits.empty() && digits.back() == '0') digits.pop_back();
        if (!digits.empty() && digits.back() == '.') digits.pop_back();
    }
    return (negative ? "-" : "") + digits;
}

int main(int argc, char* argv[]) {
    string filename;
    if (argc >= 2) filename = argv[1];
    else {
        cout << "Enter input filename: ";
        if (!(cin >> filename)) return 1;
    }
    ifstream file(filename);
    if (!file) {
        cerr << "ERROR: cannot open file \"" << filename << "\"\n";
        return 1;
    }
    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        ++lineNumber;
        istringstream stream(line);
        vector<string> tokens;
        string token;
        while (stream >> token) tokens.push_back(token);
        cout << "line " << lineNumber << ": ";
        if (tokens.size() != 2) {
            cout << "ERROR: expected exactly two numbers\n";
            continue;
        }
        bool validA = validNumber(tokens[0]);
        bool validB = validNumber(tokens[1]);
        if (!validA || !validB) {
            cout << "ERROR: invalid number";
            if (!validA) cout << " \"" << tokens[0] << "\"";
            if (!validB) cout << " \"" << tokens[1] << "\"";
            cout << '\n';
            continue;
        }
        cout << tokens[0] << " + " << tokens[1] << " = "
             << addNumbers(tokens[0], tokens[1]) << '\n';
    }
    return 0;
}
