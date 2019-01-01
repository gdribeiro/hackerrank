#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <regex>
#include <iterator>
#include <stack>

using namespace std;

class Tag {
    protected:
        static std::map<std::string, Tag*> tags;
        std::map<std::string, std::string> attributes;
        std::string tagName;
        std::list<Tag*> parents;
        std::list<Tag*> children;

    public:
        void setTag(std::string tag) {
            tagName = tag;
        }
        std::string getTag() {
            return tagName;
        }
        std::string getAttribute(std::string attr){
            return attributes[attr];
        }
        std::list<Tag*> getParents() {
            return parents;
        }
        std::list<Tag*> getChildren() {
            return children;
        }
        void setAttribute(std::string name, std::string value) {
            attributes[name] = value;
        }
        void addParent(Tag* parent) {
            parents.push_back(parent);
        }
        void addChild(Tag* child) {
            children.push_back(child);
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
        void printAttributes() {
            if(attributes.empty()) {
                cout << "attributes is empty";
                return;
            }
            for (std::map<std::string, std::string>::iterator i=attributes.begin(); i!=attributes.end(); ++i)
                std::cout << "number of attributes: " << attributes.size() << endl
                << "name: "<< i->first
                << " : " << "value: " << i->second << endl;

        }
};
class Parser {
    
};

std::map<std::string, Tag*> Tag::tags;

int main() {
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
        hrml_queries.push_back(query);
    }


    // String with the pattern to create the regex object
    std::string start_tag_pattern =
        "<([a-z0-9_]+)([\\s]*([a-z0-9_]+)\\s=\\s\"([a-z0-9_]+)\"[\\s]*)+>*";
    std::string close_tag_pattern =
        "<//([a-z0-9_]+)*>";
    // Creates the regex object from pattern with flags
    std::regex openTagID(start_tag_pattern, std::regex_constants::icase);
    std::regex closeTagID(close_tag_pattern, std::regex_constants::icase);



    std::sregex_iterator it_end;
    std::stack<Tag*> tagStack;
    for(int i=0; i<nlines; ++i){
        const std::string text = hrml[i];

        if (std::regex_match(text, openTagID)) {
            std::sregex_iterator it(text.begin(), text.end(), openTagID);   
            for (std::sregex_iterator i=it; i!=it_end; ++i) {
                std::smatch match = *i;
                
                std::string tag = match[1];
                Tag* tagObj = new Tag(tag);
                for(int a=3; a<match.size(); a++) {
                    std::string name, value;
                    name = match[a];
                    value = match[a+1];
                    tagObj->setAttribute(name, value);
                    if(a%2) a++; // iterates every 2 positions to get the pairs key,value
                }
                if (tagStack.empty()) {
                    tagStack.push(tagObj);
                } else {
                    tagObj->addParent(tagStack.top());
                    tagStack.top()->addChild(tagObj);
                    tagStack.push(tagObj);
                }
            }
        } else if(std::regex_match(text, closeTagID)) {
            tagStack.pop();
        }

    }
    for (map<string,Tag*>::iterator i=Tag::getTagsBegin(); i!=Tag::getTagsEnd(); ++i) {
        std::cout << i->first << " : " << i->second << ' ' << i->second->getTag() << endl;
        i->second->printAttributes();
    }

    
    for(int i = 0; i < nqueries; i++) {
        std::string text = hrml_queries[i];
        
    }
    




    return 0;
}
