#include <iostream>
#include <filesystem>
#include <string>

/*
 * discrepancy [-arguments] [source_directory] [target_directory]
 *
 * discrepancy searches for files in the target directory that are not present in the source directory
 *
 * The default search is a shallow search of only the specified directories given at runtime
 *
 * -r, --recursive-search
 *      Recursively search the target directory
 * -s, --sort-lexicographically
 *      Sort the results in lexicographical order, also known as word order or alphabetical order
 */

void recursive_search(const std::string &source_dir, const std::string &target_dir);

void shallow_search(const std::string &dir_name);

int main(int argc, char *argv[]) {
    // TODO design a parser for the CLI arguments & implement a better system for turning them on
    if (argc > 2) {
        std::string raw_input = argv[1];

        char shell_input = raw_input.at(1);

        switch (shell_input) {
            case 'r':
                recursive_search(argv[2], argv[3]); // TODO remove hard coded test values
                break;
            default:
                std::cout << "Invalid argument\n"; // TODO make more verbose error logging
        }

    } else {
        shallow_search(argv[1]);
    }

    exit(EXIT_SUCCESS);
}

//TODO compare the two vectors and display the files not in the source dir that are in the target dir
void recursive_search(const std::string &source_dir, const std::string &target_dir) {
    std::vector<std::string> source_contents, target_contents;

    for (auto& dir_entry : std::filesystem::recursive_directory_iterator(source_dir)) {
        source_contents.push_back(dir_entry.path().string().substr(dir_entry.path().string().find_last_of('/') + 1));
    }

    for (auto& dir_entry : std::filesystem::recursive_directory_iterator(target_dir)) {
        target_contents.push_back(dir_entry.path().string().substr(dir_entry.path().string().find_last_of('/') + 1));
    }

    /* Testing...testing...
    for (const std::string &source_file : source_contents) {
        for (const std::string &target_file : target_contents) {
            std::cout << source_file << " | " << target_file << std::endl;
        }
    } */
}

//TODO finish this function just like the recursive counterpart
void shallow_search(const std::string &dir_name) {
    for (auto& dir_entry : std::filesystem::directory_iterator(dir_name)) {
        std::cout << dir_entry.path().string().substr(dir_entry.path().string().find_last_of('/') + 1) << std::endl;
    }
}

