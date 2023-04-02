#include <iostream>
#include <cstdlib>
#include <cstring>

/*5
Programacion
200
3
3
Ingles
150
4
2
Laboratorio 2
400
5
1
Matematica
450
3
4
Arso
150
2*/

using namespace std;
class Materia{
private:    // ---PROPIEDADES---
    int numero;
    int cantidadDocentes;
    int cantidadAlumnos;
    char nombre[30];
public:     // ---METODOS---
    // SET -> ESTABLECER
    void setNumero(int _numero){ (numero = _numero); }
    void setNombre(const char *_nombre){ strcpy(nombre, _nombre); }
    void setCantidadAlumnos(int _cantidadAlumnos){ (cantidadAlumnos = _cantidadAlumnos); }
    void setCantidadDoncentes(int _cantidadDoncentes){ cantidadDocentes = _cantidadDoncentes; }
    // GET -> OBTENER
    int getNumero(){ return numero; }
    const char *getNombre(){ return nombre;  }
    int getCantidadAlumnos(){ return cantidadAlumnos; }
    int getCantidadDocentes(){ return cantidadDocentes; }

};

void cargarCadena(char *palabra, int tamanio);

void cargarMaterias(Materia *vectoMaterias);
void mostrarMaterias(Materia *vectoMaterias);
void cargarAccesos(float *vectorHoras, int matrizAccesosMarzo[20][31]);
void mostrarMateriasSinAcceso(float *vectorHoras);
void mostrarMateriaConMasAccesosEnMarzo(float *vectorHoras);
void mostrarMateriasYiasEnMarzo(int matrizAccesosMarzo[20][31]);
int buscarPosicionMayor(float *vec, int tamanio);




int main(){

    //char matrizNombre[20][30]{}; // [20] cantidad de materias a guardar. [30] cantidad de caracteres para los nombres de las materias.
    //int matrizEnteros[20][2]{}; // [20] por cada materia(20), se guarda numero de materia, cantidad de alumnos y profesores.

    Materia vectorMaterias[20]{};
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
            cargarMaterias(vectorMaterias);
            break;
        case 2:
            mostrarMaterias(vectorMaterias);
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

void cargarMaterias(Materia *vectoMaterias){
    int numeroMateria, cantidadDocentes, cantidadAlumnos;
    char nombre[30];

    for(int i=0;i<5; i++){
        cout << "Ingrese numero de materia: ";
        cin >> numeroMateria;
        vectoMaterias[i].setNumero(numeroMateria);
        cout << "Ingrese nombre de materia: ";
        cargarCadena(nombre, 29);
        vectoMaterias[i].setNombre(nombre);
        cout << "Ingrese cantidad de profesores: ";
        cin >> cantidadDocentes;
        vectoMaterias[i].setCantidadDoncentes(cantidadDocentes);
        cout << "Ingrese cantidad de alumnos: ";
        cin >> cantidadAlumnos;
        vectoMaterias[i].setCantidadAlumnos(cantidadAlumnos);
    }
}

void mostrarMaterias(Materia *vectoMaterias){
    for(int i=0;i<5; i++){
        cout << "Numero de materia: " << vectoMaterias[i].getNumero() << endl;
        cout << "Nombre de materia: " << vectoMaterias[i].getNombre() << endl;
        cout << "Cantidad de docentes: " << vectoMaterias[i].getCantidadDocentes() << endl;
        cout << "Cantidad de alumnos: " << vectoMaterias[i].getCantidadAlumnos() << endl;
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

int buscarPosicionMayor(float *vec, int tamanio){
    int posMayor = 0;
    for(int i=0; i<tamanio; i++){
        if(vec[i] > vec[posMayor]){
            posMayor = i;
        }
    }
    return posMayor;
}

void mostrarMateriaConMasAccesosEnMarzo(float *vectorHoras){
    int pos = buscarPosicionMayor(vectorHoras, 20);
    cout << "-----PUNTO B-----" << endl << endl;
    cout << "La materia con mas cantidad de horas en el mes de marzo es: " << pos + 1 << " con esta cantidad de horas: " << vectorHoras[pos];

}

void mostrarMateriasYiasEnMarzo(int matrizAccesosMarzo[20][31]){
    cout << "-----PUNTO B-----" << endl << endl;
    cout << "La cantidad de accesos por materias en cada dia de marzo es: " << endl << endl;
    for(int i=0; i<20; i++){
        cout << "Materia " << i + 1 << endl;
        for(int j=0; j<31; j++){
            if(matrizAccesosMarzo[i][j] != 0){
                cout << "Dia: " << j + 1 << endl;
                cout << "Cantidad de accesos: " << matrizAccesosMarzo[i][j];
            }
        }
        cout << endl;
    }
}
