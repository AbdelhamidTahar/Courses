#include <iostream>
#include <string>

using namespace std;


struct sElectricityBill
{
    double Coef = 0;
    double NewIndex = 0;
    double OldIndex = 0;
    // Maximum consumption per tranche in kilowatt-hours (kWh).
    double ElecMaxConsumptionFirstTrancheKWH = 125;
    double ElecMaxConsumptionSecondTrancheKWH = 125;
    double ElecMaxConsumptionThirdTrancheKWH = 750;
    // Fourth Tranche KWH is unLimit.

    //Average consumption per tranche in kilowatt-hours (kWh).
    double ElecConsumptionFirstTrancheInKWH = 0;
    double ElecConsumptionSecondTrancheInKWH = 0;
    double ElecConsumptionThirdTrancheInKWH = 0;
    double ElecConsumptionFourthTrancheInKWH = 0;

    //Unit price per tranche in Algerian Dinar (DZD).
    double ElecUnitPriceFirstTranchePerDZD = 0;
    double ElecUnitPriceSecondTranchePerDZD = 0;
    double ElecUnitPriceThirdTranchePerDZD = 0;
    double ElecUnitPriceFourthTranchePerDZD = 0;

    //Price per tranche.
    double ElecPriceFirstTranchePerDZD = 0;
    double ElecPriceSecondTranchePerDZD = 0;
    double ElecPriceThirdTranchePerDZD = 0;
    double ElecPriceFourthTranchePerDZD = 0;

    // Calculate the sum of two tranches (in Algerian Dinar)
    double ElecPriceFirstAndSecondTranchesPerDZD = 0;
    double ElecPriceThirdAndFourthTranchesPerDZD = 0;


    double ElectricityConsumptionInKWH = 0;
    double ElectricityConsumptionINDZD = 0;

    

};

enum enMainMenueOptions
{
    eElectricityBill = 1,
    eGasBill = 2,
    eGasAndElectricityBill = 3,
    eExit =4
};

void ShowMainMenue();

bool IsInputNumberError()
{
    bool InputError = false;

    /* cin.fail() return true
    when use don't input number.
    true = errour input*/
    InputError = cin.fail();

    if (InputError == false)
    {
        return false;
    }
    else
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return InputError;
    }

}


double ReadPositiveNumber(const string &Message)
{
    bool InputError = false;
    double Number = 0;  // Variable to store the user's input, initialized to 0.

    do
    {
        // Display the prompt message to the user.
        cout << Message ;
        // Read the number entered by the user.
        cin >> Number;

        InputError = IsInputNumberError();

    } while ((Number < 0) || (InputError == true));  // Continue prompting if the number is not positive.

    return Number;  // Return the valid positive number.
}


void ReadIndexesElectricity(sElectricityBill& ElectricityBill)
{
    ElectricityBill.OldIndex = ReadPositiveNumber("\nPlease enter the Old Electricity Index(A.Index).");
    do
    {
        ElectricityBill.NewIndex = ReadPositiveNumber
        ("\nPlease enter the Old Electricity Index(N.Index).");
    } while (ElectricityBill.NewIndex < ElectricityBill.OldIndex);
}

void ReadElectricityBillingParameters(sElectricityBill& ElectricityBill)
{
    ElectricityBill.Coef = ReadPositiveNumber
    ("\nPlease enter the value of the electrical coefficient (Coef).");

    ElectricityBill.ElecUnitPriceFirstTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the first tranche:");

    ElectricityBill.ElecUnitPriceSecondTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the second tranche:");

    ElectricityBill.ElecUnitPriceThirdTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the third tranche:");

    ElectricityBill.ElecUnitPriceFourthTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the fourth tranche:");

}


double CalculateElectricityConsumptionInKWH(const double& OldIndex, const double &NewIndex)
{
    return NewIndex - OldIndex;
}

double CalculateConsumptionPerTranche
(double& ElectricityConsumptionInKWH, bool& HasRemaining, const double& MaxConsumptionTranch = 0)
{
    double RemainingConsumption = 0;
    double temp = 0;
    if (ElectricityConsumptionInKWH < 0 || HasRemaining == false)
    {

        return 0;
    }
    else
    {
        if (MaxConsumptionTranch == 0)
        {
            return ElectricityConsumptionInKWH;
        }
        else
        {
            RemainingConsumption = ElectricityConsumptionInKWH - MaxConsumptionTranch;
            if (RemainingConsumption > 0)
            {

                ElectricityConsumptionInKWH = RemainingConsumption;
                HasRemaining = true;
                return MaxConsumptionTranch;
            }
            else
            {
                temp = ElectricityConsumptionInKWH;
                ElectricityConsumptionInKWH = RemainingConsumption;
                HasRemaining = false;
                return temp;
            }
        }
    }
}

void DistributionOfConsumptionIntoTranches(sElectricityBill& ElectricityBill)
{
    bool HasRemaining = true;
    double TempElectricityConsumptionInKWH = ElectricityBill.ElectricityConsumptionInKWH;

    ElectricityBill.ElecConsumptionFirstTrancheInKWH =
        CalculateConsumptionPerTranche
        (TempElectricityConsumptionInKWH, HasRemaining, ElectricityBill.ElecMaxConsumptionFirstTrancheKWH);

    ElectricityBill.ElecConsumptionSecondTrancheInKWH =
        CalculateConsumptionPerTranche
        (TempElectricityConsumptionInKWH, HasRemaining, ElectricityBill.ElecMaxConsumptionSecondTrancheKWH);

    ElectricityBill.ElecConsumptionThirdTrancheInKWH =
        CalculateConsumptionPerTranche
        (TempElectricityConsumptionInKWH, HasRemaining, ElectricityBill.ElecMaxConsumptionThirdTrancheKWH);

    ElectricityBill.ElecConsumptionFourthTrancheInKWH =
        CalculateConsumptionPerTranche
        (TempElectricityConsumptionInKWH, HasRemaining);

}

double CalculateCostPerTranche(const double &TrancheConsumptionkWH,const double &UnitPrice)
{
    return TrancheConsumptionkWH * UnitPrice;
}

void CalculateTotalCostOfTranches(sElectricityBill& ElectricityBill)
{
    ElectricityBill.ElecPriceFirstTranchePerDZD =
        CalculateCostPerTranche
        (ElectricityBill.ElecConsumptionFirstTrancheInKWH, ElectricityBill.ElecUnitPriceFirstTranchePerDZD);

    ElectricityBill.ElecPriceSecondTranchePerDZD =
        CalculateCostPerTranche
        (ElectricityBill.ElecConsumptionSecondTrancheInKWH, ElectricityBill.ElecUnitPriceSecondTranchePerDZD);

    ElectricityBill.ElecPriceThirdTranchePerDZD =
        CalculateCostPerTranche
        (ElectricityBill.ElecConsumptionThirdTrancheInKWH, ElectricityBill.ElecUnitPriceThirdTranchePerDZD);

    ElectricityBill.ElecPriceFourthTranchePerDZD =
        CalculateCostPerTranche
        (ElectricityBill.ElecConsumptionFourthTrancheInKWH, ElectricityBill.ElecUnitPriceFourthTranchePerDZD);
}

double SumTwoTranchesCost(const double& FirstTrancheCost, const double& SecondTrancheCost)
{
    return FirstTrancheCost + SecondTrancheCost;
}

double ElectricityConsumptionInDA( sElectricityBill& ElectricityBill)
{
    DistributionOfConsumptionIntoTranches(ElectricityBill);

    CalculateTotalCostOfTranches(ElectricityBill);

    ElectricityBill.ElecPriceFirstAndSecondTranchesPerDZD = SumTwoTranchesCost
    (ElectricityBill.ElecPriceFirstTranchePerDZD, ElectricityBill.ElecPriceSecondTranchePerDZD);

    ElectricityBill.ElecPriceThirdAndFourthTranchesPerDZD = SumTwoTranchesCost
    (ElectricityBill.ElecPriceThirdTranchePerDZD, ElectricityBill.ElecPriceFourthTranchePerDZD);


    return SumTwoTranchesCost(
        ElectricityBill.ElecPriceFirstAndSecondTranchesPerDZD,
        ElectricityBill.ElecPriceThirdAndFourthTranchesPerDZD
    );
};

double ElectricityBill()
{
    sElectricityBill ElectricityBill;

    ReadIndexesElectricity(ElectricityBill);
    ReadElectricityBillingParameters(ElectricityBill);
    ElectricityBill.ElectricityConsumptionInKWH =
        CalculateElectricityConsumptionInKWH
        (ElectricityBill.OldIndex, ElectricityBill.NewIndex);


    ElectricityBill.ElectricityConsumptionINDZD = ElectricityConsumptionInDA(ElectricityBill);
      
    cout << "\nTOTAL " << ElectricityBill.ElectricityConsumptionInKWH << " KWH\n" ;
    cout << "TOTAL " << ElectricityBill.ElectricityConsumptionINDZD << " DZD\n";


    return 0;
}


void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eElectricityBill:
    {
        system("cls");
        ElectricityBill();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eGasBill:
    {
        system("cls");

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eGasAndElectricityBill:
    {
        system("cls");
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eExit:
    {
        system("cls");
    }
    
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Electricity Bill.\n";
    cout << "\t[2] Gas Bill.\n";
    cout << "\t[3] Gas And Electricity Bill.\n";
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()

{
    ShowMainMenue();
    system("pause>0");
    return 0;
}