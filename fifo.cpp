// Dario Restrepo Landazury - Primer taller de Estrutura de datos 

#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

struct paciente  // La estrutura de datos 
{
    char nombre[30];
    int codigo;
    paciente *siguiente; // este apuntador servirar como NULL es decir que este siempre estara a apuntara a el vacio
};                       //esto servira que en caso de que haya una nueva variable paciente(que es este caso es una estrutucra)
                        //apuntara a esa variable haciendo que la siguiente apunte a null y siga asi indefinidamente

paciente *primero,*aux,*aux2; // los apuntadores donde se guardaran los espacios de memoria 

void registrar();
void consultar();

int op1,op2;

int main(){
     
     do
     {
        system("cls");
        cout<<"********************************"<<"\n\n";
        cout<<"*******MENU PRINCIPAL************"<<endl;
        cout<<"1.REGISTRAR PACIENTES"<<endl;
        cout<<"2.CONSULTAR PACIENTES"<<endl;
        cout<<"3.SALIR "<<endl;
        cout<<"*********************************"<<endl;
        cout<<"->";cin>>op1;


        switch (op1)
        {
          case 1: registrar();
          break;
          case 2: consultar();
          break;
          case 3: exit(0);
        }

        if(op1>3)
        {
           cout<<" LA OPCION SELECCIONADA NO EXISTE VUELVA A INTENTARLO"<<endl;
           cout<<"DESEA CONTINUAR 1.SI/2.NO -> ";cin>>op2;
        }
     }while(op2==1);
  
    return 0;
}

void registrar()
{
    system("cls");
     
     if (primero==NULL)
     {
        cout<<"***************************************************"<<endl;
        cout<<"********ALGUNAS RECOMENNDACIONES******************* "<<endl;
        cout<<" POR FAVOR RECUERDE QUE SOLO SE ACEPTAN NUMEROS ENTEROS,NADA DE DECIMALES ES DECIR SIN PUNTO O COMA"<<endl;
        cout<<"CUENDO INGRESE SU NOMBRE RECUERDE HACERLO SIN ESPACIOS "<<endl;
        cout<<"*****************************************************"<<endl;
        
        primero = (struct paciente *) malloc(sizeof(struct paciente));
        cout<<"\n";
        cout<<"INGRESE SU NOMBRE -> ";cin>>primero->nombre;
        cout<<"\n";
        cout<<"INGRESE SU NUMERO DE DOCUMENTO -> ";cin>>primero->codigo;

        primero->siguiente=NULL;

        cout<<"\n";

             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }else
     {
         cout<<"***************************************************"<<endl;
        cout<<"********ALGUNAS RECOMENNDACIONES******************* "<<endl;
        cout<<" POR FAVOR RECUERDE QUE SOLO SE ACEPTAN NUMEROS ENTEROS,NADA DE DECIMALES ES DECIR SIN PUNTO O COMA"<<endl;
        cout<<"CUENDO INGRESE SU NOMBRE RECUERDE HACERLO SIN ESPACIOS "<<endl;
        cout<<"*****************************************************"<<endl;

        aux = (struct paciente *) malloc(sizeof(struct paciente));
        cout<<"\n";
        cout<<" INGRESE SU NOMBRE -> ";cin>>aux->nombre;
        cout<<"\n";
        cout<<"INGRESE SU NUMERO DE DOCUMENTO -> ";cin>>aux->codigo;

        aux->siguiente = NULL;
        aux2 = primero;

        while(aux2->siguiente!=NULL)
        
            aux2 = aux2->siguiente;
            aux2->siguiente = aux;
            aux2 = aux = NULL;

            free(aux);
            free(aux2);

            cout<<"\n";


             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }

     
       
     


}

void consultar()
{
   system("cls");
   for(aux = primero;aux!=NULL;aux = aux->siguiente)
   {
    cout<<"*****************************************"<<endl;
    cout<<" SU NOMBRE ES -> "<<aux->nombre<<endl;
    cout<<" SU NUMERO DE DOCUMENTO ES -> "<<aux->codigo<<endl;
    cout<<"******************************************"<<endl;
    cout<<"\n";
   }
 
   

     cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                consultar();
            }else if(op1==3)
            {
                exit(0);
            }

}