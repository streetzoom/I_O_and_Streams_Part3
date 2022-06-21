#include <iostream>
#include <fstream>
#include <string>

bool find_substring(const std::string &string, const std::string &substring) {
    size_t was_found = string.find(substring);
    if (was_found == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

int main() {
    std::ifstream in_file;
    in_file.open("../romeoandjuliet.txt");
    if (!in_file) {
        std::cerr << "Error: can't open the file" << std::endl;
        std::exit(1);
    }

    std::string string{};
    std::string substring{};
    int match_words{0};
    int total_words{0};

    std::cout << "Enter the substring to search for:";
    std::cin >> substring;

    while (in_file >> string) {
        ++total_words;
        if (find_substring(string, substring)) {
            ++match_words;
            std::cout << string << "   ";
        }
    }

    std::cout << "\n" << total_words << " words were searched..." << std::endl;
    std::cout << "The substring " << substring << " was found " << match_words << " times" << std::endl;

    in_file.close();
    return 0;
}

