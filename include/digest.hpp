#pragma once

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include<sstream>

    #include "node.hpp"

    class Digest
    {
        public:
            Digest();
            ~Digest();

            Node feed(std::string);
            std::vector<Node> evaluate(Node, std::string);            
    };