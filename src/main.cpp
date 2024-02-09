#include "digest.hpp"

std::string load(char *path)
{
    std::ifstream f(path);
    std::string content;

    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf();
        content = ss.str();
    }

    return (content);
}

Node run(char *path)
{
    std::string html = load(path);
    Digest digest = Digest();

    Node htmlTree = digest.feed(html);

    std::string xpathExpression = "//a[@class='link']/@href";
    std::vector<Node> result = digest.evaluate(htmlTree, xpathExpression);

    for (const auto& element : result) {
        std::cout << element.text << std::endl;
    }

    return (htmlTree);
}

int main(int argc, char **argv)
{
    Node result;

    if (argc == 2) {
        result = run(argv[1]);
    }

    return 0;
}
