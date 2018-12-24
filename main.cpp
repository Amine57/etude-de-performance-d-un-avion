#include <iostream>

using namespace std;

class Avion
{
    string nom; // le nom de l'avion
    double dist; // la distance qui va la prendre en h
    double Pv; // la poid au vide
    double Pl; //poid pour decolage
    double Pa; // poid de l atterrissage
    double Vp; // comme bien de litre elle va prendre dans 1 heur
    double Pb; // poid de bagage
    double Pm; // poid minimum de decolage et atterrissage
    int N; //nombre de passager
public:
    Avion (){nom = ""; dist =0; }
    Avion (string a, double b, double c, double d, double e, double f, double g,double h, int i){nom=a; dist=b; Pv=c; Pl=d; Pa=e; Vp=f; Pb=g;Pm=h; N=i;}
    string getNom(){return nom;}
    double getDist(){return dist;}
    double getPv(){return Pv;}
    double getPl(){return Pl;}
    double getPa(){return Pa;}
    double getVp(){return Vp;}
    double getPb(){return Pb;}
    double getPm(){return Pm;}
    double getN(){return N;}


    void setNom(string a){nom = a;}
    void setDist(double a){dist = a;}
    void setPv(double a){Pv = a;}
    void setPl(double a){Pl = a;}
    void setPa(double a){Pa = a;}
    void setVp(double a){Vp = a;}
    void setPb(double a){Pb = a;}
    void setPm(double a){Pm = a;}
    void setN(int a){N = a;}



    double Kc(){ return dist*Vp; } // kérosène consomé dans le tragé
    double Pp(){return 0.08*N;} // fonction qui calcule le poid general des passagers
    double decolage(){return (Pv+Pb+Pp()+Kc());} // fonctio qui calcule le poid de l'avion au decolage avec ces choses
    double atterrissage(){return (decolage()- Kc());} // focntion qui calcule le poid de l'avion au atterrissage avec ces choses



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
    cout << "Le poid max du decolage en (tone) est : " ;
    cin >> b;
    A.setPl(b);
    cout << "Le poid max du l'atterrissage en (tone) est : " ;
    cin >> b;
    A.setPa(b);
    cout << "Le poid minimal du decolage et du attirrissage en (tone) est : ";
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
