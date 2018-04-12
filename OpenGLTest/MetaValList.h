#include "GLDebugLog.h"

#ifndef GL_TEST_META_VAL_LIST_H
#define GL_TEST_META_VAL_LIST_H


template< typename SCALER_TYPE_T >
struct MetaValListSlice
{
	MetaValListSlice();
	MetaValListSlice( SCALER_TYPE_T start_, SCALER_TYPE_T size_, SCALER_TYPE_T stride_ );
	MetaValListSlice( const MetaValListSlice< SCALER_TYPE_T >& other );
	SCALER_TYPE_T start, size, stride;
};

template< typename SCALER_TYPE_T >
struct MetaValListGSlice
{
	MetaValListSlice();
	MetaValListSlice( SCALER_TYPE_T start_, std::valarray< SCALER_TYPE_T > sizes_, 
			std::valarray< SCALER_TYPE_T > strides_ );
	MetaValListSlice( const MetaValListGSlice< SCALER_TYPE_T >& other );
	SCALER_TYPE_T start;
	std::valarray< SCALER_TYPE_T > sizes, strides
};


template<  typename ELEMENT_TYPE_T, typename VALARRAY_HELPER_ARRAY_T >
struct MetaValListHelperArray
{
	MetaValListHelperArray( const VALARRAY_HELPER_ARRAY_T& other );
	MetaValListHelperArray() = delete;
	void operator+=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator-=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator*=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator/=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator%=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator&=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator|=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator^=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator<<=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator>>=( const std::valarray< ELEMENT_TYPE_T >& other ) const;
	void operator=( const  ELEMENT_TYPE_T& value ) const;
	void operator=( const std::valarray< ELEMENT_TYPE_T >& valueArray ) const;
	const VALARRAY_HELPER_ARRAY_T& operator=( const VALARRAY_HELPER_ARRAY_T& sl_arr ) const;
};

template< typename ELEMENT_TYPE_T, typename SCALER_TYPE_T >
struct MetaValList
{
	typedef std::valarray< ELEMENT_TYPE_T > VALARRAY_T;
	typedef MetaValList< ELEMENT_TYPE_T, SCALER_TYPE_T > THIS_T;
	VALARRAY_T& headReference;
	VALARRAY_T* head, *tail;
	SCALER_TYPE_T length;
	constexpr inline VALARRAY_T* At( const SCALER_TYPE_T INDEX );
	constexpr inline VALARRAY_T* Iterate();
	void Add( SCALER_TYPE_T index );
	void Remove( SCALER_TYPE_T index );
	void Push();
	void Pop();


	//std::valarray interface copy.//

	//Math Operators.//

	//Binary.//
	THIS_T operator+() const;
	THIS_T operator-() const;
	THIS_T operator~() const;
	MetaValList< bool, SCALER_TYPE_T > operator!() const;

	//Unary.//
	THIS_T operator+=( const THIS_T& other );
	THIS_T operator-=( const THIS_T& other );
	THIS_T operator*=( const THIS_T& other );
	THIS_T operator/=( const THIS_T& other );
	THIS_T operator%=( const THIS_T& other );
	THIS_T operator&=( const THIS_T& other );
	THIS_T operator|=( const THIS_T& other );
	THIS_T operator^=( const THIS_T& other );
	THIS_T operator<<=( const THIS_T& other );
	THIS_T operator>>=( const THIS_T& other );
	THIS_T operator+=( const ELEMENT_TYPE_T& value );
	THIS_T operator-=( const ELEMENT_TYPE_T& value );
	THIS_T operator*=( const ELEMENT_TYPE_T& value );
	THIS_T operator/=( const ELEMENT_TYPE_T& value );
	THIS_T operator%=( const ELEMENT_TYPE_T& value );
	THIS_T operator&=( const ELEMENT_TYPE_T& value );
	THIS_T operator|=( const ELEMENT_TYPE_T& value );
	THIS_T operator^=( const ELEMENT_TYPE_T& value );
	THIS_T operator<<=( const ELEMENT_TYPE_T& value );
	THIS_T operator>>=( const ELEMENT_TYPE_T& value );

	//Sum.//
	ELEMENT_TYPE_T sum() const;

	//Other methods.//
	void swap( VALARRAY_T& other );
	std::size_t size() const;
	void resize( std::size_t count, ELEMENT_TYPE_T value = ELEMENT_TYPE_T() );
	ELEMENT_TYPE_T sum() const;
	ELEMENT_TYPE_T min() const;
	ELEMENT_TYPE_T max() const;
	THIS_T shift( int count ) const;
	VALARRAY_T cshift( int count ) const;
	VALARRAY_T apply( ELEMENT_TYPE_T function( ELEMENT_TYPE_T ) ) const;
	VALARRAY_T apply( ELEMENT_TYPE_T function( const ELEMENT_TYPE_T& ) ) const;
};

/*template< typename ELEMENT_TYPE_T, typename SCALER_TYPE_T >
MetaValList< ELEMENT_TYPE_T, SCALER_TYPE_T, LENGTH >::*/

#endif
