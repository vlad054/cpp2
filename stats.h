#pragma once

#include "http_request.h"
  
#include <string_view>
#include <map>


using namespace std;

 
class Stats
{

public:

Stats();
 
void AddMethod (string_view method);
  
void AddUri (string_view uri);
  
const map < string_view, int >&GetMethodStats () const;
  
const map < string_view, int >&GetUriStats () const;

void Print() const{
    cout << " mapMethodsStat :" << endl;
    for (auto f: mapMethodsStat){
        cout << f.first << " - " << f.second << endl;
    }
    cout << " mapURIStat :" << endl;
    for (auto f: mapURIStat){
        cout << f.first << " - " << f.second << endl;
    }
}

private:
    map <string_view, int > mapMethodsStat;
    map <string_view, int > mapURIStat;
    
 
};


 
HttpRequest ParseRequest (string_view line);

