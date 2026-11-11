#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Original function from the lab; intentionally retains the fault.
bool faillecture(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 1; i < static_cast<int>(attendance_records.size()); ++i) {
        absentcount += attendance_records[i] == 0;
    }
    return absentcount >= 3;
}

int countActual(const vector<int>& a) {
    int count = 0;
    for (int i = 1; i < static_cast<int>(a.size()); ++i) count += (a[i] == 0);
    return count;
}
int countExpected(const vector<int>& a) {
    int count = 0;
    for (int x : a) count += (x == 0);
    return count;
}
void test(const string& question, const vector<int>& a) {
    cout << question << " attendance: ";
    for (int x : a) cout << x << ' ';
    int expected = countExpected(a);
    int actual = countActual(a);
    cout << "\nExpected absence count: " << expected
         << "\nActual absence count: " << actual
         << "\nExpected output: " << (expected >= 3 ? "FAIL" : "PASS")
         << "\nActual output: " << (faillecture(a) ? "FAIL" : "PASS")
         << "\n\n";
}
int main() {
    cout << "Q2: No valid 10-entry test can avoid executing the faulty loop.\n\n";
    test("Q3", {1,1,1,1,1,1,1,1,1,1});
    test("Q4", {0,0,1,1,1,1,1,1,1,1});
    test("Q5", {0,0,0,1,1,1,1,1,1,1});
}
