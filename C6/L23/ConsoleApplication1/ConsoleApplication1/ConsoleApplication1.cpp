#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int Page = 1;
	int TotalPages = 10;

	printf("The Page Is = %d \n", Page);
	printf("You Are In Page %d Of %d\n", Page, TotalPages);
	printf("The Sum Of Page And Total Pages is :%d \n", Page + TotalPages);
	printf("I'm In the page Number %d \n Of total Pages : %d \n", Page, TotalPages);
	printf("I am in page number %d Page and i live in page number %d\n", Page, 00);


	int Number = 1;
	printf("This format Whine Number Must Be 2 digits %0*d\n", 2, Number);
	printf("This format Whine Number Must Be 3 digits %0*d\n", 3, Number);
	printf("This format Whine Number Must Be 4 digits %0*d\n", 4, Number);
	printf("this is sum betwin %0*d + %0*d = %0*d \n", 2, Number, 2, Number, 2, Number + Number);




	int W1 = 2; int X = 7;
	int W2 = 3; int Y = 85;



	printf("%0*d\n%0*d", W1, X, W2, Y);

}
