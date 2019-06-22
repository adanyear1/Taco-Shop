#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global Variable For Amount of Taco Type
const int numtipodetacos = 5;
//Global Variable For Taco Pricing
//const int preciodetaco = 2;
//const double ordendetacos;
//const double preciodeorden;
//Global Variable For Taco Menu Number
int tacomenu_number;
//Global Variable For Amount of Tacos ordered
int t;

struct tipodetaco
{
    string taco1,
           taco2,
           taco3,
           taco4,
           taco5;
};

//struct preciototal
//{
    //double taco[preciodetaco];
//};

struct tacodata
{
    tipodetaco nonnumeric;
    //preciototal numeric;
};
//FUNCTION PROTOTYPES
//function call that reads data from input file
void displaymenu(ifstream &, struct tacodata meal[], int);
//function call that shows menu to customer
void Order(struct tacodata meal[], int);
//function call that prints receipt for customer
void Receipt(ofstream &, struct tacodata meal[], int);

int main()
{
    tacodata meal[numtipodetacos];//Array for taco variety

    //DECLARING INPUT FILE
    ifstream fin;
    fin.open("TacoOrdering_Menu.txt");
    if(!fin)
    {
        cout << "Unable To Read Menu File" << endl;
        return-1;
    }
    //DECLARING OUTPUT FILE
    ofstream fout;
    fout.open("Recipt.txt");
    if(!fout)
    {
        cout << "Unable To Copy To Recipt File" << endl;
        return-1;
    }
    //FOR LOOP FOR FUNCTION
    for (int food = 0; food < 1;food++)
    {
        displaymenu(fin, meal, food);
        Order(meal, food);
        Receipt(fout, meal, food);
    }
    return 0;
}

void displaymenu(ifstream &fin, struct tacodata meal[], int food)
{
    cout << setw(40) << "Bienvenidos A Taqueria El Pariente\n";
    cout << "\n";
    //This Function Is Used To Input String Data
    for (int i = 0; i < numtipodetacos;i++)
    {
        getline(fin, meal[food].nonnumeric.taco1);
        getline(fin, meal[food].nonnumeric.taco2);
        getline(fin, meal[food].nonnumeric.taco3);
        getline(fin, meal[food].nonnumeric.taco4);
        getline(fin, meal[food].nonnumeric.taco5);
    }
    cout << setw(25) << "1. " << meal[food].nonnumeric.taco1 << endl
         << setw(25) << "2. " << meal[food].nonnumeric.taco2 << endl
         << setw(25) << "3. " << meal[food].nonnumeric.taco3 << endl
         << setw(25) << "4. " << meal[food].nonnumeric.taco4 << endl
         << setw(25) << "5. " << meal[food].nonnumeric.taco5 << endl
         << "\n"
         << "\n";
}
void Order(struct tacodata meal[], int food)
{
    char correct;
    do
    {
        cout << setw(42) << "Que Tipo De Tacos Te Gustaria Ordenar?" << endl;
        cin >> tacomenu_number;
        cout << "Cuantos Tacos Te Gustaria Ordenar" << endl;
        cin >> t;
        if (tacomenu_number == 1)
        {
            cout << "Pedio " << t << " de " << "Al Pastor" << endl;
        }
        else
        {
            cout << "Pedio Numero Incorrecto" << endl;
        }
        cout << "Esta Correcta Su Orden (y/n)" << endl;
        cin >> correct;
    }while(correct == 'n' || correct == 'N');

}
void Receipt(ofstream &fout, struct tacodata meal[], int food)
{
    fout << setw(45) << "Taqueria El Pariente " << endl
         << setw(38) << "1915 Rundberg LN," << endl
         << setw(38) << "Austin, TX, 78626" << endl
         << setw(38) << "(512) 968-1111" << endl;

}

