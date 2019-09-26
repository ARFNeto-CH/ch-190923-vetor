#include <iostream>
using namespace std;

struct Numeros
{
	int		maior;
	int		menor;
	int*	valores;

	Numeros(int quantos)
	{
		valores = new int[quantos];
	}
};


int main()
{
	int quantos;
	int v;

	cout << "Quantos?     : ";
	cin >> quantos;

	if (quantos < 1) return 0;
	Numeros num = Numeros(quantos);

	cout << "Primeiro Valor: ";
	cin >> v;
	num.menor = v;
	num.maior = v;
	num.valores[0] = v;

	for (int n = 0; n < quantos-1; n++)
	{
		cout << "Valor " << n + 2 << " de " << quantos << ": ";
		cin >> v;
		if (v > num.maior) num.maior = v;
		if (v < num.maior) num.menor = v;
		int ix;
		for (ix=n+1; ix>0; ix--)
		{	// comeca do final	
			if ( v > num.valores[ix-1] ) break;
			num.valores[ix] = num.valores[ix-1];	// abre espaco
		}	// end for
		num.valores[ix] = v;		// ix marca o lugar certo
	}	// end for

	// agora mostra os valores...
	cout << quantos << " valores" << endl;
	cout << "menor valor: " << num.menor << endl;
	cout << "maior valor: " << num.maior << endl;
	cout << "valores: " << endl;
	for (int n = 0; n < quantos; n++) cout << num.valores[n] << endl;
	return 0;
}

