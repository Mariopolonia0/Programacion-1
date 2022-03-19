#include <stdio.h>/*practica 5 de proyecto programacion I 2019-1   mario pe�a polonia 2016-0037*/
#include "utils.h"
#include <stdlib.h>                           //system("cls");system("pause;");
#define archcli"cliente.dat"  
#define archpro"producto.dat" 
#define cont"contador.dat"
#define contfac"contadorventa.dat"
                                
struct cliente  {int codi;  char nom[30],ape[30], dire[30], num[30];}c;
struct producto {int codi,precio;float itbis;  char dec[30];}p;
                                        
int opc=0 ,v=10;     int impagrep();          int opcagrepr();  void agrepro(); int impcuadro(int,int,int,int,int,int,int,int);
int impagrepro();     int faproc(); int proifo(producto,int);int imtotal(float,float,float); int implistpro2(int );
int menu();           int fac();    int clien();             int cuadmenu();int cuadmenu2();         int con();       
int impagre();        int opcagre();int impagrecli();        void agrecli();int 	cliifo(cliente);int implistpro();
int implistcli();     int implistcli2(int);              void guarcli();void guarcon();       void carcon();
int carliscli();      cliente buscarcli(int);                void guarpro();producto buscarpro(); int edcli();    int elicli();
                                   int proximocli();   int carconfac(float);int reconfac();
								            //p.codi=100;guarcon();   carcon();p.codi=100;guarcon();     
int main()
{    do {  switch(opc) { case 0 :{opc=menu();                   break;}
                         case 1 :{clien();faproc();v=10;opc=0;  break;}
				         case 2 :{opc=opcagre();                break;}
				         case 3 :{opcagrepr();                  break;}
					     default:{v=5;break;}
				       }  
	    }while(v==10);  system("cls");printf("\n\n\n\t\tPRECIONA ENTRE PARA FINALIZAR EL PROGRAMA");getchar();getchar();return 0; 
} 



int edcli()
{  /*     int b=0;
       	gotoxy(19 ,7);printf("DIGITE EL CODIGO QUE QUIERE EDITAR :");
		scanf("%i",&opc); buscarcli(b);
	      if(opc == *c.codi)
          {
		    impagrecli();agrecli(b);guarcli(b);
	      }	else
	            {
	            printf("CLIENTE NO ENCONTRADO REVISE LA LISTA DE CLIENTE");	
				}	*/
}

int elicli()
{
  gotoxy(19 ,7);printf("OPCION EN MANTENIMIENTO INTENTE EN OTRO MOMENTO");getchar();getchar();
}
	 
int faproc()
{           
            int b=0;int m,y=9;
		    if(v==10){do {gotoxy(2,y);scanf("%d",&opc);b=0;
                                   if(opc==0){v=0;b++;reconfac();}
						           else { buscarpro(); if(opc ==p.codi){proifo(p,y);y++;}
						                               else{ gotoxy(2,y); printf("codigo no existe ");
				                                             getchar();getchar();gotoxy(2,y);printf("\t\t\t\t\t\t\t\t");}
				                        }
					    }while(v==10);v=10;
				     }
} 

int reconfac(){	float total,toimp,toitb;
                             FILE *f = fopen(contfac,"w");
                              fprintf(f,"%.2f  ",total=0);
	                          fprintf(f,"%.2f  ",toimp=0);
	                          fprintf(f,"%.2f  ",toitb=0);fclose (f);
	//toimp,toitb,total;
}
				
producto buscarpro(){FILE *f = fopen(archpro, "r+b");
                         fread(&p,sizeof(producto),1,f);
                         while(!feof(f)){if(p.codi == opc){ return p;}
                         fread(&p,sizeof(producto),1,f); } fclose(f);	} 		
						 
cliente buscarcli(int b){FILE *f = fopen(archcli, "r+b");
                     fread(&c,sizeof(cliente),1,f);
                     while(!feof(f)){if(c.codi == opc){return c;}
                     fread(&c,sizeof(cliente),1,f); } fclose(f);	} 		
					 
int imtotal(float a,float b,float c)	{
	int gxo=10 , gx=45 ,gy1=22 , gy2=23 , gy3=24;
	gotoxy(gx,gy1);printf("total importe :%.2f",a);   
	gotoxy(gx,gy2);printf("total itbis   :%.2f",b);  
    gotoxy(gx,gy3);printf("total general :%.2f",c);
    gotoxy(gxo,gy1);printf("CODIGOS DE FACTURACION");   
	gotoxy(gxo,gy2);printf("0 = A SALIR");  
    gotoxy(gxo,gy3);printf("1 = A ELIMINAR PRODUCTO"); }					 					 			
				
     //printf ("total==%.2f    ",total);
int	proifo(producto z,int y){int can;float itb=0,sub=0,imp=0,toimp,toitb,total;
   
    FILE *co = fopen(contfac,"r+b"); 
	fscanf(co,"%f  ",&total);fscanf(co,"%f  ",&toimp);fscanf(co,"%f  ",&toitb);	fclose (co);	
   
    gotoxy(43,y);printf("%i",z.precio);gotoxy(20,y);puts(z.dec);
    gotoxy(10,y);scanf("%i",&can);  itb=(z.precio*can)*z.itbis;  imp=z.precio*can;  sub=imp+itb;             
    gotoxy(52,y);printf("%.2f",itb);gotoxy(60,y);printf("%.2f",imp);gotoxy(70,y);printf("%.2f",sub); 
	toimp=imp+toimp; toitb=toitb+itb;  total=sub+total;	imtotal(toimp,toitb,total); 
	FILE *f = fopen(contfac,"w");
	fprintf(f,"%.2f  ",total);fprintf(f,"%.2f  ",toimp);fprintf(f,"%.2f  ",toitb);
	
	
	fclose (f);	}  
		
				  
void guarcon(){
	FILE *con = fopen(cont,"w");
	fprintf(con,"%d  ",c.codi);fprintf(con,"%d",p.codi);fclose (con); }
	


void carcon(){
	FILE *con = fopen(cont,"r+b");
	fscanf(con, "%d  ",&c.codi);fscanf(con,"%d",&p.codi);  
	}


int opcagrepr(){int y;cuadmenu();impagrep();scanf("%i",&opc);;
switch (opc){case 1:{system("cls");cuadmenu();impagrepro();agrepro();guarpro();opc=3;break;}
             case 2:{system("cls");cuadmenu();elicli();     break;}
             case 3:{system("cls");cuadmenu();elicli();     break;}
             case 4:{y=11;system("cls");cuadmenu();implistpro();implistpro2(y);opc=3;break;} 
             case 5:{opc=0;	break;} }return opc;}
 
 
int implistpro2(int y){
 
    FILE *f = fopen(archpro, "r+b");if(f==0){printf("eso mismo");}
	                                else{fread(&p, sizeof(producto),1,f);
                                   	while(!feof(f)){gotoxy(18,y);printf("%i",p.codi);   gotoxy(27,y);puts(p.dec);
                                                    gotoxy(45,y);printf("%i",p.precio); gotoxy(58,y);printf("%.2f",p.itbis);
													 y++;fread(&p,sizeof(producto),1,f);
													}
			gotoxy(23,y=y+2);system("pause"); } }
                          
int implistpro(){system("cls");cuadmenu();
gotoxy(21,8); printf("ESTA ES LA LISTA DE LOS PRODUCTO DEL SISTEMA");
gotoxy(18,10);printf("Codigo   Descripcion       Precios      Itbis");}  

void agrepro(){int y=10,x=38;  carcon();
   
    fflush(stdin);  gotoxy(x,y);printf("%i",p.codi);         
y++;fflush(stdin);	gotoxy(x,y);gets(p.dec);
y++;fflush(stdin);  gotoxy(x,y);scanf("%i",&p.precio);             
y++;fflush(stdin);  gotoxy(x,y);scanf("%f",&p.itbis);   	}

void guarpro(){
	             FILE *ar = fopen(archpro,"a+b");
                 if(ar==0){ printf("ERROR DE ARCHIVO DE CLIENTE"); }
                 else {	fwrite(&p,sizeof(producto),1,ar);	 }
                  fclose(ar);p.codi++;guarcon();
				  }
                                          
int impagrepro(){int y=8;
	gotoxy(30,y);printf("INGRESE EL NUEVO PRODUCTO");y=y+2;
    gotoxy(25,y);printf("Codigo      :");y++;
    gotoxy(25,y);printf("Descripcion :");y++;
    gotoxy(25,y);printf("Precio      :");y++;
    gotoxy(25,y);printf("Itbis       :");y++;}
  
int impagrep(){system("cls");cuadmenu();int y=7;
    gotoxy(23 ,y);printf("EN ESTA VENTANA SE EDITAN LOS PRODUCTOS\n\n");y=y+2;
    gotoxy(34,10);printf("1.AGREGAR PRODUCTOS");gotoxy(34,11);printf("2.ELIMINAR PRODUCTOS");
    gotoxy(34,12);printf("3.EDITAR PRODUCTOS ");gotoxy(34,13);printf("4.VER LISTA DE PRODUCTOS ");gotoxy(34,14);printf("5.SALIR");
    gotoxy(31,16);printf("ELIJA LA OPCION DESEADA:");}	  
  
int cliifo(cliente e){gotoxy(21,4);puts(e.nom);
                      gotoxy(21,5);puts(e.dire);
                      gotoxy(63,3);puts(e.num);con();	} 
     
int con(){ char fec[30];
    gotoxy(63,4);scanf("%s",&fec);   
	gotoxy(63,5);scanf("%s",&fec);
	gotoxy(65,5);printf("/");scanf("%s",&fec);
	gotoxy(68,5);printf("/");scanf("%s",&fec);	}
                                                            //cuadmenu();
int menu(){system("cls");cuadmenu();cuadmenu2();
    int opc,y=8;gotoxy(22,y);printf("BIENVENIDO A SU PROGRAMA DE FACTURACION");y++;y++;
  	gotoxy(31,y);printf("  MENU DEL PROGRAMA  \n");y++;gotoxy(33,y);printf("1.FACTURAR\n");y++;
    gotoxy(33,y);printf("2.EDITAR CLIENTE\n");y++;     gotoxy(33,y);printf("3.EDITAR PRODUCTO\n");y++;
  	gotoxy(33,y);printf("4.SALIR");y=y+2;              gotoxy(30,y);printf("ELIJA LA OPCI%cN DESEADA:",224);scanf("%i",&opc); return opc; }
 impcuadro(int x1,int y1,int x2,int y2,int lx1,int ly1,int lx2,int ly2)
{
 	            for ( y1=3;y1<ly1;y1++){gotoxy(8,y1);printf("%c",176); }  
  	            for ( x1=8;x1<lx1;x1++){gotoxy(x1,2);printf("%c",176);}    
  	            for ( y2=3;y2<ly2;y2++){gotoxy(77,y2);printf("%c",176); }  
  	            for ( x2=8;x2<lx2;x2++){gotoxy(x2,6);printf("%c",176);}    
}

int cuadmenu(){	for (int y=5;y<20;y++){gotoxy(10,y);printf("%c%c",177,219);}
             	for (int x=10;x<72;x++){gotoxy(x,5);printf("%c",177);}
  	            for (int y=6;y<20;y++){gotoxy(70,y);printf("%c%c",219,177);}
  	            for (int x=10;x<72;x++){gotoxy(x,20);printf("%c",177,219);} }
  	
int cuadmenu2(){for (int y=10;y<17;y++){gotoxy(22,y);printf("%c",14); }  
  	            for (int x=22;x<61;x++){gotoxy(x,10);printf("%c",176);}
  	            for (int y=11;y<17;y++){gotoxy(60,y);printf("%c",14); }  
  	            for (int x=22;x<61;x++){gotoxy(x,17);printf("%c",176);}}	
			
int impagre(){system("cls");cuadmenu();int y=7;
gotoxy(23 ,y);printf("EN ESTA VENTANA SE EDITAN LOS CLIENTE\n\n");y=y+2;
gotoxy(34,10);printf("1.AGREGAR CLIENTE");gotoxy(34,11);printf("2.ELIMINAR CLIENTE");
gotoxy(34,12);printf("3.EDITAR CLIENTE ");gotoxy(34,13);printf("4.VER LISTA DE CLIENTE ");gotoxy(34,14);printf("5.SALIR");
gotoxy(31,16);printf("ELIJA LA OPCION DESEADA:");}		
		
int opcagre(){int y;                impagre();scanf("%i",&opc);
         switch (opc){  case 1:{system("cls");cuadmenu();impagrecli();agrecli();guarcli();opc=2;break;}
                        case 2:{system("cls");cuadmenu();elicli();     break;}
                        case 3:{system("cls");cuadmenu();elicli();     break;}
                    	case 4:{y=11;system("cls");cuadmenu();implistcli();implistcli2(y);opc=2;break;}   
				        case 5:{opc=0;	break;} }return opc;}

//c.codi++;printf("%d",c.codi);system("pause");
int implistcli2(int y){
 
    FILE *f = fopen(archcli, "r+b");if(f==0){printf("eso mismo");}
	                                else{fread(&c, sizeof(cliente),1,f);
                                   	while(!feof(f)){
			gotoxy(18,y);printf("%i",c.codi); gotoxy(29,y);puts(c.nom);
            gotoxy(40,y);puts(c.dire);        gotoxy(57,y);puts(c.num);
            y++;fread(&c, sizeof(cliente),1,f);}
			gotoxy(23,y=y+2);system("pause"); } }
                          
int implistcli(){system("cls");cuadmenu();
gotoxy(21,8); printf("ESTA ES LA LISTA DE CLIENTE DEL SISTEMA");
gotoxy(18,10);printf("Codigo     Nombre     Direcion         Numero Tel");}                
	                                              
void agrecli(){int y=10,x=36; 
    carcon();
    fflush(stdin);  gotoxy(x,y);printf("%i",c.codi);         
y++;fflush(stdin);	gotoxy(x,y);gets(c.nom);
y++;fflush(stdin);  gotoxy(x,y);gets(c.ape);              
y++;fflush(stdin);  gotoxy(x,y);gets(c.dire);   
y++;fflush(stdin);  gotoxy(x,y);gets(c.num); 
	}	

void guarcli(){
	            FILE *arcl = fopen(archcli,"a+b");
                 if(arcl==0){ printf("ERROR DE ARCHIVO DE CLIENTE"); }
                 else {	fwrite(&c,sizeof(cliente),1,arcl);	 }
                  fclose(arcl);c.codi++; guarcon();
				  }
				  

			                                    
int impagrecli(){int y=8;
	gotoxy(30,y);printf("INGRESE EL NUEVO CLIENTE");y=y+2;
    gotoxy(25,y);printf("Codigo    :");y++;gotoxy(25,y);printf("Nombre    :");y++;   
	gotoxy(25,y);printf("Apellido  :");y++;gotoxy(25,y);printf("Direcion  :");y++;
    gotoxy(25,y);printf("Numero    :");y++;}
	                                                  //lx1=78;ly1=6;lx2=78;ly2=6;
int fac(){ system("cls");impcuadro(8,3,8,3,78,6,78,6);
    gotoxy(10,3);printf("codigo    :" );gotoxy(10,4);printf("cliente   :");gotoxy(10,5);printf("direcion  :");
    gotoxy(52,3);printf("numero    :");gotoxy(52,4);printf("condicion :"); gotoxy(52,5);printf("fecha     :");
    float toimp=0,toitb=0,total=0; int gxo=10 ,gx=45 ,gy1=22 , gy2=23 , gy3=24;
    gotoxy(1,7);printf(" codigo  cantidad  descripcion            precio   itbis   importe   Subtotal");
    gotoxy(gx,gy1);printf("total importe :%.2f",toimp);gotoxy(gx,gy2);printf("total itbis   :%.2f",toitb);
    gotoxy(gx,gy3);printf("total general :%.2f",total); gotoxy(gxo,gy1);printf("CODIGOS DE FACTURACION");   
	gotoxy(gxo,gy2);printf("0 = A SALIR");  
    gotoxy(gxo,gy3);printf("1 = A ELIMINAR PRODUCTO");  } 



int clien(){ int b=0;system("cls");fac(); gotoxy(21,3);scanf("%d",&opc);buscarcli(b);
            if (opc == c.codi){cliifo(c);v=10;}else{system("cls");
            gotoxy(20,10);printf("cliente no existe por favor vea la lista de cliente\n\n\t\t\t");
		    system("pause;");v=0; } reconfac();     }
 
	
					 
					 			
