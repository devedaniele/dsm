#include "Server/http.hpp"
#include <fstream>

using namespace std;

http srv;

int main(){

    srv.get("/",[](Request &req,Response &res){
        filebuf file;
        file.open("index.html",ios_base::in);
        int len = file.in_avail();
        char body[len];
        file.sgetn(body,len);
        file.close();

        string headers = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
        headers.append(to_string(len));
        headers.append("\n\n");

        res.end(headers + body);
    });
    /* srv.post("/",[](Request&,Response &res){
        res.end("done");
    }); */

    cout << "staring server....." << endl;

    srv.listen(8767);
    
    return 0;
};
