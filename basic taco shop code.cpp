#include <iostream>

using namespace std;

int main()
{
    double lunes, martes, miercoles, jueves, 
           viernes, sabado, domingo;
    int totalsemanal,
        annualmente;
    cout<< "Cuantos Tacos Vendes El Lunes? ";
    cin >> lunes;
    cout<< "Cuantos Tacos Vendes El Martes? ";
    cin >> martes;
    cout<< "Cuantos Tacos Vendes El Miercoles? ";
    cin >> miercoles;
    cout<< "Cuantos Tacos Vendes El Jueves? ";
    cin >> jueves;
    cout<< "Cuantos Tacos Vendes El Viernes? ";
    cin >> viernes;
    cout<< "Cuantos Tacos Vendes El Sabado? ";
    cin >> sabado;
    cout<< "Cuantos Tacos Vendes El Domingo? ";
    cin >> domingo;
    totalsemanal = lunes + martes + miercoles + jueves + viernes + sabado + domingo;
    cout << "Por Semana Vendes " << totalsemanal << " tacos" << endl;
    annualmente = totalsemanal*52;
    cout << "Annualmente Vendes " << annualmente << " Tacos" << endl;
    return 0;
}
