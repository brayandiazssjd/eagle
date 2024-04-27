#include <iostream>
#include <stdio.h>

void imprimirArreglo(int arr[], int tam){
	for(int i=0; i<tam; i++){
		std::cout<< arr[i] << std::endl;
	}
}

int main(int argc, char** argv) {
	int arreglo[100], size, mayor, valor;
	FILE *fp;
	//Leyendo el archivo "a" y colocando los valores en el arreglo
	fp = fopen("a.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &size);
		mayor = size;
		for(int i=0;i<size;i++){
			fscanf(fp, "%d", &arreglo[i]);
		}
		std::cout<<"a:"<<std::endl;
		imprimirArreglo(arreglo, size);
		fclose(fp);
	}else{
		std::cout<<"El archivo no existe";
	}
	
	//Ahora el archivo "b"
	fp = fopen("b.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &size);
		if(size>mayor){
			mayor = size;
		}
		for(int i=0;i<size;i++){
			fscanf(fp, "%d", &valor);
			arreglo[i] = arreglo[i]+valor;
		}
		std::cout<<"b:"<<std::endl;
		imprimirArreglo(arreglo, size);
		fclose(fp);
	}else{
		std::cout<<"El archivo no existe";
	}

	//Ahora el archivo "c"
	fp = fopen("c.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &size);
		if(size>mayor){
			mayor = size;
		}		
		for(int i=0;i<size;i++){
			fscanf(fp, "%d", &valor);
			arreglo[i] = arreglo[i]+valor;
		}
		std::cout<<"c:"<<std::endl;
		imprimirArreglo(arreglo, size);
		fclose(fp);
	}else{
		std::cout<<"El archivo no existe";
	}
	
	//Ahora escribimos el resultado en otro archivo que vamos a crear.
	fp = fopen("d.txt", "w");
	if(fp!=NULL){
		fprintf(fp, "%d\n", mayor);
		for(int i=0; i<mayor; i++){
			fprintf(fp, "%d\n", arreglo[i]);
		}
		fclose(fp);
	}else{
		std::cout<<"Archivo d.txt no se pudo crear";
	}
		
	return 0;
}
