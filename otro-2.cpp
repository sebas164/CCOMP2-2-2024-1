#include <iostream>
#include <array>

using namespace std;

const int N = 8;

bool posValida(array<array<int,N>,N>& tablero, int row, int col) {
    
    for (int i = 0; i < row; i++) {
        if (tablero[i][col] == 1) {
            return false;
        }
    }
    
    for (int i = 0; i < col; i++) {
        if (tablero[row][i] == 1) {
            return false;
        }
    }

    int i = row;
    int j = col;
    while (i >= 0 && j >= 0) {
        if (tablero[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }    
    
    i = row;
    j = col;
    while (i >= 0 && j < N) {
        if (tablero[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    i = row;
    j = col; 
    
    while (i < N && j >= 0) {
        if (tablero[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }


    
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void imprimirTablero(array<array<int,N>,N> &tablero){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
void reynas(array<array<int,N>,N>& tablero,int coi,int contador) {
    
   for(int i=coi;i<N;i++){
        for(int j=0;j<N;j++){
                
            if(posValida(tablero,i,j)){
                tablero[i][j]=1;
                contador++;
                
                if(contador==N){
                    imprimirTablero(tablero);
                    cout<<"----------------"<<endl;
                }else{
                    reynas(tablero,i+1,contador);                    
                    
                }
                if(tablero[i][j]==1){
                    tablero[i][j]=0;
                    contador--;
                }
                
                

            }
            

                
            

        
        }
   }    
}

int main() {
    array<array<int,N>,N>tablero{8, 0};
    reynas(tablero,0,0);
    

    return 0;
}
