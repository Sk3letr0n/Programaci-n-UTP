#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char** argv) 
{
	system("color F0");
	int opcion,n,i,V[n]={0},suma=0,ctapos=0,ctaneg=0,ctamayor=0,Vpar[i]={0},j,a=0,b=1,c,Vcua[10],semisuma,num,cta=0,p,pr;
	int V1[n]={0},V2[n]={0},Suma[n]={0},Vec[p],m,posicion,posicionr,ctadiv,mp,A,B;
	int menor=999999999,mayor=-999999999,mayorpar=-999999999,mayor7=-999999;
	//float prom;
	long long int Ventas[12]={0},sumaventas=0,Mejormes,pos=0;
	string Mes[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	double prom;
	setlocale(LC_ALL,"spanish");
	do
{
	system("cls");
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"°°°       Menu Ejercicios Taller N°6      °°°"<<endl;
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"°°°             1-Ejercicio 1             °°°"<<endl;
	cout<<"°°°             2-Ejercicio 2             °°°"<<endl;
	cout<<"°°°             3-Ejercicio 3             °°°"<<endl;
	cout<<"°°°             4-Ejercicio 4             °°°"<<endl;
	cout<<"°°°             5-Ejercicio 5             °°°"<<endl;
	cout<<"°°°             6-Ejercicio 6             °°°"<<endl;
	cout<<"°°°             7-Ejercicio 7             °°°"<<endl;
	cout<<"°°°             8-Ejercicio 8             °°°"<<endl;
	cout<<"°°°             9-Ejercicio 9             °°°"<<endl;
	cout<<"°°°             10-Ejercicio 10           °°°"<<endl;
	cout<<"°°°             11-Ejercicio 11           °°°"<<endl;
	cout<<"°°°             12-Ejercicio 12           °°°"<<endl;
	cout<<"°°°             13-Ejercicio 13           °°°"<<endl;
	cout<<"°°°             14-Ejercicio 14           °°°"<<endl;
	cout<<"°°°             15-Ejercicio 15           °°°"<<endl;
	cout<<"°°°             16-Ejercicio 16           °°°"<<endl;
	cout<<"°°°             17-Ejercicio 17           °°°"<<endl;
	cout<<"°°°             18-Ejercicio 18           °°°"<<endl;
	cout<<"°°°             19-Ejercicio 19           °°°"<<endl;
	cout<<"°°°             20-Ejercicio 20           °°°"<<endl;
	cout<<"°°°             21-Terminar               °°°"<<endl;
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<" Ingrese la opcion deseada ";
	cin>>opcion;
	switch(opcion)
	{
		case 1:cout<<" Ejercicio 1 "<<endl;
//Realizar un programa que me permita inicializar, leer, y escribir un vector, además que muestre la suma y el promedio de sus elementos.
	           cout<<"Ingrese de que tamaño desea el vector "<<endl;
			   cin>>n;
			   for(i=0;i<n;i++)
			   {
			   		cout<<"Ingrese el Vector ["<<i+1<<"]: ";
			   		cin>>V[i];
			   		suma=suma+V[i];
			   }
			   cout<<" Escritura del Vector "<<endl;
			   for(i=0;i<n;i++)
			   {
			   		cout<<"["<<V[i]<<"] ";
			   }		
			   prom=suma/n;
			   cout<<"La suma del Vector es: "<< suma << " y su promedio es: "<< prom <<endl;
			   system("pause");
			   break;
		case 2:cout<<" Ejercicio 2 "<<endl;
//2. Leer n números enteros, almacenarlos en un vector y determinar cuántos de estos números son negativos y cuantos positivos.	
               cout<<" Ingrese total de numeros a leer ";
			   cin>>n;
				if(n>=1 && n<=100)
				{
		 			cout<<" \t Captura Vector "<<endl;
		 			cout<<endl;
					for(i=0;i<n;i++)
					{	
						cout<<" Ingrese el Vector ["<<i+1<<"] numero ";
						cin>>V[i];
						if(V[i]>=0)
						{
							ctapos++;
						}
						else
						{
							ctaneg++;
						} 
					}
					cout<<endl;
					cout<<" \t Escritura Vector "<<endl;
					cout<<endl;
					for(i=0;i<n;i++)
					{
						cout<<" ["<<V[i]<<"]  ";
					}
					cout<<endl;
					cout<<" Total de elementos positivos es: "<< ctapos <<endl;
					cout<<" Total de elementos negativos es: "<< ctaneg <<endl;
				}
				else
				{
					cout<<" Sin espacio reservado en memoria "<<endl;
				}
				system("pause");
				break;
		case 3:cout<<" Ejercicio 3 "<<endl;
//Leer n números enteros, almacenarlos en un vector y determinar cuál es el número menor.	
               cout<<" Ingrese total de elementos a procesar ";
			   cin>>n;
			   cout<<endl;
			   cout<<" Captura Vector "<<endl;
			   cout<<endl;
			   for(i=0;i<n;i++)
		       {
					cout<<" Ingrese el Vector ["<<i+1<<"]: ";
					cin>>V[i];
					if(V[i]<menor)
					{
						menor=V[i];
					}
				}
				cout<<endl<<endl;
				cout<<"Escritura Vector "<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" ["<<V[i]<<"] ";
				}
				cout<<"El numero menor es: "<< menor <<endl;
				system("pause");
				break;
		case 4:cout<<" Ejercicio 4 "<<endl;
//Leer n números enteros, almacenarlos en un vector y determinar cuál es el número mayor.	
               cout<<" Ingrese total de elementos a procesar ";
			   cin>>n;
			   cout<<endl;
			   cout<<" Captura Vector "<<endl;
			   cout<<endl;
			   for(i=0;i<n;i++)
		       {
					cout<<" Ingrese el Vector ["<<i+1<<"]: ";
					cin>>V[i];
					if(V[i]>mayor)
					{
						mayor=V[i];
					}
				}
				cout<<endl<<endl;
				cout<<"Escritura Vector "<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" ["<<V[i]<<"] ";
				}
				cout<<"El numero mayor es: "<< mayor <<endl;
				system("pause");
				break;
		case 5:cout<<" Ejercicio 5 "<<endl;
//Leer n números enteros almacenarlos en un vector y determinar cuántas veces esta repetido el número mayor.
               mayor=-999999999;
			   ctamayor=0;						
			   cout<<" Ingrese total de elementos a procesar ";
			   cin>>n;
			   cout<<endl;
			   cout<<" Captura Vector "<<endl;
			   cout<<endl;
			   for(i=0;i<n;i++)
		       {
					cout<<" Ingrese el Vector ["<<i+1<<"]: ";
					cin>>V[i];
					if(V[i]>mayor)
					{
						mayor=V[i];
						ctamayor++;
					}
			   }
			   cout<<endl<<endl;
			   cout<<" Escritura Vector "<<endl;
			   for(i=0;i<n;i++)
			   {
			   		cout<<"["<<V[i]<<"]";
			   }
			   cout<<" El numero mayor es: "<< mayor << " y esta repetido: "<< ctamayor << " veces "<<endl;
			   system("pause");
			   break;
		case 6:cout<<" Ejercicio 6 "<<endl;//desde aca se me empezo a dañar, no lo podia verificar bien desde el pc de mi casa
//Leer n números enteros almacenarlos en un vector y determinar en qué posición se encuentran el mayor par leído.
               cout<<" Ingrese el numero de elementos a procesar ";
			   cin>>n;
			   for(i=0;i<n;i++)
			   {
			    	cout<<" Ingrese el Vector ["<<i+1<<"]: ";
					cin>>V[i];
					if(V[i]%2==0)
					{
						Vpar[j]=V[i];
						j++;
					}
				}
				cout<<endl;
				cout<<" Escritura Vector "<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" ["<<V[i]<<"] ";
				}
				cout<<endl;
				cout<<" Escritura Vectores Pares "<<endl;
				cout<<endl;
				for(i=0;i<j;i++)
				{
					cout<<" ["<<Vpar[i]<<"] ";
					if(Vpar[i]>mayorpar)
					{
						mayorpar=Vpar[i];
					}
				}
				cout<<endl;
				cout<<" El mayor par es: "<< mayorpar <<endl;
	   			system("pause");
	   			break;
	   	case 7:cout<<" Ejercicio 7 "<<endl;
//Descargar en un vector de 10 posiciones los 10 primeros elementos de la serie Fibonacci.	   	
	   		   cout<<" 10 PRIMEROS TERMINOS DE FIBONACCI "<<endl;
			   V[0]=a;
			   V[1]=b;
			   for(i=2;i<10;i++)
			   {
					c=a+b;
					V[i]=c;
					a=b;
					b=c;
				}
				cout<<" Impresion de Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<"["<<V[i]<<"]"<<endl;
				}
		        system("pause");
			    break;
		case 8:cout<<" Ejercicio 8 "<<endl;
//8. Leer 10 números enteros, almacenarlos en un vector y determinar a cuanto es igual el cuadrado de cada uno de los números leídos.		
			   cout<<endl<<endl;
			   cout<<" Captura Vector "<<endl;
			   for(i=0;i<10;i++)
			   {
					cout<<" Ingrese el ["<<i+1<<"] Elemento ";
					cin>>V[i];
					Vcua[i]=pow(V[i],2);
			   }
			   cout<<endl<<endl;
			   cout<<" Escritura Vector Cuadrado "<<endl;
			   for(i=0;i<10;i++)
			   {
					cout<<" ["<<Vcua[i]<<"]";
			   }
			   cout<<endl;
		       system("pause");
			   break;
		case 9:cout<<" Ejercicio 9 "<<endl;
//Leer 10 números enteros almacenarlos en un vector y determinar en qué posiciones se encuentran los números terminados en 4 imprimirlos y su pos.		
		       cout<<" Captura Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" Ingrese el ["<<i+1<<"] Elemento ";
					cin>>V[i];
				}
				cout<<endl<<endl;
				cout<<" Escritura Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" ["<<V[i]<<"] ";
				}
				cout<<endl<<endl;
				cout<<" Escritura vector terminado en 4 "<<endl;
				for(i=0;i<10;i++)
				{
					if(V[i]%10==4)
					{
						cout<<" ["<<V[i]<<"] pos ["<<i+1<<"] "<<endl;
					}
				}
		       system("pause");
			   break;	   	   		
		case 10:cout<<" Ejercicio 10 "<<endl;
//Leer 10 números enteros, almacenarlos en un vector y determinar cuantos números de los almacenados en dicho vector terminan en 15, mostrar la suma.		
		        cout<<" Captura Vector"<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" Ingrese el ["<<i+1<<"] Elemento ";
					cin>>V[i];
				}
				cout<<endl<<endl;
				cout<<" Escritura Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" ["<<V[i]<<"] ";
					if(V[i]%100==15)
					{
						suma=suma+V[i];
					}
				}
				cout<<endl;
				cout<<" \t ESCRITURA ELEMENTOS MAS DE 3 DIGITOS "<<endl;
				for(i=0;i<10;i++)
				{
					if(V[i]>999)
					{
						cout<<" ["<<V[i]<<"] pos ["<<i+1<<"] "<<endl;
					}
				}
				cout<<endl;
				cout<<" La suma terminados en 15 son: "<< suma <<endl;
		       system("pause");
			   break;
		case 11:cout<<" Ejercicio 11 "<<endl;
//Leer n números enteros almacenarlos en un vector y determinar en qué posiciones se encuentran los números con más de 3 dígitos.		
		        cout<<" Captura Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" Ingrese el ["<<i+1<<"] Elemento ";
					cin>>V[i];
				}
				cout<<endl<<endl;
				cout<<" Escritura Vector "<<endl;
				for(i=0;i<10;i++)
				{
					cout<<" ["<<V[i]<<"] ";
				}
				cout<<endl;
				cout<<" \t ESCRITURA ELEMENTOS MAS DE 3 DIGITOS "<<endl;
				for(i=0;i<10;i++)
				{
					if(V[i]>999)
					{
						cout<<" ["<<V[i]<<"] pos ["<<i+1<<"] "<<endl;
					}
				}
		       system("pause");
			   break;
		case 12:cout<<" Ejercicio 12 "<<endl;
//12-Leer 10 números enteros, almacenarlos en un vector y determinar cuál es el número menor, también identificar el conjunto de los números terminados en 7
//hallar el mayor y su posición.		
		        for (i=0;i<10;i++)
				{
					cout<<"Ingrese un valor: "<<endl;
					cin>>V[i];
				}
				cout<<endl;
				for(i=0;i<10;i++)
				{
					if(V[i]<menor)
					{
						menor=V[i];
					}
					if(V[i]%10==7)
					{
						cout<<"El valor: "<<V[i]<<" termina en 7"<<endl;
						if(	V[i]>mayor7)
						{
							mayor7=V[i];
							posicion=i+1;
							posicionr=i;
						}
					}
				}
				cout<<"El mayor terminado en 7 es: "<<mayor7<<endl;
				cout<<"Su posicion es la: "<<posicion<<endl;
				cout<<"Su posicion real es la: "<<posicionr<<endl;
				cout<<"El menor valor es el numero: "<<menor<<endl;
		       system("pause");
			   break;
		case 13:cout<<" Ejercicio 13 "<<endl;
//13-Leer 10 enteros, almacenarlos en un vector y determinar en qué posición del vector está el mayor número primo leído.		
		        for(i=0;i<10;i++)
				{
					cout<<"Ingrese un valor: "<<endl;
					cin>>V[i];
				}
				mp=-999999;
				for(i=0;i<10;i++)
				{
					ctadiv=0;
					for(n=1;n<=V[i];n++)
					{
						if(V[i]%n==0)
						{
							ctadiv++;
						}
					}
					if(ctadiv==2 && V[i]>mp)
					{
						mp=V[i];
						pos=i+1;
						posicionr=i;
					}
				}
				cout<<endl<<"La posicion del mayor primo es: "<<pos<<endl;
				cout<<"La posicion real del mayor primo es: "<<posicionr<<endl;
		       system("pause");
			   break;
		case 14:cout<<" Ejercicio 14 "<<endl;
//Dado un vector de n elementos y 2 valores enteros A y B realizar un programa que permita almacenar en un segundo vector los vr. Comprendidos
//entre A y B pertenecientes al vector.		
		        cout<<"Ingrese el numero de elementos a procesar: "<<endl;
				cin>>n;
				cout<<endl;
				for(i=0;i<n;i++)
				{
					V1[i]=0;
				}
				for(i=0;i<n;i++)
				{
					V2[i]=0;
				}
				for(i=0;i<n;i++)
				{
					cout<<"Ingrese el valor para Vector 1: "<<endl;
					cin>>V1[i];
				}
				cout<<endl;
				cout<<"Ingrese el limite A: "<<endl;
				cin>>A;
				cout<<"Ingrese el limite B: "<<endl;
				cin>>B;
				if (A>B)
				{
					i=A;
					A=B;
					B=i;
				}
				c=1;
				for(i=0;i<n;i++)
				{
					if(	V1[i]>=A && V1[i]<=B)
					{
						V2[c]=V1[i];
						c++;
					}
				}
				cout<<endl<<"Vector 2: "<<endl;
				for(i=0;i<c;i++)
				{
					cout<<V2[i]<<endl;
				}
		       system("pause");
			   break;
		case 15:cout<<" Ejercicio 15 "<<endl;
//Una empresa desea procesar las ventas realizadas mes a mes con el fin de obtener la siguiente información anual:
//• Mes en el que se obtuvo la mejor venta
//• El monto de la venta máxima obtenida
//• Total de las ventas
//• Promedio de ventas.		
		        cout<<endl<<endl;
				cout<<"\t LIQUIDA VENTAS ANUALES DE LA EMPRESA LA BUENA VIBRA :)"<<endl;
				cout<<endl;
				cout<<" \t\t DIGITAR LAS VENTAS DEL AÑO "<<endl;
				cout<<" \t\t CAPTURA VENTAS "<<endl;
				for(i=0;i<12;i++)
				{
					cout<<" Ingrese las ventas de ["<<Mes[i]<<"] : ";
					cin>>Ventas[i];
				}
				Mejormes=Ventas[0];
				cout<<endl<<endl;
				cout<<" \t\t SALIDAS DEL PROGRAMA "<<endl;
				for(i=0;i<12;i++)
				{
					sumaventas=sumaventas+Ventas[i];
					if(Ventas[i]>Mejormes)
					{
						Mejormes=Ventas[i];
						pos=i;
					}
				}
				prom=sumaventas/12.0;
				cout<<" Total de ventas del año:$ "<<sumaventas<<" M/cte "<<endl;
				cout<<" Promedio ventas del año:$ "<<prom<<" M/cte "<<endl;
				cout<<" Mejor venta deñ año:$ "<<Mejormes<<" M/cte en el mes "<<Mes[pos]<<endl;
				cout<<endl<<endl;
				cout<<" \t\t VENTAS DEL AñO "<<endl;
				for(i=0;i<12;i++)
				{
					cout<<" ["<<Mes[i]<<"] : "<<"["<<Ventas[i]<<"]$ "<<endl;
				}
		       system("pause");
			   break;
		case 16:cout<<" Ejercicio 16 "<<endl;
//Dado un vector de n elementos realizar un programa que permita determinar la suma de los elementos en posición par.		
			    cout<<"Ingrese el numero de elementos a procesar: "<<endl;
				cin>>n;
				suma=0;
				cout<<endl;
				for(i=0;i<n;i++)
				{
				cout<<"Ingrese el Vector ["<<i+1<<"]: "<<endl;
				cin>>V[i];
				}
				for(i=0;i<n;i++)
				{
					if(i%2==0)
					{
						suma=suma+V[i];
					}
				}
				cout<<endl<<"La suma de las posiciones pares es: "<< suma <<endl;
		       system("pause");
			   break;
		case 17:cout<<" Ejercicio 17 "<<endl;
//Leer 10 números enteros, almacenarlos en un vector y determinar si la semisuma entera entre el valor mayor y el valor menor es un número par.		
		        for(i=0;i<10;i++)
				{
					cout<<"Ingrese el Vector ["<<i+1<<"] "<<endl;
					cin>>V[i];
				}
				for(i=0;i<10;i++)
				{
					if(V[i]<menor)
					{
						menor=V[i];
					}
					if(V[i]>mayor)
					{
						mayor=V[i];
					}
				}
				semisuma=(menor+mayor)/2;
				if(semisuma%2==0)
				{
					cout<<endl<<"La semisuma es par."<<endl;
				}
				else
				{
					cout<<endl<<"La semisuma no es par."<<endl;
				}
		       system("pause");
			   break;
		case 18:cout<<" Ejercicio 18 "<<endl;
//Capturar dos vectores de n elementos, generar otro vector con la suma de los anteriores mostrar en pantalla el vector resultado.		
		        cout<<"Ingrese el numero de elementos de cada vector: "<<endl;
				cin>>n;
				cout<<endl;
				for(i=0;i<n;i++)
				{
					cout<<"Ingrese un valor para el Vector 1: "<<endl;
					cin>>V1[i];
				}
				cout<<endl;
				for(i=0;i<n;i++)
				{
					cout<<"Ingrese un valor para el vector 2: "<<endl;
					cin>>V2[i];
				}
				for(i=0;i<n;i++)
				{
					Suma[i]=V1[i]+V2[i];
				}
				cout<<endl<<"Impresion vector suma: "<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" ["<<Suma[i]<<"] ";
				}
		       system("pause");
			   break;
		case 19:cout<<" Ejercicio 19 "<<endl;
//Capturar un vector de n elementos, luego ingresar un número entero por teclado, validar si hace parte del vector, imprimir el número de veces que se
//encuentre y su posición.		
		        cout<<"Ingrese el tamaño del Vector: "<<endl;
				cin>>n;
				cout<<endl;
				for(i=0;i<n;i++)
				{
					cout<<"Ingrese el Vector ["<<i+1<<"]: "<<endl;
					cin>>V[i];
				}
				cout<<endl;
				cout<<"Ingrese el numero a procesar dentro del vector: "<<endl;
				cin>>num;
				for(i=0;i<n;i++)
				{
					if(V[i]==num)
					{
						cout<<"Encontrado en la posicion: "<<i+1<<". Posicion real: "<<i<<endl;
						cta++;
					}
				}
				if(cta>0)
				{
					cout<<endl<<"Encontrado "<< cta <<" veces."<<endl;
				}
				else
				{
					cout<<endl<<"No encontrado en el vector."<<endl;
				}
		       system("pause");
			   break;
		case 20:cout<<" Ejercicio 20 "<<endl;
//Realizar un programa que capture en un vector los números primos comprendidos entre 100 y 300.		
		        n=0;
				p=0;
				do
				{
				n++;
				c=0;
				for(i=1;i<=n;i++)
				{
					if(n%i==0)
					{
						c++;
					}
				}
				if(c==2)
				{
					p++;
				}
				}while(n<300);

				n=0;
				m=0;
				do
				{
				n++;
				c=0;
				for(i=1;i<=n;i++)
				{
					if(n%i==0)
					{
						c++;
						pr=i;
					}
				}
				if(c==2)
				{
					V[m]=pr;
					m++;
				}
				}while(n<300);
				cout<<endl<<" Escritura vector: "<<endl;
				for(i=0;i<p;i++)
				{
					cout<<"["<<V[i]<<"] ";
				}
		       system("pause");
			   break;	   
			   	   	   	   	   	   	   	   	   	   	   
	}
}while(opcion!=21);
cout<<"Gracias por usar este humilde programa :D "<<endl;
	
	return 0;
}
