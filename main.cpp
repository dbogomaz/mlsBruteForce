/* File config.txt:
num = 123
str = hello
flt = 12.2
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Config {
    int    num;
    string str;
    double flt;
};

void loadConfig(Config& config) {
    ifstream fin("../config.txt");
    string line;
    while (getline(fin, line)) {
        istringstream sin(line.substr(line.find("=") + 1));
        if (line.find("num") != -1)
            sin >> config.num;
        else if (line.find("str") != -1)
            sin >> config.str;
        else if (line.find("flt") != -1)
            sin >> config.flt;
    }
}

ostream &operator<< (ostream &ostr, Config &cfg) {
    ostr << cfg.num << "-" << cfg.str << "-" << cfg.flt;
    return ostr;
};

istream &operator>> (istream &istr, Config &cfg) {
    istr >> cfg.num;
    istr >> cfg.str;
    istr >> cfg.flt;

    return istr;
};


int main() {
    Config config;
    loadConfig(config);
    cout << config.num << '\n';
    cout << config.str << '\n';
    cout << config.flt << '\n';

    cout << "-->";
    cin >> config;


    cout << endl;
    cout << config << endl;

}
