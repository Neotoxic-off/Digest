#include "digest.hpp"

Digest::Digest()
{

}

Digest::~Digest()
{
    
}

Node Digest::feed(std::string htmlContent)
{
    Node root;
    std::stringstream ss(htmlContent);
    char c;
    std::string tag;
    bool inTag = false;
    bool inAttribute = false;
    std::string attributeName;
    std::string attributeValue;

    while (ss.get(c)) {
        if (c == '<') {
            inTag = true;
            tag.clear();
            continue;
        } else if (c == '>') {
            inTag = false;
            if (tag[0] == '/') {
                root.tag = tag.substr(1);
            } else {
                Node newNode;
                newNode.tag = tag;
                root.children.push_back(newNode);
            }
            continue;
        }

        if (inTag) {
            tag += c;
        }
    }

    return root;
}

std::vector<Node> Digest::evaluate(Node root, std::string expression)
{
    std::vector<Node> result;

    return (result);
}
