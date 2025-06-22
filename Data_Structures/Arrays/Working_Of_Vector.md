
# Understanding std::vector in C++ – A Complete Guide

## 📘 Introduction
`std::vector` is a part of the C++ Standard Template Library (STL) and is one of the most commonly used data structures. It acts as a **dynamic array**, allowing you to store elements in a contiguous memory block, with automatic resizing as needed.

This document serves as an **in-depth guide and reference** to understand how vectors work, both from the outside (APIs) and the inside (implementation).

---

## 🚀 Features of `std::vector`
- Dynamic resizing
- Contiguous memory allocation
- Random access via indexing
- STL compatibility (iterators, algorithms)
- Template-based and type-safe

---

## 🧠 Internal Structure
A `std::vector<T>` manages three key pointers internally:

```cpp
T* _start;          // Start of allocated storage
T* _finish;         // End of used elements
T* _end_of_storage; // End of allocated storage
```

### 📐 Layout in Memory
```
[_start .................. _finish .......... _end_of_storage]
[   used elements         |   unused reserved memory        ]
```

---

## 🧱 Memory Management & Allocation

### 1. No Initial Allocation
Declaring a vector like `std::vector<int> v;` allocates no memory until an element is inserted.

### 2. Growth Strategy
When the capacity is exceeded:
- A new memory block is allocated, typically **double** the current capacity.
- Existing elements are **copied or moved** to the new block.
- Old memory is deallocated.

This makes `push_back()` **amortized O(1)**.

### 3. Custom Allocator
Vectors use `std::allocator<T>` by default, which uses `new[]` and `delete[]`.

---

## ⚙️ Commonly Used Methods

| Method                | Description |
|-----------------------|-------------|
| `push_back(val)`      | Adds `val` at the end |
| `pop_back()`          | Removes last element |
| `size()`              | Returns number of elements |
| `capacity()`          | Returns allocated capacity |
| `resize(n)`           | Changes size to `n` |
| `reserve(n)`          | Allocates space for `n` elements |
| `clear()`             | Removes all elements |
| `empty()`             | Checks if vector is empty |
| `at(i)`               | Safe access with bounds checking |
| `operator[i]`         | Direct element access (no bounds check) |
| `front()` / `back()`  | Access first/last element |
| `insert(pos, val)`    | Insert value at given position |
| `erase(pos)`          | Remove element at given position |
| `begin()` / `end()`   | Iterators to start/end |

---

## 📊 Time Complexities

| Operation        | Time Complexity |
|------------------|-----------------|
| `push_back`      | Amortized O(1)  |
| `insert`         | O(n)            |
| `erase`          | O(n)            |
| `access [i]`     | O(1)            |
| `resize`         | O(n)            |

---

## 🔎 How `push_back()` Works Internally

```cpp
void push_back(const T& val) {
    if (_finish == _end_of_storage) {
        reallocate(); // Allocate bigger space and move elements
    }
    *_finish = val;
    ++_finish;
}
```

### 📦 `reallocate()` Example

```cpp
void reallocate() {
    size_t new_capacity = current_capacity * 2;
    T* new_storage = allocator.allocate(new_capacity);
    std::copy(_start, _finish, new_storage);
    destroy_and_deallocate_old();
    _start = new_storage;
    _finish = _start + old_size;
    _end_of_storage = _start + new_capacity;
}
```

---

## 🧪 Custom Implementation (Simplified)

```cpp
template<typename T>
class SimpleVector {
private:
    T* data;
    size_t capacity;
    size_t length;
public:
    SimpleVector() : data(nullptr), capacity(0), length(0) {}

    void push_back(const T& val) {
        if (length == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[length++] = val;
    }

    void reserve(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < length; ++i) new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

    size_t size() const { return length; }
    T& operator[](size_t i) { return data[i]; }
};
```

---

## 📈 Flowchart: Vector Expansion Process

```
[Element Inserted] 
        |
[Is Capacity Full?] -- No --> [Insert at End]
        |
       Yes
        |
[Allocate New Block (2x)]
        |
[Move Old Elements]
        |
[Insert New Element]
        |
[Free Old Memory]
```

---

## 📌 Best Practices
- Use `reserve()` when size is known ahead of time
- Prefer `emplace_back()` over `push_back()` for object construction
- Avoid unnecessary copies — use `std::move()` where possible

---

## 📚 References
- [cplusplus.com – vector](https://cplusplus.com/reference/vector/vector/)
- [cppreference.com – std::vector](https://en.cppreference.com/w/cpp/container/vector)
- GCC/libstdc++ implementation of `std::vector`

---

## 💬 Contribute
If you have insights, code snippets, or corrections — feel free to fork and contribute!

---

**Author:** Saksham Sharma  
