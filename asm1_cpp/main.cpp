#include <iostream>
#include <string>
#include <fstream>
#include "descriptive_statistics.h"
#include "inferential_statistics.h"


using namespace std;

void split_str(string* line, string* x, string* y, char delim);

bool isdigit(const string& s);

int main(int argc, char* argv[]) {

    if (argc > 2 || argc == 1) {
        cerr << "Invalid argument" << endl;
        cerr << "Enter with the following format: ./main <file_name.csv>" << endl;
        return -1;
    }

    int array_size = 0, current = 0;
    string line, x, y;

    ifstream input_file(argv[argc - 1], ifstream::in);

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

    auto* x_arr = new int[array_size];
    auto* y_arr = new int[array_size];

    while (!input_file.eof()) {
        getline(input_file, line);
        if (!line.empty()) {
            // todo: move the func to a different files
            split_str(&line, &x, &y, ',');
            // todo: move the func to a different files
            if (!isdigit(x) || !isdigit(y)) {
                x.clear();
                y.clear();
                array_size--;
                continue;
            }

            if (current < array_size) {
                x_arr[current] = stoi(x);
                y_arr[current] = stoi(y);
            }

            x.clear();
            y.clear();
            current++;
        }
    }

    line.clear();
    input_file.close();

    //todo: calculate all the function

    cout << "\noriginal numbers: " << endl;
    for (int i = 0; i < array_size; ++i) {
        cout << x_arr[i] << " " << y_arr[i] << endl;
    }

    cout << endl;
    // Calculate the median
    cout << "median_x = " << median(x_arr, array_size);
    cout << " - median_y = " << median(y_arr, array_size) << endl;
    //cout << "skew_x= " << skewness(x_arr, array_size) <<" - skew_y= " << skewness(y_arr, array_size);

    // Debugging for inferential statistics
    cout << "number of rows: " << array_size << endl;
    //cout << x_arr << endl;
    cout << "\ncov(x_y) = " << CalculateCovariance(x_arr, y_arr, array_size) << endl; // SAMPLE, not POPULATION

    delete[] x_arr;
    delete[] y_arr;

    return 0;
}

void split_str(string* line, string* x, string* y, char delim) {
    size_t pos = 0;
    pos = line->find(delim);
    *x = line->substr(0, pos);
    line->erase(0, pos + strlen(&delim));
    *y = *line;
}

bool isdigit(const string& s) {
    return s.find_first_not_of("0123456789") == string::npos;
}