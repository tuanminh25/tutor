#ifndef COMP6771_ROPE_H
#define COMP6771_ROPE_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
class rope {
    class iter {
		public:
			// 1.1 - iterator traits
			using iterator_category = std::bidirectional_iterator_tag; // 2.4
			using value_type = char;
			using reference = const value_type&;

			// using pointer = void; // this iterator does not return a raw pointer
			using difference_type = std::ptrdiff_t;

			iter() = default;

			friend class rope;

			auto operator++() -> iter& { // 1.4
				++inner_;
				while (outer_ != last_ and inner_ == outer_->end()) { // skip empty string as well
					++outer_;
					if (outer_ != last_) {
						inner_ = outer_->begin();
					}
				}
				return *this;
			}



			auto operator--() -> iter& { // 2.4
				// gotta do it the other way around, now
				// if we're at the end, step back until we find a non-empty string
				// (don't need to handle if they don't exist,
				//  since if so `--r.end()` doesn't make sense anyway)
				while (outer_ == last_ or inner_ == outer_->begin()) {
					--outer_;
					inner_ = outer_->end();
				}
				--inner_;
				return *this;
			}


			auto operator*() const -> reference { // 1.5
				return *inner_;
			}

			friend auto operator==(const iter& lhs, const iter& rhs) -> bool { // 1.6
				return lhs.outer_ == rhs.outer_ and
					(lhs.outer_ == lhs.last_ or lhs.inner_ == rhs.inner_);
			}


		private: // 1.2
			using outer_t = std::vector<std::string>::const_iterator;
			using inner_t = std::string::const_iterator;

			iter(outer_t first, outer_t last) // 1.3
				: last_(last), 
				outer_(std::find_if_not(first, last, [](const auto& s) { return s.empty(); })),
				inner_(outer_ == last_ ? inner_t{} : outer_->begin()) {}


			outer_t last_ {};
			outer_t outer_ {};
			inner_t inner_ {};

	};

public:
	using iterator = iter; // 1.6
	using const_iterator = iter; // 2.1
	using reverse_iterator = std::reverse_iterator<iterator>; // 2.4
	using const_reverse_iterator = std::reverse_iterator<const_iterator>; // 2.5

	rope() = default;

	explicit rope(std::vector<std::string> rope) : rope_{std::move(rope)} {} 
	// explicit prevents implicit conversion
	// like prevent Myclass A = 42

	auto begin() -> iterator { // 1.6
		return {rope_.begin(), rope_.end()};
	}

	auto end() -> iterator { // 1.6
		return {rope_.end(), rope_.end()};
	}


	auto begin() const -> const_iterator { // 2.1 - can be called on const rope
		return {rope_.begin(), rope_.end()};
	}

	auto end() const -> const_iterator { // 2.1 - can be called on const rope
		return {rope_.end(), rope_.end()};
	}


	auto cbegin() const -> const_iterator { // 2.3 - can be called on const rope
		return begin();
	}

	auto cend() const -> const_iterator { // 2.3 - can be called on const rope
		return end();
	}

	auto rbegin() -> reverse_iterator { // 2.4 - last element
		return reverse_iterator{ end() };
	}

	auto rend() -> reverse_iterator { // 2.4 - before the first element
		return reverse_iterator{ begin() };
	}

	auto rbegin() const -> const_reverse_iterator { // 2.5 - this is for const rope
		return reverse_iterator{ end() };
	}

	auto rend() const -> const_reverse_iterator { // 2.5 - this is for const rope
		return reverse_iterator{ begin() };
	}

	auto crbegin() const -> const_reverse_iterator { // 2.5 - this is for const rope
		return reverse_iterator{ end() };
	}

	auto crend() const -> const_reverse_iterator { // 2.5 - this is for const rope
		return reverse_iterator{ begin() };
	}


private:
	std::vector<std::string> rope_;

};

#endif // COMP6771_ROPE_H