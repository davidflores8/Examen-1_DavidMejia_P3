#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void liberarMatriz(string**, int);
void printMatriz(string**, int);
string** crearMatriz(int);


int main()
{
	string** matriz=NULL;
	matriz=crearMatriz(11);
	printMatriz(matriz, 11);
	liberarMatriz(matriz, 11);
	return 0;

}

string** crearMatriz(int size)
{
        string**matriz=NULL;
        matriz=new string*[size];
        for(int i=0; i<size;i++)
        {
                matriz[i]=new string[size];
        }
        return matriz;
}


void printMatriz(string** matrix, int size)
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




void liberarMatriz(string** matriz, int size)
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

