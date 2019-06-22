#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global Variable For Amount of Taco Type
const int numtipodetacos = 5;
//Global Variable For Taco Pricing
const int preciodeorden = 1;
const int preciodetaco = 2;
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

struct preciototal
{
    double total[preciodeorden];
};

struct tacodata
{
    tipodetaco nonnumeric;
    preciototal numeric;
};
//FUNCTION PROTOTYPES
//function call that reads data from input file
void displaymenu(ifstream &, struct tacodata meal[], int);
//function call that shows menu to customer
void Order(struct tacodata meal[], int);
//function call that prints receipt for customer
void Receipt(ofstream &, struct tacodata meal[], int);
//function call that calculates taco cost
void price(struct tacodata meal[], int);

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
        price(meal, food);
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
    char incorrect;
    do
    {
        cout << setw(42) << "Que Tipo De Tacos Te Gustaria Ordenar?" << endl;
        cin >> tacomenu_number;
        cout << "Cuantos Tacos Te Gustaria Ordenar" << endl;
        cin >> t;
        if (tacomenu_number == 1)
        {
            cout << "Pedio " << t << " de " << meal[food].nonnumeric.taco1 << endl;
        }
        else if (tacomenu_number == 2)
        {
            cout << "Pedio " << t << " de " << meal[food].nonnumeric.taco2 << endl;
        }
        else if (tacomenu_number == 3)
        {
            cout << "Pedio " << t << " de " << meal[food].nonnumeric.taco3 << endl;
        }
        else if (tacomenu_number == 4)
        {
            cout << "Pedio " << t << " de " << meal[food].nonnumeric.taco4 << endl;
        }
        else if (tacomenu_number == 5)
        {
            cout << "Pedio " << t << " de " << meal[food].nonnumeric.taco5 << endl;
        }
        else
        {
            cout << "Pedio Numero Incorrecto" << endl;
        }
        cout << "Esta Correcta Su Orden (y/n)" << endl;
        cin >> incorrect;
    }while(incorrect == 'n' || incorrect == 'N');

}
void price(struct tacodata meal[], int food)
{
    meal[food].numeric.total[1] = t*preciodetaco;
    cout << meal[food].numeric.total[1] << endl;
}
void Receipt(ofstream &fout, struct tacodata meal[], int food)
{
    fout << setw(45) << "Taqueria El Pariente " << endl
         << setw(38) << "1915 Rundberg LN," << endl
         << setw(38) << "Austin, TX, 78626" << endl
         << setw(38) << "(512) 968-1111" << endl
         << "______________________________________________________________________________________________________________________" << endl;

    fout << setw(28) << "Item" << setw(15) << "Quantity" << endl;
    if (tacomenu_number == 1)
        {
            fout << setw(30) << meal[food].nonnumeric.taco1 << setw(10) << t << endl;
        }
        else if (tacomenu_number == 2)
        {
            fout << setw(30) << meal[food].nonnumeric.taco2 << setw(13) << t << endl;
        }
        else if (tacomenu_number == 3)
        {
            fout << setw(30) << meal[food].nonnumeric.taco3 << setw(13) << t << endl;
        }
        else if (tacomenu_number == 4)
        {
            fout << setw(30) << meal[food].nonnumeric.taco4 << setw(13) << t << endl;
        }
        else if (tacomenu_number == 5)
        {
            fout << setw(30) << meal[food].nonnumeric.taco5 << setw(13) << t << endl;
        }
        else
        {
            fout << "Pedido No Fue Realizado" << endl;
        }
        fout << setw(30) << "Total" << setw(6) << "$"<< meal[food].numeric.total[1] << endl;

}
