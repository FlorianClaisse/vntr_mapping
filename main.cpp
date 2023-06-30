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
         << "./vntr_mapping <filepath> [columns name]\n\n"
         << "\t<filepath>\t\tPath to input file (csv format)\n"
         << "\t[columns name]\t\tThe name of the columns to process.\n"
         << "\t\t\t\tKnowing that the sort order will be based on the order of the columns passed as an argument,\n"
         << "\t\t\t\tand that the last column name will be the column that will be counted. (Maximum 10)\n"
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
        array<string, 2> line{v1.first, to_string(v1.second)};
        writer << line;
    }
}

void search2(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
        long sum1{0}, lines1{0};
        for (const auto &v2: v1.second) {
            sum1 += v2.second, lines1++;
            array<string, 5> line{v1.first, v2.first, to_string(v2.second),
                                  (v2 == *v1.second.rbegin() ? to_string(sum1) : ""),
                                  (v2 == *v1.second.rbegin() ? to_string(lines1) : "")};
            writer << line;
        }
    }
}

void search3(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
        long sum1{0}, lines1{0};
        for (const auto &v2: v1.second) {
            long sum2{0}, lines2{0};
            for (const auto &v3: v2.second) {
                sum1 += v3.second, sum2 += v3.second, lines1++, lines2++;
                array<string, 8> line{v1.first, v2.first, v3.first, to_string(v3.second),
                                      (v3 == *v2.second.rbegin() ? to_string(sum2) : ""),
                                      (v3 == *v2.second.rbegin() ? to_string(lines2) : ""),
                                      (v2 == *v1.second.rbegin() ? to_string(sum1) : ""),
                                      (v2 == *v1.second.rbegin() ? to_string(lines1) : "")};
                writer << line;
            }
        }
    }
}

void search4(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
        long sum1{0}, lines1{0};
        for (const auto &v2: v1.second) {
            long sum2{0}, lines2{0};
            for (const auto &v3: v2.second) {
                long sum3{0}, lines3{0};
                for (const auto &v4: v3.second) {
                    sum1 += v4.second, sum2 += v4.second, sum3 += v4.second;
                    lines1++, lines2++, lines3++;
                    array<string, 11> line{v1.first, v2.first, v3.first, v4.first, to_string(v4.second),
                                          (v4 == *v3.second.rbegin() ? to_string(sum3) : ""),
                                          (v4 == *v3.second.rbegin() ? to_string(lines3) : ""),
                                          (v3 == *v2.second.rbegin() ? to_string(sum2) : ""),
                                          (v3 == *v2.second.rbegin() ? to_string(lines2) : ""),
                                          (v2 == *v1.second.rbegin() ? to_string(sum1) : ""),
                                          (v2 == *v1.second.rbegin() ? to_string(lines1) : "")};
                    writer << line;
                }
            }
        }
    }
}

void search5(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
        long sum1{0}, lines1{0};
        for (const auto &v2: v1.second) {
            long sum2{0}, lines2{0};
            for (const auto &v3: v2.second) {
                long sum3{0}, lines3{0};
                for (const auto &v4: v3.second) {
                    long sum4{0}, lines4{0};
                    for (const auto &v5: v4.second) {
                        array<string, 14> line{v1.first, v2.first, v3.first, v4.first, v5.first, to_string(v5.second),
                                               (v5 == *v4.second.rbegin() ? to_string(sum4) : ""),
                                               (v5 == *v4.second.rbegin() ? to_string(lines4) : ""),
                                               (v4 == *v3.second.rbegin() ? to_string(sum3) : ""),
                                               (v4 == *v3.second.rbegin() ? to_string(lines3) : ""),
                                               (v3 == *v2.second.rbegin() ? to_string(sum2) : ""),
                                               (v3 == *v2.second.rbegin() ? to_string(lines2) : ""),
                                               (v2 == *v1.second.rbegin() ? to_string(sum1) : ""),
                                               (v2 == *v1.second.rbegin() ? to_string(lines1) : "")};
                        writer << line;
                    }
                }
            }
        }
    }
}

void search6(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();
        string v6 = row[cols_name[5]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end() ||
            value[v1][v2][v3][v4][v5].find(v6) == value[v1][v2][v3][v4][v5].end())
            value[v1][v2][v3][v4][v5][v6] = 1;
        else
            value[v1][v2][v3][v4][v5][v6] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        for (const auto &v6: v5.second) {
                            array<string, 7> line{v1.first, v2.first, v3.first, v4.first, v5.first, v6.first, to_string(v6.second)};
                            writer << line;
                        }
                    }
                }
            }
        }
    }
}

void search7(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();
        string v6 = row[cols_name[5]].get();
        string v7 = row[cols_name[6]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end() ||
            value[v1][v2][v3][v4][v5].find(v6) == value[v1][v2][v3][v4][v5].end() ||
            value[v1][v2][v3][v4][v5][v6].find(v7) == value[v1][v2][v3][v4][v5][v7].end())
            value[v1][v2][v3][v4][v5][v6][v7] = 1;
        else
            value[v1][v2][v3][v4][v5][v6][v7] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        for (const auto &v6: v5.second) {
                            for (const auto &v7: v6.second) {
                                array<string, 8> line{v1.first, v2.first, v3.first, v4.first, v5.first, v6.first, v7.first, to_string(v7.second)};
                                writer << line;
                            }
                        }
                    }
                }
            }
        }
    }
}

void search8(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();
        string v6 = row[cols_name[5]].get();
        string v7 = row[cols_name[6]].get();
        string v8 = row[cols_name[7]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end() ||
            value[v1][v2][v3][v4][v5].find(v6) == value[v1][v2][v3][v4][v5].end() ||
            value[v1][v2][v3][v4][v5][v6].find(v7) == value[v1][v2][v3][v4][v5][v7].end() ||
            value[v1][v2][v3][v4][v5][v6][v7].find(v8) == value[v1][v2][v3][v4][v5][v7][v8].end())
            value[v1][v2][v3][v4][v5][v6][v7][v8] = 1;
        else
            value[v1][v2][v3][v4][v5][v6][v7][v8] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        for (const auto &v6: v5.second) {
                            for (const auto &v7: v6.second) {
                                for (const auto &v8: v7.second) {
                                    array<string, 9> line{v1.first, v2.first, v3.first, v4.first, v5.first, v6.first, v7.first, v8.first, to_string(v8.second)};
                                    writer << line;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void search9(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();
        string v6 = row[cols_name[5]].get();
        string v7 = row[cols_name[6]].get();
        string v8 = row[cols_name[7]].get();
        string v9 = row[cols_name[8]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end() ||
            value[v1][v2][v3][v4][v5].find(v6) == value[v1][v2][v3][v4][v5].end() ||
            value[v1][v2][v3][v4][v5][v6].find(v7) == value[v1][v2][v3][v4][v5][v7].end() ||
            value[v1][v2][v3][v4][v5][v6][v7].find(v8) == value[v1][v2][v3][v4][v5][v7][v8].end() ||
            value[v1][v2][v3][v4][v5][v6][v7][v8].find(v9) == value[v1][v2][v3][v4][v5][v7][v8][v9].end())
            value[v1][v2][v3][v4][v5][v6][v7][v8][v9] = 1;
        else
            value[v1][v2][v3][v4][v5][v6][v7][v8][v9] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        for (const auto &v6: v5.second) {
                            for (const auto &v7: v6.second) {
                                for (const auto &v8: v7.second) {
                                    for (const auto &v9: v8.second) {
                                        array<string, 10> line{v1.first, v2.first, v3.first, v4.first, v5.first, v6.first, v7.first, v8.first, v9.first, to_string(v9.second)};
                                        writer << line;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void search10(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
    map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>>>> value;
    for (const auto &row: reader) {
        string v1 = row[cols_name[0]].get();
        string v2 = row[cols_name[1]].get();
        string v3 = row[cols_name[2]].get();
        string v4 = row[cols_name[3]].get();
        string v5 = row[cols_name[4]].get();
        string v6 = row[cols_name[5]].get();
        string v7 = row[cols_name[6]].get();
        string v8 = row[cols_name[7]].get();
        string v9 = row[cols_name[8]].get();
        string v10 = row[cols_name[9]].get();

        if (value.find(v1) == value.end() ||
            value[v1].find(v2) == value[v1].end() ||
            value[v1][v2].find(v3) == value[v1][v2].end() ||
            value[v1][v2][v3].find(v4) == value[v1][v2][v3].end() ||
            value[v1][v2][v3][v4].find(v5) == value[v1][v2][v3][v4].end() ||
            value[v1][v2][v3][v4][v5].find(v6) == value[v1][v2][v3][v4][v5].end() ||
            value[v1][v2][v3][v4][v5][v6].find(v7) == value[v1][v2][v3][v4][v5][v7].end() ||
            value[v1][v2][v3][v4][v5][v6][v7].find(v8) == value[v1][v2][v3][v4][v5][v7][v8].end() ||
            value[v1][v2][v3][v4][v5][v6][v7][v8].find(v9) == value[v1][v2][v3][v4][v5][v7][v8][v9].end() ||
            value[v1][v2][v3][v4][v5][v6][v7][v8][v9].find(v10) == value[v1][v2][v3][v4][v5][v7][v8][v9][v10].end())
            value[v1][v2][v3][v4][v5][v6][v7][v8][v9][v10] = 1;
        else
            value[v1][v2][v3][v4][v5][v6][v7][v8][v9][v10] += 1;
    }

    ofstream output{output_path};
    MyWriter writer{output};

    writer << cols_name;

    for (const auto &v1: value) {
        for (const auto &v2: v1.second) {
            for (const auto &v3: v2.second) {
                for (const auto &v4: v3.second) {
                    for (const auto &v5: v4.second) {
                        for (const auto &v6: v5.second) {
                            for (const auto &v7: v6.second) {
                                for (const auto &v8: v7.second) {
                                    for (const auto &v9: v8.second) {
                                        for (const auto &v10: v9.second) {
                                            array<string, 11> line{v1.first, v2.first, v3.first, v4.first, v5.first, v6.first, v7.first, v8.first, v9.first, v10.first, to_string(v10.second)};
                                            writer << line;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void set_cols_name(vector<string> &cols_name) {
    vector<string> added_value;
    for (int i = 0; i < cols_name.size(); i++) {
        if (i == 0) added_value.push_back(string(cols_name[i]) + "_sum");
        else {
            added_value.push_back(string(cols_name[i]) + "_sum");
            added_value.push_back(string(cols_name[i]) + "_count");
        }
    }

    for (const auto &value: added_value)
        cols_name.push_back(value);
}

// ./vntr_mapping <filepath> col1 col2 col3 ...
int main(int argc, const char **argv) {
    if (argc < 3)
        return usage();

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        return usage() + 1;

    if (!fs::exists(argv[1]))
        return usage();

    vector<string> cols_name;
    for (int i = 2; i < argc; i++)
        cols_name.emplace_back(argv[i]);

    CSVReader reader{argv[1]};

    switch (cols_name.size()) {
        case 1:
            set_cols_name(cols_name);
            search1(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 2:
            set_cols_name(cols_name);
            search2(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 3:
            set_cols_name(cols_name);
            search3(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 4:
            set_cols_name(cols_name);
            search4(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 5:
            set_cols_name(cols_name);
            search5(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 6:
            set_cols_name(cols_name);
            search6(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 7:
            set_cols_name(cols_name);
            search7(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 8:
            set_cols_name(cols_name);
            search8(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 9:
            set_cols_name(cols_name);
            search9(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 10:
            set_cols_name(cols_name);
            search10(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        default:
            return usage();
    }

    return 0;
}
