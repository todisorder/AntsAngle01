# include <fstream>
# include "stdlib.h"
# include <iostream>
# include <cmath>
# include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

static double const Pi =  3.1415926535;

double PheromoneProfile(double x)
{
    
    double aux = 1.*exp(-abs(20. * x));
    
    return 1.*aux;
}

/////////////////////////////////////////
/////////////////////////////////////////
//.___  ___.      ___       __  .__   __.
//|   \/   |     /   \     |  | |  \ |  |
//|  \  /  |    /  ^  \    |  | |   \|  |
//|  |\/|  |   /  /_\  \   |  | |  . `  |
//|  |  |  |  /  _____  \  |  | |  |\   |
//|__|  |__| /__/     \__\ |__| |__| \__|
/////////////////////////////////////////
/////////////////////////////////////////

int main (void){
    
    double ell = 0.5;     //  Sensing radius
    double beta = Pi/4.;    //  Sensing half-angle
    
    double dt;
    
    int discr = 10.;       //  Number of r points for circular sector
    int disctheta = 10.;   //  Number of theta points for circular sector
    double Ftheta = 0.;
    
    double Tfinal;
    
    double X1;
    double X2;
    double Theta;
    double Tcurrent = 0.;
    
    string COMM;
    string DIR;       // Not needed since this question is in the Executar shell script.
    cout << "// Comments:" << endl;
    getline(cin, COMM, '\n');               // Nice... de http://www.cprogramming.com/tutorial/string.html
    cout << "// Delta t:" << endl;
    cin >> dt;
    cout << "//  Final time:" << endl;
    cin >> Tfinal;
    
    string DIR2 = "./"+DIR+"/";     // Not needed since this question is in the Executar shell script.
    
    
    //    PrintInfo(xx,yy,tt,COMM);
    
    
    int tt;
    tt = Tfinal / dt;

    cout << "Number of steps = " << tt << endl;
    
    //  Initialization
    X1 = 0.2;
    X2 = 1.;
    Theta = Pi/2.;
    
    double drSector = ell / discr;
    double dthetaSector = 2.*beta / disctheta;
    
    double X1aux = X1;
    double X2aux = X2;
    double Thetaaux = Theta;
    
    ofstream AntPos("AntPos.txt");
    AntPos << Tcurrent << "\t" << X1 << "\t" << X2 << "\t" << Theta << "\t" << endl;
    
    
    //  Main Loop
    for (int iter=1; iter <= tt; iter++) {
        
        Tcurrent = Tcurrent + dt;
        
        X1 = X1aux + dt * cos(Thetaaux);
        X2 = X2aux + dt * sin(Thetaaux);
        
        for (int kk=1; kk<=discr; kk++) {
            for (int jj=1; jj<=disctheta; jj++) {
                double pointr = drSector*kk;
                double pointtheta = Thetaaux - beta + dthetaSector*jj;
                Ftheta = Ftheta - drSector * dthetaSector *(sin(Thetaaux - pointtheta) * PheromoneProfile(X1aux + pointr*cos(pointtheta)) * pointr * pointr);
            }
        }
        
//        cout << Ftheta << endl;
        Theta = Thetaaux + dt * Ftheta;
        Ftheta = 0.;
        
        
        X1aux = X1;
        X2aux = X2;
        Thetaaux = Theta;
        AntPos << Tcurrent << "\t" << X1 << "\t" << X2 << "\t" << Theta << "\t" << endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}