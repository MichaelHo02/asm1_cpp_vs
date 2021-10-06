#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void split_str(string* line, string* x, string* y, char delim);

bool isdigit(const string& s);

int main(int argc, char* argv[]) {

    if (argc > 2 || argc == 1) {
        cerr << "Invalid argument" << endl;
        cerr << "Enter with the following format: ./main <file_name.csv>" << endl;
    }

    int array_size = 0, current = 0;
    string line, x, y;

    string filename = argv[argc - 1];

    ifstream input_file(argv[argc - 1]);

    if (!input_file.is_open()) {
        cerr << "Cannot open the file" << endl;
        return -1;
    }

    while (!input_file.eof()) {
        getline(input_file, line);
        if (!line.empty()) {
            array_size++;
        }
    }
    line.clear();
    input_file.clear();
    input_file.seekg(0);

    auto* x_arr = new long double[array_size];
    auto* y_arr = new long double[array_size];

    while (!input_file.eof()) {
        getline(input_file, line);
        if (!line.empty()) {
            // todo: move the func to a different files
            split_str(&line, &x, &y, ',');
            // Testing
            cout << x << " and " << y << endl;
            // todo: move the func to a different files
            if (!isdigit(x) || !isdigit(y)) {
                x.clear();
                y.clear();
                array_size--;
                continue;
            }

            if (current < array_size) {
                x_arr[current] = stold(x);
                y_arr[current] = stold(y);
            }

            x.clear();
            y.clear();
            current++;
        }
    }

    line.clear();
    input_file.close();

    //todo: calculate all the function

    return 0;
}

void split_str(string* line, string* x, string* y, char delim) {
    size_t pos = 0;
    while ((pos = line->find(delim)) == string::npos) {}
    *x = line->substr(0, pos);
    line->erase(0, pos + strlen(&delim));
    *y = *line;
}

bool isdigit(const string& s) {
    return s.find_first_not_of("0123456789") == string::npos;
}