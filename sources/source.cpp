// Copyright 2018 Your Name <your_email>
#include <header.hpp>
int main() {
    std::vector<int> sizes;
    for (int i = 4; i < 16; ++i) {
        sizes.push_back(4 * i);
    }
    for (int i = 1; i < 16; ++i) {
        sizes.push_back(64 * i);
    }
    for (int i = 1; i < 33; ++i) {
        sizes.push_back(256 * i);
    }
    try {
        Experement(sizes);
    }
    catch (int a) {
        return a;
    }
}
