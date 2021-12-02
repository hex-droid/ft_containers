#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	// ft::pair
	template <class T1, class T2>
		struct pair{
			typedef T1 first_type;
			typedef T2 second_type;
			pair(void) : first(0), second(0){}
			template <class U, class V>
				pair (const pair<U,V>& pr){
					*this = pr;
				}
			pair (const first_type& a, const second_type &b)
				: first(a), second(b){}
			pair& operator= (const pair& pr){
				if (this != &pr){
					first = pr.first;
					second = pr.second;
				}
				return *this;
			}
			first_type	first;
			second_type	second;
		};
	template<class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}
	template<class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(lhs==rhs);
		}
	template<class T1, class T2>
		bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}
	template<class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(rhs<lhs);
		}
	template <class T1, class T2>
		bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return rhs<lhs;
		}
	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>&lhs, const pair<T1,T2>& rhs){
			return !(lhs<rhs);
		}
	// ft::make_pair
	//
	template <class T1, class T2>
		pair<T1,T2>	make_pair(T1 x, T2 y){
			return pair<T1,T2>(x,y);
		}

	template <class T1, class T2>
		std::ostream	&operator<<(std::ostream& o, pair<T1,T2>const & rhs){
			o << "first: " << rhs.first << " | second: " << rhs.second << std::endl;
			return o;
		}
}

#endif