#include <iostream>
#include <thread>
#include <chrono>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Provide an integer between 0 and 10000. Exiting" << std::endl;
        return 1;
    }

    int64_t seconds;

    try {
        seconds = std::stoi(argv[1]);
    } catch (const std::invalid_argument &ex) {
        std::cerr << "The provided argument, \"" << argv[1] << "\", is not an integer." << std::endl;
        return 1;
    }

    for (auto i = 0; i < seconds; i++) {
        std::cout << "Sleeping for 1 second." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Finished." << std::endl;
    return 0;
}
