#include <iostream>
//#include "Team.hpp"
//#include "Player.hpp"
#include "List.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]){

    /*string nm, np;
    Player p;
    cin >> nm;
    p.setFirstName(nm);
    cin >> np;
    p.setSecondName(np);
    int poi;
    cin >> poi;
    p.setPoints(poi);
    p.afisare();
    */
     /*int n;
    cout << "cati?";
    cin >> n;
    Player *P;
    P = new Player[n];
    for(int i = 0; i < n; i++){
        P[i].setFirstName();
        P[i].setSecondName();
        P[i].setPoints();
    }
    string nume_echipa;
    cout<<"numele echipei: "; cin >> nume_echipa;

    Team t(n, nume_echipa, P);
    Team m;
    m = t;
    m.afisare();
*/
    /*
    Team *T;
    T = new Team [nr];
    for(int i = 0; i < nr; i++){

        f >> T[i];
    }

    for(int i = 0; i < nr; i++)
        T[i].afisare();


    delete [] T;
*/
    /*ifstream f("d.in");
    if(!f)
        cout << "eroare la fisiser";
    int nr;
    f >> nr;
    Team T[25];
    for(int i = 0; i < nr; i++){

        f >> T[i];
    }

    for(int i = 0; i < nr; i++){

        T[i].afisare();
    }*/
    /*ifstream f("d.in");
    if(!f)
        cout << "eroare la fisiser!";
    int nr;
    f >> nr;
    Team *T;
    T = new Team[nr];
    List L;
    f >> T[0];
    L.Add_beginning(T[0]);
    for(int i = 1; i < nr; i++){
        f >> T[i];
        L.Add_beginning(T[i-1]);
    }
    L.Add_beginning(T[nr-1]);
    for(int i = 0; i < nr; i++){

        //T[i].write();
    }
    ofstream r("r.out");
    if(!r)
        cout << "eroare la fisiser!";
    delete [] T;

    L.write(r);
    f.close();
    r.close();
    */
    ifstream input("c.in");
    ifstream date("d.in");
    ofstream output("out7.out");
    List L;
    Queue Q;
    int no_teams;
    int *task;
    task = new int[5];
    for (int i =0 ;i <5; i++)
    {
        input >> task[i];
    }
    for (int i = 0; i < 3; i++) {
		//Team t;
		//date >> t;

        date >> no_teams;
        //cout  << no_teams << endl;
		switch (i) {
			case 0: {
				if (task[i] == 1)
				{

				    bool afisare = true;
                    if(task[1] == 1)
                    {
                        afisare = false;
                    }
					L.read_write(no_teams, date, output,afisare);
					//L.Delete_Node(L.getHead());
					//cout << no_teams << endl;
				}


				break;
			}
			case 1: {
				if (task[i] == 1)
                    //L.Delete_Node(t);
                    //cout << "test1";
                    //if(no_teams != L.highestPower2(no_teams)){
                       L.Delete_Write(no_teams, output);


                    //cout << no_teams;
                    //L.write_sub2(output);

				break;
			}
			case 2: {
				if (task[i] == 1){

                    //L.Delete_Write(no_teams, output);
                    Q.Form_Matches(L, output);
                    Queue *cod = &Q;
                    int round_no = log2(L.highestPower2(no_teams));
                    for(int i = 1; i <= round_no; i++)
                    {
                        Stack * Winners = new Stack();
                        Stack Losers;
                        cod->write_matches(i, output, *Winners, Losers);
                        Winners->Write(i, output);
                        Queue* cod = new Queue();
                        cod->Form_MatchesStack(*Winners);
                        delete Winners;
                    }
                    //cout << round_no;


				}

				break;
			}
			default: {
				cout << "Error! " << endl;
				break;
			}
		}
	}

	input.close();
	output.close();
	date.close();
	delete [] task;
    return 0;

}
