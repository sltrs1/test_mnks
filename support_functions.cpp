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

void print_list_pair(std::list<std::pair<int, int>>& v) {
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

std::vector<std::pair<int, int>> decimation(std::vector<std::pair<int, int>>& data, int N) {

    if (N <= 2 || data.size() == 0) {
        return std::vector<std::pair<int, int>>();
    }

    std::vector<std::pair<int, int>> res;

    for (size_t i = 0; i < data.size(); ) {

        // Вычисляется длина подпоследоватльности
        size_t len = find_seq_len(data, i, data.size() - 1);

        // Добавляется первый элемент подпоследоватльности
        res.push_back(data[i]);

        // Добавляется каждый N-й элементподпоследоватльности
        for (size_t j = 1; j < len; j++) {
            if (j % N == 0) {
                res.push_back(data[i + j - 1]);
            }
        }

        // Если последний элемент подпоследоватльности не попал в результат
        // (последний не является первым или не является N-м),
        // то добавить его
        if (is_present(res, data[i + len - 1]) == false) {
            res.push_back(data[i + len - 1]);
        }

        // Пропуск обработанной подпоследоватльности
        i+=len;
    }

    return res;
}
