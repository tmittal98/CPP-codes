//LRU CACHE
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
    public:
        int maxSize;
        list<int> l;
        unordered_map<int,list<int>::iterator> mp;
    
    LRUCache(int size){
        this->maxSize = size > 1 ? size : 1;
    }

    void pageRequest(int pageno){
        
        if(mp.find(pageno) == mp.end()){
            //not present
            if(l.size() == maxSize){
                //size full
                //erase the least recently used from l
                //erase the element from map
                int last = l.back();
                mp.erase(last);
                l.pop_back();
            }
        }
        else{
            //present 
            l.erase(mp[pageno]);
        }
       l.push_front(pageno);
       mp.insert({pageno,l.begin()});
    }

    void display(){

        //display the current cache
        for(list<int>::iterator it = l.begin() ; it != l.end(); it++){
            cout<<*it<<endl;
        }
        return;
    }
};


int main() {
    LRUCache cache(3);

    cache.pageRequest(1);
    cache.pageRequest(2);
    cache.pageRequest(3);
    cache.pageRequest(4);
    cache.pageRequest(1);
    cache.pageRequest(3);

    cache.display();

    return 0;
}
//1 2 3 4 1 3


// 3
// 1
// 4



