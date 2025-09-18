#include <iostream>
#include <ctime>
using namespace std;

const int RIGHE = 3, COLONNE = 3;

// prototipi funzioni
void interfaccia();
void riempi_matrice_casuale(int mat[RIGHE][COLONNE]);
void riempi_matrice_manuale(int mat[RIGHE][COLONNE]);
void visualizza_matrice(int mat[RIGHE][COLONNE]);
void azzera_matrice(int mat[RIGHE][COLONNE]);
bool matrice_diagonale(int mat[RIGHE][COLONNE]);
bool matrice_scalare(int mat[RIGHE][COLONNE]);
bool matrice_unitaria(int mat[RIGHE][COLONNE]);
bool matrice_nulla(int mat[RIGHE][COLONNE]);
bool matrice_singolare(int mat[RIGHE][COLONNE]);
bool matrice_simmetrica(int mat[RIGHE][COLONNE]);
bool matrice_triangolare_superiore(int mat[RIGHE][COLONNE]);
bool matrice_triangolare_inferiore(int mat[RIGHE][COLONNE]);

int main(){
    int matrice[RIGHE][COLONNE];
    char scelta;

    do{
        interfaccia();
        cout << endl;
        cout << "\tScegli l'operazione da svolgere: ";
        cin >> scelta;
        cout << endl;

        // flusso di elaborazione
        switch (scelta) {
            case '1':
                riempi_matrice_manuale(matrice);
                visualizza_matrice(matrice);
                break;
            case '2':
                riempi_matrice_casuale(matrice);
                visualizza_matrice(matrice);
                break;
            case '3':
                azzera_matrice(matrice);
                visualizza_matrice(matrice);
                break;
            case '4':
                if(matrice_diagonale(matrice)){         // controllo matrice diagonale
                    cout << "\tla matrice e' diagonale ";
                    if(matrice_scalare(matrice)){       // controllo matrice scalare
                        cout << "ed e' scalare ";
                        if(matrice_unitaria(matrice))   // controllo matrice unitaria
                            cout << " e unitaria";
                        else
                            cout << "ma non e' unitaria";
                    }else{
                        cout << "ma non e' scalare";
                    }
                    cout << endl;
                }else{
                    if (RIGHE == COLONNE)
                        cout << "\tLa matrice non e' diagonale\n";
                        cout << endl;
                }

                if(matrice_nulla(matrice)){            	    // controllo matrice nulla
                    cout << "\tLa matrice e' nulla\n";
                    cout << endl;
                }else{
                    cout << "\tLa matrice non e' nulla\n";
                    cout << endl;
                }

                if (matrice_singolare(matrice)){            // controllo matrice singolare
                    cout << "\tLa matrice e' singolare\n";
                    cout << endl;
                }else{
                    cout << "\tLa matrice non e' singolare\n";
                    cout << endl;
                }

                if(matrice_simmetrica(matrice)){            // controllo matrice simmetrica
                    cout << "\tLa matrice e' simmetrica\n";
                    cout << endl;
                }else{
                    cout << "\tLa matrice non e' simmetrica\n";
                    cout << endl;
                }

                // controllo matrice triangolare superiore
                if (matrice_triangolare_superiore(matrice)){
                    cout << "\tLa matrice e\' triangolare superiore\n";
                    cout << endl;
                }else{
                    cout << "\tLa matrice non e\' triangolare superiore\n";
                    cout << endl;
                }

                // controllo matrice triangolare inferiore
                if (matrice_triangolare_inferiore(matrice)){
                    cout << "\tLa matrice e\' triangolare inferiore\n";
                    cout << endl;
                }else{
                    cout << "\tLa matrice non e\' triangolare inferiore\n";
                    cout << endl;
                }
                break;
        }
        cout << "\t";
        system("PAUSE");
    }while(scelta != '9');
    return 0;
}

void interfaccia(){
    system("CLS");
    cout << endl;
    cout << "\tMenu Principale\n";
    cout << endl;
    cout << "\tRiempi matrice manualmente" << "...............................1\n" << endl;
    cout << "\tRiempi matrice con numeri casuali" << "........................2\n" << endl;
    cout << "\tAzzera la matrice" << "........................................3\n" << endl;
    cout << "\tControlla la matrice" << ".....................................4\n" << endl;
    cout << "\tEsci" << ".....................................................9\n" << endl;
}

// riempi la matrice casualmente
void riempi_matrice_casuale(int mat[RIGHE][COLONNE]){
    srand(time(0));
    for(int i = 0; i < RIGHE; i++)
        for(int j = 0; j < COLONNE; j++)
            mat[i][j] = (rand()%10);                // numeri casuali da 0 a 9
}

// riempi la matrice manualmente
void riempi_matrice_manuale(int mat[RIGHE][COLONNE]){
    int cont = 0;
    cout << "\tInserisci " << RIGHE * COLONNE << " numeri per riempire la matrice: \n";
    cout << endl;
    for(int i = 0; i < RIGHE; i++)
        for(int j = 0; j < COLONNE; j++){
            cout << "\tInserisci " << cont + 1 << " numero: ";
            cin >> mat[i][j];                       // inserimento manuale
            cout << endl;
            cont++;
        }
}

// inizializza la matrice a 0
void azzera_matrice(int mat[RIGHE][COLONNE]){
    for(int i = 0; i < RIGHE; i++)
        for(int j = 0; j < COLONNE; j++)
            mat[i][j] = 0;                          // inizializzazione della cella a 0
}

// Visualizza la matrice
void visualizza_matrice(int mat[RIGHE][COLONNE]){
    cout << endl << endl;
    for(int i = 0; i < RIGHE; i++){
        cout << "\t";
        for(int j = 0; j < COLONNE; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

// controlla se la matrice è diagonale
bool matrice_diagonale(int mat[RIGHE][COLONNE]){
    bool diagonale = true;
    if(RIGHE != COLONNE){
        cout << "La matrice non e\' quadrata, quindi: ";
        diagonale = false;
        return diagonale;
    }
    for (int i = 0; i < RIGHE; i++)
        for (int j = 0; j < COLONNE; j++)
            if((i == j) && (mat[i][j] == 0))
                diagonale = false;
            else
                if((i != j) && (mat[i][j] != 0))
                    diagonale = false;
    return diagonale;
}

// se è diagonale controlla scalare
bool matrice_scalare(int mat[RIGHE][COLONNE]){
    bool scalare = true;
    int val = mat[0][0];
    int i = 1, j = 1;

    if (matrice_diagonale(mat)){
        while (i < RIGHE){
            if(mat[i][j] != val)
                scalare = false;
            i++;
            j++;
        }
    }
    else scalare = false;
    return scalare;
}

// se è scalare controlla unitaria
bool matrice_unitaria(int mat[RIGHE][COLONNE]){
    bool unitaria = true;
    int i = 1, j = 1;

    if (matrice_scalare(mat)){
        while (i < RIGHE){
            if(mat[i][j] != 1)
                unitaria = false;
            i++;
            j++;
        }
    }
    else unitaria = false;
    return unitaria;
}

// controlla se la matrice è nulla
bool matrice_nulla(int mat[RIGHE][COLONNE]){
    bool nulla = true;
    for (int i = 0; i < RIGHE; i++)
        for (int j = 0; j < COLONNE; j++)
            if(mat[i][j] != 0)
                nulla = false;
    return nulla;
}

// controlla se la matrice è singolare
bool matrice_singolare(int mat[RIGHE][COLONNE]){
    int diag_principale = 1, diag_secondaria = 1;       // inizializzate a 1 per prodotto
    int determinante;
    bool singolare = true;

    for(int i = 0; i < RIGHE; i++){                     // calcolo prodotto delle due diagonali
        diag_principale = diag_principale * mat[i][i];
        diag_secondaria = diag_secondaria * mat[i][RIGHE-1-i];
    }

    determinante = diag_principale - diag_secondaria;   // calcolo del determinante
    if(determinante != 0)
        singolare = false;
    return singolare;
}

// controlla se la matrice è simmetrica
bool matrice_simmetrica(int mat[RIGHE][COLONNE]){
    bool simmetrica = true;
    int i = 0, j = 0;
    do{
        do{
            if(mat[i][j] != mat[j][i]) simmetrica = false;
            j++;
        }while((j < RIGHE) && (simmetrica == true));
        i++;
        j = 0;
    }while((i < COLONNE) && (simmetrica == true));
    return simmetrica;
}

// controlla se la matrice è triangolare superiore
bool matrice_triangolare_superiore(int mat[RIGHE][COLONNE]){
    bool tri_sup = true;
    int i = 0, j = 0;
    do{
        do{
            if((i > j)&&(mat[i][j] != 0)) tri_sup = false;
            j++;
        }while((j < COLONNE)&&(tri_sup == true));
        i++;
        j = 0;
    }while((i < RIGHE)&&(tri_sup == true));
    return tri_sup;
}

// controlla se la matrice è triangolare inferiore
bool matrice_triangolare_inferiore(int mat[RIGHE][COLONNE]){
    bool tri_inf = true;
    int i = 0, j = 0;
    do{
        do{
            if((j > i) && (mat[i][j] != 0)) tri_inf = false;
            j++;
        }while((j < COLONNE) && (tri_inf == true));
        i++;
        j = 0;
    }while((i < RIGHE)&&(tri_inf == true));
    return tri_inf;
}
