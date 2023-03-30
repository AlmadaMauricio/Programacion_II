#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void cargarCadena(char *palabra, int tamanio);

void cargarMaterias(char matrizNombre[20][30], int matrizEnteros[20][2]);
void mostrarMaterias(char matrizNombre[20][30], int matrizEnteros[20][2]);
void cargarAccesos(float *vectorHoras, int matrizAccesosMarzo[20][31]);
void mostrarMateriasSinAcceso(float *vectorHoras);
void mostrarMateriaConMasAccesosEnMarzo(float *vectorHoras);
void mostrarMateriasYiasEnMarzo(int matrizAccesosMarzo[20][31]);

int main(){

    char matrizNombre[20][30]{}; // [20] cantidad de materias a guardar. [30] cantidad de caracteres para los nombres de las materias.
    int matrizEnteros[20][2]{}; // [20] por cada materia(20), se guarda numero de materia, cantidad de alumnos y profesores.
    float vectorHoras[20]{}; // por cada materia (20), se acumulan las horas
    int matrizAccesosMarzo[20][31]{}; // por cada materia (20), se cuentan los accesos de los 31 dias de marzo

    int opcion;

    while(true){
        system("cls");
        cout << "-----MENU PRINCIPAL-----" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - CARGAR MATERIAS" << endl;
        cout << "2 - MOSTRAR MATERIAS" << endl;
        cout << "3 - CARGAR INGRESOS" << endl;
        cout << "4 - MOSTRAR MATERIAS SIN ACCESO" << endl;
        cout << "5 - MOSTRAR LA MATERIA CON MAS HORAS DE ACCESO" << endl;
        cout << "6 - MOSTRAR INGRESOS A CADA MATERIA POR CADA DIA DE MARZO" << endl;
        cout << "0 - SALIR" << endl;
        cout << "--------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
        case 1:
            cargarMaterias(matrizNombre, matrizEnteros);
            break;
        case 2:
            mostrarMaterias(matrizNombre, matrizEnteros);
            break;
        case 3:
            cargarAccesos(vectorHoras, matrizAccesosMarzo);
            break;
        case 4:
            mostrarMateriasSinAcceso(vectorHoras);
            break;
        case 5:
            mostrarMateriaConMasAccesosEnMarzo(vectorHoras);
            break;
        case 6:
            mostrarMateriasYiasEnMarzo(matrizAccesosMarzo);
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Opcion incorrecta." << endl;
            break;
        }
        cout << endl;
        system("pause");
    }

	cout << endl << endl;
	system("pause");
	return 0;
}

void cargarCadena(char *palabra, int tamanio){
    int i;
    fflush(stdin);
    for(i=0;i<tamanio;i++){
        palabra[i]=cin.get();
        if(palabra[i]=='\n') break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

void cargarMaterias(char matrizNombre[20][30], int matrizEnteros[20][2]){
    int numeroMateria;
    for(int i=0;i<5; i++){
        cout << "Ingrese numero de materia: ";
        cin >> numeroMateria;
        cout << "Ingrese nombre de materia: ";
        cargarCadena(matrizNombre[numeroMateria - 1], 29);
        cout << "Ingrese cantidad de profesores: ";
        cin >> matrizEnteros[numeroMateria - 1][0];
        cout << "Ingrese cantidad de alumnos: ";
        cin >> matrizEnteros[numeroMateria - 1][1];
    }
}

void mostrarMaterias(char matrizNombre[20][30], int matrizEnteros[20][2]){
    for(int i=0;i<5; i++){
        cout << "Numero de materia: " << i + 1 << endl;
        cout << "Nombre de materia: " << matrizNombre[i] << endl;
        cout << "Cantidad de profesores: " << matrizEnteros[i][1] << endl;
        cout << "Cantidad de alumnos: " << matrizEnteros[i][2] << endl;
        cout << endl;
    }
}

void cargarAccesos(float *vectorHoras, int matrizAccesosMarzo[20][31]){
    int numeroLegajo, dia, mes, numeroMateria;
    float cantidadHoras;

    cout << "Numero de Legajo: ";
    cin >> numeroLegajo;
    while(numeroLegajo != 0){
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Numero de materia: ";
        cin >> numeroMateria;
        cout << "Cantidad de horas: ";
        cin >> cantidadHoras;
        vectorHoras[numeroMateria - 1] += cantidadHoras;
        if(mes == 3){
            matrizAccesosMarzo[numeroMateria - 1][dia -1] ++;
        }
        cout << "--------------------------" << endl;
        cout << "Numero de Legajo: ";
        cin >> numeroLegajo;
    }
}

void mostrarMateriasSinAcceso(float *vectorHoras){
    cout << "-----PUNTO A-----" << endl << endl;
    cout << "Las materias sin acceso son: " << endl;
    for(int i=0; i<20;i++){
        if(vectorHoras[i] == 0){
            cout << "Materia: " << i + 1 << endl;
        }
    }
}

void mostrarMateriaConMasAccesosEnMarzo(float *vectorHoras){


}

void mostrarMateriasYiasEnMarzo(int matrizAccesosMarzo[20][31]){



}




