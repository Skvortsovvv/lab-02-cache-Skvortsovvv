// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic pop
#define DUP(x) x x x x x x x x x x
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
void Backward(int* p, int val, std::ofstream& backwardfile) {
    [[maybe_unused]] int k = 0;
    for (int i = 0; i < val; i += 16) {
        p[i] = val - i - 16;
    }
    for (int i = val-16; i > 0; i -= 16) {  //prerun
        k = p[i];
    }
    int i = 0;
    double N = 100000;
    auto t_start = std::chrono::high_resolution_clock::now(); // run
    for (size_t j = 0; j < N; ++j) {
        DUP(DUP(DUP(i = p[i];)));
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    i = 1;
    auto time = std::chrono::duration<double,
    std::nano>(t_end - t_start).count()
        / pow(10, 9) *(!!i);
    backwardfile << "(" << val * (4 / 1048576.) << ";" << time << ") ";
    std::cout << "All time: " << std::chrono::duration<double,
    std::nano>(t_end - t_start).count() << " nsec for all massive for: ";
    std::cout << val * (4 / 1048576.) << " mbyte" << std::endl;
}
void Forward(int* p, int val, std::ofstream& forwardfile) {
    [[maybe_unused]] int k = 0;
    for (int i = 0; i < val; i+=16) {
        p[i] = i + 16;
    }
    p[val - 16] = 0;
    for (int i = 0 ; i < val; i+=16) {
        k = p[i];
    }
    int i = 0;
    double N = 100000;
    auto t_start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < N; ++j) {
        DUP(DUP(DUP(i = p[i];)));
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration<double,
    std::nano>(t_end - t_start).count()
        / pow(10, 9) * (!!i); // converting in seconds
    forwardfile << "(" << val * (4 / 1048576.) << ";" << time << ") ";
    // converting into mbytes and write into file
    std::cout << "All time: " << std::chrono::duration<double,
    std::nano>(t_end - t_start).count() << " nsec for all massive for: ";
    std::cout << val * (4 / 1048576.) << " mbyte" << std::endl;
}
void Random(int* p, int val, std::ofstream& randomfile) {
    for (int i = 0; i < val; i += 16) {
        p[i] = i + 16;
    }
    p[val - 16] = 0;
    for (int i = 0; i < val; i += 16) {
        int rindex = std::rand() % val/16;
        rindex *= 16;
        int temp = p[i];
        p[i] = p[rindex];
        p[rindex] = temp;
    }
    [[maybe_unused]] int k = 0;
    for (int i = 0; i < val; i += 16) {
        k = p[i];
    }
    int i = 0;
    double N = 100000;
    auto t_start = std::chrono::high_resolution_clock::now();
    for (size_t j = 0; j < N; ++j) {
        DUP(DUP(DUP(i = p[i];)));
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration<double,
    std::nano>(t_end - t_start).count()
        / pow(10, 9) * (!!i); // converting in seconds
    randomfile <<"(" << val * (4 / 1048576.) << ";" << time << ") ";
    // converting into mbytes and write into file
    std::cout << "All time: " << std::chrono::duration<double,
    std::nano>(t_end - t_start).count() << " nsec for all massive for: ";
    std::cout << val * (4 / 1048576.) << " mbyte" << std::endl;
}
void Experement(std::vector<int> v) {
    std::string path1 = "forward.txt";
    std::ofstream forward;
    forward.open(path1);
    if (!forward) {
        std::cout << "file 1 not found" << std::endl;
        throw(-1);
    }
    std::string path2 = "backward.txt";
    std::ofstream backward;
    backward.open(path2);
    if (!backward) {
        std::cout << "file 2 not found" << std::endl;
        throw(-1);
    }
    std::string path3 = "random.txt";
    std::ofstream random;
    random.open(path3);
    if (!random) {
        std::cout << "file 3 not found" << std::endl;
        throw(-1);
    }
    std::cout << "Forward Acces: " << std::endl;
    for (int val : v) {
        val *= 1024;
        val = val / 4;
        int* massive = new int[val];
        Forward(massive, val, forward);
        delete[]massive;
    }
    std::cout << "Backward Acces: " << std::endl;
    for (int val : v) {
        val *= 1024;
        val = val / 4;
        int* massive = new int[val];
        Backward(massive, val, backward);
        delete[]massive;
    }
    std::cout << "Random Acces: " << std::endl;
    for (auto val : v) {
        val *= 1024;
        val = val / 4;
        int* massive = new int[val];
        for (int i = 0; i < val; ++i) {
            massive[i] = std::rand();
        }
        Random(massive, val, random);
        delete[]massive;
    }
}
#endif // INCLUDE_HEADER_HPP_
