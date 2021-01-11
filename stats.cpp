
#include <iostream>
#include "stats.h"

Stats::Stats(){
    
    mapMethodsStat["GET"] = 0;
    mapMethodsStat["POST"] = 0;
    mapMethodsStat["PUT"] = 0;
    mapMethodsStat["DELETE"] = 0;
    mapMethodsStat["UNKNOWN"] = 0;
    
    mapURIStat["/"] = 0;
    mapURIStat["/basket"] = 0;
    mapURIStat["/order"] = 0;
    mapURIStat["/product"] = 0;
    mapURIStat["/help"] = 0;
    mapURIStat["unknown"] = 0;

}

void Stats::AddMethod(string_view method){

    string ss(method);
    if (method == "GET" || method == "POST" || method == "PUT" || method == "DELETE"){
        mapMethodsStat[method]++;
    }
    else{
        mapMethodsStat["UNKNOWN"]++;
    }
    // Print();
}

void Stats::AddUri(string_view uri){
    
    string ss(uri);
    
    if ((uri == "/") || (uri == "/order") || (uri == "/product") || (uri == "/help") || (uri == "/basket")){
        mapURIStat[uri]++;
    }
    else{
        mapURIStat["unknown"]++;
    }
    // Print();
}

const map < string_view, int > & Stats::GetMethodStats() const{
      return mapMethodsStat;
}
  
const map < string_view, int > & Stats::GetUriStats() const{
      return mapURIStat;
}

HttpRequest ParseRequest(string_view line){
    HttpRequest req;
    
    // line.remove_prefix(line.find_first_not_of(' '));
    
    size_t pos = line.find_first_not_of(' ');
    
    size_t pos1 = line.find(' ', pos);
    req.method = line.substr(pos, pos1 - pos);
    
    size_t pos2 = line.find(' ', pos1 + 1);
    req.uri = line.substr(pos1 + 1, pos2 - pos1 - 1);
    
    req.protocol = line.substr(pos2 + 1);
    
    return req;
    
}
