#include "GLDebugLog.h"

#ifndef GL_TEST_GL_POINT_H
#define GL_TEST_GL_POINT_H

enum class MATH_SET_TYPE
{
	SCALER = 0, 
	POINT = 1, 
	VECTOR = 2, 
	QUATERNION = 3, 
	MATRIX = 4, 
	POLYIGINAL_GEOMETRY = 5, 
};
//Helper class.//
template< typename SCALER_TYPE_T >
struct ScalerModel
{
	std::function< SCALER_TYPE_T( const SCALER_TYPE_T&, const SCALER_TYPE_T& ) > add, subtract, multiply, divide;
	std::function< bool( const SCALER_TYPE_T&, const SCALER_TYPE_T& ) > greaterThan, lessThan,
		greaterThanOrEqual, lessThanOrEqual, isEqual;
	THIS_TYPE_T Add( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Subtract( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Multiply( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Divide( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T operator[]( std::size_t index );
	THIS_TYPE_T operator=( const THIS_TYPE_T& other );
	THIS_TYPE_T operator+( const THIS_TYPE_T& other );
	THIS_TYPE_T operator-( const THIS_TYPE_T& other );
	THIS_TYPE_T operator*( const THIS_TYPE_T& other );
	THIS_TYPE_T operator/( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator+=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator-=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator*=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator/=( const THIS_TYPE_T& other );
	bool operator>( const THIS_TYPE_T& other );
	bool operator<( const THIS_TYPE_T& other );
	bool operator>=( const THIS_TYPE_T& other );
	bool operator<=( const THIS_TYPE_T& other );
	bool operator==( const THIS_TYPE_T& other );
};
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
struct MathSet
{
	MATH_SET_TYPE type;
	typedef MathSet< SCALER_TYPE_T, SCALER_TYPE_T > THIS_TYPE_T;
	typedef std::tuple< std::valarray< SCALER_TYPE_T >&, std::valarray< SCALER_TYPE_T >& > COMPONENT_SIZE_COMPARE_T;
	THIS_TYPE_T* head, *next, *previous, *tail;
	SCALER_TYPE_T length;
	const SCALER_TYPE_T position;
	const SCALER_TYPE_T DIMENTIONS_C = DIMENTIONS;
	//Replace with a linked list of these; allocate on heap next to eachother.//
	std::valarray< SCALER_TYPE_T > components;
	MathSet( THIS_TYPE_T* head_ = nullptr, THIS_TYPE_T* next_ = nullptr, 
			THIS_TYPE_T* previous_ = nullptr, THIS_TYPE_T* tail_ = nullptr ) : 
			head( head_ ), next( next_ ), previous( previous_ ), tail( tail_ ) {
	}
	SCALER_TYPE_T DotProduct( const THIS_TYPE_T& other );
	THIS_TYPE_T Translate( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Scale( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T UniformScale( SCALER_TYPE_T scaler, bool set = false );
	THIS_TYPE_T Rotate( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Assign( const THIS_TYPE_T& other );
	THIS_TYPE_T Add( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Subtract( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Multiply( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T Divide( const THIS_TYPE_T& other, bool set = false );
	THIS_TYPE_T operator[]( std::size_t index );
	THIS_TYPE_T operator=( const THIS_TYPE_T& other );
	THIS_TYPE_T operator+( const THIS_TYPE_T& other );
	THIS_TYPE_T operator-( const THIS_TYPE_T& other );
	THIS_TYPE_T operator*( const THIS_TYPE_T& other );
	THIS_TYPE_T operator/( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator+=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator-=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator*=( const THIS_TYPE_T& other );
	THIS_TYPE_T& operator/=( const THIS_TYPE_T& other );
	bool operator>( const THIS_TYPE_T& other );
	bool operator<( const THIS_TYPE_T& other );
	bool operator>=( const THIS_TYPE_T& other );
	bool operator<=( const THIS_TYPE_T& other );
	bool operator==( const THIS_TYPE_T& other );
	COMPONENT_SIZE_COMPARE_T SmallerOrEqual( const std::valarray< SCALER_TYPE_T >& other );
	COMPONENT_SIZE_COMPARE_T LargerOrEqual( const std::valarray< SCALER_TYPE_T >& other );
	constexpr inline SCALER_TYPE_T SUM_COMPONENTS_CE();
};

template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
inline COMPONENT_SIZE_COMPARE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::SmallerOrEqual( const std::valarray< SCALER_TYPE_T >& other ) {
	constexpr ( other.size() > components.size() ) ? return COMPONENT_SIZE_COMPARE_T{ std::move( components ), other } : 
			return COMPONENT_SIZE_COMPARE_T{ other, std::move( components ) };
}
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
inline COMPONENT_SIZE_COMPARE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::LargerOrEqual( const std::valarray< SCALER_TYPE_T >& other ) {
	constexpr ( other.size() < components.size() ) ? return COMPONENT_SIZE_COMPARE_T{ other, std::move( components ) } :
		return COMPONENT_SIZE_COMPARE_T{ std::move( components ), other };
}

template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
constexpr SCALER_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::SUM_COMPONENTS_CE() {
	constexpr return components.sum() + ( ( next != nullptr ) ? next->SUM_COMPONENTS_CE() : 0 );
}

template< typename LIST_T >
constexpr PreviousAssign( LIST_T* node, LIST_T* tail ) {
	list->tail = tail;
	if( list->previous != nullptr )
		PreviousAssign( list->previous, tail );
}

template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS, const SCALER_TYPE_T POSITION = 0 >
constexpr MathSet< SCALER_TYPE_T, DIMENTIONS >* MakeMathSet( std::function< SCALER_TYPE_T( SCALER_TYPE_T, std::size_t ) > division, 
		std::function< bool( SCALER_TYPE_T, std::size_t ) > modulo, std::function< SCALER_TYPE_T( SCALER_TYPE_T ) > absoluteValue,
		SCALER_TYPE_T pass = DIMENTIONS, MathSet< SCALER_TYPE_T, DIMENTIONS >* head = nullptr, 
		MathSet< SCALER_TYPE_T, DIMENTIONS >* previous = nullptr, MathSet< SCALER_TYPE_T, DIMENTIONS >* tail = nullptr )
{
	static const std::numaric_limits< std::size_t > size_tLimit;
	overflow = subtract( absoluteValue( pass ), size_tLimit.max() );
	MathSet< SCALER_TYPE_T, DIMENTIONS >* mathSet = new MathSet< SCALER_TYPE_T, DIMENTIONS >( nullptr, previous, tail );
	if( oveflow <= ( ( int ) ( 0 ) ) ) {
		PreviousAssign( mathSet, mathSet );
		return mathSet;
	}
	else {
		mathSet->next = MakeMathSet< SCALER_TYPE_T, DIMENTIONS, ( POSITION + 1 ) >( 
				subtract, lessThanOrEqualTo, overflow, mathSet, nullptr );
	}
}

#endif
