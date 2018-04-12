#include "MathSet.h"
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
SCALER_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::DotProduct( const THIS_TYPE_T& other )
{
	auto inOrder = SmallerThanOrEqual( other );
	const std::size_t MAX_SIZE = ( ( THIS_TYPE_T& ) ( std::get< 0 >( inOrder ) ) ).size();
	auto result = std::get< 0 >( inOrder ) * std::get< 1 >( inOrder );
	return result.sum();
}
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Translate( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Scale( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::UniformScale( SCALER_TYPE_T scaler, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Rotate( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Assign( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Add( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Subtract( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Multiply( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::Divide( const THIS_TYPE_T& other, bool set = false );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator[]( std::size_t index );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator+( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator-( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator*( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T MathSet< SCALER_TYPE_T, DIMENTIONS >::operator/( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T& MathSet< SCALER_TYPE_T, DIMENTIONS >::operator+=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T& MathSet< SCALER_TYPE_T, DIMENTIONS >::operator-=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T& MathSet< SCALER_TYPE_T, DIMENTIONS >::operator*=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
THIS_TYPE_T& MathSet< SCALER_TYPE_T, DIMENTIONS >::operator/=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
bool MathSet< SCALER_TYPE_T, DIMENTIONS >::operator>( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
bool MathSet< SCALER_TYPE_T, DIMENTIONS >::operator<( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
bool MathSet< SCALER_TYPE_T, DIMENTIONS >::operator>=( const THIS_TYPE_T& other );
template< typename SCALER_TYPE_T, SCALER_TYPE_T DIMENTIONS >
bool MathSet< SCALER_TYPE_T, DIMENTIONS >::operator<=( const THIS_TYPE_T& other );
