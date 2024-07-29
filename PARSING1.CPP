#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class RecursiveDescentParser {
public:
    RecursiveDescentParser(const string& input) : input(input), pos(0) {}

    bool parse() {
        return E() && pos == input.length();
    }

private:
    bool E() {
        cout << "E -> ";
        if (T()) {
            return Eprime();
        }
        return false;
    }

    bool Eprime() {
        if (pos < input.length() && (input[pos] == '+' || input[pos] == '-')) {
            cout << input[pos++] << " ";
            return T() && Eprime();
        }
        return true;
    }

    bool T() {
        cout << "T -> ";
        if (F()) {
            return Tprime();
        }
        return false;
    }

    bool Tprime() {
        if (pos < input.length() && (input[pos] == '*' || input[pos] == '/')) {
            cout << input[pos++] << " ";
            return F() && Tprime();
        }
        return true;
    }

    bool F() {
        cout << "F -> ";
        if (pos < input.length()) {
            if (isalnum(input[pos])) {
                cout << input[pos++] << " ";
                return true;
            } else if (input[pos] == '(') {
                cout << input[pos++] << " ";
                if (E()) {
                    if (pos < input.length() && input[pos] == ')') {
                        cout << input[pos++] << " ";
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string input;
    size_t pos;
};

int main() {
    string input;
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);

    RecursiveDescentParser parser(input);

    if (parser.parse()) {
        cout << "Expression is successfully parsed." << endl;
    } else {
        cout << "Error in parsing expression." << endl;
    }
    return 0;
}
