#ifndef COMP6771_RING_H
#define COMP6771_RING_H

#include <cstddef>
#include <iterator>

/*
Behavior:
- When the buffer is full, writing may either:
- Overwrite the oldest data (if allowed)
- Block or fail (if not allowed)
- When the buffer is empty, reads may return nothing or block.


*/
template<typename T, std::size_t N>
class Ring {
public:

    template<typename InputIt>
	Ring(InputIt first, InputIt last)
	: head_{0}
	, tail_{0}
	, size_{0} {
		if (static_cast<std::size_t>(std::distance(first, last)) > N) {
			throw std::invalid_argument{"Not enough capacity"};
		}
		for (; first != last; ++first)
			do_push(*first);
	}


	Ring(std::initializer_list<T> il)
	: Ring(il.begin(), il.end()) {}

    // Do notthing when full
    auto push(const T& t) -> void {
		if (size_ < N) {
			do_push(t);
		}
	}

    // See head elem
    auto peek() const -> const T& {
		return elems_[head_];
	}

    // Call do pop
	auto pop() -> void {
		if (size_ > 0) {
			do_pop();
		}
	}

	auto size() const -> std::size_t {
		return size_;
	}


private:
    // Push to tail
	auto do_push(const T& t) {
		elems_[tail_++] = t;
		tail_ %= N;
		size_++;
	}

    // Pop head out, replace head if needed
	auto do_pop() {
		// head_ = ++head_ % N;
        head_ = (head_ + 1) % N;
		size_--;
	}

	std::size_t head_;
	std::size_t tail_;
	std::size_t size_;
	T elems_[N];
};

// Crucial for cases like this: Ring r{1, 2, 3, 4, 5};
// Because sizeof...(Ts) + 1 means
// couting the number of parse in parameter
template<typename T, typename... Ts>
Ring(T, Ts...) -> Ring<T, sizeof...(Ts) + 1>;



#endif // COMP6771_RING_H
