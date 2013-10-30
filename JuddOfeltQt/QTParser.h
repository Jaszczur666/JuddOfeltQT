#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Experiment{
public:
vector <double> u2;
vector <double> u4;
vector <double> u6;
vector <double> lambda;
double n;
double o2;
double o4;
double o6;
double do2;
double do4;
double do6;
double RMS;
double RMSNormalized;
vector <double> fexp;
double j;
bool filled;
void LoadAbsoDataFromFile(QString filename);
void LoadEmDataFromFile(QString Filename);
 Experiment()
  {
    filled=false;
  }
};

void Experiment::LoadAbsoDataFromFile(QString Filename)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
    wstring name,str;
    name=Filename.toStdWString();
    ifstream inpfile(name);
    //cout << "Attempting to open file: "<<name<<endl;
//	getline(inpfile,str);
	inpfile>>j>>n;
    cout <<"n= "<< n <<" j= "<<j<<endl;
    this->lambda.clear();
    this->u2.clear();
    this->u4.clear();
    this->u6.clear();
    this->fexp.clear();
    this->n=n;
    this->j=j;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
        this->fexp.push_back(pexp);
        this->u2.push_back(u2);
        this->u4.push_back(u4);
        this->u6.push_back(u6);
        this->lambda.push_back(1./wavenumber);
        this->o2=1e-20;
        this->o4=1e-20;
        this->o6=1e-20;
	cout <<pexp <<" "<<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}

void Experiment::LoadEmDataFromFile(QString Filename)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
    wstring name;
    name=Filename.toStdWString();
	ifstream inpfile(name);
//    cout<<name<<endl;
//	getline(inpfile,str);
	inpfile>>j>>n;
	cout << n <<" "<<j<<endl;
    this->lambda.clear();
    this->u2.clear();
    this->u4.clear();
    this->u6.clear();
    this->fexp.clear();
    this->n=n;
    this->j=j;
	while(inpfile >> wavenumber>>u2>>u4>>u6){
        this->fexp.push_back(pexp);
        this->u2.push_back(u2);
        this->u4.push_back(u4);
        this->u6.push_back(u6);
        this->lambda.push_back(1./wavenumber);
        this->o2=1e-20;
        this->o4=1e-20;
        this->o6=1e-20;
	cout  <<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}
