#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct node
{
    vector<struct node *> child;
    char data;
    char isroot;
};

void buildtree(char *str);
void printtree(struct node *now);

struct node *root;

int main()
{
    root = new struct node();
    root->data = NULL;
    root->isroot = 1;

    buildtree("asdf");
    buildtree("asfe");
    printtree(root);

}


void buildtree(char *str)
{
    int len = strlen(str);
    int flag = 0;
    struct node *tmpnode;
    tmpnode = root;

    for(int i=0; i<len; i++) {
        for(int j=0; j<tmpnode->child.size(); j++) {
            if(str[i] != tmpnode->child[j]->data) continue;
            tmpnode = tmpnode->child[j];
            flag = 1;
            break;
        }
        if(!flag) {
            struct node *newnode = new struct node();
            newnode->data = str[i];
            newnode->isroot = 0;

            tmpnode->child.push_back(newnode);
            tmpnode = newnode;
        }
        flag = 0;
    }
}

void printtree(struct node *now)
{
    static vector<char> pnt;

    if(now->child.size() == 0) {
        for(int i=0; i <pnt.size(); i++)
            printf("%c", pnt[i]);
        printf("\n");
        return;
    }


    for(int i=0; i<now->child.size(); i++){
        pnt.push_back(now->child[i]->data);
        printtree(now->child[i]);
        pnt.pop_back();
    }
}
