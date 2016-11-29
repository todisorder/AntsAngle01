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
    
    double aux = 1.*exp(-abs(1. * x));
    
    return aux;
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
    
    double ell = 0.05;     //  Sensing radius
    double beta = Pi/4.;    //  Sensing half-angle
    
    double dt;
    
    double dr;
    double dtheta;
    
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
    
    double X1aux = X1;
    double X2aux = X2;
    double Thetaaux = Theta;
    
    for (int iter=1; iter <= tt; iter++) {
        
        
        X1 = X1aux + dt * cos(Theta);
        X2 = X2aux + dt * sin(Theta);
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}