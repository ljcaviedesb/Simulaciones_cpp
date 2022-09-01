#include <iostream>
#include <cmath>
//////////////////////////////////////////////////////////////////////////////
// Solucion de un sistema Sol-Planeta usando Elementos Discretos            //
//                                                                          //
// El metodo de elementos discretos analiza de un sistema su comportamiento //
// a través del tiempo calculando las fuerszas entre los elementos del      //
// sistema.                                                                 //
// Se avanza en pedazos de tiempo/espacio pequeños.                         //
//////////////////////////////////////////////////////////////////////////////
const double GM = 1.0; // (Constante gravitacional)*(Masa del sol)

// Declaracion de clases
class Cuerpo;

class Cuerpo{
private:
  double x,y,Vx,Vy,Fx,Fy,m,R;
public:
  void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
  void CalculeFuerza(void);
  void Muevase(double dt);
  double Getx(void){return x;}; //Inline
  double Gety(void){return y;}; //Inline
};
// Funciones del cuerpo
void Cuerpo::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){
  x=x0; y=y0; Vx=Vx0; Vy=Vy0; m=m0; R=R0;
}
void Cuerpo::CalculeFuerza(void){
  double aux=GM*m*pow(x*x+y*y,-1.5);
  Fx=-aux*x;  Fy=-aux*y;
}
void Cuerpo::Muevase(double dt){
   x+=Vx*dt;     y+=Vy*dt;
  Vx+=Fx/m*dt;  Vy+=Fy/m*dt;
}

// main
int main(){
  Cuerpo Planeta;
  double r0=10,m0=1;
  double omega,V0,T;
  double t,dt=0.0001;

  omega=sqrt(GM/(r0*r0*r0)); V0=omega*r0; T=2*M_PI/omega;
  
  //------------(x0,y0,Vx0,Vy0,m0,R0)
  Planeta.Inicie(r0, 0,  0, V0/2,m0,0.5);
  for(t=0;t<1.1*T;t+=dt){
    std::cout<<Planeta.Getx()<<" "<<Planeta.Gety()<<std::endl;
    Planeta.CalculeFuerza();
    Planeta.Muevase(dt);
  }

  return 0;
}
