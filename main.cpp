#include <iostream>
#include <vector>
#include <list>
#include "support_functions.h"

void decimate (std::list<std::pair<int, int>> & data, int N) {

    if (N <= 2 || data.size() == 0) {
        return;
    }

    size_t size = data.size();
    int count = 1;
    auto it = data.begin();
    auto it_end = data.end();

    while (it != it_end) {

        if (count == 1 || count % N == 0 || !compare_pairs(*it, *std::next(it)) ) {

            if (!compare_pairs(*it, *std::next(it))) {
                count = 1;
            } else {
                count++;
            }
            it++;
        }
        else {
            it++;
            data.erase(std::prev(it));
            it_end = data.end();
            count++;
        }
    }

}


int main()
{
    std::list<std::pair<int, int>> data;
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
    std::list<std::pair<int, int>> data2(data);

    print_list_pair(data);
    decimate(data, 3);
    print_list_pair(data);
    decimate(data2, 4);
    print_list_pair(data2);

}