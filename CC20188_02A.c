#include <stdio.h>


struct Takaful
{
    int contribution;
};



struct Rebate
{
    int child;
    int purchasedValue;
    int donation;
    int totalTaxRebate;
    int totalTaxableIncome;
    struct Takaful medical;
    struct Takaful family;
};


struct Tax
{
    int incomeTax;
};


struct IncomeTax
{
   char name[20];
   char address[40];
   int salary;
   struct Tax tax;
   struct Rebate taxRebate;
};

struct IncomeTax getinfo();
struct IncomeTax calculateRebate(struct IncomeTax IT);
int calculateTax(struct IncomeTax IT);
void display(struct IncomeTax IT[]);


int main()
{
    struct IncomeTax personalInfo[3];

    for(int i=0;i<3;i++){
        personalInfo[i] = getinfo();
        personalInfo[i] = calculateRebate(personalInfo[i]);
        personalInfo[i].tax.incomeTax = calculateTax(personalInfo[i]);
    }
    
    display(personalInfo); 

}

struct IncomeTax getinfo(){
    struct IncomeTax ITInfo;

    printf("\nEnter Name: ");
    scanf(" %[^\n]s", &ITInfo.name);
    printf("Enter house address: ");
    scanf(" %[^\n]s", &ITInfo.address);
    printf("Enter total basic salary for year 2021: ");
    scanf("%d", &ITInfo.salary);
    printf("Enter number of child: ");
    scanf("%d", &ITInfo.taxRebate.child);
    printf("Enter medical Takaful contribution: ");
    scanf("%d", &ITInfo.taxRebate.medical.contribution);
    printf("Enter family Takaful contribution: ");
    scanf("%d", &ITInfo.taxRebate.family.contribution);
    printf("Enter the purchased value for smartphones of computer (Max RM2000): ");
    scanf("%d", &ITInfo.taxRebate.purchasedValue);
    printf("Enter contribution for zakat or donations: ");
    scanf("%d", &ITInfo.taxRebate.donation);

    return ITInfo;

}

struct IncomeTax calculateRebate(struct IncomeTax IT){

    if(IT.taxRebate.purchasedValue > 2000)
    IT.taxRebate.purchasedValue = 2000;

    IT.taxRebate.totalTaxRebate = (IT.taxRebate.child * 2000) + IT.taxRebate.medical.contribution +
     IT.taxRebate.family.contribution + IT.taxRebate.purchasedValue + IT.taxRebate.donation;

    IT.taxRebate.totalTaxableIncome = IT.salary - IT.taxRebate.totalTaxRebate;

    return IT;
}

int calculateTax(struct IncomeTax IT){

    if (IT.taxRebate.totalTaxableIncome < 30000)
    {
        IT.tax.incomeTax = IT.taxRebate.totalTaxableIncome * 0.02;
    }else if(IT.taxRebate.totalTaxableIncome >= 30000 && IT.taxRebate.totalTaxableIncome < 50000)
    {
        IT.tax.incomeTax = IT.taxRebate.totalTaxableIncome * 0.10;    
    }else if(IT.taxRebate.totalTaxableIncome >= 50000)
    {
        IT.tax.incomeTax = IT.taxRebate.totalTaxableIncome * 0.20;
    }

    return IT.tax.incomeTax;
}

void display(struct IncomeTax IT[]){

    printf("\n\t\tINDIVIDUAL INCOME TAX\n");

    for(int i=0; i<3; i++){
        printf("\n");
        printf("\nName: %s", IT[i].name);
        printf("\nAddress: %s", IT[i].address);
        printf("\nTotal income(Basic Salary) for year 2021: RM%d", IT[i].salary);
        printf("\nTotal tax rebates: RM%d", IT[i].taxRebate.totalTaxRebate);
        printf("\nTaxable income: RM%d", IT[i].taxRebate.totalTaxableIncome);
        printf("\nIncome Tax: RM%d", IT[i].tax.incomeTax);
    }
}
