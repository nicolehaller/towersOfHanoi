//Nicole haller
#include <iostream>
#include <vector>
using namespace std;

void odd_move(vector<int> t[], int &to, int&from, int&candidate); //tells where from and to tower are
void even_move(vector<int> t[], int &to, int&from, int&candidate);

int main(){ 
    vector <int> t[3]; //creates three vectors of integers to represent three towers
    //t[0]=tower A, t[1]=tower B, t[2]=tower C
    int rings, candidate=1, to, from=0, move=0; //candidate is the smallest ring that hasnt just been moved and starts at ring 1, "from" starts at tower 0 bc the rings all start on tower 0

    //get user input for number of rings
    cout<< "number of rings ";
    cin>> rings;
    //initialize the towers to start w rings+1, except t[0] will have n+1, n until 1
    for (int i=rings+1; i>=1; i--){
        t[0].push_back(i); //adds rings to tower 0, last element added is 1
    }
    //add biggest ring to Tower B and Tower C
    t[1].push_back(rings+1); 
    t[2].push_back(rings+1);
    
    bool isOdd;
    if(rings % 2==1){
        //we have an odd number of rings
        isOdd=true;
        to= 1; //initialize "to" tower to 1
    } else {
        //we have an even number of rings
        isOdd= false;
        to= 2; //initialize "to" tower to 2
    }

    //continue while size of tower 1 is less than n+1 bc need n+1 rings on tower 1 to be done
    while (t[1].size() < (rings+1)){
        //print the move ur going to make, then do it 
        move++;
        cout<< "step #" << move<< ": I moved ring " << candidate << " from Tower " << char(from+65) << " to " << char(to+65) << endl;//char refers to A B C
        //get top element from the "from" tower and push onto the "to" tower
        t[to].push_back(t[from].back()); //can push back candidate 
        //delete the top element from the "from" tower after moving it
        t[from].pop_back(); //removes top ring
        if (isOdd) odd_move(t, to, from, candidate); //if odd number of rings, perform odd move
        else even_move(t, to, from, candidate); //if even number of rings, perform even move

        //can do this here: candidate= t[from].back(); which makes candidate is top most ring of "from" tower, but I did it later
    }
    //when done print how many steps it took
    cout << "Done! all the rings were on Tower B in " << move << " steps!";
     return 0;
}

//changing values of to and from towers

void odd_move(vector<int> t[], int &to, int&from, int&candidate){ //can pass int candidate in
    //finding "from" tower
        if(t[(to+1)%3].back() < t[(to+2)%3].back()){ //if top of tower to the right of the "to" tower is less than top of tower two to the right, make tower to the right the "to" tower
                //whichever has smallest ring is from tower
                from= (to+1)%3; 
        } 
        else {  
                from= (to+2)%3; //whatever candidate is is your from tower- candidate=t[(to+2)%3].back(); //if top of tower two to the right of "to" tower is less than top of tower directly to the right of "to" tower, make tower two to the right into the "to" tower
        }
        candidate= t[from].back();
    //finding "to" tower, check tower to the right first
        if (t[from].back() < t[(from+1)%3].back()) to=(from+1)%3; //if top of "from" tower is less than top of tower to the right of "from", make tower to the right the "to" tower
        else to= (from+2)%3; //if tower to the right of "from" doesnt work, the tower two to the right works and is the "to" tower
}
//other2towers variables

void even_move(vector<int> t[], int &to, int&from, int&candidate){

    //finding "from" tower
    if(t[(to+2)%3].back() < t[(to+1)%3].back()){ //if top of left tower is less than top of second to left tower...
            //wherever candidate is is your from tower
            from= (to+2)%3;
    } 
    else {  //if top of second to left tower is less than the top of left tower...
            from= (to+1)%3; //whatever candidate is is your from tower
    }
    candidate=t[from].back(); //smallest ring (which is at top of left tower) becomes the candidate
    
    //finding "to" tower- for even, check tower to left first (first check from+2%3 before from+1%3)
    if (t[from].back() < t[(from+2)%3].back()) to=(from+2)%3; //if top of from tower is less than top of tower to the right, make tower to the right the to tower
    else to= (from+1)%3; //if tower to the right of "from" doesnt work, the tower two to the right works and is the "to" tower

}