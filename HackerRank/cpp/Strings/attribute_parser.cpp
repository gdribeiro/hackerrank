#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <regex>
#include <iterator>

using namespace std;

class Tag {
    protected:
        std::map<std::string, std::string> attributes;
        std::string tagName;
        Tag *parent;
        Tag *child;

    public:
        static std::map<std::string, Tag*> tags;

        // To return a null pointer use nullptr
        void setTag(std::string tag) {
            tagName = tag;
        }
        std::string getTag() {
            return tagName;
        }
        std::string getAttribute(std::string attr){
            return attributes[attr];
        }
        Tag* getParent() {
            return parent;
        }
        Tag* getChild() {
            return child;
        }
        void setAttribute(std::string name, std::string value) {
            attributes[name] = value;
        }
        void setParent(Tag* parent) {
            parent = parent;
        }
        void setChild(Tag* child) {
            child = child;
        }
        Tag(std::string tag) {
            tagName = tag;
            tags[tag] = this;
        }

        static map<std::string, Tag*>::iterator getTagsBegin() {
            return tags.begin();
        }
        static map<std::string, Tag*>::iterator getTagsEnd() {
            return tags.end();
        }



};


std::map<std::string, Tag*> Tag::tags;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int nlines, nqueries;
    std::string tag, query;
    std::vector<string> hrml, hrml_queries;
    std::cin >> nlines >> nqueries;
    std::getline(std::cin, tag); // just to read out the /n from the first string

    std::cout << nlines << ' ' <<  nqueries;
    std::cout << endl;
    for(int i=0; i<nlines; ++i){
        std::getline(std::cin, tag);
        // cout << tag << endl;
        hrml.push_back(tag);
    }
    std::cout << endl;
    for(int i=0; i<nqueries; ++i){
        std::getline(std::cin, query);
        // cout << query << endl;
        hrml_queries.push_back(query);
    }


    // String with the pattern to create the regex object
    std::string start_tag_pattern =
        "<([a-z0-9_]+)([\\s]*([a-z0-9_]+)\\s=\\s\"([a-z0-9_]+)\"[\\s]*)+>*";
    // Creates the regex object from pattern with flags
    std::regex tagID(start_tag_pattern, std::regex_constants::icase);
    std::sregex_iterator it_end;
    for(int i=0; i<nlines; ++i){
        const std::string text = hrml[i];

        std::sregex_iterator it(text.begin(), text.end(), tagID);   
        for (std::sregex_iterator i=it; i!=it_end; ++i) {
            std::smatch match = *i;
            std::cout << match.size() << endl;
            for(int j=0; j<match.size(); j++)
            std::cout << match[j] << endl;
        }
        for (std::sregex_iterator i=it; i!=it_end; ++i) {
            std::smatch match = *i;
            
            std::string tag = match[1];
            Tag* tagObj = new Tag(tag);
            for(int a=3; a<match.size(); a++) {
                std::string name, value;
                tagObj->setAttribute(name, value);

                if(a%2) a++;
            }
        }
      
        for (map<string,Tag*>::iterator i=Tag::getTagsBegin(); i!=Tag::getTagsEnd(); ++i)
            std::cout << Tag::tags.size() << i->first << " : " << i->second->getTag() << endl;



    }



    return 0;
}
