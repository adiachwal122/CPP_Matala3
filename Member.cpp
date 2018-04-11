#include "Member.h"
#include <algorithm>
using namespace std;
#include <iostream>
#include <list>
#include <vector>

int Member :: membersC = 0;
vector<Member*> Member::DB;

//template <typename T>
bool contains(list<int> & listOfElements, int element){
	// Find the iterator if element in list
	auto itr = std::find(listOfElements.begin(), listOfElements.end(), element);
	//return if iterator points to end or not. It points to end then it means element
	// does not exists in list
	return itr != listOfElements.end();
}
 
void Member :: follow(Member& m){
    int temp = m.getid();
    bool flag = contains(this -> following, temp);
    if (flag || (this -> id == temp)){
        cout<< "Duplicate error"<<endl;
    }
    
    else{     
        m.followers.push_back(this -> getid());
        this -> following.push_back(m.getid());
    }
}

void Member :: unfollow(Member& m){
    int temp = m.getid();
    bool flag = contains(this -> followers, temp);
    if (!flag){
        this -> following.remove(m.getid());
        m.followers.remove(this -> id);
    }
    
    else{
        cout<< "Error"<<endl;
    }
}

Member :: Member(){
    Member :: membersC++;
    this -> id = membersC ;
    Member :: DB.push_back(this);
}

Member :: ~Member(){
    int temp = 0;
    for (int i=0;i<Member::DB.size();i++) {
        Member *x = Member::DB.at(i);
        if(x -> getid()!= this -> getid()){
            if(std::find(this -> followers.begin(), this -> followers.end(), x -> getid()) != this -> followers.end()) {
                this -> followers.remove(x -> getid());
                x -> following.remove(this -> getid());
            }
                   
            if(std::find(this -> following.begin(), this -> following.end(), x -> getid()) != this -> following.end()) {
                this -> following.remove(x -> getid());
                x -> followers.remove(this -> getid());
            }
        }
        else
            temp = i;
    }
    DB.erase(DB.begin() + temp);
    membersC--;
           
}
