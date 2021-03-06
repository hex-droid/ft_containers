#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include <iostream>
# include <iterator>

namespace ft{
	template <class T>
		class Iterator : public std::iterator<std::random_access_iterator_tag, T>{
			public:
				typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
				typedef	typename std::iterator<std::random_access_iterator_tag, T>::value_type		value_type;
				typedef	typename std::iterator<std::random_access_iterator_tag, T>::pointer		pointer;
				typedef	const pointer	const_pointer;
				typedef	typename std::iterator<std::random_access_iterator_tag, T>::reference		reference;
				typedef	typename std::iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
				//Is default-constructible, copy-constructible, copy-assignable, destructible i.e (X a; X b(a); b = a;)
				Iterator(pointer ptr) : _ptr(ptr){}
				Iterator(void) : _ptr(nullptr){}
				Iterator(Iterator const &obj) {*this = obj;}
				~Iterator(void){}
				// Iterator &operator = (pointer addr){_ptr = addr; return *this; }
				Iterator &operator = (const Iterator &rhs) {
					//std::cout << "random_access assignment overload" << std::endl;
					if (this != &rhs){
						_ptr = rhs._ptr;
					}
					return *this;
				}
				//Use of non member overload is necessary
				//Can be compared for equivalence using the equality/inequality operators i.e (a == b; a != b;)
				//bool operator == (Iterator const &rhs){ return _ptr == rhs.get_ptr(); }
				//bool operator != (Iterator const &rhs){ return _ptr != rhs.get_ptr(); }

				//Can be dereferenced as an rvalue i.e (*a; a->m;)
				//For mutable iterators (non-constant) i.e (*a = t)
				pointer operator -> (void){ return _ptr; }
				reference operator * (void){//std::cout << "random access iterator * operator val-> " << *_ptr << std::endl; 
					return *_ptr; }

				//Can be incremented i.e (++a, a++, *a++)
				Iterator operator ++ (int){
					Iterator<T> tmp = *this;
					this->_ptr++;
					return tmp;
				}
				Iterator operator ++ (void){
					this->_ptr++;
					return *this;
				}

				//Can be decremented
				Iterator operator -- (int){
					Iterator<T> tmp = *this;
					this->_ptr--;
					return tmp;
				}
				Iterator operator -- (void){
					this->_ptr--;
					return *this;
				}

				//Arithmetic overload
				Iterator operator + (difference_type n) const{
					return Iterator(_ptr + n);
				}
				Iterator operator - (difference_type n) const{
					return Iterator(_ptr - n);
				}

				//Compound assignment operators += -=
				Iterator operator += (difference_type n){
					_ptr += n;
					return *this;
				}
				Iterator operator -= (difference_type n){
					_ptr -= n;
					return *this;
				}

				// offset dereference operator []
				value_type &operator [] (difference_type n){
					return *(_ptr + n);	
				}
				// Conversion operator
				operator Iterator<const T>() const{
					//std::cout << "random access iterator conversion operator" << std::endl;
					return Iterator<const T>(_ptr);
				}
				//Getter for _ptr private member
				pointer get_ptr(void) const{
					return _ptr;
				}
			private:
				pointer _ptr;
		};

	// non member overloads
	
	//Arithmetic overloads
	template<class T>
		Iterator<T>	operator + (typename std::iterator<std::random_access_iterator_tag, T>::difference_type n, Iterator<T> const &rhs)
		{
			Iterator<T> tmp;
			tmp = n + rhs.get_ptr();
			return tmp;
		}

	template<class T>
		typename std::iterator<std::random_access_iterator_tag, T>::difference_type	operator - (Iterator<T> const &lhs, Iterator<T> const &rhs)
		{
			return lhs.get_ptr() - rhs.get_ptr();
		}

	//Comparison
	template<class T1, class T2>
		bool	operator == (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() == rhs.get_ptr();
		}
	template<class T1, class T2>
		bool	operator != (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() != rhs.get_ptr();
		}
	template<class T1, class T2>
		bool	operator < (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() < rhs.get_ptr();
		}

	template<class T1, class T2>
		bool	operator > (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() > rhs.get_ptr();
		}

	template<class T1, class T2>
		bool	operator <= (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() <= rhs.get_ptr();
		}

	template<class T1, class T2>
		bool	operator >= (Iterator<T1> const &lhs, Iterator<T2> const &rhs)
		{
			return lhs.get_ptr() >= rhs.get_ptr();
		}
	// ostream operator overload
	template<class T>
		std::ostream	&operator << (std::ostream &o, Iterator<T> const &obj)
		{
			o << "Address: " << std::hex << obj.get_ptr() << std::endl;
			o << "Value: " << *obj.get_ptr() << std::endl;
			return o;
		}
}
#endif
