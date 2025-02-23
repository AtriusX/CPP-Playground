#pragma once

#include <stdexcept>

namespace collections {

    template <typename T>
    class List {

    private:
        std::size_t arrSize;
        std::size_t count;
        T* arr;

        inline T* tryAlloc(const std::size_t size);

    public:
        List();

        explicit List(const std::size_t size);

        ~List();

        const T& get(const int index);

        void set(const int index, const T& value);

        void add(const T& element);

        void add(const int index, const T& element);

        void remove(const int index);

        void removeElement(const T& element);

        void clear();

        void reverse();

        std::size_t size() const;

        inline friend bool operator==(const List<T>& lhs, const List<T>& rhs) {
            if (lhs->count != rhs->count) {
                return false;
            }
    
            for (int i = 0; i < lhs->count; i++) {
                if (lhs->arr[i] != rhs->arr[i]) {
                    return false;
                }
            }
    
            return true;
        }
    };

    template<typename T>
    inline List<T>::List() : List(10) {}

    template<typename T>
    List<T>::List(const std::size_t size) : arr(tryAlloc(size)), arrSize(size), count(0) {}

    template<typename T>
    List<T>::~List() {
        delete[] arr;
    }

    template<typename T>
    const T& List<T>::get(const int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Out of range!");
        }

        return arr[index];
    }

    template<typename T>
    void List<T>::set(const int index, const T& value) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Out of range!");
        }

        arr[index] = value;
    }

    template<typename T>
    void List<T>::add(const T& element) {
        if (!arr) {
            arrSize = 10;
            arr = tryAlloc(arrSize);
        }

        if (count == arrSize) {
            // Reallocate
            arrSize *= 1.5;
            const auto& temp = tryAlloc(arrSize);

            if (!temp) {
                return;
            }

            for (int i = 0; i < count; i++) {
                temp[i] = arr[i];
            }

            delete arr;
            arr = temp;
        }
        arr[count] = element;
        count++;
    }

    template<typename T>
    void List<T>::add(const int index, const T& element) {
        if (!arr || index < 0 || index >= arrSize) {
            throw std::out_of_range("Out of range!");
        }

        if (count == arrSize) {
            // Reallocate
            arrSize *= 1.5;
            const auto& temp = tryAlloc(arrSize);

            if (!temp) {
                return;
            }
            // Insert pre-existing elements
            for (int i = 0; i < index; i++) {
                temp[i] = arr[i];
            }
            // Insert new element
            temp[index] = element;
            count++;
            // Shift remaining elements
            for (int i = index + 1; i < count; i++) {
                temp[i] = arr[i - 1];
            }

            delete[] arr;
            arr = temp;
            return;
        }
        // Shift elements over by one down to the index value
        for (int i = count - 1; i >= index; i--) {
            arr[i] = arr[i - 1];
        }
        // Insert new element
        arr[index] = element;
    }

    template<typename T>
    void collections::List<T>::remove(const int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Out of range!");
        }

        if (count <= arrSize / 2 && arrSize >= 10) {
            // Reallocate to 75%
            arrSize *= 0.75;
            const auto& temp = tryAlloc(arrSize);

            if (!temp) {
                return;
            }

            for (int i = 0, next = 0; i < count; i++) {
                if (i != index) {
                    temp[next++] = arr[i];
                }
            }

            count--;
            delete arr;
            arr = temp;
            return;
        }

        int i = index;
        while (i < count) {

            if (i != count - 1) {
                arr[i] = arr[i + 1];
            }

            i++;
        }

        count--;
    }

    template<typename T>
    void List<T>::removeElement(const T& element) {
        if (!element) {
            return;
        }

        if (count <= arrSize / 2 && arrSize >= 10) {
            // Reallocate to 75%
            arrSize *= 0.75;
            const auto& temp = tryAlloc(arrSize);

            if (!temp) {
                return;
            }

            int next = 0;

            for (int i = 0; i < count; i++) {
                if (arr[i] != element) {
                    temp[next++] = element;
                }
            }

            count = next;
            delete arr;
            arr = temp;
            return;
        }

        for (int i = count - 1; i >= 0; i--) {
            if (arr[i] == element) {
                remove(i);
            }
        }
    }

    template<typename T>
    void List<T>::reverse() {
        // Ensure the list can be reversed
        if (count <= 1) {
            return;
        }

        T temp;
        // Reverse items
        for (int i = 0; i < count / 2; i++) {
            auto swap = count - 1 - i;
            // Perform swap
            temp = arr[swap];
            arr[swap] = arr[i];
            arr[i] = temp;
        }
    }

    template<typename T>
    void List<T>::clear() {
        arrSize = 10;
        count = 0;
        const auto& temp = tryAlloc(arrSize);
        delete arr;
        arr = temp;
    }

    template<typename T>
    std::size_t List<T>::size() const {
        return count;
    }

    template<typename T>
    inline T* List<T>::tryAlloc(const std::size_t size) {
        return new(std::nothrow) T[size];
    }
}