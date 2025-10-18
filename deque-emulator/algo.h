#pragma once

#include <deque>

template<class T, class Comp>
std::deque<T> Merge(const std::deque<T>& half1, const std::deque<T>& half2, const Comp& comparator) {
    std::deque<T> result;
    auto idx1 = half1.begin();
    auto idx2 = half2.begin();

    while (idx1 != half1.end() && idx2 != half2.end()) {
        if (comparator(*idx1, *idx2)) {
            result.push_back(*idx1);
            idx1++;
        } else {
            result.push_back(*idx2);
            idx2++;
        }
    }

    // Добавляем оставшиеся элементы
    while (idx1 != half1.end()) {
        result.push_back(*idx1);
        idx1++;
    }

    while (idx2 != half2.end()) {
        result.push_back(*idx2);
        idx2++;
    }

    return result;
}

template<class T, class Comp>
std::deque<T> MergeSort(const std::deque<T>& src, const Comp& comparator) {
    // Реализуйте рекурсивную функцию MergeSort
    // на основе задачи из урока о рекурсии.

    if (src.size() <= 1) {
        return src;
    }

    const size_t mid = src.size() / 2;
    const std::deque<T> left_sorted = MergeSort(std::deque(src.begin(), src.begin() + mid), comparator);
    const std::deque<T> right_sorted = MergeSort(std::deque(src.begin() + mid, src.end()), comparator);

    return Merge(left_sorted, right_sorted, comparator);
}
