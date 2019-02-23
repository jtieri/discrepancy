#include <iostream>
#include <filesystem>
#include <string>

/*
 * discrepancy [-arguments] [source_directory] [target_directory]
 *
 * discrepancy searches for files in the target directory that are not present in the source directory
 *
 * The default search is a shallow search of only the specified directories given at runtime. Currently, failure to
 * provide two directories will result in an error.
 *
 * -r, --recursive-search
 *      Recursively search the target directory
 * -s, --sort-lexicographically
 *      Sort the results in lexicographical order, also known as word order or alphabetical order
 */

void recursive_search(const std::string &source_dir, const std::string &target_dir);

void shallow_search(const std::string &dir_name);

int main(int argc, char *argv[]) {
    /*
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
     */

    if (argc < 3) {
        std::cout << "You have failed to provide two directories, aborting process" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        recursive_search(argv[1], argv[2]);
    }

    exit(EXIT_SUCCESS);
}

//TODO compare the two vectors and display the files not in the source dir that are in the target dir
void recursive_search(const std::string &source_dir, const std::string &target_dir) {
    std::vector<std::string> source_contents, target_contents, results;

    // Put contents from the source directory into a vector
    for (auto& dir_entry : std::filesystem::recursive_directory_iterator(source_dir)) {
        source_contents.push_back(dir_entry.path().string().substr(dir_entry.path().string().find_last_of('/') + 1));
    }

    // Put contents from the target directory into a vector
    for (auto& dir_entry : std::filesystem::recursive_directory_iterator(target_dir)) {
        target_contents.push_back(dir_entry.path().string().substr(dir_entry.path().string().find_last_of('/') + 1));
    }


    // Step through the contents of both directories and place results in a new vector
    for (auto& target_entry : target_contents) {
        for (auto& source_entry : source_contents) {
            if (source_entry == target_entry) {
                continue;
            }

            results.push_back(target_entry);
        }
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

