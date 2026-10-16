#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsUser.h"




int main()

{
   // clsMainScreen::ShowMainMenue();
   // system("pause>0");


   
    
    clsUser u = clsUser::GetAddNewUserObject("@hamid");
    u.FirstName = "ABDELHAMID";
    u.LastName = "TAHAR";
    u.Email = "TAHARABDALHAMID12@gmail.com";
    u.Phone = "=213555174615";
    u.PassWord = "1234";
    u.Permissions = 12332;

    cout << u.IsEmpty() << endl;
    cout << u.IsUserExist("uu") << endl;
    cout << u .

    return 0;
}