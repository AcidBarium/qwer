#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define Endl endl
#define ednl endl
#define eldn endl
#define dnel endl
#define enndl endl
#define Ednl endl
#define Edml endl
#define llmax 9223372036854775807
#define intmax 2147483647

template <class T>
class BSTree;
template <class T>
class BSNODE
{
    friend class BSTree<T>;

private:
    T element;
    BSNODE<T> *leftChild;
    BSNODE<T> *rightChild;

public:
    BSNODE();
    BSNODE(const T &ele)
    {
        element = ele;
        leftChild = NULL;
        rightChild = NULL;
    }
    BSNODE(const T &ele, BSNODE<T> *l, BSNODE<T> *r)
    {
        element = ele;
        leftChild = l;
        rightChild = r;
    }
    BSNODE<T> *getLeftChild() const { return leftChild; }
    BSNODE<T> *getRightChild() const { return rightChild; }
    void setLeftChild(BSNODE<T> *l) { leftChild = l; }
    void setRightChild(BSNODE<T> *r) { rightChild = r; }
    T getValue() const { return element; }
    void setValue(const T &val) { element = val; }
    bool isLeaf() const
    {
        if (leftChild == NULL && rightChild == NULL)
            return true;
        return false;
    }
};

template <class T>
class BSTree
{
private:
    BSNODE<T> *root;

public:
    BSTree() { root = NULL; }
    BSTree(BSNODE<T> *&r) { root = r; }
    void createSearchTree();
    void visit(BSNODE<T> *current);
    BSNODE<T> *search(BSNODE<T> *root, T x);
    void insertNode(const T &value);
    void deleteByCopying(BSNODE<T> *&node);
    void deleteByMerging(BSNODE<T> *&node);
    void inOrder(BSNODE<T> *root);
    void setRoot(BSNODE<T> *r);
    BSNODE<T> *getRoot();
    BSNODE<T> *getParent(BSNODE<T> *root, BSNODE<T> *current) const;
};
template <class T>
void BSTree<T>::createSearchTree()
{
    int a;
    cin >> a;
    while (a != 0)
    {
        insertNode(a);
        cin >> a;
    }
}

template <class T>
BSNODE<T> *BSTree<T>::getRoot()
{
    return root;
}

template <class T>
void BSTree<T>::setRoot(BSNODE<T> *r)
{
    this->root = r;
}

template <class T>
BSNODE<T> *BSTree<T>::getParent(BSNODE<T> *root, BSNODE<T> *current) const
{
    if (root != NULL)
    {
        if (root == current)
        {
            cout << "该节点为根结点，无父结点" << endl;
            return NULL;
        }
        else if (root->leftChild == current || root->rightChild == current)
        {
            return root;
        }
        else
        {
            getParent(root->leftChild, current);
            getParent(root->rightChild, current);
        }
    }
    return NULL;
}

template <class T>
void BSTree<T>::visit(BSNODE<T> *current)
{
    cout << current->element << " ";
}

template <class T>
BSNODE<T> *BSTree<T>::search(BSNODE<T> *root, T x)
{
    BSNODE<T> *current = root;
    if (current->element == x)
    {
        return current;
    }
    else if (x < current->element)
    {
        if (current->leftChild == NULL)
        {
            return NULL;
        }
        return search(current->leftChild, x);
    }
    else
    {
        if (current->rightChild == NULL)
        {
            return NULL;
        }
        return search(current->rightChild, x);
    }
}

template <class T>
void BSTree<T>::insertNode(const T &value)
{
    BSNODE<T> *p = root;
    BSNODE<T> *prev = NULL;
    while (p != 0)
    {
        prev = p;
        if (value <= p->getValue())
            p = p->leftChild;
        else if (value > p->getValue())
            p = p->rightChild;
    }
    if (root == NULL)
    {
        root = new BSNODE<T>(value);
    }
    else if (value <= prev->getValue())
    {
        prev->leftChild = new BSNODE<T>(value);
    }
    else if (value > prev->getValue())
    {
        prev->rightChild = new BSNODE<T>(value);
    }
}

template <class T>
void BSTree<T>::deleteByCopying(BSNODE<T> *&node)
{
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        BSNODE<T> *maxNode = node->leftChild;
        BSNODE<T> *pre = node;
        while (maxNode->rightChild != NULL)
        {
            pre = maxNode;
            maxNode = maxNode->rightChild;
        }
        node->element = maxNode->element;
        pre->rightChild = maxNode->leftChild;
        delete (maxNode);
    }
    else if (node->leftChild != NULL)
    {
        node->element = node->leftChild->element;
        node->leftChild = node->leftChild->leftChild;
    }
    else if (node->rightChild != NULL)
    {
        node->element = node->rightChild->element;
        node->rightChild = node->rightChild->rightChild;
    }
    else
    {
        BSNODE<T> *parent = getParent(root, node);
        parent->leftChild = NULL;
        parent->rightChild = NULL;
    }
}

template <class T>
void BSTree<T>::deleteByMerging(BSNODE<T> *&node)
{
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        BSNODE<T> *maxNode = node->leftChild;
        while (maxNode->rightChild != NULL)
        {
            maxNode = maxNode->rightChild;
        }
        maxNode->rightChild = node->rightChild;
        node = node->leftChild;

        delete (maxNode);
    }
    else if (node->leftChild != NULL)
    {
        node->element = node->leftChild->element;
        node->leftChild = node->leftChild->leftChild;
    }
    else if (node->rightChild != NULL)
    {
        node->element = node->rightChild->element;
        node->rightChild = node->rightChild->rightChild;
    }
    else
    {
        BSNODE<T> *parent = getParent(root, node);
        parent->leftChild = NULL;
        parent->rightChild = NULL;
    }
}

template <class T>
void BSTree<T>::inOrder(BSNODE<T> *root)
{
    if (root != NULL)
    {
        inOrder(root->leftChild);
        visit(root);
        inOrder(root->rightChild);
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    BSNODE<int> *tmp1, *tmp2;
    BSTree<int> st;
    st.createSearchTree();
    tmp1 = st.getRoot();
    st.inOrder(tmp1);
    cout << endl;
    cout << "插入结点" << endl;
    int temp;
    cin >> temp;
    st.insertNode(temp);
    st.inOrder(tmp1);
    cout << endl;
    cout << "输入一个需要查找的值" << endl;
    cin >> temp;
    tmp2 = st.search(tmp1, temp);
    if (tmp2 != NULL)
    {
        cout << "查找的值为: " << tmp2->getValue() << endl;
    }
    else
        cout << "不存在值" << temp << endl;
    cout << "输入一个需要删除的值(复制)" << endl;
    cin >> temp;
    tmp2 = st.search(tmp1, temp);
    if (tmp2 != NULL)
    {
        cout << "删除的值为: " << tmp2->getValue() << endl;
        st.deleteByCopying(tmp2);
        st.inOrder(tmp1);
    }
    else
        cout << "不存在值" << temp << endl;
    cout << endl;

    cout << "输入一个需要删除的值(合并)" << endl;
    cin >> temp;
    tmp2 = st.search(tmp1, temp);
    if (tmp2 != NULL)
    {
        cout << "删除的值为: " << tmp2->getValue() << endl;
        st.deleteByMerging(tmp2);
        st.inOrder(tmp1);
    }
    else
        cout << "不存在值" << temp << endl;

    Forget_that Just_go;
}
/*

1 2 3 4 5 6 7 8
0
9
4
5
6

                                                                                                         -^^--
                                                                      .-++^*nvvza1!!ii1uan~;^+.         ~6@@@#8i*
                                                                 .+n!6&@@###&6%%%%%%666&#&##@@@@&3uv*-  1#6uni&@6o-.      .
                                                            .-~i6#@@&6ivo~n~~~~~oo~~~o~~~~ooonai8&##@#8vz6%znz!&@@@&66u~~3&#%u^
                                                         ^z8&@@&81vo~oooooooooooooooooooo~~oooo~~~~oai6#@@6avvvvvzau!8&##8i1%@6~
                                                     .o3&@@&81n~~oooooooooooooooooooooooooooooooooo~o!@@8uvvvvvvvvzzzzvvzzzza%@3+
                                                  .n6#@#%unoooooooooooooooooooooooooooooooooooooooooa6&!vzvvvvvvvvvvvvzvvvzva6#!-
                                               .*i&@#%1o~ooooooooooooooooooooooooooooooooooovuuvo~ooa%%!zzvvvvvvvvvzvzvvzvvv3#%*
                                             .~6@@6in~oo~oooooooooooooooooooooooooooooooooooooz36un~n363zvvvvvvvvzvzvvvzvzvv1&#1
                                            ~%@@6ao~o~~ooooooooooooooooooooooooooooooooooooooooou6!vou%81zvvvvvzvzvzvzvvvvvvv6@8;
                                          ^6@@6anooo~o~ooooooooooooooooooooooooooooooooooooooo~o~z66zou6881zvzvzzzzvvvvvvvvvv6@&n
                                        .a&@6u~o~~~o~~ooooooooooooooooooooooooooooooooooooooooo~ooz63zoou6%&81azzzzzzzzvvzvvu6@8*
                                       *8@#6vooooooooooooooooooooooooooooooooooooooooooooooooooooo~z63voonz!8&@#8iuzzzvvzvvu%@&n
                                      ~&@&un~ooo~oooooooooooooooooooooooooooooooooooooooooooooooo~~~u6uo~o~~ov1%&@@#6%3i116#@@&v.
                                     o6@%zoo~oooooooooooooooooooooooooooooooooooooooooooooooooooooooo1!voo~~oo~~~nai66##@@#6i16@6;
                                   .n#@6voooooooooooooooooooooooooooooooooooooooooooooooooooooooooooov!unoo~oooooooono~onooonov6@&a.
                                   z#@%v~ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooovzooooooooooooooooooooooon!##i+
                                  v&@%z;~oooooooooooooooooooooo~oooooooooooooooooooooooooooooooooooooovivo~oooooooooooooooooooooo1&@6+
                                 ;6@6z~~ooooooooooooooooooooooooiaoooooooooooov38ao~ooooooooooooooooooz%6nooooooooooooooooooooooooi@@6+
                                +3@&u~o~oooooooooooooooooooooov86voooooooooo~n6@@8oo~ooooooooooooooo~oa&&v~oooooooooooooooooooooooni@@u-
                               -1@@6o~ooooooooooooooooooooo~~o36uooooooooooon8#@@6noooooooooooooooooooa&&zoo~oooo~ooooooooooooooonov6@#a
                               o##6nooooooooooooooooooooooooou&3n~ooooooooov%##8#6aoooooooooooooooooon!@6uznoooooooooooooooooooooooou&@6*
                              -8@@io~ooooooooooooooooooooooov66a~ooooooooou&@%;u#6a~ooooooooooooooooov%@616@#&%8iznoooooooooooooooooo!@#u
                              ~&@8n~ooooooooooooooooooooooooa66noooooooov8@@%;-z&&1ooooooooooooooooo~1@@@@@@@@@@@@#8aooooooooooooooo~z6@6^
                             .i@#!o~ooooooooooooooooooooooon3&1~~oa136&#@@@@@&83&#iooooooooooooooooov%@@@@&3v1&@@@@@@6!voooooooooooooo6@#1.
                             ;6@6u~~ooooooooooooooooooooooov86ai&@@@@@@@#@@@@@@@@@3~oooo~~n~~ooooo~v%@@@6~-;n~v%@@&#@@@&!n~oooooooooooz&@%;
                             n6@%n~oooooooooooooooooooooooou6#@@@@@@@#!;++^~!#@@@@#8noo~n%@&a~o~o~n%@@6;o3!138###@@&%#@@@%zooooooooooov8@6n
                             a&@3~~ooooooooooooooooooooonu%#@@@@@@&3n~i@@@##&%86@@#%zooo3@@&a~o~~z8@#a-v&6voooo1#@@@&6%#@#1oooooooooooo1##u.
                             i@#1o~~oooooooooooooooo~~o1&@@@@@@%a^ .1#6ivnnonz886#&aoon!#@@%vooo1&#&a-v&&uooooooi&@#@#!vznoo~oooooooooo1@#a.
                            -3@&zooooooooooooooooo~oov3#@@@@@u.   ^3#8vooooooov8#@@ion!#@@#3~~u6@&i+.*%@!n~oooooo3@6%@@!o~oooooooooooon8@&n
                            -6@6vooooooooooooooooooov8@@@##&8^   -i@&aooooooooou&@@6u%@616#!i&@@!+..-v@#aoooooo~o1#&nz@@8no~ooooooooooa&@3^
                            -6@%voooooooooooooooooooz&@#%1a&3.   ;6#8noooooooooo8@@@@@6;*%#@%1~-.. ..u@&aooooooooz&&o-a##6n~oooooooooo8@&n
                             i@%o~~oooooooooooooooooonavooo81.   n##!noooooooooo8@#@6u+..-+-........-1@&zo~oooo~o1&8* -1&@8noooooo~ooo8&#u-
                             a&%n~ooooooooooooooooooooo~ooa%i.   n#&uooooooooooo8#3o+.. -... ........-+. +;ooooov3&u. .-i#&1ooooooni83n!@%*
                             n83oooooooooooooooooooooooooou&!.   +~;.^~oooooooou%8o..................+a661oooooni&1+  ..^6#%zoooooa&@#v!@6~
                             *zaooooooooooooooooooooooooooa%i.   .o11~~ooooooon!%a....................-v8%6unv186a+  ...-z6&!noooo3@@#i6@&o.
                             ;1aooooooooooooooooooooooooooa%i-    ;38ivoooooov!6u+. ....................+ni8863u;-..----*!&&6ao~~u&@@@6&@%;
                             u&iooooooooooooooonuzooooooooa6!*..   ^u8%31aa1363o-.........................---++--------+a%86&!oon%@#&@@@#!+
                            ;%#aoooooooooooooooa3z~oooooooa86~.--....^n16686u~-..........................--.---------..~3%!66%vn%@&6@@@@&n
                           -1@%nooooooooooooooo!8aoooooooov86o.----.--------............................---------------z8%va&&!6@%~z#@@@1-
                          .v#&uoooooooooooooooo!8a~ooooooon!6a--------------.............................-------------*3%3-n%#@@6nn1#@3;.
                          z&@3nooooooooooooooon3&1oooooooon!%i*------------.........;nauuzn~;*+-...........--------.--n%6n -3##6uaau%@!+
                        -1@#6noooooooooooooooooi63noooo~oonu66o------------........~31vvau1i!66!v-..............-....^6&!^*vuuuuau1!8&&a.
                       *8@#!ooooo~~~ooooooooooou6&u~ooooooon!%u+..-...............-v6innnnnnnna!1^...............  .~%@8vvuauuau3&#@&iv!%z-
                     +i#@6a~oonnvzvoooooooooo~~n6@6n~~ooo~~oi83;...................~3!annnnnvu6i;................+n8@@#&iauu13&##&3vov6%&&o
                  .;!@@#izu3%&@@@61noooooooooooni##1oooooo~oz%%a--.   .......... ...v661vnz163z+.............-*v3#@@8u%#61!6#@&!v~~ou&%ni@!-
               -z6#@@@@@@@##63u6@!~~oooooooooooov8@6a~oooooon3@#6v+-  ..............-*u68663z+.......... -*z6&@@&6uooo!#@#@&6zooo~v3#8;+3#!-
               .v86%86!un*.  .~&@i~oooooooooooooov6@%voooooooz%@@@#&3z*-................-+-.. .. . ..^~u8#@@#%ivo~oo~~v6@@%v~oooni6#1+ *%#u.
                            . *6@3ooooooooooooooo~u&@8zooooooou&@61%#@@@&8!a~+-.  ..........-.-+;z!66##@&3anoooooooooo~z&@3oo~v3&#3*  *6@i+
                              +%@6vooooooooooooooooa%@6aooooooou&#!oonzi66&#&6%1*- .......*366%&&&&%6unooooooooooooooo~o3#!~v6##6*  .v6@6a+.
                               n@#6nooooooooooo~~oo~z8##3vo~ooo~a%&3o~ooo~~~v86i^... ....-a&6!aznooooooooooo~~o~oooo~ov~~vi#@&i^  -a6#%!&#v
                               -u@#io~o~ooooon!&3voo~oa%@#6!avov1!3%in~o~oou866i^. ......+16%ivoo~~ooo~oooov6#&1~ooo1&#36#8a~- -n%##6v~z&#a.
                                -!@@6voo~oooov8#@#1noooooi6#@@#@@@6vvnoov3%&%!88n-.......*3%88%6v~~ooooooov6@@@6~noz6@@@&i-..o3##8ao~~o1##!+
                                ..1#@6unooooooi#@@@61noo~~~oou8#@@i~oou&@#6o. *3%i+. ....^36u*u6&8anoooooz%@%#@3~o1&@@@@&n*a6@6ivn~ooou6#&6%o.
                                   ;6@@6unooooz%@66&@#63unonaavvuavoov6#3*     ~38i*.....*6%1-.o6@@8131oa6#!;8@%u8@#a-*i6&&@&1o~~oov!6#&1o6#z.
                                    .o%@@&3zoooi@&;.oi%#@@6&@@#6uo~oi&##6-      -168n-...;68u+  .z&@@@@#@#u..6@@@@8;.   -+!@!ooov!#@@%z+ o6#v
                                       *u6@@#63!#@3^   -o3@@#&86&668&66&6^       -u88u+.-n8%z.    -v%@@@6;   ~3%3o.      .n8uu%#@#6v+   +!@3^
                                          +vi%#@@@@6o     +11o.-;i668ou63^         n68!*-i%6;       .i#@z.              -~!#@@6!o.     +!@%;
                                               +;on*            o6%3*-u&3^          v6%1~!%1+       .u@@@3*         .;16@#&3o+        ~8#&u.
                                                              .~66i+.-166~          -v8%8%%n        .u@#@@&n       +1##8a^.         .z#@83&a-
                                                    .-^;~~;~noo663* .-a66;           *!66&6&3o..    .1@#a%#6;.    ;%@6~.          -o3#8a~n8#v
                                                 +a%##@&6%%8668%6o....a66~         *i6&6!ui8#@6u^.  .!@&;*6@6+   +8@%;         +a%#@8v~~oo1&i+
                                                ^8@#8iuuuuaaa!88n+....z%6~      .~%@@61uuuuu16@@@6~ ^%@%*.*8#ii333##a     .-~3#@@&izno~~oo3@6*
                                                ;%@61aau6%6!!6%3+. ...v86o    .n6##3iuuuuuuuu8@%8#@&6@@u-18&@@&6@@@#z  -^z8@@&3uvnoooooooo3@i-
                                                -!#&iauau!68%86a~+....v88v. +z6@&u^z6!uuuuuuu8@%*^i&@&1+.3@&!ua3@@%##&##@#6868vonooooo~oov%&v
                                                 v&#8uaaaaaui388%%6iv*v6%1n8@#6a- ^i&3uuuuuua3#6~  -++   1@&!a1%@6+-*oo;^.+3@ioooooooo~oou&6~
                                                 ^6@&!uaaaaaaaaaui!6888%66&@#6*   +3#6uuuuuuu3##o        v#@&iu6@%;       ^3@!noooooooooo!#8^
                                                  o6@%!!i1uaaaaaaaaauuu111i6#6^   ^3#6uuuuuuui&#v        *%#6+ ~%@%*      +3@%n~nv~o~o~oo!@6^
                                                  *8@&z;a3%%83!!i1uu11uu116##a.   ^6#6uuuuuuui#@i.       -8@%^ .v@%~       v#@63#@6un~ooo!@3+
                                                *8#@&8n. .-^vu3688%%66&&##@@6+    ^6@6uuuuuua16#3-       -6@&*  o&6z.      -u#@@#@#@&iv~~!@6;
                                                ^8@8^              --.-++!#&n.    *%@8uuuuuua16@8+        a@@v   v6&1-       n6@#%*n8@@#8%@@u.
                                                .^vo.                  -a#@1-     *%@8uuuuuuau8#6;        ~#@i-   v&@6*.      -v1;.  -;zi66#i+
                                               .v81^                  .u@#!+      ;&@%uuuuuuau8#6;        *6@3+    o&@%;.
                                              -1@#1.                  .1&#@z      ;&@%uuuuuuau8#6;        +3@6*     o#@8*
                                             .u@@1-                    .1@@!-     ;6@%uuuuuuuu6#6;        .a@#z.    .v#@6+
*/