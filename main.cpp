#include <iostream>
#include <vector>
#include "support_functions.h"

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


int main()
{
    std::vector<std::pair<int, int>> data;
    data.push_back({ 1, 10 });
    data.push_back({ 2, 11 });
    data.push_back({ 3, 11 });
    data.push_back({ 4, 11 });
    data.push_back({ 5, 11 });
    data.push_back({ 6, 10 });
    data.push_back({ 7, 11 });
    data.push_back({ 8, 11 });
    data.push_back({ 9, 11 });
    data.push_back({ 10, 11 });
    data.push_back({ 11, 11 });
    data.push_back({ 12, 11 });
    data.push_back({ 13, 11 });
    data.push_back({ 14, 10 });

    auto result3 = decimation(data, 3);
    auto result4 = decimation(data, 4);

    print_vec_pair(data);
    std::cout << std::endl;

    print_vec_pair(result3);
    std::cout << std::endl;

    print_vec_pair(result4);
    std::cout << std::endl;

}