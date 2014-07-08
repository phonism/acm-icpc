#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define maxn 20010
#define maxm 480010
#define maxb 22
const int inf = 0x3f3f3f3f;

#define th(x)	this->x = x
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
struct Maxflow {
    struct Edge {
        int t;
        int c;
        Edge*n, *r;
        Edge(int _t, int _c, Edge*_n) :
                t(_t), c(_c), n(_n) {
        }
    };
    vector<Edge*> E;
    int addV() {
        E.push_back((Edge*) 0);
        return E.size() - 1;
    }
    void clear() {
        E.clear();
    }
    Edge* makeEdge(int s, int t, int c) {
        return E[s] = new Edge(t, c, E[s]);
    }
    void addEdge(int s, int t, int c) {
        Edge*e1 = makeEdge(s, t, c), *e2 = makeEdge(t, s, c);
        e1->r = e2, e2->r = e1;
    }
    int calcMaxFlow(int vs, int vt) {
        int nV = E.size();
        int totalFlow = 0;
        int MAX_FLOW = 1 << 29;
        vector<int> am(nV, 0);
        vector<int> h(nV, 0), cnt(nV + 1, 0);
        vector<Edge*> prev(nV, (Edge*) 0), cur(nV, (Edge*) 0);
        cnt[0] = nV;
        int u = vs;
        Edge*e;
        am[u] = MAX_FLOW;
        while (h[vs] < nV) {
            for (e = cur[u]; e; e = e->n)
                if (e->c > 0 && h[u] == h[e->t] + 1)
                    break;
            if (e) {
                int v = e->t;
                cur[u] = prev[v] = e;
                am[v] = min(am[u], e->c);
                u = v;
                if (u == vt) {
                    int by = am[u];
                    while (u != vs) {
                        prev[u]->c -= by;
                        prev[u]->r->c += by;
                        u = prev[u]->r->t;
                    }
                    totalFlow += by;
                    am[u] = MAX_FLOW;
                }
            } else {
                if (!--cnt[h[u]])
                    break;
                h[u] = nV;
                for (e = E[u]; e; e = e->n)
                    if (e->c > 0 && h[e->t] + 1 < h[u]) {
                        h[u] = h[e->t] + 1;
                        cur[u] = e;
                    }
                ++cnt[h[u]];
                if (u != vs)
                    u = prev[u]->r->t;
            }
        }
        return totalFlow;
    }
    ~Maxflow() {
        for (int i = 0; i < E.size(); ++i) {
            for (Edge*e = E[i]; e;) {
                Edge*ne = e->n;
                delete e;
                e = ne;
            }
        }
    }
}g1, g2;

struct Node {
	int u, v, w;
	bool operator<(const Node &o) const {
		return w < o.w;
	}
};
Node node[maxm];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	// g1.init(n + 1);
	// g2.init(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		node[i].u = u;
		node[i].v = v;
		node[i].w = w;
	}
	// sort(node + 1, node + m + 1);
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);
	u--; v--;
	for (int i = 0; i < n; i++) {
		g1.addV();
		g2.addV();
	}
	for (int i = 1; i <= m; i++) {
		if (node[i].w == w)
			continue;
		if (node[i].w < w) {
			g1.addEdge(node[i].u, node[i].v, 1);
		} else {
			g2.addEdge(node[i].u, node[i].v, 1);
		}
	}
	printf("%d\n", g1.calcMaxFlow(u, v) + g2.calcMaxFlow(u, v));
}
