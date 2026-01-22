#include <iostream>
#include<cstdio>
using namespace std;

int main()
{

	char Name[] = "ABDELHAMID TAHAR";
	char Universty[] = "HARVARD";
	char r = 'r';

	printf("Hello %s Weclome ,Nice to meet you\n",Name);
	printf("Welcome To %s Univercity \n",Universty);


	char S = 'S';


	printf("this is test space  using printf %c \n", S);
	printf("this is test space  using printf %c \n", S);


	printf("\n\nthis is test space  using printf %*c \n", 1, S);
	printf("this is test space  using printf %*c \n", 2, S);
	printf("this is test space  using printf %*c \n", 3, S);
	printf("this is test space  using printf %*c \n", 4, S);
	printf("this is test space  using printf %*c \n", 5, S);
	printf("this is test space  using printf %*c \n", 6, S);

	return 0; 
}
