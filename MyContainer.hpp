//agassinoa20@gmail.com
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

namespace Container {

    /// @brief Generic dynamic container class supporting various custom iterators
    /// @tparam T Element type (default: int)
    template<typename T = int>
    class MyContainer {

    private:
        std::vector<T> data;

    public:

        /// @brief Add a new element to the container
        /// @param val Value to add
        void add(const T& val) {
            data.push_back(val);
        }

        /// @brief Remove all occurrences of a given value
        /// @param val Value to remove
        /// @throws std::invalid_argument if value not found
        void remove(const T& val) {
            bool found = false;
            for (int i = static_cast<int>(this->data.size()) - 1; i >= 0; i--) {
                if (val == this->data[i]) {
                    this->data.erase(this->data.begin() + i);
                    found = true;
                }
            }
            if (!found) {
                throw std::invalid_argument("Element not found: cannot remove");
            }
        }

        /// @brief Get the current size of the container
        size_t size() const { return data.size(); }

        /// @brief Access the underlying data (read-only)
        const std::vector<T>& getData() const { return data; }

        //-------------------------------------------------------------

        /// @brief Iterator for insertion order traversal
        class Order {
        private:
            typename std::vector<T>::const_iterator iterator;

        public:
            /// @brief Constructor with iterator
            Order(typename std::vector<T>::const_iterator it) : iterator(it) {}

            const T& operator*() const { return *iterator; }
            const T* operator->() const { return iterator.operator->(); }

            Order& operator++() {
                ++iterator;
                return *this;
            }

            Order operator++(int) {
                Order temp = *this;
                ++iterator;
                return temp;
            }

            bool operator==(const Order& other) const { return iterator == other.iterator; }
            bool operator!=(const Order& other) const { return iterator != other.iterator; }
        };

        // =============================================
        /// @brief Iterator that traverses elements in ascending order
        class AscendingOrder {
        private:
            std::vector<T> sortedData;
            typename std::vector<T>::const_iterator iterator;
            size_t index;

        public:
            /// @brief Constructor for begin iterator
            /// @param rawData Raw input data
            AscendingOrder(const std::vector<T>& rawData)
                : sortedData(rawData), index(0)
            {
                std::sort(sortedData.begin(), sortedData.end());
                iterator = sortedData.begin();
            }

            /// @brief Constructor for end iterator
            /// @param rawData Raw input data
            /// @param isEnd Whether this is the end iterator
            AscendingOrder(const std::vector<T>& rawData, bool isEnd)
                : sortedData(rawData)
            {
                std::sort(sortedData.begin(), sortedData.end());
                if (isEnd) {
                    index = sortedData.size();
                    iterator = sortedData.end();
                } else {
                    index = 0;
                    iterator = sortedData.begin();
                }
            }

            const T& operator*() const { return *iterator; }
            const T* operator->() const { return iterator.operator->(); }

            /// @brief Prefix increment
            AscendingOrder& operator++() {
                ++index;
                ++iterator;
                return *this;
            }

            /// @brief Postfix increment
            AscendingOrder operator++(int) {
                AscendingOrder temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const AscendingOrder& other) const { return index == other.index; }
            bool operator!=(const AscendingOrder& other) const { return !(*this == other); }
        };

        // =============================================
        /// @brief Iterator that traverses elements in descending order
        class DescendingOrder {
        private:
            std::vector<T> sortedData;
            typename std::vector<T>::const_iterator iterator;
            size_t index;

        public:
            /// @brief Constructor for begin iterator
            /// @param rawData Raw input data
            DescendingOrder(const std::vector<T>& rawData): sortedData(rawData), index(0)
            {
                std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
                iterator = sortedData.begin();
            }

            /// @brief Constructor for end iterator
            /// @param rawData Raw input data
            /// @param isEnd Whether this is the end iterator
            DescendingOrder(const std::vector<T>& rawData, bool isEnd): sortedData(rawData)
            {
                std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
                if (isEnd) {
                    index = sortedData.size();
                    iterator = sortedData.end();
                } else {
                    index = 0;
                    iterator = sortedData.begin();
                }
            }

            const T& operator*() const { return *iterator; }
            const T* operator->() const { return iterator.operator->(); }

            DescendingOrder& operator++() {
                ++index;
                ++iterator;
                return *this;
            }

            DescendingOrder operator++(int) {
                DescendingOrder temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const DescendingOrder& other) const { return index == other.index; }
            bool operator!=(const DescendingOrder& other) const { return !(*this == other); }
        };

        /// @brief Iterator that traverses elements in alternating low-high order
        class SideCrossOrder {
        private:
            std::vector<T> sortedData;
            size_t left;
            size_t right;
            size_t index;

        public:
            /// @brief Constructor for begin iterator
            SideCrossOrder(const std::vector<T>& rawData): sortedData(rawData), left(0), index(0) {
                std::sort(sortedData.begin(), sortedData.end());
                right = sortedData.size() - 1;
            }

            /// @brief Constructor for end iterator
            SideCrossOrder(const std::vector<T>& rawData, bool isEnd): sortedData(rawData) {
                std::sort(sortedData.begin(), sortedData.end());
                if (isEnd) {
                    left = sortedData.size();
                    right = sortedData.size();
                    index = sortedData.size();
                } else {
                    left = 0;
                    right = sortedData.size() - 1;
                    index = 0;
                }
            }

            const T& operator*() const {
                return (index % 2 == 0) ? sortedData[left] : sortedData[right];
            }

            const T* operator->() const {
                return &(index % 2 == 0 ? sortedData[left] : sortedData[right]);
            }

            SideCrossOrder& operator++() {
                if (index % 2 == 0) ++left;
                else --right;
                ++index;
                return *this;
            }

            SideCrossOrder operator++(int) {
                SideCrossOrder temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const SideCrossOrder& other) const { return index == other.index; }
            bool operator!=(const SideCrossOrder& other) const { return !(*this == other); }
        };

        /// @brief Iterator that traverses elements in reverse order
        class ReverseOrder {
        private:
            typename std::vector<T>::const_reverse_iterator iterator;

        public:
            /// @brief Constructor with reverse iterator
            ReverseOrder(typename std::vector<T>::const_reverse_iterator it) : iterator(it) {}

            const T& operator*() const { return *iterator; }
            const T* operator->() const { return iterator.operator->(); }

            ReverseOrder& operator++() {
                ++iterator;
                return *this;
            }

            ReverseOrder operator++(int) {
                ReverseOrder temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const ReverseOrder& other) const { return iterator == other.iterator; }
            bool operator!=(const ReverseOrder& other) const { return iterator != other.iterator; }
        };

        /// @brief Iterator that traverses elements starting from the middle
        class MiddleOutOrder {
        private:
            const std::vector<T>& data;
            size_t pos;
            std::vector<size_t> indices;

            void indicesOrder() {
                const size_t len = data.size();
                if (len == 0) return;
                indices.reserve(len);
                size_t mid = (len - 1) / 2;  // center index (rounded down)
                indices.push_back(mid);
                size_t offset = 1;
                while (indices.size() < len) {
                    if (mid >= offset)
                        indices.push_back(mid - offset);
                    if (mid + offset < len)
                        indices.push_back(mid + offset);
                    ++offset;
                }
            }

        public:
            /// @brief Constructor for begin iterator
            MiddleOutOrder(const std::vector<T>& rowData): data(rowData), pos(0) {
                indicesOrder();
            }

            /// @brief Constructor for end iterator
            MiddleOutOrder(const std::vector<T>& rawData, bool isEnd) : data(rawData) {
                if (!isEnd) {
                    indicesOrder();
                    pos = 0;
                } else {
                    pos = data.size();
                }
            }

            const T& operator*() const { return data[indices[pos]]; }
            const T* operator->() const { return &data[indices[pos]]; }

            MiddleOutOrder& operator++() {
                ++pos;
                return *this;
            }

            MiddleOutOrder operator++(int) {
                MiddleOutOrder temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const MiddleOutOrder& other) const { return pos == other.pos; }
            bool operator!=(const MiddleOutOrder& other) const { return !(*this == other); }
        };

        //-------------------------------------------------------------

        Order beginOrder() const { return Order(data.begin()); }
        Order endOrder() const { return Order(data.end()); }

        AscendingOrder beginAscending() const { return AscendingOrder(data); }
        AscendingOrder endAscending() const { return AscendingOrder(data, true); }

        DescendingOrder beginDescending() const { return DescendingOrder(data); }
        DescendingOrder endDescending() const { return DescendingOrder(data, true); }

        SideCrossOrder beginSideCross() const {return SideCrossOrder(this->data);}
        SideCrossOrder endSideCross() const {return SideCrossOrder(this->data, true);}

        ReverseOrder reverse_begin() const {return ReverseOrder(data.crbegin());}
        ReverseOrder reverse_end() const {return ReverseOrder(data.crend());}

        MiddleOutOrder beginMiddleOut() const { return MiddleOutOrder(this->data); }
        MiddleOutOrder endMiddleOut() const { return MiddleOutOrder(this->data, true); }
    };

    /// @brief Output operator for MyContainer
    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const MyContainer<T>& container) {
        stream << '[';
        const char* separator = "";
        for (const auto& item : container.getData()) {
            stream << separator << item;
            separator = ",";
        }
        stream << ']';
        return stream;
    };
}
