#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string>

int main(int argc, char** argv) {
	/*
	std::string linea, texto;
	
	std::ifstream archivo("pruebinha.txt");
	
	while(std::getline(archivo, linea)){
		texto = texto+linea+"\n";
	}
	
	archivo.close();
	std::cout << texto << std::endl;
	
	
	std:ofstream archivoDos("pruebinha.txt");
	
	*/
	
	FILE *fp;
	//lectura
	int a, b, c;
	fp = fopen("pruebinha.txt", "r");
	if(fp!=NULL){
		std::cout<<"Si se pudo abrir"<<std::endl;
		fscanf(fp, "%d%d%d", &a, &b, &c);
		std::cout<<"Los valores son:"<<std::endl<< a <<std::endl<< b <<std::endl<< c <<std::endl;
	}else{
		std::cout<<"Pailas";
	}
	fclose(fp);
	
	//escritura
	int d = 89;
	fp = fopen("pruebinha.txt", "a");
	if(fp!=NULL){
		std::cout<<"Si se pudo abrir"<<std::endl;
		fprintf(fp ,"\nEsto no estaba antes\n");
		fprintf(fp ,"%d",a);
	}else{
		std::cout<<"Pailas";
	}
	fclose(fp);
		
	return 0;
}
