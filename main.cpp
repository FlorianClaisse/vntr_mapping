#include <iostream>
#include <filesystem>
#include <cstring>
#include <map>

#include "csv.hpp"

#define ANNEE "Année"
#define CAVE "Cave"
#define STAGE "Stade d'isolement"
#define PROFILS "Profils_Cognac"

using namespace std;
using namespace csv;
namespace fs = std::filesystem;

using MyWriter = DelimWriter<ofstream, ';', '"', true>;

int usage() {
    cout << "Usage : \n"
         << "./vntr_mapping <filepath>\n\n"
         << "\t<filepath>\tPath to input file (csv format)\n"
         << "\t-h --help\tTo view help\n";

    return -1;
}

int main(int argc, const char **argv) {
    if (argc != 2)
        return usage();

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        return usage() + 1;

    if (!fs::exists(argv[1]))
        return usage();

    CSVReader reader{argv[1]};

    // [annee, [cave, [stade, [profil, nb]]]]
    map<int, map<int, map<int, map<int, int>>>> value;
    for (const auto &row: reader) {
        int annee = row[ANNEE].get<int>();
        int cave = row[CAVE].get<int>();
        int stade = row[STAGE].get<int>();
        int profils = row[PROFILS].get<int>();

        if (value.find(annee) == value.end() ||
            value[annee].find(cave) == value[annee].end() ||
            value[annee][cave].find(stade) == value[annee][cave].end() ||
            value[annee][cave][stade].find(profils) == value[annee][cave][stade].end())
            value[annee][cave][stade][profils] = 1;
        else
            value[annee][cave][stade][profils] += 1;
    }

    ofstream output{fs::path{argv[1]}.parent_path() / "output.csv"};
    MyWriter writer{output};

    auto col_names = reader.get_col_names();
    col_names.emplace_back("Number");
    writer << col_names;

    for (const auto &annee: value) {
        for (const auto &cave: annee.second) {
            for (const auto &stade: cave.second) {
                for (const auto &profils: stade.second) {
                    vector<int> line;
                    line.push_back(annee.first);
                    line.push_back(cave.first);
                    line.push_back(stade.first);
                    line.push_back(profils.first);
                    line.push_back(profils.second);

                    writer << line;
                }
            }
        }
    }

    return 0;
}
