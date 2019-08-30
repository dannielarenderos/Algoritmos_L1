#include <iostream>
using namespace std;

int fibo(int n);

int elevar(int x, int y);
int fiboporCola(int pos, int first, int second);

int sumaArr(int Lista[], int cont , int res=0) {
    if(cont== 1){
        return res+Lista[0];
    }
    return sumaArr(Lista, cont-1, res+=Lista[cont-1]);
}

int SumaMatriz(int *A, int *B, int n, int *C) {
    if (n <= -1) {
        return 0;
    } else {
        C[n] = A[n] + B[n];            
        return  C[n] + SumaMatriz(A, B, n-1, C);
    } 
}

int arreglo[6] = {12,6,-21,3,10,-2};
int temp = arreglo[0];

int numMenor(int i){ 
	if(i < sizeof(arreglo)/sizeof(arreglo[0])) { 
		if(temp > arreglo[i]){
			temp = arreglo[i];
		}else{
			i++;
		}
		numMenor(i);
	}
	return temp;
}

int main() {
int arr[3] = {99,4,2};
int A[9] = {20,0,1,3,0,0,5,1,1};
int B[9] = {9,0,1,1,2,1,1,1,0};
int C[9]; 
int i ;



int num, opc,salida=1;


while(salida==1){
cout<<endl<<"MENÚ"<<endl;
cout<<"1. Fibonacci por posposición"<<endl;
cout<<"2. Fibonacci por cola"<<endl;
cout<<"3. Suma de números de un arreglo por cola"<<endl;
cout<<"4. Suma de matrices de 3x3"<<endl;
cout<<"5. Cálculo de x a la potencia n"<<endl;
cout<<"6. Menor valor de un arreglo"<<endl;
cout<<"7. Salir"<<endl;

cout<<endl<<"Qué desea seleccionar?"<<endl;
cin>>opc;

switch(opc){

case 1:

cout<<"Fibonacci por posposición"<<endl;
cout<<"Ingresar número en la serie de fibonacci"<<endl;
cin>>num;
cout<<endl<<"El número en la serie es: ";
cout<<fibo(num)<<endl<<endl;

break;

case 2:

cout<<"Fibonacci por cola"<<endl;
cout<<"Ingresar número en la serie de fibonacci"<<endl;
cin>>num;
cout<<endl<<"El número en la serie es: ";cout<<fiboporCola(num, 0,1)<<endl;

break;


case 3:
cout <<"La suma de los números del arreglo es: "<<endl<< 
sumaArr(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
break;

case 4:

cout<<endl<<"La suma de las matrices A y B es: "<<endl;
i =1;

SumaMatriz(A, B, 8, C);
    for (int j = 0; j < 9; j++){
        cout << C[j] << ' ';
        if (i == 3) {
            cout << endl;
            i = 0;
        }
        i++;
    }

break;

case 5:
int base, expo;
cout<<"Cálculo de x a la potencia n"<<endl;
cout<<"Ingresar la base"<<endl;
cin>>base;
cout<<"Ingresar el exponente"<<endl;
cin>>expo;

cout<<"La base "<< base << " elevada a " << expo<< " es: " <<elevar(base,expo)<<endl<<endl;

break;


case 6:
 
 i = 0;
      cout << "El menor número en el  arreglo es: "; 
      cout << numMenor(i)<<endl;
      break;
break; 

default:
salida = 0;
break;
}

}



}








int fibo(int n){
  if(n==0){
    return 0;
  }
  if(n==1){
    return 1;
  }

else{
  return fibo(n-1)+fibo(n-2);
}

}


int fiboporCola(int pos, int first=0, int second=1){
    if(pos==0){
        return first;
    }
    if(pos==1){
        return second;
    }   
    pos-=1;
    return fiboporCola(pos, second, first+second);
}




int elevar(int x, int n){

  if(n==0){
    return 1;
  }

else{
return elevar(x, n-1)*x;
}

}