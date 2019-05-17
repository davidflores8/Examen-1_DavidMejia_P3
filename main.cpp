#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void liberarMatriz(char**, int);
void printMatriz(char**, int);
char** crearMatriz(int);
char** llenarMatriz(char**);

int main()
{
	char** matriz=NULL;
	matriz=crearMatriz(11);
	printMatriz(matriz, 11);
	liberarMatriz(matriz, 11);
	return 0;

}

char** llenarMatriz(char** matriz, int size)
{


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


void printMatriz(char** matrix, int size)
{
        for(int i=0;i<size;i++)
        {
                for(int j=0;j<size;j++)
                {
                        cout<<"[ "<<matrix[i][j]<<" ] ";

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

