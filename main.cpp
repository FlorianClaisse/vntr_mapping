#include <iostream>
#include <filesystem>
#include <cstring>
#include <map>

#include "csv.hpp"

using namespace std;
using namespace csv;
namespace fs = std::filesystem;

using MyWriter = DelimWriter<ofstream, ';', '"', true>;

int usage() {
    cout << "Usage : \n"
         << "./vntr_mapping <filepath> [columns name] <column count name>\n\n"
         << "\t<filepath>\t\tPath to input file (csv format)\n"
         << "\t[columns name]\t\tThe name of the columns to process.\n"
         << "\t\t\t\tKnowing that the sort order will be based on the order of the columns passed as an argument,\n"
         << "\t\t\t\tand that the last column name will be the column that will be counted. (Maximum 10)\n"
         << "\t<column count name>\tThe name of the column where the count is stored.\n"
         << "\t-h --help\t\tTo view help\n";

    return -1;
}

void search1(CSVReader &reader, const vector<string> &cols_name, const string &output_path) {
    map<string, int> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();

        if (value.find(v1) == value.end())
            value[v1] = 1;
        else
            value[v1] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        vector<string> line;
        line.push_back(v1.first);
        line.push_back(to_string(v1.second));

        writer << line;
    }
}

void search2(CSVReader &reader, vector<string> cols_name, const string &output_path) {
    map<string, map<string, int>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end())
            value[v1][v2] = 1;
        else
            value[v1][v2] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            vector<string> line;
            line.push_back(v1.first);
            line.push_back(v2.first);
            line.push_back(to_string(v2.second));

            writer << line;
        }
    }
}

void search3(CSVReader &reader, vector<string> cols_name, const string &output_path) {
    map<string, map<string, map<string, int>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end())
            value[v1][v2][v3] = 1;
        else
            value[v1][v2][v3] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                vector<string> line;
                line.push_back(v1.first);
                line.push_back(v2.first);
                line.push_back(v3.first);
                line.push_back(to_string(v3.second));

                writer << line;
            }
        }
    }
}

void search4(CSVReader &reader, vector<string> cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, int>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end())
            value[v1][v2][v3][v4] = 1;
        else
            value[v1][v2][v3][v4] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    vector<string> line;
                    line.push_back(v1.first);
                    line.push_back(v2.first);
                    line.push_back(v3.first);
                    line.push_back(v4.first);
                    line.push_back(to_string(v4.second));

                    writer << line;
                }
            }
        }
    }
}

void search5(CSVReader &reader, vector<string> cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, int>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end())
            value[v1][v2][v3][v4][v5] = 1;
        else
            value[v1][v2][v3][v4][v5] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        vector<string> line;
                        line.push_back(v1.first);
                        line.push_back(v2.first);
                        line.push_back(v3.first);
                        line.push_back(v4.first);
                        line.push_back(v5.first);
                        line.push_back(to_string(v5.second));

                        writer << line;
                    }
                }
            }
        }
    }
}

int search6(CSVReader &reader, vector<string> cols_name, const string &output_path);
int search7(CSVReader &reader, vector<string> cols_name, const string &output_path);
int search8(CSVReader &reader, vector<string> cols_name, const string &output_path);
int search9(CSVReader &reader, vector<string> cols_name, const string &output_path);
int search10(CSVReader &reader, vector<string> cols_name, const string &output_path);

// ./vntr_mapping <filepath> col1 col2 col3 ... nameLastCol
int main(int argc, const char **argv) {
    if (argc < 4)
        return usage();

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        return usage() + 1;

    if (!fs::exists(argv[1]))
        return usage();

    vector<string> cols_name;
    for (int i = 2; i < argc - 1; i++)
        cols_name.emplace_back(argv[i]);

    cols_name.emplace_back(argv[argc - 1]);

    CSVReader reader{argv[1]};

    switch (cols_name.size()) {
        case 1:
            search1(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 2:
            search2(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 3:
            search3(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 4:
            search4(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 5:
            search5(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        default:
            return usage();
    }

    return 0;
}
