#include <iostream>
using namespace std;

class clsA
{
private:
	int _intA;
	int _boolA;

	void PriA1()
	{

	}

public:
	void PpA1()
	{

	}
	int PubintA;
	int PubboolA;

protected:
	void ProA1()
	{

	}
	int ProintA;
	int ProboolA;
};

class clsB :public clsA
{
private:
	int _intB;
	int _boolB;

	void PriB1()
	{

	}

public:
	void PpB1()
	{

	}
	int PubintB;
	int PubboolB;

protected:
	void ProB1()
	{

	}
	int ProintB;
	int ProboolB;
};

class clsC : protected clsB
{
private:
	int _intC;
	int _boolC;

	void PriC1()
	{

	}

public:
	void PpC1()
	{

	}
	int PubintC;
	int PubboolC;

protected:
	void ProC1()
	{

	}
	int ProintC;
	int ProboolC;
};

class clsD : private clsC
{
private:
	int _intD;
	int _boolD;

	void PriD1()
	{

	}

public:
	void PpD1()
	{
		clsC::ProboolA = 9;
	}
	int PubintD;
	int PubboolD;

protected:
	void ProD1()
	{

	}
	int ProintD;
	int ProboolD;
};

class clsE : public clsD
{
public:
	int intE;
	
};


int main()
{
	clsA A;

	clsB B;

	clsC C;

	clsD D;
			 
	clsE E;

	//نستطيع الوصول الى الممبر العامة فقط 
	// البرايفت تبقا برايفت بالنسبة للخارج و بالنسبة للكلاسات التي ترث منها
	// البروتكتد هي برايفت بالنسبى للهارج و مرئية للداخل وهي ايضا تبقا بروتدتد داخل الكلاس الذي ورثها اي انها لا تتحول لبرايفت  او بابليك 
	A;

	// بي يرث باي بابليك من اي 
	// يعني ان البابليك الذي ورثة يصبح بابليك للخارج و بابليك له لداهليا اي انه اصبح ممبر ببلك له 
	// البرايفت لا يرثه اي انه لا يمكن الوصول له داخليا ولا يمكن الوصل له حارجيا 
	// البروتكتد يرثه يعني انه يبقا بروتكتد بالنسبة له اي كانه بروتكتد داتا بالنسبة له اي انه يورثه ايضا كبروتدتد داتا ام بالنسبة له داهليا فهو بابليك 
	// البابليك عندما يورثه يبقا بابليك و ايضا هو بابليك من الخارج 
	B;

	// هو يرث من بي كبروتاكتد 
	//معناه انه كل ما يرثه يصبح بروناكتد للهارج اي انه لا اخد يستطيع الوصول اليه 
	// الذي يرثه هو يصبح له كبابلك اي انه يرث بطريقة عادية لكنه يورث الذي يرث منه كبرونكد اي انه هو يرثخ كبابليك و يورثه كبروتيكتد
	// معناها الذي يرث منه انه لا يستطيع  الوصول اليهم من الخارج بل في الكلاس فقط 
	C;

	// يرث السي بشكل عادي 
	// لكنا ما ورثه من سي لا يورثه لغير لان الذي سيرث منه كانه برايفت بالنسبة له يعني انه سيورث فقط ما تم انشاءه بابليك داخله او بروناكدت اما ما ورثه هو فيكون برايفت لغيره اي انه لا يورق
	D;


	// يرث الدي بشكل عادي لكتا ما ورثه الدي لا يرثه هو لان
	E;

	return 0; 
}