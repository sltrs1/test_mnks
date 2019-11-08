//
// Created by sergey on 10/31/19.
//

#ifndef TEST_MNKS_SUPPORT_FUNCTIONS_H
#define TEST_MNKS_SUPPORT_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <list>

void print_vec_pair(std::vector<std::pair<int, int>>& v);

void print_list_pair(std::list<std::pair<int, int>>& v);

bool compare_pairs(std::pair<int, int>& a, std::pair<int, int>& b);

size_t find_seq_len (std::vector<std::pair<int, int>> & data, size_t start, size_t end);

bool is_present(std::vector<std::pair<int, int>>& data, std::pair<int, int>& p);

std::vector<std::pair<int, int>> decimation(std::vector<std::pair<int, int>>& data, int N);


#endif //TEST_MNKS_SUPPORT_FUNCTIONS_H
