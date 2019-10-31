//
// Created by sergey on 10/31/19.
//

#include "support_functions.h"

void print_vec_pair(std::vector<std::pair<int, int>>& v) {

    for (const auto& a : v) {
        std::cout << "(" << a.first << ", " << a.second << ") ";
    }
    std::cout << std::endl;
}

bool compare_pairs(std::pair<int, int>& a, std::pair<int, int>& b) {

    if (a.second == b.second)
        return true;
    else
        return false;
}


size_t find_seq_len (std::vector<std::pair<int, int>> & data, size_t start, size_t end) {

    size_t len = 0;
    if (start == end) {
        return 1;
    }
    do {
        len++;
    } while (  compare_pairs(data[start], data[start+len])  );

    return len;
}

bool is_present(std::vector<std::pair<int, int>>& data, std::pair<int, int>& p) {
    if (data.back().first == p.first) {
        return true;
    }
    else {
        return false;
    }
}