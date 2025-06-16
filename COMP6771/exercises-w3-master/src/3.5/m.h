#ifndef COMP6771_NAMESPACED_H
#define COMP6771_NAMESPACED_H
#include <vector>
#include <string>
#include <unordered_map>

struct celestial_body {
    std::string name;
    int pos;
};

// Hint: type aliases in modern C++ also use the "using" directive...
/*
Namespace: groups code to avoid name conflicts, accessed via :: (e.g. std::cout).

using: creates shortcuts for namespaces or types (e.g. using std::cout;, using int_vector = std::vector<int>;).
*/
namespace comp6771 {
    using vector = std::vector<int>;
    using planet = celestial_body;
    namespace planets {
        using terrestrial = celestial_body;
    };
};
#endif // COMP6771_NAMESPACED_H
