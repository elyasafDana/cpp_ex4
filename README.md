# 🧱 MyContainer – Custom Iterable Container (C++)

A templated container class in C++ that supports multiple custom iteration orders.  
The container allows you to add, remove, and traverse elements in **six different ways**.

---

## ✨ Features

- ✅ Generic container `MyContainer<T>` based on `std::vector`
- ✅ Support for insertion, deletion, and direct access
- ✅ 6 custom iterator types:
  - `Order` – default (insertion) order
  - `AscendingOrder` – increasing numerical order
  - `DescendingOrder` – decreasing numerical order
  - `ReverseOrder` – reversed insertion order
  - `MiddleOutOrder` – from center outwards
  - `SideCrossOrder` – smallest, largest, second smallest, second largest...

---

---

## 🧪 Unit Testing

The project includes tests written using [doctest](https://github.com/doctest/doctest).

### ✅ Covered Iterators:
- Ascending
- Descending
- Reverse
- Side-Cross
- Middle-Out
- Default Order
### ▶️ Run tests:
To compile  all Main file:
make Main

### ▶️ Run tests

To compile  all tests:
make test

### ▶️ Run valngrid:
make Valngrid

