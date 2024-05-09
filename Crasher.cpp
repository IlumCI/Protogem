#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // Open this source code file
    std::ifstream src(__FILE__);
    if (!src.is_open()) {
        std::cerr << "Error: Could not open source file.\n";
        return 1;
    }

    // Open a new file for writing
    std::ofstream copy("copy.cpp");
    if (!copy.is_open()) {
        std::cerr << "Error: Could not create copy file.\n";
        return 1;
    }

    // Copy the content of this source code to the new file
    copy << src.rdbuf();

    // Close file streams
    src.close();
    copy.close();

    // Compile the copied file
    system("g++ copy.cpp -o copy");

    // Execute the compiled file
    system("./copy");

    return 0;
}
