#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void liberarMatriz(char**, int);
void printMatriz(char**, int);
char** crearMatriz(int);
char** llenarMatriz(char**, int);
bool turnoValido (char**, string, bool);
bool paraMover(char**, string, bool);
int fila_a_mover;
int columna_a_mover;
int fila_para_mover;
int columna_para_mover;
int main()
{
	bool gananBlancos=false;
	bool gananNegros=false;	
	bool turno=false;
	bool piezaValida=false;
	bool movValido=false;
	fila_a_mover=0;
	columna_a_mover=0;
	string movimiento1="";	
	string movimiento2="";
	char** matriz=NULL;
	matriz=crearMatriz(11);
	matriz=llenarMatriz(matriz, 11);
	printMatriz(matriz, 11);
	while(gananBlancos==false && gananNegros==false)
	{
		if(turno==false)
		{
			cout<<"Moscovita, por favor ingrese la coordenada que desea moverse:  "<<endl;
			cin>>movimiento1;
			piezaValida=turnoValido(matriz, movimiento1, turno);
			while(piezaValida==false)
			{
				cout<<"Ingrese un movimiento valido"<<endl;
				cin>>movimiento1;
				piezaValida=turnoValido(matriz, movimiento1,turno);
			}
			cout<<"Mocovita, por favor, ingrese la coordenada donde sea moverse: "<<endl;
			cin>>movimiento2;
			movValido=paraMover(matriz, movimiento2, turno);
			while(movValido==false)
			{
				cout<<"Ingrese una posicion valida: "<<endl;
				cin>>movimiento2;
				movValido=paraMover(matriz, movimiento2, turno);
			}
			printMatriz(matriz,11);
			turno=true;
		}	
		if(turno==true)
		{
			cout<<"Sueco, por favor ingrese la coordenada que desea moverse:  "<<endl;
                        cin>>movimiento1;
                        piezaValida=turnoValido(matriz, movimiento1, turno);
                        while(piezaValida==false)
                        {
                                cout<<"Ingrese un movimiento valido"<<endl;
                                cin>>movimiento1;
                                piezaValida=turnoValido(matriz, movimiento1,turno);
                        }
                        cout<<"Sueco, por favor, ingrese la coordenada donde sea moverse: "<<endl;
                        cin>>movimiento2;
                        movValido=paraMover(matriz, movimiento2, turno);
                        while(movValido==false)
                        {
                                cout<<"Ingrese una posicion valida: "<<endl;
                                cin>>movimiento2;
                                movValido=paraMover(matriz, movimiento2, turno);
                        }
			printMatriz(matriz,11);
                        turno=false;
			//cout<<"fila a mover: "<<fila_a_mover<<endl;
			//cout<<"columna a mover: "<<columna_a_mover<<endl;
			//cout<<"fila para mover: "<<fila_para_mover<<endl;
			//cout<<"columna para mover: "<<columna_para_mover<<endl;


		}
		gananBlancos=false;
		gananNegros=false;	
		//liberarMatriz(matriz, 11);
	}
	return 0;

}

bool paraMover(char** matriz, string coordenada, bool turno)
{
	int fila=0;
        int columna=0;
        bool retorno=false;
        if(coordenada.length()==4)
                if(coordenada[2]=='1' && coordenada[3]=='0')
                        fila=10;
                else if (coordenada[2]==1 && coordenada[3]=='1')
                        fila==1;
                else
                        retorno=false;
        else

                switch(coordenada[0])
                {
                        case 'A':
                                columna=0;
                        break;
                        case 'B':
                                columna=1;
                        break;
                        case 'C':
                                columna=2;
                        break;
                        case 'D':
                                columna=3;
                        break;
                        case 'E':
                                columna=4;
                        break;
                        case 'F':
                                columna=5;
                        break;
                        case 'G':
                                columna=6;
			 break;
                        case 'H':
                                columna=7;
                        break;
                        case 'I':
                                columna=8;
                        break;
                        case 'J':
                                columna=9;
                        break;
                        case 'K':
                                columna=10;
                        break;
                        default:
                                retorno=false;
                        break;
                }
                switch(coordenada[2])
                {
                        case '0':
                                fila=0;
                        break;
                        case '1':
                                fila=1;
                        break;
                        case '2':
                                fila=2;
                        break;
                        case '3':
                                fila=3;
                        break;
                        case '4':
                                fila=4;
                        break;
                        case '5':
				fila=5;
                        break;
                        case '6':
                                fila=6;
                        break;
                        case '7':
                                fila=7;
                        break;
                        case '8':
                                fila=8;
                        break;
                        case '9':
                                fila=9;
                        break;
                        default:
                                retorno=false;
                        break;
                }
               	fila_para_mover=columna;
                columna_para_mover=fila;
		cout<<" lo que hay en el pesacio donde movere:   "<<matriz[fila_para_mover][columna_para_mover]<<endl;
		cout<<" "<<endl;
		cout<<"Fila para mover "<<fila_para_mover<<endl;
		cout<<"Columna para mover "<<columna_para_mover<<endl;
		cout<<" "<<endl;
		cout<<"Fila a mover "<<fila_a_mover<<endl;
		cout<<"Columna a mover "<<columna_a_mover<<endl;
		if((fila_para_mover==0 && columna_para_mover==0) || (fila_para_mover==10 && columna_para_mover==0) || (fila_para_mover=10 && columna_para_mover==10) || (fila_para_mover==0 && columna_para_mover==10))
		{
			//cout<<"Entra aqui"<<endl;
			retorno=false;
		}
		else
		{
			//cout<<"entra al else"<<endl;
			
			if(fila_para_mover!=fila_a_mover && turno==true && matriz[columna][fila]==' ')
			{
				//cout<<"aquie esta el pedo 2"<<endl;
				matriz[columna][fila]='B';
				matriz[fila_a_mover][columna_a_mover]=' ';
				retorno=true;
			}
			if(columna_para_mover!=columna_a_mover && turno==true && matriz[columna][fila]==' ')
			{
				//cout<<"aquie esta el pedo"<<endl;
				matriz[columna][fila]='B';
                       		matriz[fila_a_mover][columna_a_mover]=' ';
				retorno=true;
			}
			if(fila_para_mover==fila_a_mover && turno==false && matriz[columna][fila]==' ')
                	{
                        	matriz[fila_para_mover][columna_para_mover]='N';
                        	matriz[fila_a_mover][columna_a_mover]=' ';
                        	retorno=true;
                	}
                	if(columna_para_mover==columna_a_mover && turno==false && matriz[columna][fila]==' ')
                	{
                        	matriz[fila_para_mover][columna_para_mover]='N';
                        	matriz[fila_a_mover][columna_a_mover]=' ';
                        	retorno=true;
                	}

			if(columna!=fila_a_mover && fila!=columna_a_mover)
			{
				cout<<"entra"<<endl;
				retorno=false;
			}
		}
	return retorno;	
}

bool turnoValido(char** matriz, string coordenada, bool turno)
{
	int fila=0;
	int columna=0;
	bool retorno=false;
	if(coordenada.length()==4)	
		if(coordenada[2]=='1' && coordenada[3]=='0')
			fila=10;
		else if (coordenada[2]==1 && coordenada[3]=='1')
			fila==1;
		else
			retorno=false;
	else
	
		switch(coordenada[0])
		{
			case 'A':
				columna=0;
			break;
			case 'B':
				columna=1;
			break;
			case 'C':
				columna=2;
			break;
			case 'D':
				columna=3;
			break;
			case 'E':
				columna=4;
			break;
			case 'F':
				columna=5;
			break;
			case 'G':
				columna=6;
			break;
			case 'H':
				columna=7;
			break;	
			case 'I':
				columna=8;
			break;
			case 'J':
				columna=9;
			break;
			case 'K':
				columna=10;
			break;
			default:
				retorno=false;
			break;
		}
		switch(coordenada[2])
		{			
			case '0':
				fila=0;
			break;
			case '1':
				fila=1;
			break;
			case '2':
				fila=2;
			break;
			case '3':
				fila=3;
			break;
			case '4':
				fila=4;
			break;
			case '5':
				fila=5;
			break;
			case '6':
				fila=6;
			break;
			case '7':
				fila=7;
			break;
			case '8':
				fila=8;
			break;
			case '9':
				fila=9;
			break;
			default:
				retorno=false;
			break;
		}
		fila_a_mover=columna;
		columna_a_mover=fila;
		retorno=false;
		if(turno==false)
			if(matriz[fila][columna]=='N')
				retorno=true;
		if(turno==true)
			if(matriz[fila][columna]=='B' || matriz[fila][columna]=='R')
				retorno=true;
	
	//cout<<matriz[fila][columna]<<endl;
	return retorno;		
}


char** llenarMatriz(char** matriz, int size)
{
	for(int i=0; i<size;i++)
		for(int j=0; j<size;j++)
			if(i==0 && j==4 || i==0 && j==5 || i==0 && j==6)
				matriz[i][j]='N';
			else if(i==1 && j==4 || i==1 && j==6)
				matriz[i][j]='N';
			else if(i==2 && j==5)
				matriz[i][j]='N';
			else if(i==3 && j==5)
				matriz[i][j]='B';
			else if(i==4 && j==4 || i==4 && j==5 || i==4 && j==6)
			       matriz[i][j]='B';
			else if(i==4 && j==0 || i==4 && j==1 || i==4 && j==9 || i==4 && j==10)
				matriz[i][j]='N';
			else if (i==5 && j==0 || i==5 && j==2)
				matriz[i][j]='N';
			else if(i==5 && j==3 || i==5 && j==4 || i==5 && j==5 || i==5 && j==6 || i==5 && j==7)
				matriz[i][j]='B';
			else if(i==5 && j==8 || i==5 && j==10)
				matriz[i][j]='N';
			else if(i==6 && j==0 || i==6 && j==1)	
				matriz[i][j]='N';
			else if (i==6 && j==0 || i==6 && j==1 || i==6 && j==9 || i==6 && j==10)
				matriz[i][j]='N';
			else if(i==6 && j==4 || i==6 && j==6 || i==6 && j==5)
				matriz[i][j]='B';
			else if(i==7 && j==5)
				matriz[i][j]='B';
			else if(i==8 && j==5)
				matriz[i][j]='N';
			else if(i==9 && j==4 || i==9 && j==6)
				matriz[i][j]='N';
			else if(i==10 && j==4 || i==10 && j==5 || i==10 && j==6)
				matriz[i][j]='B';
			else
				matriz[i][j]=' ';
			
	matriz[5][5]='R';
	return matriz;		
}

char** crearMatriz(int size)
{
        char**matriz=NULL;
        matriz=new char*[size];
        for(int i=0; i<size;i++)
        {
                matriz[i]=new char[size];
        }
        return matriz;
}


void printMatriz(char** matriz, int size)
{
        for(int i=0;i<size;i++)
        {
                for(int j=0;j<size;j++)
                {
                        	cout<<"["<<matriz[i][j]<<"]";
                }
                cout<<" "<<endl;
        }
}




void liberarMatriz(char** matriz, int size)
{
        for(int g=0;g<size;g++)
        {
                if(matriz[g]!=NULL)
                {
                        delete[] matriz[g];
                        matriz[g]=NULL;
                }
        }
        if(matriz!=NULL)
        {
                delete[]matriz;
        }
}

