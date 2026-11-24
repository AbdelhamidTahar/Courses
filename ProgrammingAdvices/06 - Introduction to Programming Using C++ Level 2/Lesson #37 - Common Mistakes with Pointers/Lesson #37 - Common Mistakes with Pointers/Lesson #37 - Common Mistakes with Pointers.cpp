#include <iostream>

int main()
{
    //Common Mistakes with Pointers

    int Number, * PointerOfNumber;

    PointerOfNumber = Number; //This is an error; the pointer should only hold a reference, 
                              //meaning it should hold the address of another 
                              //variable of the same type.


    PointerOfNumber = &Number; // That's true Because Pointer Has reference (Addresse) of Varible.

    *PointerOfNumber = &Number; // This is incorrect because the location 
                                //the pointer is referring to should have a value or be assigned a value,
                                // not just a reference or address.

    *PointerOfNumber = Number; // This is correct because the violin in RAM 
                               //that the pointer is referring to has a value,
                               // not an address.
    
}
