#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 202020;
const int inf = 0x3f3f3f3f;

struct State {
	State *par, *go[26];
	int val, max, min;
	void init() {
		memset(go, 0, sizeof(go));
		val = 0; max = 0; min = inf;
	}
};
char str[maxn];
State *root, *tail, que[maxn], *top[maxn];
int tot, len, c[maxn];

inline void add(int c, int l) {
	State *np = &que[tot++], *p = tail;
	np->val = l;
	while (p && p->go[c] == NULL) {
		p->go[c] = np; p = p->par;
	}
	if (p == NULL) np->par = root;
	else {
		State *q = p->go[c];
		if (q->val == p->val + 1) np->par = q;
		else {
			State *nq = &que[tot++];
			*nq = *q;
			nq->val = p->val + 1;
			np->par = q->par = nq;
			while (p && p->go[c] == q) {
				p->go[c] = nq; p = p->par;
			}
		}
	}
	tail = np;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int l = strlen(str); len = 1; tot = 0;
	memset(c, 0, sizeof(c));
	int ans = 0, tmp = 0;
	for (int i = 0; i < maxn; i++)
		que[i].init();
	root = tail = &que[tot++];
	for (int i = 0; i < l; i++)
		add(str[i]-'a', len++);
	for (int i = 0; i < tot; i++)
		c[que[i].val]++;
	for (int i = 1; i < len; i++)
		c[i] += c[i-1];
	for (int i = 0; i < tot; i++)
		top[--c[que[i].val]] = &que[i];
	for (int cas = 2; cas <= n; cas++) {
		scanf("%s", str);
		l = strlen(str); tmp = 0;
		State *p = root;
		for (int i = 0; i < l; i++) {
			int c = str[i] - 'a';
			if (p->go[c]) {
				p = p->go[c]; tmp++;
			} else {
				while (p && p->go[c] == NULL)
					p = p->par;
				if (p) {
					tmp = p->val + 1; p = p->go[c];
				} else {
					p = root; tmp = 0;
				}
			}
			if (p->max < tmp) p->max = tmp;
		}
		for (int i = tot - 1; i >= 0; i--) {
			p = top[i];
			if (p->min > p->max) p->min = p->max;
			if (p->par) {
				State *q = p->par;
				q->max = min(q->val, max(q->max, p->max));
			}
			p->max = 0;
		}
	}
	for (int i = 0; i < tot; i++)  
    	ans = max(ans, que[i].min);  
    printf("%d\n", ans); 
}
