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
bool ganan_Blancos(char**);
bool ganan_Negros(char**);
void CapturaGuardianes(char**, int);
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
	fila_para_mover=0;
	columna_para_mover=0;
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
			gananBlancos=ganan_Blancos(matriz);
			gananNegros=ganan_Negros(matriz);
                        CapturaGuardianes(matriz,11);
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
			gananBlancos=ganan_Blancos(matriz);
			gananNegros=ganan_Negros(matriz);
			CapturaGuardianes(matriz,11);
			printMatriz(matriz,11);
                        turno=false;


		}
		if(gananNegros==true)
			cout<<"Los moscovitas han ganado el juego"<<endl;
		else if (gananBlancos==true)
			cout<<"Los suecos han ganado el juego"<<endl;
		liberarMatriz(matriz, 11);
	}
	return 0;

}

void CapturaGuardianes(char** matriz, int size)

{
	int i=0;
	int j=0;
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
			if(matriz[i][j]=='B')
			{
				if(matriz[i+1][j]=='N' && matriz[i-1][j]=='N' && matriz[i][j+1]=='N' && matriz[i][j-1]=='N')
					matriz[i][j]=' ';
			}
			if(matriz[i][j]=='N')
                        {
                                if(matriz[i+1][j]=='B' && matriz[i-1][j]=='B' && matriz[i][j+1]=='B' && matriz[i][j-1]=='B')
                                        matriz[i][j]=' ';
                        }             
}


bool ganan_Blancos(char** matriz)
{
	if(matriz[10][0]=='R')
		return true;
	else if(matriz[0][0]=='R')
		return true;
	else if(matriz[10][10]=='R')
		return true;
	else if(matriz[0][10]=='R')
		return true;
	else
		return false;
}

bool ganan_Negros(char**matriz)
{
	int i=0;
        int j=0;
	bool retorno=false;
        for(i=1;i<10;i++)
                for(j=1;j<10;j++)
                        if(matriz[i][j]=='R')
                        {
                                if(matriz[i+1][j]=='N' && matriz[i-1][j]=='N' && matriz[i][j+1]=='N' && matriz[i][j-1]=='N')
                                        retorno=true;
                        }

	return retorno;
}


bool paraMover(char** matriz, string coordenada, bool turno)
{
	int fila=0;
        int columna=0;
        bool retorno=false;
        if(coordenada.length()==4)
                if(coordenada[2]=='1' && coordenada[3]=='0')
                        fila=9;
                else if (coordenada[2]==1 && coordenada[3]=='1')
                        fila==10;
                else
                        retorno=false;
        else

                switch(coordenada[0])
                {
                        case 'A':
                                fila=0;
                        break;
                        case 'B':
                                fila=1;
                        break;
                        case 'C':
                                fila=2;
                        break;
                        case 'D':
                                fila=3;
                        break;
                        case 'E':
                                fila=4;
                        break;
                        case 'F':
                                fila=5;
                        break;
                        case 'G':
                                fila=6;
			break;
                        case 'H':
                                fila=7;
                        break;
                        case 'I':
                                fila=8;
                        break;
                        case 'J':
                                fila=9;
                        break;
                        case 'K':
                                fila=10;
                        break;
                        default:
                                retorno=false;
                        break;
                }
                switch(coordenada[2])
                {
                        case '0':
                                columna=0;
                        break;
                        case '1':
                                columna=1;
                        break;
                        case '2':
                                columna=2;
                        break;
                        case '3':
                                columna=3;
                        break;
                        case '4':
                                columna=4;
                        break;
                        case '5':
				columna=5;
                        break;
                        case '6':
                                columna=6;
                        break;
                        case '7':
                                columna=7;
                        break;
                        case '8':
                                columna=8;
                        break;
                        case '9':
                                columna=9;
                        break;
                        default:
                                retorno=false;
                        break;
                }
		retorno=false;
		if((fila==0 && columna==0) || (fila==10 && columna==0) || (fila==10 && columna==10) || (fila==0 && columna==10))
		{
			retorno=false;
		}
		else
		{
			
			if(fila==fila_a_mover && turno==true && matriz[fila][columna]==' ')
			{
				matriz[fila][columna]='B';
				matriz[fila_a_mover][columna_a_mover]=' ';
				retorno=true;
			}
			if(columna==columna_a_mover && turno==true && matriz[fila][columna]==' ')
			{
				matriz[fila][columna]='B';
                       		matriz[fila_a_mover][columna_a_mover]=' ';
				retorno=true;
			}
			if(fila!=fila_a_mover && turno==false && matriz[fila][columna]==' ')
                	{
                        	matriz[fila][columna]='N';
                        	matriz[fila_a_mover][columna_a_mover]=' ';
                        	retorno=true;
                	}
                	if(columna!=columna_a_mover && turno==false && matriz[fila][columna]==' ')
                	{
                        	matriz[fila][columna]='N';
                        	matriz[fila_a_mover][columna_a_mover]=' ';
                        	retorno=true;
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
				fila=0;
			break;
			case 'B':
				fila=1;
			break;
			case 'C':
				fila=2;
			break;
			case 'D':
				fila=3;
			break;
			case 'E':
				fila=4;
			break;
			case 'F':
				fila=5;
			break;
			case 'G':
				fila=6;
			break;
			case 'H':
				fila=7;
			break;	
			case 'I':
				fila=8;
			break;
			case 'J':
				fila=9;
			break;
			case 'K':
				fila=10;
			break;
			default:
				retorno=false;
			break;
		}
		switch(coordenada[2])
		{			
			case '0':
				columna=0;
			break;
			case '1':
				columna=1;
			break;
			case '2':
				columna=2;
			break;
			case '3':
				columna=3;
			break;
			case '4':
				columna=4;
			break;
			case '5':
				columna=5;
			break;
			case '6':
				columna=6;
			break;
			case '7':
				columna=7;
			break;
			case '8':
				columna=8;
			break;
			case '9':
				columna=9;
			break;
			default:
				retorno=false;
			break;
		}
		fila_a_mover=fila;
		columna_a_mover=columna;
		retorno=false;
		if(turno==false)
			if(matriz[fila_a_mover][columna_a_mover]=='N')
				retorno=true;
		if(turno==true)
			if(matriz[fila_a_mover][columna_a_mover]=='B' || matriz[fila_a_mover][columna_a_mover]=='R')
				retorno=true;
	
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

