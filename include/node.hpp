#pragma once

    #include <iostream>
    #include <vector>

    struct Node
    {
        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
        std::string text;
        std::vector<Node> children;
    };
