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

class Query {
    protected:
        std::vector<std::string> tags;
        std::string attribute;
    public:
        std::string getAttribute() {
            return attribute;
        }
        std::vector<std::string> getTags() {
            return tags;
        }
        Query(std::vector<std::string> parsedQuery) {
            for(int i=0; i < parsedQuery.size() - 1; i++) {
                tags.push_back(parsedQuery[i]); 
            }
            attribute = parsedQuery[parsedQuery.size()-1];
        }
        void printQuery() {
            cout << "Tags: " << endl;
            for(int i = 0; i < tags.size(); i++)
            {
                cout << tags[i] << ' ';
            }
            cout << endl;
            cout << "Attribute" << endl;
            cout << attribute << endl;
        }
};

class Tag {
    protected:
        static std::map<std::string, Tag*> tags;
        static std::string root;
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
        Tag* getChildByName(std::string name) {
            Tag* child;
            for(std::list<Tag*>::iterator i = children.begin(); i != children.end(); i++)
            {
                if((*i)->getTag() == name) return *i;
            }
            return nullptr;
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
        void printParents() {
            cout << "parents: " << endl;
            for(std::list<Tag*>::iterator i = parents.begin(); i != parents.end(); i++)
            {
                cout << (*i)->getTag() << " - " ;
            }
            cout << endl;
        }
        void printChildren() {
            cout << "children: " << endl;
            
            for(std::list<Tag*>::iterator i = children.begin(); i != children.end(); i++)
            {
                cout << (*i)->getTag() << " - " ;
            }
            cout << endl;
        }
        Tag(std::string tag) {
            
            if (tags.empty()) {
                root = tag;
            }
            
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
        void printTag() {
            cout << endl << this->tagName << endl;
            this->printParents();
            this->printChildren();
            this->printAttributes();
        }
        static void queryAttribute(Query* q) {
            std::vector<string> qTags       = q->getTags();
            std::string         attribute   = q->getAttribute();
            Tag *nextTag;
            int i = 0;
            Tag *tag = tags[qTags[i]];
            
            if (qTags[i] == root) {
                i++;
                for(i; i < qTags.size(); i++)
                {
                    // tag->printTag();
                    nextTag = tag->getChildByName(qTags[i]);                
                    if (!nextTag) {
                        cout << "Not Found!" << endl;
                        return;
                    }
                    tag = nextTag;                
                }
            } else {
                cout << "Not Found!" << endl;
                return;
            }

            std::string attr = tag->getAttribute(attribute);
            if (!attr.empty()) {
                cout << attr << endl;
            } else {
                cout << "Not Found!" << endl;
            }
        
           
        }
};

class Parser {
    // Here should go the input parsing, but i won't do it ...
};

// Makes Tag::tags class member known globally
std::map<std::string, Tag*> Tag::tags;
std::string Tag::root;

int main() {
    int nlines, nqueries;
    std::string tag, query;
    std::vector<string> hrml, hrml_queries;
    std::cin >> nlines >> nqueries;
    std::getline(std::cin, tag); // just to read out the /n from the first string

    for(int i=0; i<nlines; ++i){
        std::getline(std::cin, tag);
        hrml.push_back(tag);
    }
    for(int i=0; i<nqueries; ++i){
        std::getline(std::cin, query);
        hrml_queries.push_back(query);
    }
    // String with the pattern to create the regex object
    std::string start_tag_pattern =
        "<([[:print:]]\\b)(\\s([[:print:]])\\s=\\s\"([[:print:]])\")*(\\s([[:print:]])\\s=\\s\"([[:print:]])\")>";
    std::string close_tag_pattern = "</(\\w+)*>";
    // Creates the regex object from pattern with flags
    std::regex openTagID(start_tag_pattern, std::regex_constants::icase |  std::regex::ECMAScript);
    std::regex closeTagID(close_tag_pattern, std::regex_constants::icase |  std::regex::ECMAScript);
    std::sregex_iterator it_end;
    std::stack<Tag*> tagStack;
    for(int i=0; i<nlines; ++i){
        const std::string text = hrml[i];
        if (std::regex_search(text, openTagID)) {
            std::sregex_iterator it(text.begin(), text.end(), openTagID);   
            for (std::sregex_iterator i=it; i!=it_end; ++i) {
                std::smatch match = *i;
                std::string tag = match[1];
                // for(std::smatch::iterator i=match.begin(); i != match.end(); i++)
                // {
                //     cout << *i << endl;
                // }
                Tag* tagObj = new Tag(tag);
                for(int a=3; a<match.size(); a++) {
                    std::string name, value;
                    name = match[a];
                    value = match[a+1];
                    a++;
                    tagObj->setAttribute(name, value);
                    if(! (a%2)) a++; // iterates every 2 positions to get the pairs key,value
                }
                if (tagStack.empty()) {
                    tagStack.push(tagObj);
                } else {
                    tagObj->addParent(tagStack.top());
                    tagStack.top()->addChild(tagObj);
                    tagStack.push(tagObj);
                }
            }
        } else if(std::regex_search(text, closeTagID)) {  
            std::smatch match;
            std::regex_search(text, match, closeTagID);
            if (tagStack.top()->getTag() != match[1])
                throw std::invalid_argument("Invalid HRML syntax");
            tagStack.pop();
        }
    }
       
    std::string query_pattern = "(\\b\\w+\\b)"; 
    std::regex query_regex(query_pattern, std::regex_constants::icase | std::regex::ECMAScript);
    std::vector<std::string> parsedQuery;
    for(int i = 0; i < nqueries; i++) {
        std::string text = hrml_queries[i];
        std::smatch match;

        std::sregex_iterator it(text.begin(), text.end(), query_regex);   
        for (std::sregex_iterator i=it; i!=it_end; ++i) {
            std::smatch match = *i;
            parsedQuery.push_back(match.str());
        }   
        Query* q = new Query(parsedQuery);
        Tag::queryAttribute(q);
        parsedQuery.clear();
    }
    return 0;
}