/*
Titulo:Practico tres de programacion
Auntor:Jose Eduardo Flores Saravia
Descripcion: Practico de creacion de menu de string
Fecha 2024-01-28
*/

#include <iostream>//proporciona funciones para entrada y salida estándar.
#include <sstream>//proporciona la clase istringstream, que se utiliza para tratar una cadena de texto como un flujo de entrada
#include <string>// es la biblioteca estándar de C++ para trabajar con cadenas de texto.
/*
#include <cctype> es la biblioteca estándar de C++ que proporciona funciones para clasificar caracteres. 
En este código, se utiliza para funciones como tolower y toupper para convertir caracteres a minúsculas o mayúsculas.
*/
#include <cctype>
#include <windows.h>//para interactuar con funciones y características específicas del sistema operativo Windows.

using namespace std;

// Variables globales
string nombre, apellidoP, apellidoM, valor_uno, valor_dos;
char opcion;

/* 
char vocal: La vocal que se busca en la cadena para ser reemplazada.
char numero: El número con el cual se va a reemplazar la vocal.
*/
void cambiarVocales(char vocal, char numero)//Parametros de entrada
{
	/*size_t site = 0;: Una variable que se utiliza para almacenar la posición en la cadena valor_dos donde se encontró la última ocurrencia de la vocal.*/
	size_t site = 0; //size_t se utiliza para representar la longitud de una cadena y también como tipo para la variable de control en un bucle.
	do//La función utiliza un bucle 
	{
		/*Utiliza la función find para buscar la próxima ocurrencia de la vocal a partir de la posición actual (site) 
		en la cadena valor_dos. Si no se encuentra, find devuelve string::npos (un valor especial que indica "no encontrado").*/
		site = valor_dos.find(vocal, site);
		if (site != string::npos)//Verifica si se encontró la vocal. Si es el caso, procede a reemplazarla.
			valor_dos[site] = numero;//Cambia la vocal por el número en la posición encontrada.
		
		if (site != string::npos)// Incrementa la posición (site) para que la próxima búsqueda comience después de la posición actual
			site++;
	} while (site != string::npos);// Incrementa la posición (site) para que la próxima búsqueda comience después de la posición actual
}

void ingresoVocal()
{
	cout << "Ingrese su frase: ";// Muestra un mensaje pidiendo al usuario que ingrese una frase.
	cin.ignore(); // Ignorar el salto de línea anterior
	getline(cin, valor_dos);// Lee toda la línea ingresada por el usuario y la almacena en la variable valor_dos
	/*Utiliza un bucle para recorrer cada carácter de la cadena valor_dos y lo convierte a minúscula utilizando la función tolower.*/
	for (char &c : valor_dos)
	{
		/*Dentro del bucle, se aplica la función tolower a cada caracter c. 
		La función tolower convierte un caracter a minúscula si es una letra. 
		La modificación se realiza directamente sobre el caracter en valor_dos porque c es una referencia,
		por lo que cualquier cambio en c afectará al caracter correspondiente en valor_dos.*/
		c = tolower(c); // Convertir a minúsculas
	}
	/*Llama a la función cambiarVocales para reemplazar las vocales específicas por números, ofuscando la frase.*/
	cambiarVocales('a', '4');
	cambiarVocales('e', '3');
	cambiarVocales('i', '1');
	cambiarVocales('o', '0');
	cambiarVocales('s', '5');
	cambiarVocales('t', '7');
	Sleep(1000);
	cout << "Palabra ofuscada: " << valor_dos << endl;//Muestra en la consola la frase después de haber sido ofuscada.
}

void ingresoDatosUsuario() // Ingreso del nombre
{
	cout << "Ingrese su nombre completo: ";//Muestra un mensaje en la consola solicitando al usuario que ingrese su nombre completo.
	cin.ignore(); // : Ignora cualquier carácter en el búfer de entrada, especialmente el salto de línea que pueda haber quedado después de alguna entrada previa.
	/*Lee una línea completa desde la entrada estándar (teclado) y almacena esa línea en la variable nombre. 
	getline permite leer espacios en blanco y caracteres especiales hasta que se presiona la tecla Enter.*/
	getline(cin, nombre); // Lee la línea completa, incluyendo espacios
}


/* La función toma una cadena de texto como entrada. La referencia (&) indica que se pasa por referencia para evitar hacer una copia completa de la cadena.*/
bool contieneLetras(const std::string &str)//Funcion para verificar si el valor ingresado no contiene letras
{
	/*for-each es conocido como bucle for basado en rango, y se utiliza para iterar sobre elementos de un rango o secuencia. 
	iterar = repetir varias veces un proceso con la intención de alcanzar una meta deseada, objetivo o resultado.
	char c: Declara una variable c de tipo char que se utilizará para representar cada caracter en la cadena str
	: str: Indica el rango o secuencia sobre la cual se va a iterar, que es la cadena str.
	*/
	for (char c : str)
	{
		/*
		if (isalpha(c)): Dentro del bucle, se verifica si el caracter actual c es una letra utilizando la función isalpha.
		Esta función retorna true si el caracter es una letra y false si no lo es.
		*/
		if (isalpha(c))//
		{
			/*Si encuentra al menos una letra en la cadena, la función retorna true inmediatamente.*/
			return true;
		}
	}
	/*return false;: Si el bucle completo termina de ejecutarse sin encontrar ninguna letra, la función retorna false*/
	return false;
}

void sumaCadena(const string &cadena) // Funcion de suma de cadenas
{
	/*
	Se crea un objeto de tipo "istringstream" con el nombre de "iss" utilizando la cadena "cadena" como fuente. Esto permite tratar la cadena como si fuera un flujo de entrada.
	*/
	istringstream iss(cadena);
	/*
	Se inicia una variable resultado en cero para acumular la suma de los números.
	*/
	int resultado = 0;
	/*
	int numero;: Se declara una variable numero que se utilizará para almacenar los números extraídos de la cadena.
	*/
	int numero;
	/*
	while (iss >> numero): Se utiliza un bucle while que extrae números del flujo de entrada (iss) y los asigna a la variable numero.
	El bucle continuará mientras haya números para extraer.
	*/
	while (iss >> numero)
	{
		/*
		if (contieneLetras(iss.str())): Se verifica si la cadena que queda en iss después de la extracción de números contiene letras. 
		Esto se hace llamando a la función contieneLetras. Si la cadena contiene letras, se muestra un mensaje de error y la función se detiene.
		*/
		if (contieneLetras(iss.str()))
		{
			cerr << "Error: No es posible sumar con letras." << endl;
			return;
		}
		//Se acumula el valor de numero en la variable resultado
		resultado += numero;
		// Se utiliza ignore para ignorar el siguiente carácter después del número, que se asume que es el carácter '+' que separa los números en la cadena.
		iss.ignore(1, '+');
	}
	Sleep(1000);
	cout << "Resultado de la suma: " << resultado << endl;//se imprime el resultado de la suma.
}

void separarNombre(string nombreCompleto) // Funcion de SepararNombre
{
	/*
	Se crea un objeto de tipo "istringstream" llamado "nom" utilizando la cadena nombreCompleto como fuente. 
	Esto permite tratar la cadena como si fuera un flujo de entrada.
	*/
	istringstream nom(nombreCompleto);
	/*
	Se utiliza el operador >> para leer las partes de la cadena separadas por espacios y asignarlas a las variables "nombre", "apellidoP" y "apellidoM"
	*/
	nom >> nombre >> apellidoP >> apellidoM; // Lee las partes de la cadena separadas por espacios
	/*
	Se utiliza la función toupper para convertir a mayúscula la primera letra del nombre.
	*/
	// Convertir la primera letra de cada parte a mayúscula
	nombre[0] = toupper(nombre[0]);
	apellidoP[0] = toupper(apellidoP[0]);
	apellidoM[0] = toupper(apellidoM[0]);
}

void mostrarNombre() // Mostrar nombre
{
	// Imprime en el orden deseado
	Sleep(1000);
	cout << "Nombre: " + nombre << endl;
	cout << "Apellido paterno: " + apellidoP << endl;
	cout << "Apellido materno: " + apellidoM << endl;
	cout << "Nombre completo: " + apellidoP + " " + apellidoM + " " + nombre << endl;
}

void menu() // Menu principal del usuario
{
	cout << "------MENU------" << endl;
	cout << "(1)-SUMA DE CADENAS" << endl;
	cout << "(2)-NOMBRE DE USUARIO" << endl;
	cout << "(3)-OFUSCAR UNA FRACE" << endl;
	cout << "(s/S)-SALIR" << endl;
	cin >> opcion;
}

int main()
{
	do
	{
		menu();
		opcion = tolower(opcion);
		switch (opcion)
		{
		case '1':
			system("cls");
			cout << "Ingrese una cadena para sumar: ";
			cin.ignore(); // Ignorar el salto de línea anterior
			getline(cin, valor_uno); // Leer la cadena completa
			sumaCadena(valor_uno);
			break;
		case '2':
			system("cls");
			ingresoDatosUsuario();
			separarNombre(nombre);
			mostrarNombre();
			break;
		case '3':
			system("cls");
			ingresoVocal();
			break;
		case 's':
			cout << "Finalizando...." << endl;
			break;
		default:
			cerr << "Opción no válida. Inténtelo de nuevo." << endl;
			break;
		}
	} while (opcion != 's');
	
	return 0;
}

