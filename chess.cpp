#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Tamaño del tablero
bool esSeguro(vector<vector<int>>& tablero, int row, int col) {
    // Verificar la columna
    for (int i = 0; i < row; i++) {
        if (tablero[i][col] == 1) {
            return false;
        }
    }

    // Verificar la diagonal izquierda arriba
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    // Verificar la diagonal derecha arriba
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    // Verificar la diagonal izquierda abajo
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    // Verificar la diagonal derecha abajo
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void reynas(vector<vector<int>>& tablero, int row, int col){
    int num=8;
    while(num!=0){

        for(int i=0;i<tablero.size();i++){
            for(int j=0;j<tablero[row].size();j++){
                
                if(esSeguro(tablero,i,j)){
                    tablero[row][col]=1;
                    num--;
                }
                else{
                    continue;
                }

                
            }

        }

    }

}

int main(){
    vector<vector<int>>tablero{0};
    reynas(tablero,8,8);
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }


}
