#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits.h>
#include <map>

using namespace std;

class Tree

{

public:

    string name;

    vector<Tree*> list;

    Tree() {}

    Tree(string name)

    {

        this->name = name;

    }

};

 

Tree* getMatch(vector<Tree*> list, string name)

{

    if(list.empty()) return NULL;

 

    for(vector<Tree*>::iterator it = list.begin(); it != list.end(); ++it)

    {    

        if((*it)->name == name) {

            return *it;

        }

    }

    return NULL;

}

 

void addDir(Tree* t, char* dirname)

{

    char* back = strdup(dirname);

    char* next = strtok(back , "/");

    Tree* current = t;

    while(next != NULL)

    {

        Tree* chk = getMatch(current->list, next);

        if(chk == NULL) {

            Tree *newNode = new Tree(next);

            current->list.push_back(newNode);

            current = newNode;

        } else {

            current = chk;

        }

        next = strtok(NULL, "/");

    }

}

 

int main()

{

    int N;

    ofstream outfile("result.txt");

    scanf("%d",&N);

    for(int Ti=1; Ti<=N; Ti++)

    {

        int c1,c2;

        int count = 0;

        char dirname[105];

        Tree *fs = new Tree();

        fs->name = "/";

        scanf("%d %d",&c1,&c2);

        for(int i=0; i<c1; i++) {

            scanf("%s", dirname);

            addDir(fs, dirname);

        }

        for(int i=0; i<c2; i++) {

            scanf("%s", dirname);

            char* back = strdup(dirname);

            char* next = strtok(back , "/");

            Tree* current = fs;

            while(next != NULL)

            {

                Tree* chk = getMatch(current->list, next);

                if(chk == NULL) {

                    Tree *newNode = new Tree(next);

                    current->list.push_back(newNode);

                    current = newNode;

                    ++count;

                } else {

                    current = chk;

                }

                next = strtok(NULL, "/");

            }

        }

        outfile<<"Case #"<<Ti<<": "<<count<<endl;

    }

}
