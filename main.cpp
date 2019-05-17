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

int main()
{
	char** matriz=NULL;
	matriz=crearMatriz(11);
	matriz=llenarMatriz(matriz, 11);
	printMatriz(matriz, 11);
	liberarMatriz(matriz, 11);
	return 0;

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
			else if(i==4 && j==4 || i==4 && j==5 || i==4)
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
			else if(i==6 && j==5 || i==6 && j==5 || i==6 && j==7)
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

