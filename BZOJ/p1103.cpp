#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
 
const int maxn = 250020;
const int inf = 0x3f3f3f3f;
 
/*
template<class T>
struct SplayNode
{
    SplayNode<T> *L, *R, *P;
    T key;
    T sum;
    T max;
    int size;
    bool rev;
};
 
template<class T>
struct SplayTree
{
    int C, Top, count;
    SplayNode<T> *root, *null, nodes[maxn], *stack[maxn];
 
    SplayNode<T>* newNode(const T& c)
    {
        count++;
        SplayNode<T> *res;
        if (Top)
            res = stack[--Top];
        else
            res = &nodes[++C];
        res->size = 1;
        res->L = res->R = res->P = null;
        res->rev = 0;
        res->sum = res->key = res->max = c;
        return res;
    }
    void push_up(SplayNode<T>* x)
    {
        if (x == null)
            return;
        //push_down(x->L);
        //push_down(x->R);
        x->size = x->L->size + x->R->size + 1;
        x->sum = x->L->sum + x->R->sum + x->key;
        x->max = max(x->key, max(x->L->max, x->R->max));
    }
    void push_down(SplayNode<T>* x)
    {
        if (x == null)
            return;
        if (x->rev)
        {
            x->L->rev ^= 1;
            x->R->rev ^= 1;
            swap(x->L, x->R);
 
            x->rev = 0;
        }
    }
    void init(int N)
    {
        C = count = Top = 0;
        null = &nodes[++C];
        null->L = null->R = null->P = null;
        null->sum = 0;
        null->key=null->max=-0x7FFFFFFF;
        for (int i = 1; i <= N; i++)
            newNode(0);
    }
    void leftRotate(SplayNode<T>* y)
    {
        SplayNode<T>* x = y->R, *z = y->P;
        push_down(y);
        push_down(x);
        if (z != null)
        {
            if (z->L == y)
                z->L = x;
            else if (z->R == y)
                z->R = x;
        }
        y->R = x->L;
        x->L = y;
        x->P = z;
        y->P = x;
        if (y->R != null)
            y->R->P = y;
        push_up(y);
    }
    void rightRotate(SplayNode<T>* y)
    {
        SplayNode<T>* x = y->L, *z = y->P;
        push_down(y);
        push_down(x);
        if (z != null)
        {
            if (z->R == y)
                z->R = x;
            else if (z->L == y)
                z->L = x;
        }
        y->L = x->R;
        x->R = y;
        x->P = z;
        y->P = x;
        if (y->L != null)
            y->L->P = y;
        push_up(y);
    }
    void splay(SplayNode<T>* x)
    {
        if (x == null)
            return;
        null->L = null->R = null->P = null;
        push_down(x);
        while (x->P->L == x || x->P->R == x)
        {
            if (x == x->P->L)
            {
                if (x->P->P->L != x && x->P->P->R != x)
                    rightRotate(x->P);
                else if (x->P == x->P->P->L)
                {
                    rightRotate(x->P->P);
                    rightRotate(x->P);
                }
                else if (x->P == x->P->P->R)
                {
                    rightRotate(x->P);
                    leftRotate(x->P);
                }
            }
            else
            {
                if (x->P->P->L != x && x->P->P->R != x)
                    leftRotate(x->P);
                else if (x->P == x->P->P->R)
                {
                    leftRotate(x->P->P);
                    leftRotate(x->P);
                }
                else if (x->P == x->P->P->L)
                {
                    leftRotate(x->P);
                    rightRotate(x->P);
                }
            }
        }
        push_up(x);
    }
    void access0(SplayNode<T> *v)
    {
        if (v->P != null)
            access0(v->P);
        push_down(v);
    }
    void access(SplayNode<T> *x)
    {
        access0(x);
        for (SplayNode<T> *v = null, *u = x; u != null; u = u->P)
        {
            splay(u);
            u->L = v;
            v->P = u;
            push_up(v = u);
        }
        splay(x);
    }
    SplayNode<T>* findRoot(SplayNode<T> *x)
    {
        access(x);
        while (x->R != null)
            x = x->R;
        return x;
    }
    T queryLCASUM(SplayNode<T> *x, SplayNode<T> *y)
    {
        if (x==y) return 0;
        T res = 0;
        access(x);
        for (SplayNode<T> *v = null, *u = y; u != null; u = u->P)
        {
            splay(u);
            if (u->P == null)
            {
                push_down(u->L);
                push_down(v);
                res += u->key;
                res += u->L->sum + v->sum;
            }
            u->L = v;
            v->P = u;
            push_up(v = u);
        }
        return res;
    }
    void cut(SplayNode<T> *x)
    {
        access(x);
        SplayNode<T> *r = x->R;
        r->P = null;
        x->R = null;
        push_up(x);
    }
    void link(SplayNode<T> *son, SplayNode<T> *parent)
    {
        access(son);
        access(parent);
        son->P = parent;
    }
    void changeRoot(SplayNode<T> *x)
    {
        access(x);
        x->L = null;
        push_up(x);
        x->rev ^= 1;
        push_down(x);
    }
    void change(SplayNode<T> *x,T value)
    {
        access(x);
        x->key=value;
        push_up(x);
    }
};
SplayTree<int> tree;
*/
 
 
template<class T>
struct SplayNode {
    SplayNode<T> *L, *R, *P;
    T key; 
    T sum;
    T max; 
    int size;
    bool rev;
};
 
template<class T>
struct SplayTree {
 
    int C, Top, count;
    SplayNode<T> *root, *null, nodes[maxn], *stack[maxn];
 
    SplayNode<T>* newNode(const T& c) {
        count++;
        SplayNode<T> *res;
        if (Top)
            res = stack[--Top];
        else
            res = &nodes[++C];
        res->size = 1;
        res->L = res->R = res->P = null;
        res->rev = 0;
        res->sum = res->key = res->max = c;
        return res;
    }
 
    void pushUp(SplayNode<T> *x) {
        if (x == null)
            return ;
        //pushDown(x->L);
        //pushDown(x->R);
        x->size = x->L->size + x->R->size + 1;
        x->sum = x->L->sum + x->R->sum + x->key;
        x->max = max(x->key, max(x->L->max, x->R->max));
    }
 
    void pushDown(SplayNode<T> *x) {
        if (x == null)
            return ;
        if (x->rev) {
            x->L->rev ^= 1;
            x->R->rev ^= 1;
            swap(x->L, x->R);
            x->rev = 0;
        }
    }
 
    void init(int N) {
        C = count = Top = 0;
        null = &nodes[++C];
        null->L = null->R = null->P = null;
        null->sum = 0;
        null->key = null->max = -inf;
        for (int i = 1; i <= N; i++)
            newNode(0);
    }
 
    void leftRotate(SplayNode<T> *y) {
        SplayNode<T> *x = y->R, *z = y->P;
        pushDown(y);
        pushDown(x);
        if (z != null) {
            if (z->L == y)
                z->L = x;
            else if (z->R == y)
                z->R = x;
        }
        y->R = x->L;
        x->L = y;
        x->P = z;
        y->P = x;
        if (y->R != null)
            y->R->P = y;
        pushUp(y);
    }
 
    void rightRotate(SplayNode<T> *y) {
        SplayNode<T> *x = y->L, *z = y->P;
        pushDown(y);
        pushDown(x);
        if (z != null) {
            if (z->R == y)
                z->R = x;
            else if (z->L == y)
                z->L = x;
        }
        y->L = x->R;
        x->R = y;
        x->P = z;
        y->P = x;
        if (y->L != null)
            y->L->P = y;
        pushUp(y);
    }
 
    void splay(SplayNode<T> *x) {
        if (x == null)
            return ;
        null->L = null->R = null->P = null;
        pushDown(x);
        while (x->P->L == x || x->P->R == x) {
            if (x == x->P->L) {
                if (x->P->P->L != x && x->P->P->R != x)
                    rightRotate(x->P);
                else if (x->P == x->P->P->L) {
                    rightRotate(x->P->P);
                    rightRotate(x->P);
                } else if (x->P == x->P->P->R) {
                    rightRotate(x->P);
                    leftRotate(x->P);
                }
            } else {
                if (x->P->P->L != x && x->P->P->R != x)
                    leftRotate(x->P);
                else if (x->P == x->P->P->R) {
                    leftRotate(x->P->P);
                    leftRotate(x->P);
                } else if (x->P == x->P->P->L) {
                    leftRotate(x->P);
                    rightRotate(x->P);
                }
            }
        }
        pushUp(x);
    }
 
    void access0(SplayNode<T> *v) {
        if (v->P != null)
            access0(v->P);
        pushDown(v);
    }
 
    void access(SplayNode<T> *x) {
        access0(x);
        for (SplayNode<T> *v = null, *u = x; u != null; u = u->P) {
            splay(u);
            u->L = v;
            v->P = u;
            pushUp(v = u);
        }
        splay(x);
    }
 
    SplayNode<T> *findRoot(SplayNode<T> *x) {
        access(x);
        while (x->R != null)
            x = x->R;
        return x;
    }
 
    void updateLCA(SplayNode<T> *x, SplayNode<T> *y, T w) {
        access(x);
        for (SplayNode<T> *v = null, *u = x; u != null; u = u->P) {
            splay(u);
            if (u->P == null) {
                u->key += w;
                u->L->add != w;
                v->add += w;
            }
            u->L = v;
            v->P = u;
            pushUp(v = u);
        }
    }
 
    T queryLCASUM(SplayNode<T> *x, SplayNode<T> *y) {
        if (x == y) 
            return 0;
        T res = 0;
        access(x);
        for (SplayNode<T> *v = null, *u = y; u != null; u = u->P) {
            splay(u);
            if (u->P == null) {
                pushDown(u->L);
                pushDown(v);
                res += u->key;
                res += u->L->sum + v->sum;
            }
            u->L = v;
            v->P = u;
            pushUp(v = u);
        }
        return res;
    }
 
    T queryLCAMAX(SplayNode<T> *x, SplayNode<T> *y) {
        T res = 0;
        access(x);
        for (SplayNode<T> *v = null, *u = y; u != null; u = u->P) {
            splay(u);
            if (u->P = null) {
                pushDown(u->L);
                pushDown(v);
                res = max(u->key, max(u->L->max, v->max));
            }
            u->L = v;
            v->P = u;
            pushUp(v = u);
        }
        return res;
    }
 
    void cut(SplayNode<T> *x) {
        access(x);
        SplayNode<T> *r = x->R;
        r->P = null;
        x->P = null;
        pushUp(x);
    }
 
    void link(SplayNode<T> *son, SplayNode<T> *parent) {
        access(son);
        access(parent);
        son->P = parent;
    }
 
    void changeRoot(SplayNode<T> *x) {
        access(x);
        x->L = null;
        pushUp(x);
        x->rev ^= 1;
        pushDown(x);
    }
 
    void change(SplayNode<T> *x, T value) {
        access(x);
        x->key = value;
        pushUp(x);
    }
 
};
SplayTree<int> tree;
 
 
 
/* //点权
struct ListNode {
    ListNode *next;
    int index;
};
 
ListNode *list[maxn], nodes[maxn*5];
int C, N, M, queue[maxn];
int vis[maxn];
 
void addEdge(int p, int q) {
    ListNode *t = &nodes[C++];
    t->next = list[p]->next;
    t->index = q;
    list[p]->next = t;
}
 
void init() {
    scanf("%d", &N);
    C = 0;
    for (int i = 1; i <= N; i++) {
        list[i] = &nodes[C++];
        list[i]->next = 0;
    }
    tree.init(N);
 
    for (int i = 1; i < N; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        addEdge(p, q);
        addEdge(q, p);
    }
    for (int i = 1; i <= N; i++) {
        vis[i] = 0;
        scanf("%d", &tree.nodes[i+1].key);
        tree.nodes[i+1].max = tree.nodes[i+1].key;
        tree.nodes[i+1].sum = tree.nodes[i+1].key;
    }
 
    int head = 0, tail = 0;
    tree.nodes[2].P = tree.null;
    vis[1] = 1;
    qeueu[tail++] = 1;
    while (head < tail) {
        int current = queue[head++];
        for (ListNode *ite = list[current]->next; ite; ite = ite->next) {
            if (!vis[ite->index]) {
                vis[ite->index] = 1;
                tree.nodes[ite->index+1].P = tree.nodes+current+1;
                queue[tail++] = ite->index;
            }
        }
    }
}
 
void work() {
    char cmd[16];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'Q' && cmd[1] == 'S') {
            int p, q;
            scanf("%d %d", &p, &q);
            int res = tree.queryLCA1(tree.nodes+1+p, tree.nodes+1+q);
            printf("%d\n", res);
        } else if (cmd[0] == 'C') {
            int p, q;
            scanf("%d %d", &p, &q);
            tree.change(tree.nodes+1+p, q);
        } else {
            int p, q;
            scanf("%d %d", &p, &q);
            int res = tree.queryLCA2(tree.nodes+1+p, tree.nodes+1+q);
            printf("%d\n", res);
        }
    }
}
*/
 
 
struct ListNode {
    ListNode *next;
    int index;
    int value;
};
 
int C;
ListNode nodes[3*maxn], *list[maxn];
 
void initList(int N) {
    C = 0;
    for (int i = 1; i <= N; i++) {
        list[i] = &nodes[C++];
        list[i]->next = 0;
    }
}
 
void addEdge(int p, int q, int value) {
    ListNode *t = &nodes[C++];
    t->next = list[p]->next;
    list[p]->next = t;
    t->value = value;
    t->index = q;
}
 
int vis[maxn], parent[maxn], value[maxn];
 
void dfs(int current) {
    for (ListNode *ite = list[current]->next; ite; ite = ite->next) {
        if (!vis[ite->index]) {
            vis[ite->index] = 1;
            dfs(ite->index);
            parent[ite->index] = current;
            value[ite->index] = ite->value;
        }
    }
}
 
void dfs() {
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dfs(1);
}
 
int N, M;
 
void buildTree() {
    dfs();
    tree.init(N);
    for (int i = 1; i <= N; i++) {
        tree.nodes[i+1].P = tree.nodes + parent[i] + 1;
        tree.nodes[i+1].key = tree.nodes[i+1].max = value[i];
    }
    tree.nodes[2].P = tree.null;
}
 
struct Edge {
    int x, y;
    Edge() {}
    Edge(int p, int q) : x(p), y(q) {}
};
 
Edge edge[maxn];
 
void init() {
    scanf("%d", &N);
    initList(N);
    for (int i = 1; i < N; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        addEdge(p, q, 1);
        addEdge(q, p, 1);
        edge[i] = Edge(p, q);
    }
    buildTree();
}
 
void work() {
    char cmd[16];
    scanf("%d", &M);
    for (int i = 0; i < M + N - 1; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'W') {
            int p, q;
            scanf("%d", &q);
            p = 1;
            int res = tree.queryLCASUM(tree.nodes+1+p, tree.nodes+1+q);
            printf("%d\n", res);
        } else {
            int p, q;
            scanf("%d %d", &p, &q);
            if (parent[p] != q)
                swap(p, q);
            tree.change(tree.nodes+1+p, 0);
        }
    }
}
 
 
int main() {
    init();
    work();
}