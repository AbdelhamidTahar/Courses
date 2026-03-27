#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


struct strElectricityBill
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

struct strGasBill
{
    double Pcs = 0;
    double NewIndex = 0;
    double OldIndex = 0;

    // Maximum consumption per tranche in Therm (Th).
    double GasMaxConsumptionFirstTrancheTh = 1125.00;
    double GasMaxConsumptionSecondTrancheTh = 1375.00;
    double GasMaxConsumptionThirdTrancheTh = 5000;
    // Fourth Tranche Th is unLimit.

    // Average consumption per tranche in Therm (Th).
    double GasConsumptionFirstTrancheInTh = 0;
    double GasConsumptionSecondTrancheInTh = 0;
    double GasConsumptionThirdTrancheInTh = 0;
    double GasConsumptionFourthTrancheInTh = 0;

    // Unit price per tranche in Algerian Dinar (DZD).
    double GasUnitPriceFirstTranchePerDZD = 0;
    double GasUnitPriceSecondTranchePerDZD = 0;
    double GasUnitPriceThirdTranchePerDZD = 0;
    double GasUnitPriceFourthTranchePerDZD = 0;

    // Price per tranche.
    double GasPriceFirstTranchePerDZD = 0;
    double GasPriceSecondTranchePerDZD = 0;
    double GasPriceThirdTranchePerDZD = 0;
    double GasPriceFourthTranchePerDZD = 0;

    // Calculate the sum of two tranches (in Algerian Dinar)
    double GasPriceFirstAndSecondTranchesPerDZD = 0;
    double GasPriceThirdAndFourthTranchesPerDZD = 0;

    double GasConsumptionInTh = 0;
    double GasConsumptionINDZD = 0;
};

struct strFees
{
    double FixedTaxes = 0;
    double ServiceFees = 0;

    double AmountBeforeFees = 0;

    double VAT9Percent = 0;
    double VAT19Percent = 0;
    double TotalVAT = 0;

    double FixedConsumptionCharges = 0;

    double HousingTax = 0;
    double Contribution = 0;

    double REPEAmountDZD = 0;
    double RGPEAmountDZD = 0;

    double NetPaymentDZD = 0;

    double StampDutyDZD = 0;

    double TotalDueCashDZD = 0;
};



void PrintGasAndElectricityBillingScreen();

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

void ReadIndexesElectricity(strElectricityBill& ElectricityBill)
{
    ElectricityBill.OldIndex = ReadPositiveNumber("\nPlease enter the Old Electricity Index(A.Index).");
    do
    {
        ElectricityBill.NewIndex = ReadPositiveNumber
        ("\nPlease enter the New Electricity Index(N.Index).");
    } while (ElectricityBill.NewIndex < ElectricityBill.OldIndex);
}

void ReadElectricityBillingParameters(strElectricityBill& ElectricityBill)
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

double CalculateConsumptionFromIndex(const double& OldIndex, const double &NewIndex,const double &Factors)
{
    return (NewIndex - OldIndex ) * Factors;
}

double CalculateConsumptionPerTranche
(double& ConsumptionValue, bool& HasRemaining, const double& MaxConsumptionTranch = 0)
{
    double RemainingConsumption = 0;
    double temp = 0;
    if (ConsumptionValue < 0 || HasRemaining == false)
    {

        return 0;
    }
    else
    {
        if (MaxConsumptionTranch == 0)
        {
            return ConsumptionValue;
        }
        else
        {
            RemainingConsumption = ConsumptionValue - MaxConsumptionTranch;
            if (RemainingConsumption > 0)
            {

                ConsumptionValue = RemainingConsumption;
                HasRemaining = true;
                return MaxConsumptionTranch;
            }
            else
            {
                temp = ConsumptionValue;
                ConsumptionValue = RemainingConsumption;
                HasRemaining = false;
                return temp;
            }
        }
    }
}

void DistributionOfConsumptionIntoTranches(strElectricityBill& ElectricityBill)
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

double CalculateCostPerTranche(const double &TrancheConsumption,const double &UnitPrice)
{
    return TrancheConsumption * UnitPrice;
}

void CalculateTotalCostOfTranches(strElectricityBill& ElectricityBill)
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

double ElectricityConsumptionInDA( strElectricityBill& ElectricityBill)
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

void PrintElectricityBillingSystemScreen()
{
    cout << "-----------------------------------------\n";
    cout << "|                                        |\n";
    cout << "|       Electricity Billing System       |\n";
    cout << "|                                        |\n";
    cout << "-----------------------------------------\n";
}

strElectricityBill ElectricityBill()
{
    PrintElectricityBillingSystemScreen();
    strElectricityBill ElectricityBill;

    ReadIndexesElectricity(ElectricityBill);
    ReadElectricityBillingParameters(ElectricityBill);
    ElectricityBill.ElectricityConsumptionInKWH =
        CalculateConsumptionFromIndex
        (ElectricityBill.OldIndex, ElectricityBill.NewIndex, ElectricityBill.Coef);


    ElectricityBill.ElectricityConsumptionINDZD = 
        ElectricityConsumptionInDA(ElectricityBill);
      


    return ElectricityBill;
}

void PrintHeaderGasandElectricityBillingScreen()
{
    cout << "-----------------------------------------\n";
    cout << "|                                        |\n";
    cout << "|   Gas and Electricity Billing System   |\n";
    cout << "|                                        |\n";
    cout << "-----------------------------------------\n";

}

void PrintGasAndElectricityBillingScreen()
{
    PrintHeaderGasandElectricityBillingScreen();
}

void PrintGasBillingSystemScreen()
{
    cout << "-----------------------------------------\n";
    cout << "|                                        |\n";
    cout << "|          Gas Billing System            |\n";
    cout << "|                                        |\n";
    cout << "-----------------------------------------\n";
}

void ReadIndexesGas(strGasBill& GasBill)
{
    GasBill.OldIndex = ReadPositiveNumber("\nPlease enter the Old Gas Index(A.Index).");
    do
    {
        GasBill.NewIndex = ReadPositiveNumber
        ("\nPlease enter the New Gas Index(N.Index).");
    } while (GasBill.NewIndex < GasBill.OldIndex);
}

void ReadGasBillingParameters(strGasBill& GasBill)
{
    GasBill.Pcs = ReadPositiveNumber
    ("\nPlease enter the value of the Gas coefficient (Pcs).");

    GasBill.GasUnitPriceFirstTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the first tranche:");

    GasBill.GasUnitPriceSecondTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the second tranche:");

    GasBill.GasUnitPriceThirdTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the third tranche:");

    GasBill.GasUnitPriceFourthTranchePerDZD = ReadPositiveNumber(
        "\nPlease enter the unit price for the fourth tranche:");

}

void DistributionOfConsumptionIntoTranches(strGasBill& GasBill)
{
    bool HasRemaining = true;
    double TempGasConsumptionInKWH = GasBill.GasConsumptionInTh;

    GasBill.GasConsumptionFirstTrancheInTh =
        CalculateConsumptionPerTranche
        (TempGasConsumptionInKWH, HasRemaining, GasBill.GasMaxConsumptionFirstTrancheTh);

    GasBill.GasConsumptionSecondTrancheInTh =
        CalculateConsumptionPerTranche
        (TempGasConsumptionInKWH, HasRemaining, GasBill.GasMaxConsumptionSecondTrancheTh);

    GasBill.GasConsumptionThirdTrancheInTh =
        CalculateConsumptionPerTranche
        (TempGasConsumptionInKWH, HasRemaining, GasBill.GasMaxConsumptionThirdTrancheTh);

    GasBill.GasConsumptionFourthTrancheInTh =
        CalculateConsumptionPerTranche
        (TempGasConsumptionInKWH, HasRemaining);

}

void CalculateTotalCostOfTranches(strGasBill& GasBill)
{
    GasBill.GasPriceFirstTranchePerDZD =
        CalculateCostPerTranche
        (GasBill.GasConsumptionFirstTrancheInTh, GasBill.GasUnitPriceFirstTranchePerDZD);

    GasBill.GasPriceSecondTranchePerDZD =
        CalculateCostPerTranche
        (GasBill.GasConsumptionSecondTrancheInTh, GasBill.GasUnitPriceSecondTranchePerDZD);

        GasBill.GasPriceThirdTranchePerDZD =
            CalculateCostPerTranche
            (GasBill.GasConsumptionThirdTrancheInTh, GasBill.GasUnitPriceThirdTranchePerDZD);

        GasBill.GasPriceFourthTranchePerDZD =
            CalculateCostPerTranche
            (GasBill.GasConsumptionFourthTrancheInTh, GasBill.GasUnitPriceFourthTranchePerDZD);
}

double GasConsumptionInDA(strGasBill& GasBill)
{
    DistributionOfConsumptionIntoTranches(GasBill);

    CalculateTotalCostOfTranches(GasBill);

    GasBill.GasPriceFirstAndSecondTranchesPerDZD = SumTwoTranchesCost
    (GasBill.GasPriceFirstTranchePerDZD, GasBill.GasPriceSecondTranchePerDZD);

    GasBill.GasPriceThirdAndFourthTranchesPerDZD = SumTwoTranchesCost
    (GasBill.GasPriceThirdTranchePerDZD, GasBill.GasPriceFourthTranchePerDZD);


    return SumTwoTranchesCost(
        GasBill.GasPriceFirstAndSecondTranchesPerDZD,
        GasBill.GasPriceThirdAndFourthTranchesPerDZD
    );
};

strGasBill GasBill()
{
    PrintGasBillingSystemScreen();
    strGasBill GasBill;

    ReadIndexesGas(GasBill);
    ReadGasBillingParameters(GasBill);
    GasBill.GasConsumptionInTh =
        CalculateConsumptionFromIndex
        (GasBill.OldIndex, GasBill.NewIndex, GasBill.Pcs);


    GasBill.GasConsumptionINDZD =
        GasConsumptionInDA(GasBill);



    return GasBill;
}

void PrintTaxesScreen()
{
    cout << "-----------------------------------------\n";
    cout << "|                                        |\n";
    cout << "|              Read Taxes                |\n";
    cout << "|                                        |\n";
    cout << "-----------------------------------------\n";
}

void ReadTaxes(strFees& sFees)
{
    PrintTaxesScreen();
    sFees.FixedTaxes = ReadPositiveNumber("Please enter the fixed fees(subscription) in DZD.: ");
    sFees.ServiceFees = ReadPositiveNumber("Please enter the Service Fees in DZD.: ");
    sFees.FixedConsumptionCharges = ReadPositiveNumber("Please enter the Fixed Consumption Charges in DZD.: ");
    sFees.HousingTax = ReadPositiveNumber("Please enter the Housing Tax in DZD.: ");
    sFees.Contribution = ReadPositiveNumber("Please enter the Contribution in DZD.: ");
    sFees.REPEAmountDZD = ReadPositiveNumber("Please enter the REPE Amount in DZD.: ");
    sFees.RGPEAmountDZD = ReadPositiveNumber("Please enter the RGPE Amount in DZD.: ");
}

double CalculateVAT(const double& Amount, const  double& Percent)
{
    return Amount * Percent;
}

void CalculateTotalVAT(strFees& sFees, const strElectricityBill& sElectricityBill, const strGasBill& sGasBill)
{
    double TotalTranches = 0;

    TotalTranches = SumTwoTranchesCost
    (sElectricityBill.ElecPriceFirstAndSecondTranchesPerDZD,
        sGasBill.GasPriceFirstAndSecondTranchesPerDZD);
    sFees.VAT9Percent = CalculateVAT(TotalTranches + sFees.FixedTaxes, 0.09);


    TotalTranches = SumTwoTranchesCost
    (sElectricityBill.ElecPriceThirdAndFourthTranchesPerDZD,
        sGasBill.GasPriceThirdAndFourthTranchesPerDZD);
    sFees.VAT19Percent = (TotalTranches * 0.19);

    sFees.TotalVAT = sFees.VAT9Percent + sFees.VAT19Percent;

}

void CalculatBill(strFees& sFees,const strElectricityBill &sElectricityBill,const strGasBill &sGasBill)
{
    double TotalElectricityAndGasCostDZD = 0;

    TotalElectricityAndGasCostDZD = SumTwoTranchesCost
            (sElectricityBill.ElectricityConsumptionINDZD, sGasBill.GasConsumptionINDZD);

    
    sFees.AmountBeforeFees = TotalElectricityAndGasCostDZD + sFees.FixedTaxes + sFees.ServiceFees;

    CalculateTotalVAT(sFees, sElectricityBill, sGasBill);

    sFees.NetPaymentDZD = sFees.AmountBeforeFees + sFees.TotalVAT
                          + sFees.FixedConsumptionCharges + sFees.HousingTax
                          + sFees.Contribution + sFees.REPEAmountDZD
                          + sFees.RGPEAmountDZD;


    sFees.StampDutyDZD = sFees.NetPaymentDZD * 0.01;
    sFees.TotalDueCashDZD = sFees.NetPaymentDZD + sFees.StampDutyDZD;

}

void PrinGasAndElectricityHeaderBillt(const strElectricityBill& sElectricityBill, const strGasBill& sGasBill)
{

    cout << "\n_____Your consumption_________________________________________\n";
    cout << "                   consumption" << "            Amount In DZD\n";

    cout << "Electricity" << setw(17) << sElectricityBill.ElectricityConsumptionInKWH;
    cout << setw(25) << sElectricityBill.ElectricityConsumptionINDZD;

    cout << endl;

    cout << "Gas" << setw(25) << sGasBill.GasConsumptionInTh;
    cout << setw(25) << sGasBill.GasConsumptionINDZD;

    cout << "\n______________________________________________________________\n";

}

void PrintGasAndElectricityDetailsBill(strFees& sFees)
{
    cout << "Fixed Taxes (Subscription)       : " << sFees.FixedTaxes << " DZD\n";
    cout << "Service Fees                     : " << sFees.ServiceFees << " DZD\n";
    cout << "Amount Before Fees               : " << sFees.AmountBeforeFees << " DZD\n";
    cout << "VAT (9%)                         : " << sFees.VAT9Percent << " DZD\n";
    cout << "VAT (19%)                        : " << sFees.VAT19Percent << " DZD\n";
    cout << "Total VAT                        : " << sFees.TotalVAT << " DZD\n";
    cout << "Fixed Consumption Charges        : " << sFees.FixedConsumptionCharges << " DZD\n";
    cout << "Housing Tax                      : " << sFees.HousingTax << " DZD\n";
    cout << "Contribution                     : " << sFees.Contribution << " DZD\n";
    cout << "Montant REPE                     : " << sFees.REPEAmountDZD << " DZD\n";
    cout << "Montant RGPE                     : " << sFees.RGPEAmountDZD << " DZD\n";
};

void PrintGasAndElectricityFootersBill(strFees& sFees)
{
    cout << "______________________________________________________________\n";
    cout << "Net Payment (Including All Fees) : " << sFees.NetPaymentDZD << " DZD\n";
    cout << "______________________________________________________________\n";
    cout << "Stamp Duty (Cash Payment)        : " << sFees.StampDutyDZD << " DZD\n";
    cout << "Total Amount Due (Cash)          : " << sFees.TotalDueCashDZD << " DZD\n";
    cout << "______________________________________________________________\n";
}

void PrintGasAndElectricityBill
(strFees& sFees, const strElectricityBill& sElectricityBill, const strGasBill& sGasBill)
{
    PrinGasAndElectricityHeaderBillt(sElectricityBill, sGasBill);
    PrintGasAndElectricityDetailsBill(sFees);
    PrintGasAndElectricityFootersBill(sFees);

}

void GasandElectricityBillingSystem()
{
    //Electricity Bill System.
    strElectricityBill sElectricityBill;
    system("cls");
    PrintGasAndElectricityBillingScreen();
    sElectricityBill = ElectricityBill();


    //Gas Bill System.
    strGasBill sGasBill;
    system("cls");
    PrintGasAndElectricityBillingScreen();
    sGasBill = GasBill();


    //Total Bill Calculation.
    strFees sFees;
    system("cls");
    ReadTaxes(sFees);
    CalculatBill(sFees, sElectricityBill, sGasBill);

    //Print Bill.
    system("cls");
    PrintGasAndElectricityBill(sFees, sElectricityBill, sGasBill);
}


int main()

{
    GasandElectricityBillingSystem();
    system("pause>0");
    return 0;
}