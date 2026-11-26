#include <iostream>
using namespace std;


//Every temlate func we write this line template <typename TypeOne, typename TypeToq, typename TypeThree> 
//type to return value
//ex
template <typename t1, typename t2, typename t3> 
t3 Sum(t1 Number1, t2 Number2)
{
	return (Number1 + Number2);
}


int main()
{
	cout << Sum<int, float, bool>(12, 53.663f);
	
	return 0;
}