#pragma once
#include<vector>
#include <stdexcept>
#include <optional>
#include <algorithm>
#include <iterator> 



template <typename T>
class Range {
public:

	Range() {}

	Range(const std::vector<T>& vec) : arr(vec) {}

	Range& operator=(const Range& other) {
		if (this != &other) {
			arr(other.arr);
		}
		return *this;
	}

	Range(const Range& other) {
		arr(other.arr);
	}

	Range(Range&& other) noexcept : arr(other.arr) { }

	Range& operator=(Range&& other) noexcept {
		if (this != &other) {
			arr(other.arr);
		}
		return *this;
	}

	T first() {
		if (!arr.empty()) {
			return arr.front();
		}
		else {
			throw std::out_of_range("The vector is empty.");
		}
	}

	T last() {
		if (!arr.empty()) {
			return arr.back();
		}
		else {
			throw std::out_of_range("The vector is empty.");
		}
	}

	std::optional<T> find(T& value) {
		auto it = std::find(arr.begin(), arr.end(), value);
		if (it != arr.end()) {
			return value;
		}
		else {
			return std::nullopt;
		}
	}

	std::optional<int> findIndex(T& value) {
		auto it = std::find(arr.begin(), arr.end(), value);
		if (it != arr.end()) {
			return std::distance(arr.begin(), it);
		}
		else {
			return std::nullopt;
		}
	}

	bool exist(T& value) {
		auto it = std::find(arr.begin(), arr.end(), value);
		return it != arr.end();
	}

	Range<T> where(T& value) {
		std::vector<T> result;
		std::copy_if(arr.begin(), arr.end(), std::back_inserter(result),
			[value](int fvalue) { return fvalue == value; });
		return Range<T>(result);
	}

	std::vector<T> getVector() {
		return arr;
	}

	void push_back(T& value) {
		arr.push_back(value);
	}

	void insert(size_t pos, T& value) {
		arr.insert(pos, value);
	}

	void clear() {
		arr.clear();
	}

	void pop_back() {
		arr.pop_back();
	}

	void remove(const size_t index) {
		auto iter = arr.cbegin();
		arr.erase(iter + index);
	}

	void remove_range(const size_t index, const size_t lastindex) {
		if (lastindex < index) return;
		auto begin = arr.cbegin();
		arr.erase(begin + index);
		auto last = arr.cend();
		arr.erase(begin, last);
	}

	int size() {
		return arr.size();
	}

	bool empty() {
		return arr.empty();
	}

	T operator[]( const size_t index) {
		return arr.at(index);
	}

	const T operator[](const size_t index) const { return arr[index]; }

	typename std::vector<T>::iterator begin() { return arr.begin(); }
	typename std::vector<T>::iterator end() { return arr.end(); }
	typename std::vector<T>::const_iterator begin() const { return arr.begin(); }
	typename std::vector<T>::const_iterator end() const { return arr.end(); }

private:
	std::vector<T> arr;
};