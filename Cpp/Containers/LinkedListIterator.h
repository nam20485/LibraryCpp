#pragma once

#include <iterator>

template<typename TValue> class LinkedList;

/**

    @class   LinkedListIterator
    @brief   Allows iterating an instance of LinkedList<TValue>
    @details ~ Designed in the style of the STL container iterators. 
			   Allows compatibility and use with the range-based for loop and all of the STL algorithms, e.g. std::find, std::for_each, and others in <algorithms>, etc.
			   Use LinkedList<TValue>::iterator member for instantiating this class.
    @tparam  TValue - type of value of the list that the iterator will be used for

**/
template<typename TValue>
class LinkedListIterator
{
public:

	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = typename std::remove_cv<TValue>::type;
	using difference_type = std::ptrdiff_t;
	using pointer = value_type*;
	using reference = value_type&;

	/**
		@brief Create a LinkedListIterator pointing to no position
	**/
	constexpr LinkedListIterator() noexcept
		: LinkedListIterator(nullptr)
	{}	

	/**
		@brief  Allows de-referencing of the iterator to return the current value
		@retval  - TValue reference to the value the iterator is currently pointing to
	**/
	reference operator*();

	/**
		@brief  Advances the iterator forward by one position
		@retval  - iterator instance advanced forward by one poistion
	**/
	const LinkedListIterator<TValue>& operator++();

	/**
		@brief  Advances the iterator forward by one position
		@retval  - iterator instance advanced forward by one poistion
	**/
	const LinkedListIterator<TValue> operator++(int);

	/**
		@brief  Advances the iterator backward by one position
		@retval  - iterator instance advanced backward by one position
	**/
	const LinkedListIterator<TValue>& operator--();

	/**
		@brief  Advances the iterator backward by one position
		@retval  - iterator instance advanced backward by one position
	**/
	const LinkedListIterator<TValue> operator--(int);

	/**
		@brief  Tests equality against the provided iterator
		@param  other - iterator to test equality against
		@retval       - false if both iterators point at the same position in the list, true otherwise
	**/
	bool operator==(const LinkedListIterator<TValue>& other);

	/**
		@brief  Tests inequality against the provided iterator
		@param  other - iterator to test inequality against
		@retval       - true if both iterators point at the same position in the list, false otherwise
	**/
	bool operator!=(const LinkedListIterator<TValue>& other);

protected:
	LinkedList<TValue>::Node* current;

	// Create a LinkedListIterator pointing to the provided position
	explicit constexpr LinkedListIterator(LinkedList<TValue>::Node* current) noexcept
		: current(current)
	{}

	friend class LinkedList<value_type>;
};

template<typename TValue>
inline LinkedListIterator<TValue>::reference LinkedListIterator<TValue>::operator*()
{
	return current->data;
}

template<typename TValue>
inline const LinkedListIterator<TValue>& LinkedListIterator<TValue>::operator++()
{
	current = current->next;
	return *this;
}

template<typename TValue>
inline const LinkedListIterator<TValue> LinkedListIterator<TValue>::operator++(int)
{
	return this->operator++();
}

template<typename TValue>
inline const LinkedListIterator<TValue>& LinkedListIterator<TValue>::operator--()
{
	current = current->prev;
	return *this;
}

template<typename TValue>
inline const LinkedListIterator<TValue> LinkedListIterator<TValue>::operator--(int)
{
	return this->operator--();
}

template<typename TValue>
inline bool LinkedListIterator<TValue>::operator==(const LinkedListIterator<TValue>& other)
{
	//return other.current != nullptr && this->current == other.current;
	return current == other.current;
}

template<typename TValue>
inline bool LinkedListIterator<TValue>::operator!=(const LinkedListIterator<TValue>& other)
{
	//return ! (*this).operator==(other);
	return !(*this == other);
}


template<typename TValue>
class ConstLinkedListIterator : public LinkedListIterator<TValue>
{
public:
	constexpr ConstLinkedListIterator() noexcept
		: ConstLinkedListIterator(nullptr)
	{}	
	
	const LinkedListIterator<TValue>::reference operator*() const;

private:
	constexpr explicit ConstLinkedListIterator(LinkedList<TValue>::Node* current) noexcept
		: LinkedListIterator<TValue>(current)
	{}

};

template<typename TValue>
inline const LinkedListIterator<TValue>::reference ConstLinkedListIterator<TValue>::operator*() const
{
	return this->current->data;
}
