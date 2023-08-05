/*

- TAREA:
Algoritmo para: Arbol binario  para mochila

*/

#include <bits/stdc++.h>

using namespace std;

// Clase para representar un objeto con peso y beneficio
class Objeto 
{
    public:
        int pesoObjeto;
        int beneficioObjeto;
        //constructor
        Objeto(int _pesoObjeto, int _beneficioObjeto) 
        {
            pesoObjeto = _pesoObjeto;
            beneficioObjeto = _beneficioObjeto;
        }
};

// Actualiza la solución óptima encontrada en el árbol combinatorio
void ActualizarArbol(vector<int>& vecSolucion, vector<Objeto>& vecObjetos, vector<int>& vecMochilaFin, int& pesoFinal, int& bfinal) 
{
    int beneficioTOTAL = 0;
    int pesoTotal = 0;
    for (int i = 0; i < vecObjetos.size(); i++) 
    {
        if (vecSolucion[i] == 1) 
        {
            beneficioTOTAL += vecObjetos[i].beneficioObjeto;
            pesoTotal += vecObjetos[i].pesoObjeto;
        }
    }
    if (beneficioTOTAL > bfinal) 
    {
        for (int i = 0; i < vecObjetos.size(); i++) 
        {
            vecMochilaFin[i] = vecSolucion[i];
        }
        pesoFinal = pesoTotal;
        bfinal = beneficioTOTAL;
    }
}

// Valida si una solución parcial es válida, es decir, si no excede la capacidad de la mochila
bool validarSolucion(const vector<int>& vecSolucion, int numEtapa, vector<Objeto>& vecObjetos, int capacidadMochila) 
{
    int pesoTotal = 0;
    for (int i = 0; i <= numEtapa; i++) 
    {
        if (vecSolucion[i] == 1) 
        {
            pesoTotal += vecObjetos[i].pesoObjeto;
        }
    }
    return pesoTotal <= capacidadMochila;
}


// Genera el árbol binario de decisiones recursivamente para el problema de la mochila
void ArbolBinario(vector<int>& vecSolucion, int numNivel, vector<Objeto>& vecObjetos) 
{
    if (numNivel >= vecObjetos.size()) return;

    cout<<numNivel+1<<": ";
    for (int i = 0; i <= numNivel; i++) 
    {
        //CASOS
        if (vecSolucion[i] == 0) 
        
        {
            cout << "NO ";
        } 
        else if (vecSolucion[i] == 1) 
        
        {
            cout << "YES ";
        } 
        else 
        
        {
            cout << "NONE ";
        }
    }
    cout << endl;
    vecSolucion[numNivel] = 1;
    ArbolBinario(vecSolucion, numNivel + 1, vecObjetos);
    vecSolucion[numNivel] = 0;
    ArbolBinario(vecSolucion, numNivel + 1, vecObjetos);
    vecSolucion[numNivel] = -1;
}


// Genera el árbol binario de decisiones recursivamente para el problema de la mochila
void BackTracking(int capMochila,vector<int>& vecSolucion, int numEtapa, vector<Objeto>& vecObjetos, vector<int>& vecMochilaFin, int& pesoFinal, int& bfinal) 
{
    int i = 0;
    if (numEtapa>vecObjetos.size()-1) return;
    
    do 
    {
        vecSolucion[numEtapa] = i;
        if (validarSolucion(vecSolucion, numEtapa, vecObjetos, capMochila)) 
        {
            if (numEtapa == vecObjetos.size() - 1)
                ActualizarArbol(vecSolucion, vecObjetos, vecMochilaFin, pesoFinal, bfinal);
            else
                BackTracking(capMochila,vecSolucion, numEtapa + 1, vecObjetos, vecMochilaFin, pesoFinal, bfinal);
        }
        i++;
    }
    while(vecSolucion[numEtapa]!=1);
    vecSolucion[numEtapa]=-1;
}

int main() 
{
    int numOjectos, capMochila;
    cout<<"Ingrese el numero que tendra el vector de Objetos: ";
    cin>>numOjectos;
    cout<<"Ingrese la capacidad que tendra la mochila: ";
    cin>>capMochila;
    vector<int> vecPeso(numOjectos);
    vector<int> vecObj(numOjectos);
    
    for(int i=0;i<numOjectos;i++){
        cout<<"\nElemento N° "<<i+1<<": "<<endl;
        cout<<"Peso: ";cin>>vecPeso[i];
        cout<<"Beneficio: ";cin>>vecObj[i];
    }

    vector<Objeto> vecObjetos;
    for (int i = 0; i < numOjectos; i++) 
    {
        vecObjetos.push_back(Objeto(vecPeso[i], vecObj[i]));
    }

    vector<int> solActual(numOjectos, -1);
    vector<int> Mochi01(numOjectos, 0);
    int pesoFinal = 0, beneficioFinal = 0;

    cout<<"Obteniendo arbol binario de decisiones..."<<endl;
    ArbolBinario(solActual, 0, vecObjetos);
    BackTracking(capMochila,solActual, 0, vecObjetos, Mochi01, pesoFinal, beneficioFinal);

    cout<<"Obteniendo solucion optima Mochila... "<<endl;
    for (int i=0; i<numOjectos; i++) 
    {
        if (Mochi01[i]==1) 
        {
            cout<<"Objeto "<<i+1<<" ";
        }
    }
    cout<<"\nEl valor optimo es: "<<beneficioFinal<<endl;
    return 0;
}