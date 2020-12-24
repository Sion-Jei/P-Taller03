#include <iostream> 
#include <cmath> 
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std; 
  
static double haversine(double lat1, double lon1, double lat2, double lon2) { 
        // Distancia entre latitudes y longitudes
        double dLat = (lat2 - lat1) * M_PI / 180; 
        double dLon = (lon2 - lon1) * M_PI / 180; 
  
        // Convierte a radianes
        lat1 = (lat1) * M_PI / 180; 
        lat2 = (lat2) * M_PI / 180; 
  
        // Aplicacion de la formula 
        double a = pow(sin(dLat / 2), 2) +  pow(sin(dLon / 2), 2) *  cos(lat1) * cos(lat2); 
        double rad = 6371; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    } 
void lectura(char** argv) {
    ifstream archivo;
    string texto;

    archivo.open(argv[1]);

    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo txt \n";
        exit(1);
    }

    while(!archivo.eof()) {
        getline(archivo,texto);
        cout << texto << endl;
    }

    archivo.close();
}

int main(int argc, char** argv) { 
    lectura(argv);
    double lat1 = -20.242413; 
    double lon1 = -70.132937; 
    double lat2 = -23.670139; 
    double lon2 = -70.404583; 
      
    cout << haversine(lat1, lon1, lat2, lon2) << " Km. \n"; 
    return 0; 
} 
  