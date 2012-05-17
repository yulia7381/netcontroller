#include "../service/network_service.h"
#include "../model/Node.h"
#include "../model/Link.h"
#include "../model/Graph.h"


#include <string>
#include <iostream>

int main() {
    NetworkService ns;

    // Node n1(0, "name1", "code1", Position(1,2, 5,1));
    // Node n2(0, "name2", "code2", Position(2,4, 5,1));
    // Node n3(0, "name3", "code3", Position(5,1, 5,1));


    // std::list<Link> links;
    // links.push_back(Link(0, &n1, &n2));
    // links.push_back(Link(0, &n1, &n3));
    // links.push_back(Link(0, &n2, &n3));


    // Graph gr(links);
    
    // ns.saveGraph(gr);
    std::cout << "start";
    Graph gr = ns.getGraph();
    std::cout << "start" << std::endl;


    // std::cout << gr.getLinks().size();


}
