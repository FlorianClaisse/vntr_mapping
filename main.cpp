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
        for (const auto &v2: v1.second) {
            vector<string> line;
            line.push_back(v1.first);
            line.push_back(v2.first);
            line.push_back(to_string(v2.second));

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

int search6(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
                            vector<string> line;
                            line.push_back(v1.first);
                            line.push_back(v2.first);
                            line.push_back(v3.first);
                            line.push_back(v4.first);
                            line.push_back(v5.first);
                            line.push_back(v6.first);
                            line.push_back(to_string(v6.second));

                            writer << line;
                        }
                    }
                }
            }
        }
    }
}

int search7(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
                                vector<string> line;
                                line.push_back(v1.first);
                                line.push_back(v2.first);
                                line.push_back(v3.first);
                                line.push_back(v4.first);
                                line.push_back(v5.first);
                                line.push_back(v6.first);
                                line.push_back(v7.first);
                                line.push_back(to_string(v7.second));

                                writer << line;
                            }
                        }
                    }
                }
            }
        }
    }
}

int search8(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
                                    vector<string> line;
                                    line.push_back(v1.first);
                                    line.push_back(v2.first);
                                    line.push_back(v3.first);
                                    line.push_back(v4.first);
                                    line.push_back(v5.first);
                                    line.push_back(v6.first);
                                    line.push_back(v7.first);
                                    line.push_back(v8.first)
                                    line.push_back(to_string(v8.second));

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

int search9(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
                                        vector<string> line;
                                        line.push_back(v1.first);
                                        line.push_back(v2.first);
                                        line.push_back(v3.first);
                                        line.push_back(v4.first);
                                        line.push_back(v5.first);
                                        line.push_back(v6.first);
                                        line.push_back(v7.first);
                                        line.push_back(v8.first)
                                        line.push_back(v9.first)
                                        line.push_back(to_string(v9.second));

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

int search10(CSVReader &reader, vector<string> &cols_name, const string &output_path) {
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
                                            vector<string> line;
                                            line.push_back(v1.first);
                                            line.push_back(v2.first);
                                            line.push_back(v3.first);
                                            line.push_back(v4.first);
                                            line.push_back(v5.first);
                                            line.push_back(v6.first);
                                            line.push_back(v7.first);
                                            line.push_back(v8.first)
                                            line.push_back(v9.first)
                                            line.push_back(v10.first)
                                            line.push_back(to_string(v10.second));

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
        case 2:
            search1(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 3:
            search2(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 4:
            search3(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 5:
            search4(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 6:
            search5(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 7:
            search6(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 8:
            search7(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 9:
            search8(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 10:
            search9(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        case 11:
            search10(reader, cols_name, (fs::path(argv[1]).parent_path() / "output.csv"));
            break;
        default:
            return usage();
    }

    return 0;
}
