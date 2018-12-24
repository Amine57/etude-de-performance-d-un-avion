#include <iostream>

using namespace std;

class Avion
{
    string nom; // le nom de l'avion
    double dist; // la distance qui va le prendre en h
    double Pv; // la poid au vide
    double Pl; //poid pour decollage
    double Pa; // poid de l atterrissage
    double Vp; // comme bien de litre il va prendre dans 1 heur
    double Pb; // poid de bagage
    double Pm; // poid minimum de decollage et atterrissage
    int N; //nombre de passager
public:
    Avion (){nom = ""; dist =0; } // constructeur par defaut
    Avion (string a, double b, double c, double d, double e, double f, double g,double h, int i){nom=a; dist=b; Pv=c; Pl=d; Pa=e; Vp=f; Pb=g;Pm=h; N=i;} //constructeur surchargé
    string getNom(){return nom;} // accesseur pour le nom
    double getDist(){return dist;} // accesseur pour la durée du trajet
    double getPv(){return Pv;} // accesseur pour le poid de cet avion au vide
    double getPl(){return Pl;} // accesseur pour le poid de decollage
    double getPa(){return Pa;} // accesseur pour le poid de l'atterrissage
    double getVp(){return Vp;} // accesseur pour le consommation de cet avion par heur
    double getPb(){return Pb;} // accesseur pour le poid du bagage
    double getPm(){return Pm;} // accesseur pour le poid minimal du decollage et atterrissage
    double getN(){return N;} // accesseur pour le nombre des passagers


    void setNom(string a){nom = a;} //mutateur pour le nom
    void setDist(double a){dist = a;} //mutateur pour la durée du trajet
    void setPv(double a){Pv = a;} ///mutateur pour le poid de cet avion au vide
    void setPl(double a){Pl = a;} //mutateur pour le poid de decollage
    void setPa(double a){Pa = a;} //mutateur pour le poid de l'atterrissage
    void setVp(double a){Vp = a;} //mutateur pour le consommation de cet avion par heur
    void setPb(double a){Pb = a;} //mutateur pour le poid du bagage
    void setPm(double a){Pm = a;} //mutateur pour le poid minimal du decollage et atterrissage
    void setN(int a){N = a;} //mutateur pour le nombre des passagers



    double Kc(){ return dist*Vp; } // kérosène consommé dans ce trajet
    double Pp(){return 0.08*N;} // fonction qui fait le calcule du poid general des passagers
    double decolage(){return (Pv+Pb+Pp()+Kc());} // fonctio qui calcule le poid de l'avion au decollage avec ces trucs
    double atterrissage(){return (decolage()- Kc());} // focntion qui calcule le poid de l'avion au atterrissage avec ces trucs



};

int main()
{
    cout << "                                        *************************************" << endl;
    cout << "                                        * ETUDE DES PERFORMANCES D'UN AVION *" << endl;
    cout << "                                        *************************************" << endl;
    Avion A;
    string a;
    double b;
    int c;

    cout << "Le nom de l'avion est : " ;
    cin >> a;
    A.setNom(a);
    cout << "La duree de ce trajet en (h) est : " ;
    cin >> b;
    A.setDist(b);
    cout << "Le poid de cette avion vide en (tone) est : " ;
    cin >> b;
    A.setPv(b);
    cout << "Le poid max du decollage en (tone) est : " ;
    cin >> b;
    A.setPl(b);
    cout << "Le poid max du l'atterrissage en (tone) est : " ;
    cin >> b;
    A.setPa(b);
    cout << "Le poid minimal du decollage et du attirrissage en (tone) est : ";
    cin >> b;
    A.setPm(b);
    cout << "La consommation de kerosene par cet avion en (tone) est : ";
    cin >> b;
    A.setVp(b);
    cout << "La poid de tous le bagage en (tone) est : ";
    cin >> b;
    A.setPb(b);
    cout << "Le nombre des passagers est : ";
    cin >> c;
    A.setN(c);
    //********************************************
    if (A.decolage()<A.getPl() && A.decolage()> A.getPm() ) cout << "L'avion peut decoller !" << endl;
    else cout << "L'avion ne peut pas decoller ! " << endl;
    if (A.atterrissage()<A.getPa() && A.atterrissage()> A.getPm()) cout << "L'avion peut atterrir !" <<endl;
    else cout << "L'avion ne peut pas atterrir !" << endl;
    if (A.Kc()>18 ) cout << "Cet avion ne peut pas prendre ce trajet directement, il faudra qu'il fasse une escale, merci! "<<endl; 
    cout << "****************************************" << endl;
    cout << "kerosene consomme est : " << A.Kc() << endl;
    cout << "Le poid totale de passager en (tone) est : " << A.Pp() << endl;
    cout << "Le poid qu'il va decoller avec, en (tone) est : " << A.decolage() << endl;
    cout << "Le poid qu'il va atterrir avec, en (tone) est : "<< A.atterrissage() << endl;




	system("Pause");
    return 0;
}
