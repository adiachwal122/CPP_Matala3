#include <iostream>
#include <list>
using namespace std;
#include <vector>

class Member{
    
    int id;
    list <int> followers ;//im following
    list <int> following ;//following me
    
    public :
        static int membersC;
       static vector<Member*> DB;
        
        int getid(){ return id; }
        
        int numFollowers(){ return followers.size(); }
        int numFollowing(){ return following.size(); }
        
        void follow (Member&);
        void unfollow (Member&);
        static int count(){ return membersC;}
        
        Member();
        ~Member();
        
};